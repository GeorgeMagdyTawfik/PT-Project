#include "RedoAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"
RedoAction::RedoAction(ApplicationManager* pApp):Action(pApp)
{}
void RedoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("redo action");
	
}
void RedoAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (pManager->GetUndoExcuted() == 0)
	{

		pOut->PrintMessage("no action to redo");
	}
	//else if (pManager->getredoexcuted() == 0)
		//pOut->PrintMessage("no action to redo");
	//else
	//pManager->redo();


}
void RedoAction::UndoExcute()
{}
void RedoAction::RedoExcute()
{}
