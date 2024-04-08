#include "AnimGraphNode_OptitrackSkeleton_DetailCustomization.h"
#include "AnimGraphNode_OptitrackSkeleton.h"

#include <DetailCategoryBuilder.h>
#include <DetailLayoutBuilder.h>
#include <DetailWidgetRow.h>
#include <IDetailChildrenBuilder.h>
#include <IDetailPropertyRow.h>
#include <ScopedTransaction.h>
#include <PropertyCustomizationHelpers.h>

#include <Widgets/Layout/SBox.h>
#include <Widgets/Input/SButton.h>
#include <Widgets/Text/STextBlock.h>

#include "Internationalization/Regex.h"

#define LOCTEXT_NAMESPACE "OptitrackNatnet"


TSharedRef< IDetailCustomization > FAnimGraphNode_OptitrackSkeleton_DetailCustomization::MakeInstance()
{
	return MakeShareable( new FAnimGraphNode_OptitrackSkeleton_DetailCustomization );
}


void FAnimGraphNode_OptitrackSkeleton_DetailCustomization::CustomizeDetails( IDetailLayoutBuilder& DetailBuilder )
{
	GraphNode = nullptr;

	TArray< TWeakObjectPtr<UObject> > SelectedObjects;
	DetailBuilder.GetObjectsBeingCustomized( SelectedObjects );

	if ( SelectedObjects.Num() == 1 )
	{
		GraphNode = Cast<UAnimGraphNode_OptitrackSkeleton>( SelectedObjects[0].Get() );
	}

	if ( GraphNode == nullptr )
	{
		return;
	}
    
	IDetailCategoryBuilder& RetargetingCategory = DetailBuilder.EditCategory( "Retargeting", LOCTEXT("RetargetingCategoryDisplayName", "Retargeting") );

	TSharedRef< IPropertyHandle > BoneMappingsProp = DetailBuilder.GetProperty( "Node.BoneSockets" );
	TSharedPtr< IPropertyHandleArray > BoneMappingsArray = BoneMappingsProp->AsArray();

#if 0
	uint32 NumBoneMappings = 0;
	if ( BoneMappingsArray.IsValid() && (BoneMappingsArray->GetNumElements( NumBoneMappings ) == FPropertyAccess::Success )
	{
		for ( uint32 BoneMappingIdx = 0; BoneMappingIdx < NumBoneMappings; ++BoneMappingIdx )
		{
			TSharedRef< IPropertyHandle > MappingProp = BoneMappingsArray->GetElement( BoneMappingIdx );
			MappingProp->
		}
	}
#else
	const bool bGenerateHeader = true;
	const bool bDisplayResetToDefault = false;
	const bool bDisplayElementNum = false;
	const bool bForAdvanced = false;

    FDetailWidgetRow& AutoFillBoneMappingRow = RetargetingCategory.AddCustomRow(LOCTEXT("AutoFillBoneMapping", "Auto fill bone mapping array. Verify bone mapping is correct."))
        .WholeRowContent()
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot()
        .FillWidth(1.0f)
        .Padding(0.0f, 5.0f)
        .VAlign(VAlign_Center)
        .HAlign(HAlign_Center)
        [
            SNew(SButton)
            .IsEnabled(this, &FAnimGraphNode_OptitrackSkeleton_DetailCustomization::IsEnabled_AutoFillBoneMapping)
        .Text(this, &FAnimGraphNode_OptitrackSkeleton_DetailCustomization::GetText_AutoFillBoneMapping)
        .ToolTipText(LOCTEXT("AutoFillBoneMappingsTooltip", "Auto fill bone mapping array with best guess of mappings. Verify mapping is correct."))
        .OnClicked(this, &FAnimGraphNode_OptitrackSkeleton_DetailCustomization::OnClicked_AutoFillBoneMapping)
        ]
        ];

	TSharedRef<FDetailArrayBuilder> BoneMappingsBuilder = MakeShareable( new FDetailArrayBuilder( BoneMappingsProp, bGenerateHeader, bDisplayResetToDefault, bDisplayElementNum ) );
	BoneMappingsBuilder->OnGenerateArrayElementWidget( FOnGenerateArrayElementWidget::CreateSP( this, &FAnimGraphNode_OptitrackSkeleton_DetailCustomization::OnGenerateElementForBoneMapping ) );
	BoneMappingsBuilder->SetDisplayName( LOCTEXT( "BoneMappingsCategory", "Bone Mappings" ) );
	RetargetingCategory.AddCustomBuilder( BoneMappingsBuilder, bForAdvanced );
#endif

#if 0
	FDetailWidgetRow& UpdateRetargetBasePoseRow = RetargetingCategory.AddCustomRow( LOCTEXT("UpdateRetargetBasePoseSearchText", "Update Retarget Base Pose") )
	.WholeRowContent()
	[
		SNew(SHorizontalBox)
		+SHorizontalBox::Slot()
		.FillWidth( 1.0f )
		.Padding( 0.0f, 5.0f )
		.VAlign( VAlign_Center )
		.HAlign( HAlign_Center )
		[
			SNew(SButton)
			.IsEnabled( this, &FAnimGraphNode_OptitrackSkeleton_DetailCustomization::IsEnabled_UpdateRetargetBasePose )
			.Text( this, &FAnimGraphNode_OptitrackSkeleton_DetailCustomization::GetText_UpdateRetargetBasePose )
			.ToolTipText( LOCTEXT("UpdateRetargetBasePose_Tooltip", "Updates this node's copy of the editor-only retarget base pose.") )
			.OnClicked( this, &FAnimGraphNode_OptitrackSkeleton_DetailCustomization::OnClicked_UpdateRetargetBasePose )
		]
	];
#endif
}


void FAnimGraphNode_OptitrackSkeleton_DetailCustomization::OnGenerateElementForBoneMapping( TSharedRef<IPropertyHandle> ElementProperty, int32 ElementIndex, IDetailChildrenBuilder& ChildrenBuilder )
{
	IDetailPropertyRow& BoneMappingRow = ChildrenBuilder.AddProperty( ElementProperty );
	BoneMappingRow.DisplayName( GetDisplayBoneName( static_cast<EOptitrackBone>(ElementIndex) ) );

}


bool FAnimGraphNode_OptitrackSkeleton_DetailCustomization::IsEnabled_UpdateRetargetBasePose() const
{
	return GraphNode->Node.RetargetBaseMesh != nullptr;
}


FText FAnimGraphNode_OptitrackSkeleton_DetailCustomization::GetText_UpdateRetargetBasePose() const
{
	if ( GraphNode->Node.HasRetargetBasePose() )
	{
		return LOCTEXT( "UpdateRetargetBasePose", "Update Retarget Base Pose" );
	}
	else
	{
		return LOCTEXT( "InitialSetRetargetBasePose", "Set Retarget Base Pose" );
	}
}

FReply FAnimGraphNode_OptitrackSkeleton_DetailCustomization::OnClicked_UpdateRetargetBasePose()
{
	FScopedTransaction Transaction( LOCTEXT( "UpdateRetargetBasePoseTransaction", "Update Retarget Base Pose" ) );

	if ( GraphNode->Node.UpdateRetargetBasePose() )
	{
		GraphNode->Modify();
	}
	else
	{
		Transaction.Cancel();
	}

	return FReply::Handled();
}

FText FAnimGraphNode_OptitrackSkeleton_DetailCustomization::GetText_AutoFillBoneMapping() const
{
    return LOCTEXT("AutoFillBoneMapping", "Auto Fill Bone Mapping");
}

FReply FAnimGraphNode_OptitrackSkeleton_DetailCustomization::OnClicked_AutoFillBoneMapping() const
{
    USkeleton* Skeleton = GraphNode->GetAnimBlueprint()->TargetSkeleton;
    const FReferenceSkeleton RefSkeleton = Skeleton->GetReferenceSkeleton();
    TArray<FMeshBoneInfo> RefMeshBones = RefSkeleton.GetRefBoneInfo();
    
    for (uint8 BoneId = 0; BoneId < static_cast<uint8>(EOptitrackBone::NumBones); ++BoneId)
    {
        TArray<FName> CandidateNames;
        TArray<FRegexPattern> CandidatePatterns;
        EOptitrackBone Bone = static_cast<EOptitrackBone>(BoneId);

        TArray<FRegexPattern> RollBoneCandidates;
        RollBoneCandidates.Push(FRegexPattern(TEXT(".*roll.*")));
        RollBoneCandidates.Push(FRegexPattern(TEXT(".*twist.*")));
        RollBoneCandidates.Push(FRegexPattern(TEXT(".*eye.*")));
        RollBoneCandidates.Push(FRegexPattern(TEXT(".*dummy.*")));
        RollBoneCandidates.Push(FRegexPattern(TEXT(".*flap.*")));

        switch (Bone)
        {
        case EOptitrackBone::Root:
            CandidatePatterns.Push(FRegexPattern(TEXT(".*root.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT(".*reference.*")));
            break;
        case EOptitrackBone::Hip:
            CandidatePatterns.Push(FRegexPattern(TEXT(".*pelvis.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT(".*hip.*")));
            break;
        case EOptitrackBone::Ab:
            CandidatePatterns.Push(FRegexPattern(TEXT(".*ab.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT(".*spine.*")));
            break;
        case EOptitrackBone::Chest:
            CandidatePatterns.Push(FRegexPattern(TEXT(".*chest.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT(".*spine.*")));
            break;
        case EOptitrackBone::Neck:
            CandidatePatterns.Push(FRegexPattern(TEXT(".*neck.*")));
            break;
        case EOptitrackBone::Head:
            CandidatePatterns.Push(FRegexPattern(TEXT(".*head.*")));
            break;
        case EOptitrackBone::LShoulder:
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*clavicle.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT(".*clavicle.*l")));
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*shoulder.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT(".*shoulder.*l")));
            break;
        case EOptitrackBone::RShoulder:
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*clavicle.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT(".*clavicle.*r")));
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*shoulder.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT(".*shoulder.*r")));
            break;
        case EOptitrackBone::LUArm:
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*u.*arm.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("u.*arm.*l")));
            CandidatePatterns.Push(FRegexPattern(TEXT("left.*arm")));
            break;
        case EOptitrackBone::RUArm:
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*u.*arm.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("u.*arm.*r")));
            CandidatePatterns.Push(FRegexPattern(TEXT("right.*arm")));
            break;
        case EOptitrackBone::LFArm:
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*fore.*arm.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("fore.*arm.*l")));
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*low.*arm.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("low.*arm.*l")));
        case EOptitrackBone::RFArm:
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*fore.*arm.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("fore.*arm.*r")));
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*low.*arm.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("low.*arm.*r")));
            break;
        case EOptitrackBone::LHand:
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*hand.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("hand.*l")));
            break;
        case EOptitrackBone::RHand:
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*hand.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("hand.*r")));
            break;
        case EOptitrackBone::LThigh:
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*thigh.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("thigh.*l")));
            CandidatePatterns.Push(FRegexPattern(TEXT("up.*leg.*l")));
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*up.*leg")));
            break;
        case EOptitrackBone::RThigh:
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*thigh.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("thigh.*r")));
            CandidatePatterns.Push(FRegexPattern(TEXT("up.*leg.*r")));
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*up.*leg")));
            break;
        case EOptitrackBone::LShin:
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*shin.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("shin.*l")));
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*calf.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("calf.*l")));
            CandidatePatterns.Push(FRegexPattern(TEXT("low.*leg.*l")));
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*low.*leg")));
            CandidatePatterns.Push(FRegexPattern(TEXT("leftleg")));
            break;
        case EOptitrackBone::RShin:
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*shin.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("shin.*r")));
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*calf.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("calf.*r")));
            CandidatePatterns.Push(FRegexPattern(TEXT("low.*leg.*r")));
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*low.*leg")));
            CandidatePatterns.Push(FRegexPattern(TEXT("rightleg")));
            break;
        case EOptitrackBone::LFoot:
            CandidatePatterns.Push(FRegexPattern(TEXT("l.*foot.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("foot.*l")));
            break;
        case EOptitrackBone::RFoot:
            CandidatePatterns.Push(FRegexPattern(TEXT("r.*foot.*")));
            CandidatePatterns.Push(FRegexPattern(TEXT("foot.*r")));
            break;
        case EOptitrackBone::LToe:
            //CandidatePatterns.Push(FRegexPattern(TEXT("l.*toe.*")));
            //CandidatePatterns.Push(FRegexPattern(TEXT("toe.*l")));
            //CandidatePatterns.Push(FRegexPattern(TEXT("l.*ball.*")));
            //CandidatePatterns.Push(FRegexPattern(TEXT("ball.*l")));
            break;
        case EOptitrackBone::RToe:
            //CandidatePatterns.Push(FRegexPattern(TEXT("r.*toe.*")));
            //CandidatePatterns.Push(FRegexPattern(TEXT("toe.*r")));
            //CandidatePatterns.Push(FRegexPattern(TEXT("r.*ball.*")));
            //CandidatePatterns.Push(FRegexPattern(TEXT("ball.*r")));
            break;
		case EOptitrackBone::LThumb1:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*thumb.*1")));
			CandidatePatterns.Push(FRegexPattern(TEXT("thumb.*1.*l")));
			break;
		case EOptitrackBone::LThumb2:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*thumb.*2")));
			CandidatePatterns.Push(FRegexPattern(TEXT("thumb.*2.*l")));
			break;
		case EOptitrackBone::LThumb3:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*thumb.*3")));
			CandidatePatterns.Push(FRegexPattern(TEXT("thumb.*3.*l")));
			break;
		case EOptitrackBone::LIndex1:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*index.*1")));
			CandidatePatterns.Push(FRegexPattern(TEXT("index.*1.*l")));
			break;
		case EOptitrackBone::LIndex2:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*index.*2")));
			CandidatePatterns.Push(FRegexPattern(TEXT("index.*2.*l")));
			break;
		case EOptitrackBone::LIndex3:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*index.*3")));
			CandidatePatterns.Push(FRegexPattern(TEXT("index.*3.*l")));
			break;
		case EOptitrackBone::LMiddle1:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*middle.*1")));
			CandidatePatterns.Push(FRegexPattern(TEXT("middle.*1.*l")));
			break;
		case EOptitrackBone::LMiddle2:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*middle.*2")));
			CandidatePatterns.Push(FRegexPattern(TEXT("middle.*2.*l")));
			break;
		case EOptitrackBone::LMiddle3:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*middle.*3")));
			CandidatePatterns.Push(FRegexPattern(TEXT("middle.*3.*l")));
			break;
		case EOptitrackBone::LRing1:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*ring.*1")));
			CandidatePatterns.Push(FRegexPattern(TEXT("ring.*1.*l")));
			break;
		case EOptitrackBone::LRing2:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*ring.*2")));
			CandidatePatterns.Push(FRegexPattern(TEXT("ring.*2.*l")));
			break;
		case EOptitrackBone::LRing3:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*ring.*3")));
			CandidatePatterns.Push(FRegexPattern(TEXT("ring.*3.*l")));
			break;
		case EOptitrackBone::LPinky1:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*pinky.*1")));
			CandidatePatterns.Push(FRegexPattern(TEXT("pinky.*1.*l")));
			break;
		case EOptitrackBone::LPinky2:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*pinky.*2")));
			CandidatePatterns.Push(FRegexPattern(TEXT("pinky.*2.*l")));
			break;
		case EOptitrackBone::LPinky3:
			CandidatePatterns.Push(FRegexPattern(TEXT("l.*pinky.*3")));
			CandidatePatterns.Push(FRegexPattern(TEXT("pinky.*3.*l")));
			break;
		case EOptitrackBone::RThumb1:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*thumb.*1")));
			CandidatePatterns.Push(FRegexPattern(TEXT("thumb.*1.*r")));
			break;
		case EOptitrackBone::RThumb2:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*thumb.*2")));
			CandidatePatterns.Push(FRegexPattern(TEXT("thumb.*2.*r")));
			break;
		case EOptitrackBone::RThumb3:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*thumb.*3")));
			CandidatePatterns.Push(FRegexPattern(TEXT("thumb.*3.*r")));
			break;
		case EOptitrackBone::RIndex1:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*index.*1")));
			CandidatePatterns.Push(FRegexPattern(TEXT("index.*1.*r")));
			break;
		case EOptitrackBone::RIndex2:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*index.*2")));
			CandidatePatterns.Push(FRegexPattern(TEXT("index.*2.*r")));
			break;
		case EOptitrackBone::RIndex3:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*index.*3")));
			CandidatePatterns.Push(FRegexPattern(TEXT("index.*3.*r")));
			break;
		case EOptitrackBone::RMiddle1:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*middle.*1")));
			CandidatePatterns.Push(FRegexPattern(TEXT("middle.*1.*r")));
			break;
		case EOptitrackBone::RMiddle2:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*middle.*2")));
			CandidatePatterns.Push(FRegexPattern(TEXT("middle.*2.*r")));
			break;
		case EOptitrackBone::RMiddle3:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*middle.*3")));
			CandidatePatterns.Push(FRegexPattern(TEXT("middle.*3.*r")));
			break;
		case EOptitrackBone::RRing1:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*ring.*1")));
			CandidatePatterns.Push(FRegexPattern(TEXT("ring.*1.*r")));
			break;
		case EOptitrackBone::RRing2:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*ring.*2")));
			CandidatePatterns.Push(FRegexPattern(TEXT("ring.*2.*r")));
			break;
		case EOptitrackBone::RRing3:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*ring.*3")));
			CandidatePatterns.Push(FRegexPattern(TEXT("ring.*3.*r")));
			break;
		case EOptitrackBone::RPinky1:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*pinky.*1")));
			CandidatePatterns.Push(FRegexPattern(TEXT("pinky.*1.*r")));
			break;
		case EOptitrackBone::RPinky2:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*pinky.*2")));
			CandidatePatterns.Push(FRegexPattern(TEXT("pinky.*2.*r")));
			break;
		case EOptitrackBone::RPinky3:
			CandidatePatterns.Push(FRegexPattern(TEXT("r.*pinky.*3")));
			CandidatePatterns.Push(FRegexPattern(TEXT("pinky.*3.*r")));
			break;
        }

        for (FRegexPattern& Pattern : CandidatePatterns)
        {
            for (FMeshBoneInfo& MeshBoneInfo : RefMeshBones)
            {
                FName BoneName = MeshBoneInfo.Name;
                FRegexMatcher Matcher(Pattern, BoneName.ToString().ToLower());
                if (Matcher.FindNext())
                {
                    // ensure bone is not a roll bone 
                    bool FoundRoll = false;
                    for (FRegexPattern& RollPattern : RollBoneCandidates)
                    {
                        FRegexMatcher RollMatcher(RollPattern, BoneName.ToString().ToLower());
                        if (RollMatcher.FindNext())
                        {
                            FoundRoll = true;
                            break;
                        }
                    }
                    if (!FoundRoll)
                    {
                        CandidateNames.Push(BoneName);
                    }
                }
            }
        }

        // handle multiple candidate names
        if (CandidateNames.Num() > 0)
        {
            if (Bone == EOptitrackBone::Chest)
            {
                // Chest should be the second spine bone (typically)
                GraphNode->Node.BoneSockets[BoneId].BoneReference.BoneName = CandidateNames[1];
            }
            else
            {
                GraphNode->Node.BoneSockets[BoneId].BoneReference.BoneName = CandidateNames[0];
            }
        }
        else
        {
            if (Bone == EOptitrackBone::Root)
            {
                // no candidates for root, likely a blank or strange name
                GraphNode->Node.BoneSockets[BoneId].BoneReference.BoneIndex = 0;
            }
        }
    }
	GraphNode->MarkPackageDirty();
    return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
