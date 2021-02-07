// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/Reply.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SWidget.h"
#include "Widgets/SCompoundWidget.h"

struct FSearchObjectItem;

class SSearchObjectBox : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSearchObjectBox)
	: _bSearchActor(false)
	{}
		SLATE_ARGUMENT(bool, bSearchActor);
	SLATE_END_ARGS()

	virtual ~SSearchObjectBox();

	/** Constructs this widget with InArgs */
	void Construct( const FArguments& InArgs, UWorld* InWorld);

	// SWidget implementation
	//virtual FReply OnKeyDown( const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent ) override;
	// End of SWidget implementation

private:
	TSharedRef<ITableRow> OnGenerateRow(TSharedPtr<FSearchObjectItem> InItem, const TSharedRef<STableViewBase>& OwnerTable);
	void OnFilterTextChanged(const FText& SearchText);
	void OnItemDoubleClicked(TSharedPtr<FSearchObjectItem> ClickedItem);

private:
	TSharedPtr<class SSearchBox> SearchBox;
	TSharedPtr<class SListView<TSharedPtr<FSearchObjectItem>>> SearchList;

	TArray<TSharedPtr<FSearchObjectItem>> SearchItems;
	TWeakObjectPtr<UWorld> WorldPtr;

	bool bSearchActor = false;
};
