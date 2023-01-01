#include "PickByType.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\cSquare.h"

PickByType::PickByType(ApplicationManager* pApp) : Action(pApp)
{
	CorrectCount = 0;
	WrongCount = 0;
}

void PickByType::ReadActionParameters()
{
}

bool PickByType::Execute(bool ReadParamsFirst)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	//the random function will land on a number, and the message will be printed accordingly
	
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("There are no more figures!");
		return false;
	}

	srand(time(0));
	int r = rand() % pManager->GetFigCount();
	char type = pManager->GetRandomType(r);
	pManager->CountTypes();

	switch (type)
	{
	case 'c':
		pOut->PrintMessage("Pick by type: pick all circles!");
		TotalCount = pManager->GetCircleCount();
		ExecuteBodyOfLoop(type, TotalCount);
		break;

	case 'r':
		pOut->PrintMessage("Pick by type: pick all rectangles!");
		TotalCount = pManager->GetRectCount();
		ExecuteBodyOfLoop(type, TotalCount);
		break;

	case 't':
		pOut->PrintMessage("Pick by type: pick all triangles!");
		TotalCount = pManager->GetTriangleCount();
		ExecuteBodyOfLoop(type, TotalCount);
		break;

	case 'h':
		pOut->PrintMessage("Pick by type: pick all hexagons!");
		TotalCount = pManager->GetHexaCount();
		ExecuteBodyOfLoop(type, TotalCount);
		break;

	case 's':
		pOut->PrintMessage("Pick by type: pick all squares!");
		TotalCount = pManager->GetSquareCount();
		ExecuteBodyOfLoop(type, TotalCount);
		break;

	}
	pManager->ResetCounts();
	pManager->ResetFillColors();

	return false;
}

void PickByType::UndoExcute()
{
}

void PickByType::RedoExcute()
{
}

void PickByType::ExecuteBodyOfLoop(char type, int TotalCount)
{

	while (TotalCount > 0)
	{
		pIn->GetPointClicked(clicked.x, clicked.y);
		pFig = pManager->GetFigure(clicked.x, clicked.y);

		if (pFig == NULL)
		{
			pOut->PrintMessage("You clicked on an empty area. Try clicking on a "
				+ pOut->TypeToString(type) + "!");
			continue;
		}

		if (pFig->GetMyType() == type)
		{
			pManager->DeleteFigure(pFig);
			CorrectCount++;
			TotalCount--;
			pOut->PrintMessage("Bravo! You are only " + to_string(TotalCount) +
				" correct clicks away from winning the game!");
		}

		else
		{
			pManager->DeleteFigure(pFig);
			WrongCount++;
			pOut->PrintMessage("Try again! Try clicking on a " + pOut->TypeToString(type) + "!");
		}
		pManager->UpdateInterface();
	}
	pOut->PrintMessage("You won! Here's your score:     Correct clicks: " + to_string(CorrectCount)
			+ "     Wrong clicks: " + to_string(WrongCount));
}


PickByType::~PickByType()
{
}
