#include "SoundAction.h"
#include "../ApplicationManager.h"
#include "../GUI/input.h"
#include "../GUI/Output.h"
#include"../Actions/SelectFigAction.h"
#include<Windows.h>


SoundAction::SoundAction(ApplicationManager* pApp) :Action(pApp)
{}

void SoundAction::ReadActionParameters()
{
}

bool SoundAction::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->GetStateOfSound())
	{
		pManager->ChangeStateOfSound();
		pOut->PrintMessage("Sound is off");
	}
	else
	{
		pManager->ChangeStateOfSound();
		pOut->PrintMessage("Sound is on");
	}

	return false;
}

void SoundAction::UndoExcute()
{}

void SoundAction::RedoExcute()
{}
