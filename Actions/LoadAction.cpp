#include "LoadAction.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\cSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CTriangle.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void LoadAction::ReadActionParameters()
{								
	pOut->PrintMessage("Load Graph: please enter file name: ");
	filename = pIn->GetSrting(pOut);
	filename += ".txt";
}

void LoadAction::Execute(bool ReadParamsFirst)
{
	// This action will not be recorded but, when switching from play mode back to draw mode we will need to 
	// reload the saved drawing without asking the kid for the name of the file
	if (ReadParamsFirst)
		ReadActionParameters();
	else
		filename = "temp.txt";

	pOut->ClearDrawArea();
	pManager->DeleteAll();
	pManager->EmptyUndoList();

	InFile.open(filename);

	if (InFile)
	{
		string color1, color2;

		InFile >> color1 >> color2 >> FigCount;

		pOut->setCrntDrawColor(pOut->DecodeColor(color1)); //should this be here?
		pOut->setCrntFillColor(pOut->DecodeColor(color2));

		for (int i = 0; i < FigCount; i++) //loop on each line, read figure type, allocate object, load, then add
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
		pManager->SetFigcount(FigCount);
		if (ReadParamsFirst)
			pOut->PrintMessage("File loaded successfully!");
		InFile.close();
	}
	else
	{
		pOut->PrintMessage("Error loading file! Are you sure there's a file with that name?");
	}
}

void LoadAction::UndoExcute()
{
}

LoadAction::~LoadAction()
{
}
void LoadAction::RedoExcute()
{}

bool LoadAction::CheckRecordability() const
{
	return false;
}