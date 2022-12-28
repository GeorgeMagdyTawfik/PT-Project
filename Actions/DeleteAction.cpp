#include "DeleteAction.h"
#include "..\ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}

void DeleteAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();
	//CFigure* pFig = pManager->GetSelectedFig();
	Output* pOut = pManager->GetOutput();
	bool done = pManager->DeleteFigure();
	if (!done)
		pOut->PrintMessage("No selected figure. Please select figure first!");
	else
		pOut->PrintMessage("Deleted selected figure.");
	
}

DeleteAction::~DeleteAction()
{
}
void DeleteAction::UndoExcute()
{}
void DeleteAction::RedoExcute()
{}

bool DeleteAction::CheckRecordability() const
{
	return true;
}