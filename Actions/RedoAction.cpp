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
void RedoAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	int redocount = pManager->getredocount();
	if ( redocount== 0)
	{

		pOut->PrintMessage("no action to redo");
	}
	//else if (pManager->getredoExcuted() == 0)
		//pOut->PrintMessage("no action to redo");
	else
	pManager->Redo();
	

}
void RedoAction::UndoExcute()
{}
void RedoAction::RedoExcute()
{
	Action* re = pManager->getundoedaction();
	re->RedoExcute();


}

bool RedoAction::CheckRecordability() const
{
	return true;
}