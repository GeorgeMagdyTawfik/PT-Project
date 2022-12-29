#include "UndoAction.h"
#include "..\ApplicationManager.h"


#include "..\GUI\Output.h"
UndoAction::UndoAction(ApplicationManager* pApp):Action(pApp)
{}

void UndoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("undo action");
	

}
void UndoAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();
	int figcount = pManager->GetFigCount();
	int undoExcuted = pManager->GetUndoExcuted();
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	if (figcount == 0)
	{
		
		pOut->PrintMessage("no action to undo");


	}
	else if (undoExcuted > 4)
	{
		
		pOut->PrintMessage("you have exceeded the maximum number of undo action");

	}
	else
	{
		UndoExcute();
		pManager->SetUndoExcuted();
		
	}

	RecordIfAllowed(this);
}
void UndoAction::UndoExcute()
{
	Action* ac = pManager->GetExcutedAction();
	ac->UndoExcute();
	pManager->setExcutedeundoAction(ac);

}
void UndoAction::RedoExcute()
{};

bool UndoAction::CheckRecordability() const
{
	return true;
}