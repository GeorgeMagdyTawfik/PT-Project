#include "ClearAllAction.h"
#include "..\ApplicationManager.h"
#include "../Figures/CRectangle.h"

#include "..\GUI\Output.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}
void ClearAllAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Cleared all!");
}
void ClearAllAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->RemovePastRecording();
	pManager->DeleteAll();
	pManager->EmptyUndoList();
	UI.DrawColor = color(0, 87, 231);
	UI.FillColor = color(0, 135, 68);
	CFigure* c = new CRectangle();
	c->SetNotFilledAsDefault();
}
void ClearAllAction::RedoExcute()
{}
void ClearAllAction::UndoExcute()
{}

bool ClearAllAction::CheckRecordability() const
{
	return true;
}