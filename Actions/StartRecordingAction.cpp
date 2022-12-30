#include "StartRecordingAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void StartRecordingAction::ReadActionParameters()
{}

void StartRecordingAction::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();
	int drawnfigs = pManager->GetFigCount();

	if (pManager->GetRecordingState() == true)
	{
		pOut->PrintMessage("Not possible : You are already recording!");
		return;
	}
	if (drawnfigs != 0)
	{
		pOut->PrintMessage("Can't start recording here");
		return;
	}
	if (pManager->GetRecordedActionsCount() != 0)
	{
		pManager->RemovePastRecording();
	}
	pManager->SetRecordingState(true);
	pOut->PrintMessage("Recording Started! you have a maximum of 20 actions to record");
}

void StartRecordingAction::UndoExcute()
{}
void StartRecordingAction::RedoExcute()
{}