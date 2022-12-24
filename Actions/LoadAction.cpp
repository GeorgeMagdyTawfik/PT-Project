#include "LoadAction.h"
#include "..\Figures\CRectangle.h"
#include "..\CCircle.h"
#include "..\cSquare.h"
#include "..\CHexagon.h"
#include "..\CTriangle.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void LoadAction::ReadActionParameters()
{
	pOut->ClearDrawArea();
	pManager->DeleteAll();		//Any more needed cleanups??
	pOut->PrintMessage("Load Graph: please enter file name: ");
	filename = pIn->GetSrting(pOut);
	filename += ".txt";
}

void LoadAction::Execute()
{
	ReadActionParameters();

	InFile.open(filename);

	if (InFile)
	{
		InFile >> ccode1 >> ccode2 >> FigCount;

		color c1, c2;
		if (ccode1 == "BLUE")
			c1 = color(0, 87, 231);
		if (ccode2 == "GREEN")
			c2 = color(0, 135, 68);

		pOut->setCrntDrawColor(c1); //should this be here?
		pOut->setCrntFillColor(c2);

		for (int i = 0; i < FigCount; i++) //loop on each line, read figure type, allocate object, load, add
		{
			InFile >> FigName;

			if (FigName == "RECT") 
			{
				CRectangle* R = new CRectangle;
				R->Load(InFile);
				pManager->AddFigure(R);
			}
			if (FigName == "CIRCLE") 
			{
				CCircle* R = new CCircle;
				R->Load(InFile);
				pManager->AddFigure(R);
			}
			if (FigName == "SQUARE")
			{
				CSquare* R = new CSquare;
				R->Load(InFile);
				pManager->AddFigure(R);
			}
			if (FigName == "TRIANG")
			{
				CTriangle* R = new CTriangle;
				R->Load(InFile);
				pManager->AddFigure(R);
			}
			if (FigName == "HEXAGON")
			{
				CHexagon* R = new CHexagon;
				R->Load(InFile);
				pManager->AddFigure(R);
			}
		}

		pOut->PrintMessage("File loaded successfully!");
		InFile.close();
	}
	else
	{
		pOut->PrintMessage("Error loading file!");
	}
}

LoadAction::~LoadAction()
{
}
