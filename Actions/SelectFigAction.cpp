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
	was_selected = pManager->GetSelectedFigure();

	if (pManager->GetFigCount() != 0)
	{
		pOut->PrintMessage("Please click on a figure: ");
		// Store the selected point in the Private data member Point
		pIn->GetPointClicked(Clicked.x, Clicked.y);
	}
	else
	{
		pOut->PrintMessage("There are no figures to select!");
	}

	ClickedFig = pManager->GetFigure(Clicked.x, Clicked.y);
}

/// The functions here need Redesign

void SelectFigAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();

	if (pManager->GetFigCount() == 0)
	{
		return;
	}
	
	// Now I know where the kid clicked
	// Get two pointers to access input and output 
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	if (ClickedFig == NULL) // a click not on a figure
	{
		pOut->ClearStatusBar();
		return;
	}

	if (ClickedFig->IsSelected() == false) // if it was not selected
	{
		//unselect the previously selcted figure
		UnselectPrevious(was_selected);

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
		//ClickedFig->ChngDrawClr(UI.DrawColor);
		
	}
	//pOut->ClearStatusBar(); //if I clear the status bar here the message will be quickly removed (won't be seen)
	// If the kid clicks on an empty space it will be ignored

	RecordIfAllowed(this);
}

void SelectFigAction::UnselectPrevious(CFigure* previous)
{
	if (previous != NULL)
	{
		previous->SetSelected(false);
		//previous->ChngDrawClr(UI.DrawColor);
		previous->UseFigGfxInfo();
		pManager->SetSelectedFigure(NULL);
			// Change its color to normal
			//ClickedFig->ChngDrawClr(UI.DrawColor);
		ClickedFig->UseFigGfxInfo();
		
		//pOut->ClearStatusBar(); //if I clear the status bar here the message will be quickly removed (won't be seen)
	}
}

void SelectFigAction::UndoExcute()
{}
void SelectFigAction::RedoExcute()
{}

bool SelectFigAction::CheckRecordability() const
{
	return true;
}