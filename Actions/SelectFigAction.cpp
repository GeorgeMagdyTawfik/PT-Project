#include "SelectFigAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

SelectFigAction::SelectFigAction(ApplicationManager* pApp) : Action(pApp)
{}

void SelectFigAction::ReadActionParameters()
{
	// Get two pointers to access input and output 
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	was_selected = pManager->GetSelectedFig();

	if (pManager->GetFigCount() != 0)
	{
		pOut->PrintMessage("Please click on a figure: ");
		// Store the selected point in the Private data member Point
		pIn->GetPointClicked(Clicked.x, Clicked.y);
	}
}

/// The functions here need Redesign

void SelectFigAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("There are no figures to select!");
		return;
	}

	ClickedFig = pManager->GetFigure(Clicked.x, Clicked.y);
	if (ClickedFig == NULL) // a click not on a figure
	{
		pOut->PrintMessage("This is not a figure, ignored the click.");
		return;
	}

	if (ClickedFig->IsSelected() == false) // if it was not selected
	{
		//unselect the previously selcted figure
		UnselectPrevious(was_selected, true);

		ClickedFig->SetSelected(true); // select this fig
		pManager->SetSelectedFigure(ClickedFig);
		// Print a message
		ClickedFig->PrintInfo(pOut);
		// Change its color to magenta
		ClickedFig->ChngDrawClr(UI.HighlightColor);
	}
	else // if the figure was selected before
	{
		ClickedFig->SetSelected(false); // unselect it
		pManager->SetSelectedFigure(NULL);
		// print a message
		pOut->PrintMessage("Unselected the figure");
		// Change its color to normal
		ClickedFig->UseFigGfxInfo();
	}
	// If the kid clicks on an empty space it will be ignored
	RecordIfAllowed(this); // I hope this will work
}

void SelectFigAction::UnselectPrevious(CFigure* previous, bool go)
{
	if (previous != NULL)
	{
		previous->SetSelected(false);
		previous->UseFigGfxInfo();
		pManager->SetSelectedFigure(NULL);
		// Change its color to normal
		//if (go)						//this boolean expands the functionality and allows for reusability
		//	ClickedFig->UseFigGfxInfo();
		
	}
}

void SelectFigAction::UndoExcute()
{}
void SelectFigAction::RedoExcute()
{}
