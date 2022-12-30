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
		pOut->PrintMessage("No previous recording"); /// how to delete a previous recording ?
		return;
		// lazem 3lshan tebda2 recording ykon el fig count zero wel recording count zero
		/// clear all has to delete the recording list, but when playing the recording i will call "delete all" which 
		// does not delete the recording list 
	}
	//TODO:  can't play while in a recording
	// call the previewrecording function of appmanager
	// if there are no actions recorded, don't play
	if (pManager->GetRecordingState() == false)	
	{
		// i think this is redundant
		//CFigure::FilledAsDefault = false;
		CFigure* c = new CRectangle();
		c->SetNotFilledAsDefault();
		delete c;
		pManager->PreviewRecordedActs();
	}
		
}
bool PlayRecordingAction::CheckRecordability() const
{
	return false;
}

void PlayRecordingAction::UndoExcute()
{}
void PlayRecordingAction::RedoExcute()
{}
