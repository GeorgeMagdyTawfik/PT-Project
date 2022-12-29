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

void DeleteAction::Execute()
{
	ReadActionParameters();
	//CFigure* pFig = pManager->GetSelectedFig();
	Output* pOut = pManager->GetOutput();
	saved = pManager->GetSelectedFig()->getfigure();
	savedredo = pManager->GetSelectedFig()->getfigure();
	bool done = pManager->DeleteFigure();
	if (!done)
		pOut->PrintMessage("No selected figure. Please select a figure first!");
	else
		pOut->PrintMessage("Deleted selected figure.");
	pManager->addtoundolist(this);
}

DeleteAction::~DeleteAction()
{




}
void DeleteAction::UndoExcute()
{

	
}
void DeleteAction::RedoExcute()
{
	
	
}