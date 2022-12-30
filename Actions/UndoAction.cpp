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
	

	ReadActionParameters();
	
	int undocount = pManager->getundocount();
	//int figcount = pManager->GetFigCount();
	Output* pOut = pManager->GetOutput();
	
	if (undocount == 0)
	{
		
		pOut->PrintMessage("no action to undo");


	}
	//else if (undoExcuted > 4)
	//{
		
		//pOut->PrintMessage("you have exceeded the maximum number of undo action");

	//}
	else
	{
		
		 pManager->Undo();
	}

	RecordIfAllowed(this);
	
}
void UndoAction::UndoExcute()
{}
void UndoAction::RedoExcute()
{};

bool UndoAction::CheckRecordability() const
{
	return true;
}