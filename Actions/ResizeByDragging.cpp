#include "ResizeByDragging.h"

ResizeByDragging::ResizeByDragging(ApplicationManager* pApp) : Action(pApp)
{}

void ResizeByDragging::ReadActionParameters()
{}

bool ResizeByDragging::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pFig = pManager->GetSelectedFig();

	bool done = false;
	if (pFig)
	{

		pOut->PrintMessage("Resize by dragging: drag the figure you want to resize");
		pFig = pManager->GetSelectedFig();
		while (pIn->GetButton(NewLocation.x, NewLocation.y) == BUTTON_UP)
		{
		}
		while (pIn->GetButton(NewLocation.x, NewLocation.y) == BUTTON_DOWN)
		{
			pFig->ResizeByDragging(NewLocation);
			Sleep(1);
			pOut->PrintMessage("The figure is being resized!");

			pManager->UpdateInterface();
		}
		done = true;
	}
	else
		pOut->PrintMessage("No selected figure. Please select a figure first!");

	if (done)
		pOut->PrintMessage("The figure has been resized");

	return false;
}

void ResizeByDragging::UndoExcute()
{}

void ResizeByDragging::RedoExcute()
{}

ResizeByDragging::~ResizeByDragging()
{}
