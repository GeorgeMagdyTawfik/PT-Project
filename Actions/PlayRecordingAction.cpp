#include "PlayRecordingAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "..\Figures\CRectangle.h"

PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void PlayRecordingAction::ReadActionParameters()
{}
void PlayRecordingAction::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetRecordingState() == true)
	{
		pOut->PrintMessage("Can't play while still recording!");
		return;
	}
	if (pManager->GetRecordedActionsCount() == 0)
	{
		pOut->PrintMessage("No previous recording");
		return;
	}
	// if there are no actions recorded, don't play
	if (pManager->GetRecordingState() == false)	
	{
		CFigure::FilledAsDefault = false;
		pManager->DeleteAll();
		pOut->ClearDrawArea();
		pOut->PrintMessage("Started Playing");
		pManager->PreviewRecordedActs();
		pOut->PrintMessage("Finished the recorded actions");
	}
		
}

void PlayRecordingAction::UndoExcute()
{}
void PlayRecordingAction::RedoExcute()
{}
