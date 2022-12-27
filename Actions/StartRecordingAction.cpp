#include "StartRecordingAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void StartRecordingAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
}

void StartRecordingAction::Execute()
{
	ReadActionParameters();
}

bool StartRecordingAction::CheckRecordability() const
{
	return false;
}

void StartRecordingAction::UndoExcute()
{}
void StartRecordingAction::RedoExcute()
{}