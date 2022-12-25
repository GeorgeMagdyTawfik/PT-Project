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
void ClearAllAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	pManager->DeleteAll();
}
void ClearAllAction::RedoExcute()
{}
void ClearAllAction::UndoExcute()
{}