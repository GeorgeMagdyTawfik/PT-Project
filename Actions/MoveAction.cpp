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

void MoveAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();

	if (pFig)
	{
		//saved = pManager->GetSelectedFig()->getfigure();
		saved = pFig->getpointerfig();
		prevlocation = saved->GetCenter();
		pFig->Move(destination);
		//pFig->UseFigGfxInfo();
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Moved figure to chosen point.");
		pManager->addtoundolist(this);
	}
	//pManager->AddToRecordingList(this);
	//RecordIfAllowed(this);				I think these have to be inside the scope	
}

void MoveAction::UndoExcute()
{
	
	saved->Move(prevlocation);
}

void MoveAction::RedoExcute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	saved->Move(destination);
}

MoveAction::~MoveAction()
{
}

bool MoveAction::CheckRecordability() const
{
	return true;
}