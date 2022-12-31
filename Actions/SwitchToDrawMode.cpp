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
	pManager->ResetCounts();
	pOut->PrintMessage("Switched to draw mode, original graph has been loaded.");
	
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
