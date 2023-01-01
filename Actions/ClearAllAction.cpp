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

	pManager->DeleteAll();
	pManager->EmptyUndoList();
	pManager->RemovePastRecording();

	UI.DrawColor = color(0, 87, 231);		//resetting colors back to default
	UI.FillColor = color(0, 135, 68);
	CFigure::FilledAsDefault = false;

	pManager->SetSelectedFigure(NULL);		//making sure there are no selected figs

	CFigure::NumberOfFigures = 0;			//resetting figure IDs back to zero

	pManager->SetStateOfSound(false);		//resetting sound state to OFF

	pOut->PrintMessage("Cleared all!");
}
void ClearAllAction::RedoExcute()
{}
void ClearAllAction::UndoExcute()
{}
