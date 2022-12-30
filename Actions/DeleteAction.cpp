#include "DeleteAction.h"
#include "..\ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{}

void DeleteAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();
	//CFigure* pFig = pManager->GetSelectedFig();
	Output* pOut = pManager->GetOutput();
	saved = pManager->GetSelectedFig()->getfigure();
	savedredo = pManager->GetSelectedFig()->getfigure();
	pOut->ClearDrawArea();
	bool done = pManager->DeleteFigure();
	if (!done)
		pOut->PrintMessage("No selected figure. Please select a figure first!");
	else
		pOut->PrintMessage("Deleted selected figure.");
	
	RecordIfAllowed(this);

	pManager->addtoundolist(this);
}

DeleteAction::~DeleteAction()
{}
void DeleteAction::UndoExcute()
{
	pManager->AddFigure(saved);
	saved = saved->getfigure();
	
}
void DeleteAction::RedoExcute()
{

	pManager->DeleteByID(savedredo);

	savedredo = savedredo-> getfigure();
}

