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
	//int figcount = pManager->GetFigCount();
	int undoExcuted = pManager->GetUndoExcuted();
	int figcount = pManager->GetFigCount();
	Output* pOut = pManager->GetOutput();
	//int actioncounter = pManager->getactioncounter();
	//if (actioncounter <  0)
	//{
	//	pOut->PrintMessage("no action to undo");
	//}
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
		pManager->setredoExcute();
	}
}
void UndoAction::UndoExcute()
{
	Action* ac = pManager->GetExcutedAction();
	ac->UndoExcute();
	pManager->setExcutedeundoAction(ac);
	
}
void UndoAction::RedoExcute()
{};