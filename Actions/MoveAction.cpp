#include "MoveAction.h"
#include "..\ApplicationManager.h"

class Action;

MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp)
{
}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pFig = pManager->GetSelectedFig();

	if (pFig)
	{
		
		pOut->PrintMessage("Move: please click on where you want to move the figure.");
		pIn->GetPointClicked(destination.x, destination.y);
		pOut->ClearDrawArea();
	}
	else
		pOut->PrintMessage("No selected figure. Please select a figure first!");
}

bool MoveAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();

	pFig = pManager->GetSelectedFig();

	if (pFig)
	{
		prevlocation = pFig->GetCenter();
		pFig->Move(destination);
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Moved figure to chosen point.");
		pManager->addtoundolist(this);
		RecordIfAllowed(this);
	}
	return true;
}

void MoveAction::UndoExcute()
{
	
	pFig->Move(prevlocation);
}

void MoveAction::RedoExcute()
{
	pFig->Move(destination);
}

MoveAction::~MoveAction()
{
}
