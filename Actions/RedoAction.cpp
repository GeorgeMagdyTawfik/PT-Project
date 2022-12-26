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
	if (pManager->getredocount() == 0)
	{

		pOut->PrintMessage("no action to redo");
	}
	else if (pManager->GetUndoExcuted() == 0)
		pOut->PrintMessage("no action to redo");
	else
	//pManager->redo();
	RedoExcute();

}
void RedoAction::UndoExcute()
{}
void RedoAction::RedoExcute()
{
	Action* re = pManager->getundoedaction();
	re->RedoExcute();


}
