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
	Action* pAct = new LoadAction(pManager);
	pAct->Execute(0);

	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();

	pManager->ResetCounts();

	pOut->PrintMessage("Switched to draw mode, the original graph has been loaded!");
	
	return false;
}

void SwitchToDrawMode::UndoExcute()
{
}

void SwitchToDrawMode::RedoExcute()
{
}


SwitchToDrawMode::~SwitchToDrawMode()
{
}
