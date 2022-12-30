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

void PickByType::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//the random function will land on a number, and the message will be printed accordingly
	srand(time(0));
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("There are no more figures!");
		return;
	}
	int r = rand() % pManager->GetFigCount();
	char type = pManager->GetRandomType(r);
	pManager->CountTypes();

	switch (type)
	{
	case 'c':
		//pOut->PrintMessage("Pick by type: pick all circles!");
		TotalCount = pManager->GetCircleCount();
		pOut->PrintMessage("Pick by type: pick all circles!" + to_string(TotalCount));
		while (TotalCount > 0)
		{
			pIn->GetPointClicked(clicked.x, clicked.y);
			pFig = pManager->GetFigure(clicked.x, clicked.y);
			
			if (pFig == NULL)
			{
				pOut->PrintMessage("You clicked on an empty area. Try clicking on a circle!");
				continue;
			}
			CCircle* pCircle = dynamic_cast<CCircle*>(pFig);
			if (pCircle != NULL)
			{
				pManager->DeleteFigure(pFig);
				CorrectCount++;
				TotalCount--;
				pOut->PrintMessage("Bravo!          Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
					+ to_string(WrongCount) + "  " + to_string(TotalCount));
			}
			else
			{
				pManager->DeleteFigure(pFig);
				WrongCount++;
				pOut->PrintMessage("Try again!     Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
					+ to_string(WrongCount));
			}
			pManager->UpdateInterface();
		}
		pOut->PrintMessage("End of game:   Correct clicks: " + to_string(CorrectCount) + "    Wrong clicks: "
			+ to_string(WrongCount));
		break;
	case 'r':
		//pOut->PrintMessage("Pick by type: pick all rectangles!");
		TotalCount = pManager->GetRectCount();
		pOut->PrintMessage("Pick by type: pick all rectangles!" + to_string(TotalCount));
		while (TotalCount > 0)
		{
			pIn->GetPointClicked(clicked.x, clicked.y);
			pFig = pManager->GetFigure(clicked.x, clicked.y);

			if (pFig == NULL)
			{
				pOut->PrintMessage("You clicked on an empty area. Try clicking on a rectangle!");
				continue;
			}
			CRectangle* pRect = dynamic_cast<CRectangle*>(pFig);
			if (pRect != NULL)
			{
				pManager->DeleteFigure(pFig);
				CorrectCount++;
				TotalCount--;
				pOut->PrintMessage("Bravo!          Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
					+ to_string(WrongCount) + "  " + to_string(TotalCount));
			}
			else
			{
				pManager->DeleteFigure(pFig);
				WrongCount++;
				pOut->PrintMessage("Try again!     Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
					+ to_string(WrongCount));
			}
			pManager->UpdateInterface();
		}
		pOut->PrintMessage("End of game:   Correct clicks: " + to_string(CorrectCount) + "    Wrong clicks: "
			+ to_string(WrongCount));
		break;
	case 't':
		//pOut->PrintMessage("Pick by type: pick all triangles!");
		TotalCount = pManager->GetTriangleCount();
		pOut->PrintMessage("Pick by type: pick all triangles!" + to_string(TotalCount));
		while (TotalCount > 0)
		{
			pIn->GetPointClicked(clicked.x, clicked.y);
			pFig = pManager->GetFigure(clicked.x, clicked.y);

			if (pFig == NULL)
			{
				pOut->PrintMessage("You clicked on an empty area. Try clicking on a triangle!");
				continue;
			}
			CTriangle* pTriangle = dynamic_cast<CTriangle*>(pFig);
			if (pTriangle != NULL)
			{
				pManager->DeleteFigure(pFig);
				CorrectCount++;
				pOut->PrintMessage("Bravo!          Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
					+ to_string(WrongCount));
				TotalCount--;
			}
			else
			{
				pManager->DeleteFigure(pFig);
				WrongCount++;
				pOut->PrintMessage("Try again!     Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
					+ to_string(WrongCount));
			}
			pManager->UpdateInterface();
		}
		pOut->PrintMessage("End of game:   Correct clicks: " + to_string(CorrectCount) + "    Wrong clicks: "
			+ to_string(WrongCount));
		break;
	case 'h':
		//pOut->PrintMessage("Pick by type: pick all triangles!");
		TotalCount = pManager->GetHexaCount();
		pOut->PrintMessage("Pick by type: pick all hexagons!" + to_string(TotalCount));
		while (TotalCount > 0)
		{
			pIn->GetPointClicked(clicked.x, clicked.y);
			pFig = pManager->GetFigure(clicked.x, clicked.y);

			if (pFig == NULL)
			{
				pOut->PrintMessage("You clicked on an empty area. Try clicking on a hexagon!");
				continue;
			}
			CHexagon* pHexagon = dynamic_cast<CHexagon*>(pFig);
			if (pHexagon != NULL)
			{
				pManager->DeleteFigure(pFig);
				CorrectCount++;
				pOut->PrintMessage("Bravo!          Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
					+ to_string(WrongCount));
				TotalCount--;
			}
			else
			{
				pManager->DeleteFigure(pFig);
				WrongCount++;
				pOut->PrintMessage("Try again!     Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
					+ to_string(WrongCount));
			}
			pManager->UpdateInterface();
		}
		pOut->PrintMessage("End of game:   Correct clicks: " + to_string(CorrectCount) + "    Wrong clicks: "
			+ to_string(WrongCount));
		break;
	case 's':
		//pOut->PrintMessage("Pick by type: pick all triangles!");
		TotalCount = pManager->GetSquareCount();
		pOut->PrintMessage("Pick by type: pick all squares!" + to_string(TotalCount));
		while (TotalCount > 0)
		{
			pIn->GetPointClicked(clicked.x, clicked.y);
			pFig = pManager->GetFigure(clicked.x, clicked.y);

			if (pFig == NULL)
			{
				pOut->PrintMessage("You clicked on an empty area. Try clicking on a square!");
				continue;
			}
			CSquare* pSquare = dynamic_cast<CSquare*>(pFig);
			if (pSquare != NULL)
			{
				pManager->DeleteFigure(pFig);
				CorrectCount++;
				pOut->PrintMessage("Bravo!          Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
					+ to_string(WrongCount));
				TotalCount--;
			}
			else
			{
				pManager->DeleteFigure(pFig);
				WrongCount++;
				pOut->PrintMessage("Try again!     Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
					+ to_string(WrongCount));
			}
			pManager->UpdateInterface();
		}
		pOut->PrintMessage("End of game:   Correct clicks: " + to_string(CorrectCount) + "    Wrong clicks: "
			+ to_string(WrongCount));
		break;
	}
	pManager->ResetCounts();
}

void PickByType::UndoExcute()
{
}

void PickByType::RedoExcute()
{
}

bool PickByType::CheckRecordability() const
{
	return false;
}

PickByType::~PickByType()
{
}
