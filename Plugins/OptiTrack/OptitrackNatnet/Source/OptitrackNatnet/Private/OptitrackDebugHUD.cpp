//======================================================================================================
// Copyright 2018, NaturalPoint Inc.
//====================================================================================================== 
#include "OptitrackDebugHUD.h"

#include <Debug/DebugDrawService.h>
#include <Engine/Canvas.h>
#include <Engine/Engine.h>
#include <EngineGlobals.h>
#include <EngineUtils.h>
#include <BatchedElements.h>

#include "OptitrackClientOrigin.h"


#if ! UE_BUILD_SHIPPING
static void	OptiTrackToggleDebugHUD( UWorld* InWorld );

FAutoConsoleCommandWithWorld GOptiTrackToggleDebugHUDCommand(
	TEXT( "OptiTrack.ToggleDebugHUD" ), TEXT( "Toggle debug HUD drawing" ),
	FConsoleCommandWithWorldDelegate::CreateStatic( OptiTrackToggleDebugHUD )
);

TAutoConsoleVariable<int32> CVarOptiTrackLatencyGraphClient(
	TEXT( "OptiTrack.LatencyGraphClient" ), 0,
	TEXT( "The index of the OptitrackClientOrigin for which to graph latency metrics." )
);
#endif // #if ! UE_BUILD_SHIPPING


void AOptitrackDebugHUD::DebugDraw( UCanvas* InDebugCanvas, APlayerController* DebugPC )
{
	Canvas = InDebugCanvas;
	if ( ! Canvas || ! Canvas->Canvas )
	{
		return;
	}

#if ! UE_BUILD_SHIPPING
	const int32 latencyClientIndex = CVarOptiTrackLatencyGraphClient->GetInt();
	if ( latencyClientIndex >= 0 && latencyClientIndex < DebugClients.Num() )
	{
		DebugDraw_ClientLatency( InDebugCanvas, DebugClients[latencyClientIndex] );
	}
#endif // #if ! UE_BUILD_SHIPPING
}


void AOptitrackDebugHUD::AddClient( AOptitrackClientOrigin* DebugClient )
{
	DebugClients.AddUnique( DebugClient );
}


// This code is largely borrowed from FStatUnitData::DrawStat.
void AOptitrackDebugHUD::DebugDraw_ClientLatency( UCanvas* InDebugCanvas, AOptitrackClientOrigin* DebugClient )
{
#if ! UE_BUILD_SHIPPING
	static const uint32 kSampleCount = AOptitrackClientOrigin::FTimingStats::kSampleCount;
	const uint32 CurrentIndex = DebugClient->TimingStats.CurrentIndex;

	FCanvas& FCanvas = *InDebugCanvas->Canvas;

	UFont* SmallFont = GEngine->GetSmallFont();

	// Graph layout. The vertical axis is time (millisecond divisions),
	// the horizontal axis is NatNet streaming frames.
	const uint32 kHeightInMs = 20;
	const float kMaxWidthPercent = 0.80f;
	const float kMaxHeightPercent = 0.80f;
	const int32 kWidthTextPad = SmallFont->GetStringSize( TEXT( "00.00ms - Stream net latency" ) );
	const int32 kMaxWidthPixels = FMath::FloorToInt( InDebugCanvas->SizeX * kMaxWidthPercent ) - kWidthTextPad;
	const int32 kMaxHeightPixels = FMath::FloorToInt( InDebugCanvas->SizeY * kMaxHeightPercent );
	const int32 kHorizPixelsPerFrame = FMath::Max( 1u, kMaxWidthPixels / kSampleCount );
	const int32 kVerticalPixelsPerMs = FMath::Max( 1u, kMaxHeightPixels / kHeightInMs );
	const int32 kWidthPixels = kSampleCount * kHorizPixelsPerFrame;
	const int32 kHeightPixels = kHeightInMs * kVerticalPixelsPerMs;
	const float kGraphLeftXPos = InDebugCanvas->SizeX * 0.5f - kWidthPixels * 0.5f;
	const float kGraphBottomYPos = InDebugCanvas->SizeY * 0.5f + kHeightPixels * 0.5f;

	const FLinearColor kGraphBorderColor( 0.3f, 0.3f, 0.3f );

	// For each type of statistic that we want to graph
	enum EGraphStats
	{
		EGS_TotalLatency = 0,
		EGS_NetworkLatency,
		EGS_ArrivalPeriod,

		EGS_Count
	};


	FBatchedElements* BatchedElements = FCanvas.GetBatchedElements( FCanvas::ET_Line );
	FHitProxyId HitProxyId = FCanvas.GetHitProxyId();

	// Reserve line vertices (2 border lines, n+1 vertical divisions, then up to the maximum number of graph lines)
	BatchedElements->AddReserveLines( 2 + kHeightInMs + 1 + EGS_Count * kSampleCount );

	// Left border
	BatchedElements->AddLine(
		FVector( kGraphLeftXPos - 1.0f, kGraphBottomYPos - 1.0f, 0.0f ),
		FVector( kGraphLeftXPos - 1.0f, kGraphBottomYPos - kHeightPixels - 1.0f, 0.0f ),
		kGraphBorderColor,
		HitProxyId );

	// Right border
	BatchedElements->AddLine(
		FVector( kGraphLeftXPos + kWidthPixels + 1.0f, kGraphBottomYPos - 1.0f, 0.0f ),
		FVector( kGraphLeftXPos + kWidthPixels + 1.0f, kGraphBottomYPos - kHeightPixels - 1.0f, 0.0f ),
		kGraphBorderColor,
		HitProxyId );

	// Horizontal lines
	for ( uint32 horizontalLineIdx = 0; horizontalLineIdx <= kHeightInMs; ++horizontalLineIdx )
	{
		const float horizontalLineY = kGraphBottomYPos - horizontalLineIdx * kVerticalPixelsPerMs - 1.0f;
		BatchedElements->AddLine(
			FVector( kGraphLeftXPos - 1.0f,                horizontalLineY, 0.0f ),
			FVector( kGraphLeftXPos + kWidthPixels + 1.0f, horizontalLineY, 0.0f ),
			kGraphBorderColor,
			HitProxyId );
	}

	for ( int32 StatIndex = 0; StatIndex < EGS_Count; ++StatIndex )
	{
		FLinearColor StatColor;
		float StatMean = 0.0f;
		float* StatValues = nullptr;
		switch ( StatIndex )
		{
		case EGS_TotalLatency:
			StatValues = DebugClient->TimingStats.TotalLatencySamples.GetData();
			StatColor = FLinearColor( 1.0f, 0.1f, 0.1f ); // Red
			break;

		case EGS_NetworkLatency:
			StatValues = DebugClient->TimingStats.NetworkLatencySamples.GetData();
			StatColor = FLinearColor( 0.1f, 1.0f, 0.1f ); // Green
			break;

		case EGS_ArrivalPeriod:
			StatValues = DebugClient->TimingStats.ArrivalPeriodSamples.GetData();
			StatColor = FLinearColor( 0.1f, 0.1f, 1.0f ); // Blue
			break;
		}

		// For each sample in our data set
		for ( int32 CurFrameIndex = 0; CurFrameIndex < kSampleCount; ++CurFrameIndex )
		{
			const int32 PrevFrameIndex = FMath::Max( 0, CurFrameIndex - 1 );

			int32 PrevSampleIndex = (CurrentIndex - kSampleCount) + PrevFrameIndex;
			if ( PrevSampleIndex < 0 )
			{
				PrevSampleIndex += kSampleCount;
			}
			const float PrevStatValue = StatValues[PrevSampleIndex];


			int32 CurSampleIndex = (CurrentIndex - kSampleCount) + CurFrameIndex;
			if ( CurSampleIndex < 0 )
			{
				CurSampleIndex += kSampleCount;
			}
			const float CurStatValue = StatValues[CurSampleIndex];

			StatMean += CurStatValue;

			const FVector LineStart(
				kGraphLeftXPos + PrevFrameIndex * kHorizPixelsPerFrame,
				kGraphBottomYPos - PrevStatValue * kVerticalPixelsPerMs * 1000.0f,
				0.0f
			);
			const FVector LineEnd(
				kGraphLeftXPos + CurFrameIndex * kHorizPixelsPerFrame,
				kGraphBottomYPos - CurStatValue * kVerticalPixelsPerMs * 1000.0f,
				0.0f
			);

			const float kLineThickness = 2.0f;
			BatchedElements->AddLine( LineStart, LineEnd, StatColor, HitProxyId, kLineThickness );
		}

		StatMean /= kSampleCount;

		const float StatMeanY = kGraphBottomYPos - StatMean * kVerticalPixelsPerMs * 1000.0f;
		float StatX = kGraphLeftXPos + kWidthPixels + 10.0f;
		FString StatString;

		switch ( StatIndex )
		{
		case EGS_TotalLatency:
			StatString = FString::Printf( TEXT( "%.02fms - Total latency" ), StatMean * 1000.0f );
			break;
		case EGS_NetworkLatency:
			StatString = FString::Printf( TEXT( "%.02fms - Stream net latency" ), StatMean * 1000.0f );
			break;
		case EGS_ArrivalPeriod:
			StatString = FString::Printf( TEXT( "Period - %.02fms" ), StatMean * 1000.0f );
			StatX = kGraphLeftXPos - SmallFont->GetStringSize( *StatString ) - 10.0f;
			break;
		}

		FCanvas.DrawShadowedString( StatX, StatMeanY - 5.0f, *StatString, SmallFont, StatColor );
	}
#endif // #if ! UE_BUILD_SHIPPING
}


#if ! UE_BUILD_SHIPPING
static void	OptiTrackToggleDebugHUD( UWorld* InWorld )
{
	if ( ! InWorld )
		return;

	AOptitrackDebugHUD* HUD = nullptr;

	for ( TActorIterator<AOptitrackDebugHUD> It( InWorld ); It; ++It )
	{
		HUD = *It;
		break;
	}

	static FDelegateHandle DebugDrawDelegateHandle;

	if ( ! HUD )
	{
		HUD = InWorld->SpawnActor<AOptitrackDebugHUD>();

		for ( TActorIterator<AOptitrackClientOrigin> It( InWorld ); It; ++It )
		{
			HUD->AddClient( *It );
		}

		FDebugDrawDelegate DrawDebugDelegate = FDebugDrawDelegate::CreateUObject( HUD, &AOptitrackDebugHUD::DebugDraw );
		DebugDrawDelegateHandle = UDebugDrawService::Register( TEXT( "Game" ), DrawDebugDelegate );
	}
	else
	{
		FDebugDrawDelegate DrawDebugDelegate = FDebugDrawDelegate::CreateUObject( HUD, &AOptitrackDebugHUD::DebugDraw );
		UDebugDrawService::Unregister( DebugDrawDelegateHandle );
		HUD->Destroy();
	}
}
#endif // #if ! UE_BUILD_SHIPPING
