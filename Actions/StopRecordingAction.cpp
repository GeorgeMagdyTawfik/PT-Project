#include "StopRecordingAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void StopRecordingAction::ReadActionParameters()
{}

void StopRecordingAction::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();

	if (pManager->GetRecordingState() == false)
	{
		pOut->PrintMessage("Not possible : Start a recording first!");
		return;
	}

	pManager->SetRecordingState(false);
	pOut->PrintMessage("Recording Stopped");
}

bool StopRecordingAction::CheckRecordability() const
{
	return false;
}

void StopRecordingAction::UndoExcute()
{}
void StopRecordingAction::RedoExcute()
{}
