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
	pFig = pManager->GetSelectedFig();
	Output* pOut = pManager->GetOutput();
	if (pFig)
	{
		saved = pManager->GetSelectedFig()->getpointerfig();
		savedredo = pManager->GetSelectedFig()->getpointerfig();
		pOut->ClearDrawArea();

		pManager->DeleteFigure(pFig);
		pOut->PrintMessage("Deleted selected figure.");
		RecordIfAllowed(this);
		pManager->addtoundolist(this);
		
	}
	else
	pOut->PrintMessage("No selected figure. Please select a figure first!");
}

DeleteAction::~DeleteAction()
{}
void DeleteAction::UndoExcute()
{
	pManager->AddFigure(saved);
	saved = saved->getpointerfig();
	
}
void DeleteAction::RedoExcute()
{

	pManager->DeleteByID(savedredo);

	savedredo = savedredo-> getpointerfig();
}

