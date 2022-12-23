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

	pOut->PrintMessage("Please click on a figure");
	
	// Store the selected point in the Private data member Point
	pIn->GetPointClicked(Clicked.x, Clicked.y);
}

void SelectFigAction::Execute()
{
	ReadActionParameters();
	
	CFigure* ClickedFig = pManager->GetFigure(Clicked.x, Clicked.y);

	// Now I know where the kid clicked
	// let's think
	// Get two pointers to access input and output 
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	if (ClickedFig == NULL)
	{
		pOut->ClearStatusBar();
		return;
	}
	if (ClickedFig != NULL) // If it is a legit figure
	{
		if (ClickedFig->IsSelected() == false) // if it was not selected
		{
			///TODO: let's unselect the previously selcted figure
			pManager->UnselectPrevious();

			ClickedFig->SetSelected(true); // select this fig
			pManager->SetSelectedFigure(ClickedFig);
			// Print a message
			pOut->PrintMessage("Selected the figure:");

			// Change its color to magenta
			ClickedFig->ChngDrawClr(UI.HighlightColor);
		}
		else // if the figure was selected before
		{
			ClickedFig->SetSelected(false); // unselect it
			pManager->SetSelectedFigure(NULL);
			// print a message
			pOut->PrintMessage("Unselected the figure:");
			
			// Change its color to normal
			ClickedFig->ChngDrawClr(UI.DrawColor);
		}
		pOut->ClearStatusBar();
	}
	// If the kid clicks on an empty space it will be ignored
}
