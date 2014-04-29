//-------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2014 Vadim Macagon
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-------------------------------------------------------------------------------
#pragma once

namespace MercurialSourceControl {

typedef TSharedPtr<class FLargeAssetTypeTreeItem> FLargeAssetTypeTreeItemPtr;
typedef TWeakPtr<class FLargeAssetTypeTreeItem> FLargeAssetTypeTreeItemWeakPtr;

/** A tree view that displays all available asset types grouped by asset categories. */
class SLargeAssetTypeTreeWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLargeAssetTypeTreeWidget) {}

	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

private:
	/** Load all the asset categories and get TreeView to redraw itself. */
	void Populate();

	/** Called by TreeView to generate a table row for the given item. */
	TSharedRef<ITableRow> TreeView_OnGenerateRow(
		FLargeAssetTypeTreeItemPtr Item, const TSharedRef<STableViewBase>& OwnerTable
	);

	/** Called by TreeView to obtain child items for the given parent item. */
	void TreeView_OnGetChildren(
		FLargeAssetTypeTreeItemPtr Parent, TArray<FLargeAssetTypeTreeItemPtr>& OutChildren
	);

	/** Called by TreeView to obtain the checked state of the given item. */
	ESlateCheckBoxState::Type TreeView_IsChecked(FLargeAssetTypeTreeItemWeakPtr ItemWeakPtr) const;

	/** Called by TreeView when an item is checked or unchecked. */
	void TreeView_OnCheckStateChanged(
		ESlateCheckBoxState::Type NewState, FLargeAssetTypeTreeItemWeakPtr ItemWeakPtr
	);

private:
	typedef STreeView<FLargeAssetTypeTreeItemPtr> SLargeAssetTypeTreeView;
	TSharedPtr<SLargeAssetTypeTreeView> TreeView;
	/** Asset categories are the top-level items in the tree. */
	TArray<FLargeAssetTypeTreeItemPtr> AssetCategories;
};

} // namespace MercurialSourceControl