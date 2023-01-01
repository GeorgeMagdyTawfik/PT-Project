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
	pManager->addtoundolist(this);

}

//Execute the action
void AddCircleAction::Execute(bool ReadParamsFirst)
{
	Output* pOut = pManager->GetOutput();
	if (ReadParamsFirst)
		ReadActionParameters();

	
	CCircle* R = new CCircle(P1, P2, CircleGfxInfo);


	pManager->AddFigure(R);
	saved = R;

	RecordIfAllowed(this);
	if (pManager->getcaseofsound() == true)
	{
		 PlaySound(TEXT("circle.WAV"), NULL, SND_SYNC);	
	}
}
void AddCircleAction::UndoExcute()
{
	pManager->DeleteFigure(saved);
}
void AddCircleAction::RedoExcute()
{
	pManager->AddFigure(saved);
}

