#include "ClearAllAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"

#include "..\GUI\Output.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}
void ClearAllAction::ReadActionParameters()
{
}
void ClearAllAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();

	Output* pOut = pManager->GetOutput();

	pOut->ClearDrawArea();

	pManager->DeleteAll();					//deleting allfigures
	pManager->EmptyUndoList();				//and any history of undo
	pManager->RemovePastRecording();		//and past recordings

	UI.DrawColor = color(0, 87, 231);		//resetting colors back to default
	UI.FillColor = color(0, 135, 68);
	CFigure::FilledAsDefault = false;

	CFigure::NumberOfFigures = 0;			//resetting figure IDs back to zero

	pManager->SetSelectedFigure(NULL);		//making sure there are no selected figs
	pManager->SetStateOfSound(false);		//resetting sound state to OFF
	pManager->SetRecordingState(false);		//ensures that any recording stops

	pOut->PrintMessage("Cleared all!");
}
void ClearAllAction::RedoExcute()
{}
void ClearAllAction::UndoExcute()
{}
