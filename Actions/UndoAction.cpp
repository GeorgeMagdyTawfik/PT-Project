#include "UndoAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"
UndoAction::UndoAction(ApplicationManager* pApp):Action(pApp)
{}

void UndoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("undo action");
	pOut->ClearDrawArea(); 

}
void UndoAction::Execute()
{
	ReadActionParameters();
	int figcount = pManager->GetFigCount();
	int undoExcuted = pManager->GetUndoExcuted();
	if (figcount == 0)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("no more action to undo");


	}
	else if (undoExcuted > 4)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("you have exceeded the maximum number of undo action");

	}
	else
	pManager->Undo();

}
void UndoAction::UndoExcute()
{}
void UndoAction::RedoExcute()
{}