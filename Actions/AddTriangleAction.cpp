#include "AddTriangleAction.h"
#include "../Figures/CTriangle.h"
#include "../ApplicationManager.h"
#include "../GUI\input.h"
#include "../GUI/Output.h"
#include<Windows.h>
#include<mmsystem.h>
AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriangleAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first point");

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second point");

	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third point");

	pIn->GetPointClicked(P3.x, P3.y);

	triangleGfxInfo.isFilled = false;
	triangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	triangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
	
	if (pManager->GetStateOfSound() == true)
	{
		 PlaySound(TEXT("triangle0.WAV"), NULL, SND_SYNC);
	}
}


bool AddTriangleAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();
	
	CTriangle* R = new CTriangle(P1, P2,P3, triangleGfxInfo);

	pManager->AddFigure(R);
	saved = R;
	
	RecordIfAllowed(this);
	pManager->addtoundolist(this);

	return true;
}
void AddTriangleAction::UndoExcute()
{
	pManager->DeleteFigure(saved);
}
void AddTriangleAction::RedoExcute()
{
	pManager->AddFigure(saved);
}
