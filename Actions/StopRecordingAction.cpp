#include "StopRecordingAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void StopRecordingAction::ReadActionParameters()
{}

void StopRecordingAction::Execute(bool ReadParamsFirst)
{
	pManager->SetRecordingState(false);
	Output* pOut = pManager->GetOutput();
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
