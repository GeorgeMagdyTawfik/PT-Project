#include "AddSquareAction.h"
#include "../Figures/CSquare.h"

#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include<Windows.h>
#include<iostream>

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center");

	//Read the center
	pIn->GetPointClicked(P1.x, P1.y);

	

	SquareGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
	pManager->addtoundolist(this);
}

//Execute the action
void AddSquareAction::Execute(bool ReadParamsFirst)
{
	//This action needs to read some parameters first
	if (ReadParamsFirst)
		ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CSquare* R = new CSquare(P1, SquareGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	saved = R->getpointerfig();
	if (pManager->getcaseofsound() == true)
	{
		bool played = PlaySound("draw the square.WAV", NULL, SND_SYNC);
		cout << played;
	}
	
	RecordIfAllowed(this);
}

void AddSquareAction::UndoExcute()
{

	pManager->DeleteByID(saved);
	saved = saved;
}
void AddSquareAction::RedoExcute()
{
	pManager->AddFigure(saved);

	saved = saved;

}

bool AddSquareAction::CheckRecordability() const
{
	return true;
}