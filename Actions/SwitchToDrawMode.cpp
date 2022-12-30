#include "SwitchToDrawMode.h"
#include "LoadAction.h"

SwitchToDrawMode::SwitchToDrawMode(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToDrawMode::ReadActionParameters()
{
}

void SwitchToDrawMode::Execute(bool ReadParamsFirst)
{
	
	Action* pAct = new LoadAction(pManager);
	Output* pOut = pManager->GetOutput();
	pAct->Execute(0);
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
	
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
