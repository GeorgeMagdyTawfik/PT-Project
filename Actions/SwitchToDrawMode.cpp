#include "SwitchToDrawMode.h"
#include "LoadAction.h"

SwitchToDrawMode::SwitchToDrawMode(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToDrawMode::ReadActionParameters()
{
}

bool SwitchToDrawMode::Execute(bool ReadParamsFirst)
{
	bool flag;
	Action* pAct = new LoadAction(pManager);
	Output* pOut = pManager->GetOutput();
	pAct->Execute(0);
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
	flag = false;
	return flag;
}

void SwitchToDrawMode::UndoExcute()
{
}

void SwitchToDrawMode::RedoExcute()
{
}

bool SwitchToDrawMode::CheckRecordability() const
{
	return false;
}

SwitchToDrawMode::~SwitchToDrawMode()
{
}
