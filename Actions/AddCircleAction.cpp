#include "AddCircleAction.h"
#include "../Figures/CCircle.h"
#include "../ApplicationManager.h"
#include "../GUI/input.h"
#include "../GUI/Output.h"
#include"../Actions/SelectFigAction.h"
#include<Windows.h>
#include<mmsystem.h>

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New circle: Click at center");

	
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New circle: Click at the point in the perimeter");

	
	pIn->GetPointClicked(P2.x, P2.y);

	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
	

}

//Execute the action
bool AddCircleAction::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();
	if (ReadParamsFirst)
		ReadActionParameters();

	
	CCircle* R = new CCircle(P1, P2, CircleGfxInfo);


	pManager->AddFigure(R);
	saved = R;

	RecordIfAllowed(this);
	if (pManager->GetStateOfSound() == true)
	{
		 PlaySound(TEXT("circle0.WAV"), NULL, SND_SYNC);	
	}
	pManager->addtoundolist(this);
	
	return true;
}
void AddCircleAction::UndoExcute()
{
	pManager->DeleteFigure(saved);
}
void AddCircleAction::RedoExcute()
{
	pManager->AddFigure(saved);
}

