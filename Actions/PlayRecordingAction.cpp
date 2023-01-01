#include "PlayRecordingAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "..\Figures\CRectangle.h"

PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void PlayRecordingAction::ReadActionParameters()
{}
bool PlayRecordingAction::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetRecordingState() == true)
	{
		pOut->PrintMessage("Can't play while still recording!");
		return false;
	}
	if (pManager->GetRecordedActionsCount() == 0)
	{
		pOut->PrintMessage("No previous recording");
		return false;
	}
	// if there are no actions recorded, don't play
	if (pManager->GetRecordingState() == false)	
	{
		CFigure::FilledAsDefault = false;
		CFigure::NumberOfFigures = 0;
		pManager->DeleteAll();
		pManager->EmptyUndoList();
		pOut->ClearDrawArea();
		pManager->SetPlayRecordingState(true);

		pOut->PrintMessage("Started Playing");

		pManager->PreviewRecordedActs();

		pOut->PrintMessage("Finished the recorded actions");
		pManager->SetPlayRecordingState(false);
	}
	return false;
}

void PlayRecordingAction::UndoExcute()
{}
void PlayRecordingAction::RedoExcute()
{}
