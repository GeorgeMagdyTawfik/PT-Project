#include "UndoAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"
UndoAction::UndoAction(ApplicationManager* pApp):Action(pApp)
{}

void UndoAction::ReadActionParameters()
{}
bool UndoAction::Execute(bool ReadParamsFirst)
{
	ReadActionParameters();
	
	int undocount = pManager->getundocount();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("undo action");
	if (undocount == 0)
	{
		pOut->PrintMessage("no action to undo");
	}
	else
	{
		
		 pManager->Undo();
	}

	RecordIfAllowed(this);

	return true;
}
void UndoAction::UndoExcute()
{}
void UndoAction::RedoExcute()
{};
