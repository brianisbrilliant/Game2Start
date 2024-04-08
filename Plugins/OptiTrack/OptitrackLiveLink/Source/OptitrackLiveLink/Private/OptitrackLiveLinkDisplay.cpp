#include "OptitrackLiveLinkDisplay.h"

#include <Features/IModularFeatures.h>
#include <Components/LineBatchComponent.h>
#include <LiveLinkTypes.h>
#include <Roles/LiveLinkAnimationTypes.h>
#include <Roles/LiveLinkTransformTypes.h>
#include <DrawDebugHelpers.h>

// Constructor initiates values and instantiates components
AOptitrackLiveLinkDisplay::AOptitrackLiveLinkDisplay()
{
	// Create the root component, allowing the actor to be moved around
	Root = CreateDefaultSubobject<USceneComponent>( TEXT( "Root" ) );
	RootComponent = Root;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Apply default properties
	mLineThicknessScale = kLineThicknessDefault;
	mSkeletonLineThickness = mLineThicknessScale;
	mRigidBodyLineThickness = mLineThicknessScale;
	mTMarkersetLineThickness = mLineThicknessScale;
	mAssetColor = kAssetColorDefault;
	mSkeletonColor = mAssetColor;
	mRigidBodyColor = mAssetColor;
	mTMarkersetColor = mAssetColor;
	mLabeledMarkerSize = kMarkerSizeDefault;
	mUnlabeledMarkerSize = kMarkerSizeDefault;
	mLabeledMarkerColor = kLabeledMarkerColorDefault;
	mUnlabeledMarkerColor = kUnlabeledMarkerColorDefault;
	
	// Create components and add them as children to this object
	if( RegisterForLiveLinkClient() )
	{
		IModularFeatures& ModularFeatures = IModularFeatures::Get();
		if( ModularFeatures.IsModularFeatureAvailable( ILiveLinkClient::ModularFeatureName ) )
		{
			ILiveLinkClient& LiveLinkClient = ModularFeatures.GetModularFeature<ILiveLinkClient>( ILiveLinkClient::ModularFeatureName );

			TArray<FLiveLinkSubjectKey> subjectKeys = LiveLinkClient.GetSubjects( false, true );

			for( const FLiveLinkSubjectKey& key : subjectKeys )
			{
				// There should only be (at most) one markers_unlabeled subject
				if( key.SubjectName.ToString().Compare( "Markers_Unlabeled", ESearchCase::IgnoreCase ) == 0 )
				{
					FName assetName = key.SubjectName;
					mUnlabeledMarkerComponent.Add( key, CreateDefaultSubobject<UOptitrackLiveLinkComponent>( assetName ) );
					mUnlabeledMarkerComponent[ key ]->mMarkerSubjectKey = key;
					mUnlabeledMarkerComponent[ key ]->mMarkerColor = mUnlabeledMarkerColor;
					mUnlabeledMarkerComponent[ key ]->mMarkerSize = mUnlabeledMarkerSize;
				}
				else if( key.SubjectName.ToString().StartsWith( "Markers_" ) )
				{
					// Attach labeled markers subjects to their components
					FString name = key.SubjectName.ToString();
					name.RemoveFromStart( "Markers_" );
					mMarkerDict.FindOrAdd( name ) = key;
					if( mNameDict.Contains( name ) )
					{
						if( mAssetComponents.Contains( mNameDict[ name ] ) )
						{
							mAssetComponents[ mNameDict[ name ] ]->mMarkerSubjectKey = key;
						}
					}
				}
				else
				{
					// Identify all assets to turn into components
					this->AddComponent( key );
					mNameDict.FindOrAdd( key.SubjectName.ToString() ) = key;
					if( mMarkerDict.Contains( key.SubjectName.ToString() ) )
					{
						mAssetComponents[ key ]->mMarkerSubjectKey = mMarkerDict[ key.SubjectName.ToString() ];
					}
				}
			}
		}
	}
}

// Destructor closes channel to Live Link
AOptitrackLiveLinkDisplay::~AOptitrackLiveLinkDisplay()
{
	UnregisterForLiveLinkData();
	UnregisterForLiveLinkClient();
}

// This non-static function MUST ONLY be called from the constructor! Otherwise it will not work
void AOptitrackLiveLinkDisplay::AddComponent( const FLiveLinkSubjectKey& key )
{
	FName assetName = key.SubjectName;
	mAssetComponents.Add( key, CreateDefaultSubobject<UOptitrackLiveLinkComponent>( assetName ) );
	this->AddInstanceComponent( mAssetComponents[ key ] );
	mAssetComponents[ key ]->SetupAttachment( RootComponent );
	mAssetComponents[ key ]->mAssetColor = mAssetColor;
	mAssetComponents[ key ]->mLineThicknessScale = mLineThicknessScale;
	mAssetComponents[ key ]->mMarkerSize = mLabeledMarkerSize;
	mAssetComponents[ key ]->mMarkerColor = mLabeledMarkerColor;
	mAssetComponents[ key ]->mParentActor = this;
}

// This function is to be used OUTSIDE the constructor! It does not attach its component to the parent actor
void AOptitrackLiveLinkDisplay::AddComponentRealtime( const FLiveLinkSubjectKey& key )
{
	FName assetName = key.SubjectName;
	mAssetComponents.Add( key, NewObject<UOptitrackLiveLinkComponent>() );
	mAssetComponents[ key ]->mAssetColor = mAssetColor;
	mAssetComponents[ key ]->mLineThicknessScale = mLineThicknessScale;
	mAssetComponents[ key ]->mMarkerSize = mLabeledMarkerSize;
	mAssetComponents[ key ]->mMarkerColor = mLabeledMarkerColor;
	mAssetComponents[ key ]->mParentActor = this;
}

// This override makes the Actor continue to tick even if the level is set to TickType==LEVELTICK_ViewportsOnly
bool AOptitrackLiveLinkDisplay::ShouldTickIfViewportsOnly() const
{
	return true;
}

// Called every frame
void AOptitrackLiveLinkDisplay::Tick( float DeltaTime )
{
	if( RegisterForLiveLinkClient() )
	{
		if( mSubjectListChanged )
			UnregisterForLiveLinkData();

		if( LiveLinkSubjectCount() == 0 )
			RegisterForLiveLinkData();
	}

	Super::Tick(DeltaTime);
	Draw();
}

void AOptitrackLiveLinkDisplay::OnLiveLinkSubjectsChanged()
{
	mSubjectListChanged = true;
}

void AOptitrackLiveLinkDisplay::OnLiveLinkSourcesChanged()
{
	mLiveLinkValid = false;
}

// Utility macro to help retrigger property events in-object (couldn't do it with a function so it is what it is)
#define RETRIGGER_PROPERTY(Event, MemberName) \
	Event.Property = FindFProperty<FProperty>( this->GetClass(), GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, MemberName ) ); \
	this->PostEditChangeProperty( Event );

// Called whenever a property is changed via the editor
void AOptitrackLiveLinkDisplay::PostEditChangeProperty( FPropertyChangedEvent& PropertyChangedEvent )
{
	// Get the name of the property which changed
	const FName PropertyName = ( PropertyChangedEvent.Property != nullptr ) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	// If "Asset Color" changed, all assets receive the same color
	if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mAssetColor ) )
	{
		mSkeletonColor = mAssetColor;
		mRigidBodyColor = mAssetColor;
		mTMarkersetColor = mAssetColor;

		// Call the function again to trigger on-changed for the subproperties
		RETRIGGER_PROPERTY( PropertyChangedEvent, mSkeletonColor );
		RETRIGGER_PROPERTY( PropertyChangedEvent, mRigidBodyColor );
		RETRIGGER_PROPERTY( PropertyChangedEvent, mTMarkersetColor );
	}
	// "Line Thickness" property updates all asset components
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mLineThicknessScale ) )
	{
		mSkeletonLineThickness = mLineThicknessScale;
		mRigidBodyLineThickness = mLineThicknessScale;
		mTMarkersetLineThickness = mLineThicknessScale;

		RETRIGGER_PROPERTY( PropertyChangedEvent, mSkeletonLineThickness );
		RETRIGGER_PROPERTY( PropertyChangedEvent, mRigidBodyLineThickness );
		RETRIGGER_PROPERTY( PropertyChangedEvent, mTMarkersetLineThickness );
	}
	// If "Display Assets" changed, all assets are updated accordingly
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mDrawAssets ) )
	{
		mDrawRigidBodies = mDrawAssets;
		mDrawSkeletons = mDrawAssets;
		mDrawTMarkersets = mDrawAssets;

		RETRIGGER_PROPERTY( PropertyChangedEvent, mDrawSkeletons );
		RETRIGGER_PROPERTY( PropertyChangedEvent, mDrawRigidBodies );
		RETRIGGER_PROPERTY( PropertyChangedEvent, mDrawTMarkersets );
	}
	// The "Skeleton Color" property updates all skeleton components
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mSkeletonColor ) )
	{
		for( const auto& it : mSkeletonData )
		{
			mAssetComponents[ it.Key ]->mAssetColor = mSkeletonColor;
		}
	}
	// The "Rigid Body Color" property updates all rigid body components
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mRigidBodyColor ) )
	{
		for( const auto& it : mRigidBodyData )
		{
			mAssetComponents[ it.Key ]->mAssetColor = mRigidBodyColor;
		}
	}
	// The "Trained Markerset Color" property updates all trained markerset components
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mTMarkersetColor ) )
	{
		for( const auto& it : mTMarkersetData )
		{
			mAssetComponents[ it.Key ]->mAssetColor = mTMarkersetColor;
		}
	}
	// The "Labeled Marker Color" property updates ALL components' marker colors, excluding unlabeled
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mLabeledMarkerColor ) )
	{
		for( const auto& it : mAssetComponents )
		{
			it.Value->mMarkerColor = mLabeledMarkerColor;
		}
	}
	// The "Unlabeled Marker Color" property updates the invisible unlabeled marker component
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mUnlabeledMarkerColor ) )
	{
		for( const auto& it : mUnlabeledMarkerComponent )
		{
			it.Value->mMarkerColor = mUnlabeledMarkerColor;
		}
	}
	// The "Skeleton Line Thickness" property updates all skeleton components
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mSkeletonLineThickness ) )
	{
		for( const auto& it : mSkeletonData )
		{
			mAssetComponents[ it.Key ]->mLineThicknessScale = mSkeletonLineThickness;
		}
	}
	// The "Rigid Body Line Thickness" property updates all rigid body components
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mRigidBodyLineThickness ) )
	{
		for( const auto& it : mRigidBodyData )
		{
			mAssetComponents[ it.Key ]->mLineThicknessScale = mRigidBodyLineThickness;
		}
	}
	// The "Trained Markerset Line Thickness" property updates all rigid body components
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mTMarkersetLineThickness ) )
	{
		for( const auto& it : mTMarkersetData )
		{
			mAssetComponents[ it.Key ]->mLineThicknessScale = mTMarkersetLineThickness;
		}
	}
	// The "Labeled Marker Size" property updates ALL components' marker sizes, excluding unlabeled
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mLabeledMarkerSize ) )
	{
		for( const auto& it : mAssetComponents )
		{
			it.Value->mMarkerSize = mLabeledMarkerSize;
		}
	}
	// The "Unlabeled Marker Size" property updates the invisible unlabeled marker component
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mUnlabeledMarkerSize ) )
	{
		for( const auto& it : mUnlabeledMarkerComponent )
		{
			it.Value->mMarkerSize = mUnlabeledMarkerSize;
		}
	}
	// "Display Skeletons" updates all skeleton components, and can also change the "Display Assets" property
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mDrawSkeletons ) )
	{
		for( const auto& it : mSkeletonData )
		{
			mAssetComponents[ it.Key ]->mDisplayAsset = mDrawSkeletons;
		}
		mDrawAssets = ( mDrawSkeletons || mDrawRigidBodies || mDrawTMarkersets );
	}
	// "Display Rigid Bodies" updates all rigid body components, and can also change the "Display Assets" property
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mDrawRigidBodies ) )
	{
		for( const auto& it : mRigidBodyData )
		{
			mAssetComponents[ it.Key ]->mDisplayAsset = mDrawRigidBodies;
		}
		mDrawAssets = ( mDrawSkeletons || mDrawRigidBodies || mDrawTMarkersets);
	}
	// "Display Trained Markersets" updates all trained markerset components, and can also change the "Display Assets" property
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mDrawTMarkersets ) )
	{
		for( const auto& it : mTMarkersetData )
		{
			mAssetComponents[ it.Key ]->mDisplayAsset = mDrawTMarkersets;
		}
		mDrawAssets = ( mDrawSkeletons || mDrawRigidBodies || mDrawTMarkersets );
	}
	// "Display Labeled Markers" updates ALL components' marker visibility, excluding unlabeled
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mDrawLabeledMarkers ) )
	{
		for( const auto& it : mAssetComponents )
		{
			it.Value->mDisplayMarkers = mDrawLabeledMarkers;
		}
	}
	// "Display Unlabeled Markers" updates the invisible unlabeled marker component
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( AOptitrackLiveLinkDisplay, mDrawUnlabeledMarkers ) )
	{
		for( const auto& it : mUnlabeledMarkerComponent )
		{
			it.Value->mDisplayMarkers = mDrawUnlabeledMarkers;
		}
	}
}

// This function is called from the child components when a component property changes
void AOptitrackLiveLinkDisplay::CheckProperties()
{
	// Checking for "visible" properties only
	// Updates the properties with OR condition (e.g. if everything is OFF then the parent is OFF)
	bool setDrawSkeletons = false;
	bool setDrawRigidBodies = false;
	bool setDrawTMarkersets = false;
	for( const auto& it : mSkeletonData )
	{
		if( mAssetComponents[ it.Key ]->mDisplayAsset )
		{
			setDrawSkeletons = true;
			break;
		}
	}
	for( const auto& it : mRigidBodyData )
	{
		if( mAssetComponents[ it.Key ]->mDisplayAsset )
		{
			setDrawRigidBodies = true;
			break;
		}
	}
	for( const auto& it : mTMarkersetData )
	{
		if( mAssetComponents[ it.Key ]->mDisplayAsset )
		{
			setDrawTMarkersets = true;
			break;
		}
	}
	mDrawSkeletons = setDrawSkeletons;
	mDrawRigidBodies = setDrawRigidBodies;
	mDrawTMarkersets = setDrawTMarkersets;
	mDrawAssets = ( mDrawSkeletons || mDrawRigidBodies || mDrawTMarkersets );

	bool setDrawLabeledMarkers = false;
	for( const auto& it : mAssetComponents )
	{
		if( it.Value->mDisplayMarkers )
		{
			setDrawLabeledMarkers = true;
			break;
		}
	}
	mDrawLabeledMarkers = setDrawLabeledMarkers;
}

// Necessary delegate for LiveLinkClient.RegisterForSubjectFrames function call
void AOptitrackLiveLinkDisplay::OnSubjectStaticDataAdded( FLiveLinkSubjectKey InSubjectKey, TSubclassOf<ULiveLinkRole> InSubjectRole, 
	const FLiveLinkStaticDataStruct& InStaticData )
{
}

// Function is called every time a subject's frame is received. Stores the transform data to be drawn on the tick() function
void AOptitrackLiveLinkDisplay::OnSubjectFrameDataAdded( FLiveLinkSubjectKey InSubjectKey, TSubclassOf<ULiveLinkRole> InSubjectRole,
	const FLiveLinkFrameDataStruct& InFrameData )
{
	if( mSkeletonData.Find( InSubjectKey ) )
	{
		if( const FLiveLinkAnimationFrameData* animData = InFrameData.Cast<FLiveLinkAnimationFrameData>() )
		{
			mSkeletonData[ InSubjectKey ] = animData->Transforms;
		}
	}

	if( mTMarkersetData.Find( InSubjectKey ) )
	{
		if( const FLiveLinkAnimationFrameData* animData = InFrameData.Cast<FLiveLinkAnimationFrameData>() )
		{
			mTMarkersetData[ InSubjectKey ] = animData->Transforms;
		}
	}

	if( const FLiveLinkTransformFrameData* trData = InFrameData.Cast<FLiveLinkTransformFrameData>() )
	{
		mRigidBodyData.FindOrAdd( InSubjectKey ) = trData->Transform;
	}

	if( mUnlabeledMarkerData.Find( InSubjectKey ) )
	{
		if( const FLiveLinkAnimationFrameData* animData = InFrameData.Cast<FLiveLinkAnimationFrameData>() )
		{
			mUnlabeledMarkerData[ InSubjectKey ] = animData->Transforms;
		}
	}

	if( mLabeledMarkerData.Find( InSubjectKey ) )
	{
		if( const FLiveLinkAnimationFrameData* animData = InFrameData.Cast<FLiveLinkAnimationFrameData>() )
		{
			mLabeledMarkerData[ InSubjectKey ] = animData->Transforms;
		}
	}
}

// Check if the Live Link connection is up. Should usually return instantly due to mLiveLinkValid being true
bool AOptitrackLiveLinkDisplay::RegisterForLiveLinkClient()
{
	if( mLiveLinkValid )
		return true;

	IModularFeatures& ModularFeatures = IModularFeatures::Get();
	if( !ModularFeatures.IsModularFeatureAvailable( ILiveLinkClient::ModularFeatureName ) )
		return false;

	ILiveLinkClient& LiveLinkClient = ModularFeatures.GetModularFeature<ILiveLinkClient>( ILiveLinkClient::ModularFeatureName );

	mSourcesChangedHandle = LiveLinkClient.OnLiveLinkSourcesChanged().Add(
		FSimpleMulticastDelegate::FDelegate::CreateUObject( this, &AOptitrackLiveLinkDisplay::OnLiveLinkSourcesChanged ) );

	mSubjectsChangedHandle = LiveLinkClient.OnLiveLinkSubjectsChanged().Add(
		FSimpleMulticastDelegate::FDelegate::CreateUObject( this, &AOptitrackLiveLinkDisplay::OnLiveLinkSubjectsChanged ) );
	
	UnregisterForLiveLinkData();

	mLiveLinkValid = true;
	return true;
}

// Close connection to Live Link. This only occurs when object is destroyed
void AOptitrackLiveLinkDisplay::UnregisterForLiveLinkClient()
{
	if( !mLiveLinkValid )
		return;

	IModularFeatures& ModularFeatures = IModularFeatures::Get();
	if( !ModularFeatures.IsModularFeatureAvailable( ILiveLinkClient::ModularFeatureName ) )
		return;

	ILiveLinkClient& LiveLinkClient = ModularFeatures.GetModularFeature<ILiveLinkClient>( ILiveLinkClient::ModularFeatureName );

	if( mSourcesChangedHandle.IsValid() )
		LiveLinkClient.OnLiveLinkSourcesChanged().Remove( mSourcesChangedHandle );
	mSourcesChangedHandle.Reset();

	if( mSubjectsChangedHandle.IsValid() )
		LiveLinkClient.OnLiveLinkSubjectsChanged().Remove( mSubjectsChangedHandle );
	mSubjectsChangedHandle.Reset();

	mLiveLinkValid = false;
}

// Function is only called from Tick() when LiveLinkSubjectCount == 0. Sets up subject lists
bool AOptitrackLiveLinkDisplay::RegisterForLiveLinkData()
{
	mStaticDataAddedHandles.Reset();
	mFrameDataAddedHandles.Reset();
	mSkelBoneParents.Reset();
	mSkeletonData.Reset();
	mTMarkersetBoneParents.Reset();
	mTMarkersetData.Reset();
	mRigidBodyData.Reset();
	mLabeledMarkerData.Reset();
	mUnlabeledMarkerData.Reset();

	IModularFeatures& ModularFeatures = IModularFeatures::Get();
	if( ModularFeatures.IsModularFeatureAvailable( ILiveLinkClient::ModularFeatureName ) )
	{
		ILiveLinkClient& LiveLinkClient = ModularFeatures.GetModularFeature<ILiveLinkClient>( ILiveLinkClient::ModularFeatureName );

		TArray<FLiveLinkSubjectKey> subjectKeys = LiveLinkClient.GetSubjects( false, true );
		for( const FLiveLinkSubjectKey& key : subjectKeys )
		{
			FDelegateHandle staticDataAdded, frameDataAdded;
			TSubclassOf<ULiveLinkRole> role;
			FLiveLinkStaticDataStruct staticData;

			if( LiveLinkClient.RegisterForSubjectFrames( key.SubjectName,
				FOnLiveLinkSubjectStaticDataAdded::FDelegate::CreateUObject( this, &AOptitrackLiveLinkDisplay::OnSubjectStaticDataAdded ),
				FOnLiveLinkSubjectFrameDataAdded::FDelegate::CreateUObject( this, &AOptitrackLiveLinkDisplay::OnSubjectFrameDataAdded ),
				staticDataAdded, frameDataAdded, role, &staticData ) )
			{
				mStaticDataAddedHandles.FindOrAdd( key ) = staticDataAdded;
				mFrameDataAddedHandles.FindOrAdd( key ) = frameDataAdded;

				if( FLiveLinkSkeletonStaticData* skeletonData = staticData.Cast<FLiveLinkSkeletonStaticData>() )
				{
					if( key.SubjectName.ToString().Compare( "Markers_Unlabeled", ESearchCase::IgnoreCase ) == 0 )
					{
						// Unlabeled markers
						mUnlabeledMarkerData.FindOrAdd( key );

						if( !mUnlabeledMarkerComponent.Contains( key ) )
						{
							FName assetName = key.SubjectName;
							mUnlabeledMarkerComponent.Add( key, NewObject<UOptitrackLiveLinkComponent>() );
							mUnlabeledMarkerComponent[ key ]->mMarkerSubjectKey = key;
							mUnlabeledMarkerComponent[ key ]->mMarkerColor = mUnlabeledMarkerColor;
							mUnlabeledMarkerComponent[ key ]->mMarkerSize = mUnlabeledMarkerSize;
						}
					}
					else if( key.SubjectName.ToString().StartsWith( "Markers_" ) )
					{
						// Labeled markers
						mLabeledMarkerData.FindOrAdd( key );

						// Attach labeled markers subjects to their components
						FString name = key.SubjectName.ToString();
						name.RemoveFromStart( "Markers_" );
						mMarkerDict.FindOrAdd( name ) = key;
						if( mNameDict.Contains( name ) )
						{
							if( mAssetComponents.Contains( mNameDict[ name ] ) )
							{
								mAssetComponents[ mNameDict[ name ] ]->mMarkerSubjectKey = key;
							}
						}
					}
					else if( key.SubjectName.ToString().StartsWith( "TMarkerset_" ) )
					{
						// Trained markersets
						mTMarkersetData.FindOrAdd( key );
						mTMarkersetBoneParents.FindOrAdd( key ) = skeletonData->BoneParents;
					}
					else
					{
						// Skeletons
						mSkeletonData.FindOrAdd( key );
						mSkelBoneParents.FindOrAdd( key ) = skeletonData->BoneParents;
					}
				}
				else if( FLiveLinkTransformStaticData* transformData = staticData.Cast<FLiveLinkTransformStaticData>() )
				{
					// Rigid bodies
					mRigidBodyData.FindOrAdd( key );
				}
			}
		}

		// Generate components for anything not-yet-created
		for( const FLiveLinkSubjectKey& key : subjectKeys )
		{
			if( !key.SubjectName.ToString().StartsWith( "Markers_" ) )
			{
				if( !mAssetComponents.Contains( key ) ) {
					// Identify all assets to turn into components
					this->AddComponentRealtime( key );
					mNameDict.FindOrAdd( key.SubjectName.ToString() ) = key;
					if( mMarkerDict.Contains( key.SubjectName.ToString() ) )
					{
						mAssetComponents[ key ]->mMarkerSubjectKey = mMarkerDict[ key.SubjectName.ToString() ];
					}
				}
			}
		}
	}

	mSubjectListChanged = false;
	return !mFrameDataAddedHandles.IsEmpty();
}

// Wipes connection to Live Link data stream. This is only called on object destruction OR when setting up initial Live Link connection
void AOptitrackLiveLinkDisplay::UnregisterForLiveLinkData()
{
	IModularFeatures& ModularFeatures = IModularFeatures::Get();
	if( ModularFeatures.IsModularFeatureAvailable( ILiveLinkClient::ModularFeatureName ) )
	{
		ILiveLinkClient& LiveLinkClient = ModularFeatures.GetModularFeature<ILiveLinkClient>( ILiveLinkClient::ModularFeatureName );

		TArray<FLiveLinkSubjectKey> subjectKeys = LiveLinkClient.GetSubjects( false, true );
		for( const FLiveLinkSubjectKey& key : subjectKeys )
		{
			if( mStaticDataAddedHandles.Find( key ) && mFrameDataAddedHandles.Find( key ) )
			{
				LiveLinkClient.UnregisterSubjectFramesHandle( key.SubjectName, mStaticDataAddedHandles[key], mFrameDataAddedHandles[key] );
			}
		}
	}

	mStaticDataAddedHandles.Reset();
	mFrameDataAddedHandles.Reset();
	mSkelBoneParents.Reset();
	mSkeletonData.Reset();
	mTMarkersetBoneParents.Reset();
	mTMarkersetData.Reset();
	mRigidBodyData.Reset();
	mLabeledMarkerData.Reset();
	mUnlabeledMarkerData.Reset();
}

// Returns number of Live Link subjects
int AOptitrackLiveLinkDisplay::LiveLinkSubjectCount() const
{
	return mFrameDataAddedHandles.Num();
}

// Called from Tick(), this function call causes all subjects to be drawn into the world.
void AOptitrackLiveLinkDisplay::Draw()
{
	UWorld* world = GetWorld();

	DrawSkeletons( world, mSkeletonData, mSkelBoneParents, mAssetComponents );
	DrawSkeletons( world, mTMarkersetData, mTMarkersetBoneParents, mAssetComponents );
	DrawRigidBodies( world, mRigidBodyData, mAssetComponents );
	DrawMarkers( world, mLabeledMarkerData, mAssetComponents );
	DrawMarkers( world, mUnlabeledMarkerData, mUnlabeledMarkerComponent );
}

// Draws assets based on a transform array and a parentBones array
void AOptitrackLiveLinkDisplay::DrawSkeletons( UWorld* world, 
	const TMap<FLiveLinkSubjectKey, TArray<FTransform>>& skeletons, 
	const TMap<FLiveLinkSubjectKey, TArray<int32>>& parentBones, 
	const TMap<FLiveLinkSubjectKey, TObjectPtr<UOptitrackLiveLinkComponent>>& components ) const
{
	for( const auto& it : skeletons )
	{
		TArray<FTransform> transforms = it.Value;

		UOptitrackLiveLinkComponent* comp = components[ it.Key ];
		if( !comp->mDisplayAsset ) continue;
		FTransform compTr = comp->GetComponentTransform();
		if( !comp->IsAttachedTo( RootComponent ) )
		{
			compTr *= RootComponent->GetComponentTransform();
		}

		if( parentBones.Contains( it.Key ) )
		{
			const TArray<int32>& boneParents = parentBones[it.Key];
			for( int32 i = 0; i < boneParents.Num(); i++ )
			{
				int32 parentIndex = boneParents[i];
				if( i < transforms.Num() && parentIndex >= 0 && parentIndex < transforms.Num() )
				{
					transforms[i] *= transforms[parentIndex];
				}
			}

			// Draw bone segments
			for( int32 i = 0; i < boneParents.Num(); i++ )
			{
				int32 parentIndex = boneParents[i];
				if( i < transforms.Num() && parentIndex >= 0 && parentIndex < transforms.Num() )
				{
					DrawDebugLine( world, ( transforms[ i ] * compTr ).GetLocation(), 
						( transforms[ parentIndex ] * compTr ).GetLocation(), comp->mAssetColor, false, -1, SDPG_MAX, comp->mLineThicknessScale );
				}
			}
		}

		// Draw coordinate vertices between bone segments
		for( FTransform& tr : transforms )
		{
			tr *= compTr;
			DrawDebugSphere( world, tr.GetLocation(), 2, 6, comp->mAssetColor, false, -1, SDPG_MAX, 0.2 * comp->mLineThicknessScale);
			DrawDebugCoordinateSystem( world, tr.GetLocation(), tr.Rotator(), 5, false, -1, SDPG_MAX, 0.4f);
		}
	}
}

// Draws assets based on transforms
void AOptitrackLiveLinkDisplay::DrawRigidBodies( UWorld* world, 
	const TMap<FLiveLinkSubjectKey, FTransform>& rigidBodies, 
	const TMap<FLiveLinkSubjectKey, TObjectPtr<UOptitrackLiveLinkComponent>>& components ) const
{
	for( const auto& it : rigidBodies )
	{
		if( !components.Contains( it.Key ) ) continue;
		UOptitrackLiveLinkComponent* comp = components[ it.Key ];
		const FTransform& compTr = comp->GetComponentTransform();

		if( !comp->mDisplayAsset ) continue;

		FTransform tr = it.Value * compTr;
		if( !comp->IsAttachedTo( RootComponent ) )
		{
			tr *= RootComponent->GetComponentTransform();
		}
		DrawDebugSphere( world, tr.GetLocation(), 2, 6, comp->mAssetColor, false, -1, SDPG_MAX, 0.2 * comp->mLineThicknessScale);
		DrawDebugCoordinateSystem( world, tr.GetLocation(), tr.Rotator(), 5, false, -1, SDPG_MAX, 0.4f);
	}
}

// Draws markers based on a transform array
void AOptitrackLiveLinkDisplay::DrawMarkers( UWorld* world, 
	const TMap<FLiveLinkSubjectKey, TArray<FTransform>>& markers, 
	const TMap<FLiveLinkSubjectKey, TObjectPtr<UOptitrackLiveLinkComponent>>& components ) const
{
	for( const auto& it : components )
	{
		if( !it.Value->mDisplayMarkers ) continue;
		if( !markers.Contains( it.Value->mMarkerSubjectKey ) ) continue;

		TArray<FTransform> markerset = markers[ it.Value->mMarkerSubjectKey ];
		const FTransform& compTr = it.Value->GetComponentTransform();
		for( const FTransform& tr : markerset )
		{
			if( tr.GetLocation() != FVector::ZeroVector )
			{
				float size = it.Value->mMarkerSize;
				FColor color = it.Value->mMarkerColor;
				FTransform sumTr = tr * compTr;
				if( !it.Value->IsAttachedTo( RootComponent ) )
				{
					sumTr *= RootComponent->GetComponentTransform();
				}
				DrawDebugBox( world, sumTr.GetLocation(), FVector(size, size, size), color, false, -1, SDPG_MAX);
			}
		}
	}
}
