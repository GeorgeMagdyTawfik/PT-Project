#include "SwitchToPlayMode.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) : Action(pApp)
{}

void SwitchToPlayMode::ReadActionParameters()
{}

void SwitchToPlayMode::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
}