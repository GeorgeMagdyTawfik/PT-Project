#include "StartRecordingAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) : Action(pApp)
{}

void StartRecordingAction::ReadActionParameters()
{}

bool StartRecordingAction::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();

	if (pManager->GetRecordingState() == true)
	{
		pOut->PrintMessage("Not possible: you are already recording!");
		return false;
	}
	if (pManager->GetFigCount() != 0 || pManager->getundocount() != 0)	
	{
		pOut->PrintMessage("Can't start recording here");
		return false;
	}
	if (pManager->GetRecordedActionsCount() != 0)
	{
		pManager->RemovePastRecording();
	}
	pManager->SetRecordingState(true);
	pOut->PrintMessage("Recording Started! You have a maximum of 20 actions to record");

	return false;
}


void StartRecordingAction::UndoExcute()
{}
void StartRecordingAction::RedoExcute()
{}