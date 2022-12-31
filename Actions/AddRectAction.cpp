#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<Windows.h>
#include<iostream>

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
	pManager->addtoundolist(this);
}

//Execute the action
void AddRectAction::Execute(bool ReadParamsFirst)
{
	//This action needs to read some parameters first
	if (ReadParamsFirst)
		ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	saved = R->getpointerfig();
	if (pManager->getcaseofsound() == true)
	{
		bool played = PlaySound("draw the rectangle.WAV", NULL, SND_SYNC);
		cout << played;
	}
	RecordIfAllowed(this);
}
void AddRectAction::UndoExcute()
{

	pManager->DeleteByID(saved);
	saved = saved;
}
void AddRectAction::RedoExcute()
{
	pManager->AddFigure(saved);

	saved = saved;

}
