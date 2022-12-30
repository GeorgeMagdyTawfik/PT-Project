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
	bool flag;
	Action* pAct = new SaveAction(pManager);
	Output* pOut = pManager->GetOutput();
	pAct->Execute(0);
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
	flag = false;
	return flag;

}

void SwitchToPlayMode::UndoExcute()
{}
void SwitchToPlayMode::RedoExcute()
{}

bool SwitchToPlayMode::CheckRecordability() const
{
	return false;
}