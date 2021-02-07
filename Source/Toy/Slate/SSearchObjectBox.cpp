// Copyright Epic Games, Inc. All Rights Reserved.

#include "SSearchObjectBox.h"
#include "Styling/SlateTypes.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/Commands/UICommandList.h"
#include "Widgets/Input/SSearchBox.h"
#include "EngineUtils.h"

#define LOCTEXT_NAMESPACE "SearchObjectBox"

struct FSearchObjectItem
{
	FString Name;
	void* Point;
};

SSearchObjectBox::~SSearchObjectBox()
{
	
}

void SSearchObjectBox::Construct( const FArguments& InArgs, UWorld* InWorld)
{
	WorldPtr = TWeakObjectPtr<UWorld>(InWorld);

	bSearchActor = InArgs._bSearchActor;

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FCoreStyle::Get().GetBrush("BlackBrush"))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SAssignNew(SearchBox, SSearchBox)
				.ToolTipText(LOCTEXT("FilterSearchToolTip", "Type here to search object or class name"))
				.HintText(LOCTEXT("FilterSearchHint", "Search object or class name"))
				.OnTextChanged(this, &SSearchObjectBox::OnFilterTextChanged)
			]

			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SAssignNew(SearchList, SListView<TSharedPtr<FSearchObjectItem>>)
				.ItemHeight(16.0f)
				.ListItemsSource(&SearchItems)
				.OnGenerateRow(this, &SSearchObjectBox::OnGenerateRow)
				.OnMouseButtonDoubleClick(this, &SSearchObjectBox::OnItemDoubleClicked)
				.SelectionMode(ESelectionMode::Single)
			]
		]
	];

}

TSharedRef<ITableRow> SSearchObjectBox::OnGenerateRow(TSharedPtr<FSearchObjectItem> InItem, const TSharedRef<STableViewBase>& OwnerTable)
{
	return
		SNew(SComboRow< TSharedRef<FString> >, OwnerTable)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.FillWidth(1)
			.Padding(2.0f)
			[
				SNew(STextBlock)
				.Text(FText::FromString(*InItem->Name))
				.Font(FCoreStyle::Get().GetFontStyle(TEXT("NormalFont")))
			]
			+ SHorizontalBox::Slot()
			.FillWidth(1)
			.Padding(2.0f)
			[
				SNew(STextBlock)
				.Text(FText::FromString(FString::Printf(TEXT("0x%p"), InItem->Point)))
				.Font(FCoreStyle::Get().GetFontStyle(TEXT("NormalFont")))
			]
		];
}

void SSearchObjectBox::OnFilterTextChanged(const FText& SearchText)
{
	if (!WorldPtr.IsValid() || !GEngine)
	{
		return;
	}

	FString FilterText = SearchText.ToString();

	SearchItems.Empty();
	FString CurName;
	for (TObjectIterator<UObject> It; It; ++It)
	{
		UObject* Obj = Cast<UObject>(*It);

		if (Obj && !Obj->IsPendingKill()&& !Obj->IsTemplate())
		{
			if (bSearchActor && Cast<UObject>(Obj) && (Obj->GetWorld() != WorldPtr.Get()))
			{
				continue;
			}

			CurName = Obj->GetName();
			if (CurName.Contains(FilterText))
			{
				TSharedPtr<FSearchObjectItem> NewItem = MakeShareable(new FSearchObjectItem);
				NewItem->Name = CurName;
				NewItem->Point = Obj;
				SearchItems.Add(NewItem);
			}
		}
	}

	SearchList->RequestListRefresh();
}

void SSearchObjectBox::OnItemDoubleClicked(TSharedPtr<FSearchObjectItem> ClickedItem)
{
	if (!ClickedItem.IsValid() || !GEngine || !WorldPtr.IsValid())
	{
		return;
	}

	FString Cmd;
	const FString ClickObjectName = ClickedItem->Name;

	if (bSearchActor)
	{
		Cmd = FString::Printf(TEXT("EditActor Name=%s"), *ClickObjectName);
	}
	else
	{
		Cmd = FString::Printf(TEXT("EditObject Name=%s"), *ClickObjectName);
	}
	GEngine->Exec(WorldPtr.Get(), *Cmd);
}

#undef LOCTEXT_NAMESPACE
