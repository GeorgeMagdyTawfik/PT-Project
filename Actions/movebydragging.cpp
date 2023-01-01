#include "movebydragging.h"

#include "..\ApplicationManager.h"

class Action;

movebydragging::movebydragging(ApplicationManager* pApp) : Action(pApp)
{}

void movebydragging::ReadActionParameters()
{}

bool movebydragging::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pFig = pManager->GetSelectedFig();

	bool done = false;
	if (pFig)
	{

		pOut->PrintMessage("Move by dragging: drag the figure you want to move.");
		pFig = pManager->GetSelectedFig();
		while (pIn->GetButton(newlocation.x, newlocation.y) == BUTTON_UP)
		{
		}
		while (pIn->GetButton(newlocation.x, newlocation.y) == BUTTON_DOWN)
		{
			pFig->Move(newlocation);
			Sleep(1);
			pOut->PrintMessage("The figure is moving!");
			
			pManager->UpdateInterface();
		}
		done = true;
	}
	else
		pOut->PrintMessage("No selected figure. Please select a figure first!");

	if (done)
		pOut->PrintMessage("The figure has been moved");

	return false;
}

void movebydragging::UndoExcute()
{}

void movebydragging::RedoExcute()
{}

movebydragging::~movebydragging()
{}
