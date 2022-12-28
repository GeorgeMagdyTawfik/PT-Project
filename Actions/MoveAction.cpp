#include "MoveAction.h"
#include "..\ApplicationManager.h"

MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp)
{
}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* pFig = pManager->GetSelectedFig();
	if (pFig)
	{
		pOut->PrintMessage("Move: please click on where you want to move the figure.");
		pIn->GetPointClicked(destination.x, destination.y);
		pOut->ClearDrawArea();
	}
	else
		pOut->PrintMessage("No selected figure. Please select a figure first!");
}

void MoveAction::Execute()
{
	ReadActionParameters();

	bool done = pManager->MoveFigure(destination);
	Output* pOut = pManager->GetOutput();
	if (done)
	{
		pOut->PrintMessage("Moved figure to chosen point.");
	}

}

void MoveAction::UndoExcute()
{
}

void MoveAction::RedoExcute()
{
}

MoveAction::~MoveAction()
{
}
