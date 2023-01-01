#include "SwitchToPlayMode.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "SaveAction.h"

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) : Action(pApp)
{}

void SwitchToPlayMode::ReadActionParameters()
{}

bool SwitchToPlayMode::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();

	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("Can't switch to play mode with no shapes!");
		return false;
	}

	Action* pAct = new SaveAction(pManager);
	pAct->Execute(0);
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("Switched to play mode, choose a game to play!");

	return false;
}

void SwitchToPlayMode::UndoExcute()
{}
void SwitchToPlayMode::RedoExcute()
{}
