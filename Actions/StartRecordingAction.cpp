#include "StartRecordingAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void StartRecordingAction::ReadActionParameters()
{}

void StartRecordingAction::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	int drawnfigs = pManager->GetFigCount();
	if (drawnfigs != 0)
	{
		pOut->PrintMessage("Can't start recording here");
		return;
	}
	pOut->PrintMessage("Can start a new recording here");
}

bool StartRecordingAction::CheckRecordability() const
{
	return false;
}

void StartRecordingAction::UndoExcute()
{}
void StartRecordingAction::RedoExcute()
{}