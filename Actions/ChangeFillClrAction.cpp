#include "ChangeFillClrAction.h"
#include "..\ApplicationManager.h"

ChangeFillClrAction::ChangeFillClrAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ChangeFillClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	ActionType ActType;

	pFig = pManager->GetSelectedFig();

	if (!pFig)
		pOut->PrintMessage("No selected figure. Please select a figure first!");

	else
	{
		
		pOut->PrintMessage("Change fill color: please choose a color: ");

		ActType = pManager->GetUserAction();

		chosen = false;

		switch (ActType)
		{
		case BLACKCLR:
			NewFill = BLACK; chosen = true;
			pOut->PrintMessage("Changed fill color to black!");
			break;
		case REDCLR:
			NewFill = RED; chosen = true;
			pOut->PrintMessage("Changed fill color to red!");
			break;
		case ORANGECLR:
			NewFill = ORANGE; chosen = true;
			pOut->PrintMessage("Changed fill color to orange!");
			break;
		case YELLOWCLR:
			NewFill = color(255, 215, 0); chosen = true;
			pOut->PrintMessage("Changed fill color to yellow!");
			break;
		case GREENCLR:
			NewFill = color(0, 135, 68); chosen = true;
			pOut->PrintMessage("Changed fill color to green!");
			break;
		case BLUECLR:
			NewFill = color(0, 87, 231); chosen = true;
			pOut->PrintMessage("Changed fill color to blue!");
			break;
		default:
			pOut->PrintMessage("You didn't pick a color.");
		}
		if (chosen) pOut->ClearDrawArea();
	}
}

void ChangeFillClrAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();

	if (chosen)
	{
		if (!pFig)
			return;
		else
		{
			//saved = pManager->GetSelectedFig()->getfigure();
			saved = pFig;

			figwasfilled = pFig->IsFilled();		//now we know whether the figure was filled or not
			defaultwasfilled = pFig->IsFilledAsDefault();

			prevUIFill = UI.FillColor;
			prevFigFill = pFig->GetFillClr();

			UI.FillColor = NewFill;
			pFig->SetFilledAsDefault();
			pFig->ChngFillClr(NewFill);
			pFig->UpdateFigGfxFillClr(NewFill);
			//pFig->ChngDrawClr(prevFigFill);
		}
	}

	RecordIfAllowed(this); /// Is it the correct line to add this

	pManager->addtoundolist(this);

}

void ChangeFillClrAction::UndoExcute()
{
	if (figwasfilled)
	{
		saved->ChngFillClr(prevFigFill);
		saved->UpdateFigGfxFillClr(prevFigFill);
		
	}
	else
	{
		saved->MakeNotFilled();
		saved->UnfillFigGfxInfo();
	}
	if (defaultwasfilled)
	{
		UI.FillColor = prevUIFill;
	}
	else
	{
		saved->SetNotFilledAsDefault();
	}
}

void ChangeFillClrAction::RedoExcute()
{
	saved->SetFilledAsDefault();
	saved->ChngFillClr(NewFill);
	saved->UpdateFigGfxFillClr(NewFill);
	UI.FillColor = NewFill;

}

ChangeFillClrAction::~ChangeFillClrAction()
{
}

bool ChangeFillClrAction::CheckRecordability() const
{
	return true;
}