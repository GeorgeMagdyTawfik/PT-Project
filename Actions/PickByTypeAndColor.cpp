#include "PickByTypeAndColor.h"

PickByTypeAndColor::PickByTypeAndColor(ApplicationManager* pApp) : Action(pApp)
{
	CorrectCount = 0;
	WrongCount = 0;
	
}

void PickByTypeAndColor::ReadActionParameters()
{
}

void PickByTypeAndColor::Execute(bool ReadParamsFirst)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("There are no more figures!");
		return;
	}

	pManager->CountFillColors();
	pManager->CountTypes();

	int NoFillFigs = pManager->GetNoFillFigs();
	if (NoFillFigs == pManager->GetFigCount())
	{
		pOut->PrintMessage("There are no colored figures!");
		return;
	}

	int r;
	char type;
	FillColors clr;

	srand(time(0));
	do
	{
		r = rand() % pManager->GetFigCount();
		clr = pManager->GetRandomFillColor(r);

	} while (clr == UNFILLED);

	type = pManager->GetRandomType(r);

	pOut->PrintMessage("Pick by type and Color: pick all " + pOut->FillColorToString(clr) +
		" " + pOut->TypeToString(type) + "s!");
	
	TotalCount = pManager->GetCountForTypeAndColor(type, clr);

	while (CorrectCount < TotalCount)
	{
		pIn->GetPointClicked(clicked.x, clicked.y);
		pFig = pManager->GetFigure(clicked.x, clicked.y);

		if (!pFig)
		{
			pOut->PrintMessage("You clicked on an empty area. Try clicking on a " +
				pOut->FillColorToString(clr) + " " + pOut->TypeToString(type) + " !");
			continue;
		}
		if (pFig->GetMyType() == type && pFig->IsFilled() && pFig->GetFillClrENUM() == clr)
		{
			pManager->DeleteFigure(pFig);
			CorrectCount++;
			pOut->PrintMessage("Bravo! You are only " + to_string(TotalCount - CorrectCount) +
				" correct clicks away from winning the game!");
		}
		else
		{
			pManager->DeleteFigure(pFig);
			WrongCount++;
			pOut->PrintMessage("Try again! Try clicking on a " +
				pOut->FillColorToString(clr) + " " + pOut->TypeToString(type) + "!");
		}
		pManager->UpdateInterface();
	}
	pOut->PrintMessage("You won! Here's your score:     Correct clicks: " + to_string(CorrectCount)
		+ "     Wrong clicks: " + to_string(WrongCount));

	pManager->ResetCounts();
	pManager->ResetFillColors();
}

void PickByTypeAndColor::UndoExcute()
{
}

void PickByTypeAndColor::RedoExcute()
{
}

PickByTypeAndColor::~PickByTypeAndColor()
{
}
