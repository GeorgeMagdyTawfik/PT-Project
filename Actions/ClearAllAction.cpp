#include "ClearAllAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}
void ClearAllAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("clearall action");
}
void ClearAllAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->DeleteAll();
	pManager->SetFigcount(0);
}
void ClearAllAction::RedoExcute()
{}
void ClearAllAction::UndoExcute()
{}

bool ClearAllAction::CheckRecordability() const
{
	return true;
}