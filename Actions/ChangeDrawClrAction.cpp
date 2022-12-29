#include "ChangeDrawClrAction.h"
#include "..\ApplicationManager.h"


ChangeDrawClrAction::ChangeDrawClrAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ChangeDrawClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	ActionType ActType;

	CFigure* pFig = pManager->GetSelectedFig();

	if (!pFig) 
		pOut->PrintMessage("No selected figure. Please select a figure first!");

	else
	{
		pOut->PrintMessage("Change draw color: please choose a color: ");

		ActType = pManager->GetUserAction();

		chosen = false;
		
		switch (ActType)
		{
		case BLACKCLR:
			NewDraw = BLACK; chosen = true;
			pOut->PrintMessage("Changed draw color to black!");
			break;
		case REDCLR:
			NewDraw = RED; chosen = true;
			pOut->PrintMessage("Changed draw color to red!");
			break;
		case ORANGECLR:
			NewDraw = ORANGE; chosen = true;
			pOut->PrintMessage("Changed draw color to orange!");
			break;
		case YELLOWCLR:
			NewDraw = color(255, 215, 0); chosen = true;
			pOut->PrintMessage("Changed draw color to yellow!");
			break;
		case GREENCLR:
			NewDraw = color(0, 135, 68); chosen = true;
			pOut->PrintMessage("Changed draw color to green!");
			break;
		case BLUECLR:
			NewDraw = color(0, 87, 231); chosen = true;
			pOut->PrintMessage("Changed draw color to blue!");
			break;
		default:
			pOut->PrintMessage("You didn't pick a color.");
		}
		if (chosen) pOut->ClearDrawArea();
	}
}

void ChangeDrawClrAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();

	if (chosen)
	{
		saved = pManager->GetSelectedFig()->getfigure();
		CFigure* pFig = pManager->GetSelectedFig();

		if (!pFig)
			return;
		else
		{
		
			prevUIDraw = UI.DrawColor; //ziad use this
			prevFigDraw = pFig->GetDrawClr();
			UI.DrawColor = NewDraw;
			pFig->ChngDrawClr(NewDraw);
			pFig->UpdateFigGfxDrawClr(NewDraw);
			
		}
	}
	pManager->addtoundolist(this);
}



void ChangeDrawClrAction::UndoExcute()
{
	UI.FillColor = prevUIDraw;
	saved->ChngDrawClr(prevFigDraw);
	saved->UpdateFigGfxDrawClr(prevFigDraw);
}

void ChangeDrawClrAction::RedoExcute()
{

}

ChangeDrawClrAction::~ChangeDrawClrAction()
{
}

bool ChangeDrawClrAction::CheckRecordability() const
{
	return true;
}