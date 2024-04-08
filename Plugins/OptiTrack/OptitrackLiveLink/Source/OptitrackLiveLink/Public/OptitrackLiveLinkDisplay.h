//======================================================================================================
// Copyright 2021, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LiveLinkTypes.h"
#include "ILiveLinkClient.h"
#include "OptitrackLiveLinkComponent.h"
#include "OptitrackLiveLinkDisplay.generated.h"

struct FLiveLinkSubjectKey;
class ULiveLinkRole;

// All non-relevant categories are hidden in the editor to prevent the user from thinking they would work
UCLASS( hidecategories = ( Rendering, Replication, Collision, HLOD, Physics, Networking, WorldPartition, Input, Actor, Cooking, DataLayers, LevelInstance ) )
class OPTITRACKLIVELINK_API AOptitrackLiveLinkDisplay : public AActor
{
	GENERATED_BODY()

public:	
	AOptitrackLiveLinkDisplay();
	virtual ~AOptitrackLiveLinkDisplay();

	bool ShouldTickIfViewportsOnly() const override;
	virtual void Tick( float DeltaTime ) override;

	void OnLiveLinkSubjectsChanged();
	void OnLiveLinkSourcesChanged();
	void OnSubjectStaticDataAdded( FLiveLinkSubjectKey InSubjectKey, TSubclassOf<ULiveLinkRole> SubjectRole, const FLiveLinkStaticDataStruct& InStaticData );
	void OnSubjectFrameDataAdded( FLiveLinkSubjectKey InSubjectKey, TSubclassOf<ULiveLinkRole> SubjectRole, const FLiveLinkFrameDataStruct& InFrameData );
	void PostEditChangeProperty( FPropertyChangedEvent& PropertyChangedEvent );
	void CheckProperties();

protected:
	void AddComponent( const FLiveLinkSubjectKey& key );
	void AddComponentRealtime( const FLiveLinkSubjectKey& key );
	bool RegisterForLiveLinkClient();
	void UnregisterForLiveLinkClient();
	bool RegisterForLiveLinkData();
	void UnregisterForLiveLinkData();

	int LiveLinkSubjectCount() const;

	void Draw();
	void DrawSkeletons( UWorld* world, const TMap<FLiveLinkSubjectKey, TArray<FTransform>>& skeletons, 
		const TMap<FLiveLinkSubjectKey, TArray<int32>>& parentBones, 
		const TMap<FLiveLinkSubjectKey, TObjectPtr<UOptitrackLiveLinkComponent>>& components ) const;
	void DrawRigidBodies( UWorld* world, const TMap<FLiveLinkSubjectKey, FTransform>& rigidBodies, 
		const TMap<FLiveLinkSubjectKey, TObjectPtr<UOptitrackLiveLinkComponent>>& components ) const;
	void DrawMarkers( UWorld* world, const TMap<FLiveLinkSubjectKey, TArray<FTransform>>& markers, 
		const TMap<FLiveLinkSubjectKey, TObjectPtr<UOptitrackLiveLinkComponent>>& components ) const;

public:
	/** Root Component to allow easy transform */
	UPROPERTY()
	TObjectPtr<USceneComponent> Root;

	/** Line thickness */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Assets", DisplayName = "Line Thickness" )
	float mLineThicknessScale;

	/** Display all assets */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Assets", DisplayName = "Display Assets" )
	bool mDrawAssets = true;

	/** All Assets Color */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Assets", DisplayName = "Asset Color" )
	FColor mAssetColor;

	/** Skeleton Line Thickness */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Skeletons", DisplayName = "Skeleton Line Thickness" )
	float mSkeletonLineThickness;

	/** Display streamed skeleton data visuals */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Skeletons", DisplayName = "Display Skeleton Data" )
	bool mDrawSkeletons = true;

	/** Skeleton color */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Skeletons", DisplayName = "Skeleton Color" )
	FColor mSkeletonColor;

	/** Rigid body Line Thickness */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Rigid Bodies", DisplayName = "Rigid Body Line Thickness" )
	float mRigidBodyLineThickness;

	/** Display streamed rigid body data visuals */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Rigid Bodies", DisplayName = "Display Rigid Body Data" )
	bool mDrawRigidBodies = true;

	/** Rigid body color */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Rigid Bodies", DisplayName = "Rigid Body Color" )
	FColor mRigidBodyColor;

	/** Trained Markerset Line Thickness */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Trained Markersets", DisplayName = "Trained Markerset Line Thickness" )
	float mTMarkersetLineThickness;

	/** Display streamed trained markerset visuals */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Trained Markersets", DisplayName = "Display Trained Markersets" )
	bool mDrawTMarkersets = true;

	/** Trained Markerset color */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Trained Markersets", DisplayName = "Trained Markerset Color" )
	FColor mTMarkersetColor;

	/** Marker Size */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Labeled Markers", DisplayName = "Labeled Marker Size" )
	float mLabeledMarkerSize;

	/** Display Markers */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Labeled Markers", DisplayName = "Display Labeled Marker Data" )
	bool mDrawLabeledMarkers = true;

	/** Marker color */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Labeled Markers", DisplayName = "Labeled Marker Color" )
	FColor mLabeledMarkerColor;

	/** Marker Size */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Unlabeled Markers", DisplayName = "Unlabeled Marker Size" )
		float mUnlabeledMarkerSize;

	/** Display Markers */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Unlabeled Markers", DisplayName = "Display Unlabeled Marker Data" )
		bool mDrawUnlabeledMarkers = true;

	/** Marker color */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Unlabeled Markers", DisplayName = "Unlabeled Marker Color" )
		FColor mUnlabeledMarkerColor;

protected:

	/** Asset Components */
	TMap<FLiveLinkSubjectKey, TObjectPtr<UOptitrackLiveLinkComponent>> mAssetComponents;

	/** Unlabeled Markers Component */
	TMap<FLiveLinkSubjectKey, TObjectPtr<UOptitrackLiveLinkComponent>> mUnlabeledMarkerComponent;

	/** Variables used to track connection to Live Link */
	bool mLiveLinkValid = false;
	bool mSubjectListChanged = false;

	/** Delegate Handles used in the data stream from Live Link */
	TMap<FLiveLinkSubjectKey, FDelegateHandle> mStaticDataAddedHandles;
	TMap<FLiveLinkSubjectKey, FDelegateHandle> mFrameDataAddedHandles;
	FDelegateHandle mSourcesChangedHandle;
	FDelegateHandle mSubjectsChangedHandle;

	/** Maps used to keep track of subject keys and transform data */
	TMap<FLiveLinkSubjectKey, TArray<int32>> mSkelBoneParents;
	TMap<FLiveLinkSubjectKey, TArray<FTransform>> mSkeletonData;
	TMap<FLiveLinkSubjectKey, TArray<int32>> mTMarkersetBoneParents;
	TMap<FLiveLinkSubjectKey, TArray<FTransform>> mTMarkersetData;
	TMap<FLiveLinkSubjectKey, FTransform> mRigidBodyData;
	TMap<FLiveLinkSubjectKey, TArray<FTransform>> mLabeledMarkerData;
	TMap<FLiveLinkSubjectKey, TArray<FTransform>> mUnlabeledMarkerData;

	/** Constants to be used for property defaults */
	const float kLineThicknessDefault = 1.0f;
	const FColor kAssetColorDefault = FColor( 0, 255, 0 );
	const FColor kLabeledMarkerColorDefault = FColor( 255, 255, 255 );
	const FColor kUnlabeledMarkerColorDefault = FColor( 255, 0, 0 );
	const float kMarkerSizeDefault = 1.0f;

	/** Utility map used to keep track of asset names */
	TMap<FString, FLiveLinkSubjectKey> mNameDict;
	TMap<FString, FLiveLinkSubjectKey> mMarkerDict;
};

