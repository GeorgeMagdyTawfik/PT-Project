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

void SoundAction::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->getcaseofsound())
	{
		pManager->changethestateofsound();
		pOut->PrintMessage("close the sound");
	}
	else
	{
		pManager->changethestateofsound();
		pOut->PrintMessage("open the sound");
	}
	

}

void SoundAction::UndoExcute()
{}

void SoundAction::RedoExcute()
{}

bool SoundAction::CheckRecordability() const
{
	return false;
}
