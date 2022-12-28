#include "AddTriangleAction.h"
#include "../Figures/CTriangle.h"
#include "../ApplicationManager.h"
#include "../GUI\input.h"
#include "../GUI/Output.h"

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
	pManager->addtoundolist(this);
}


void AddTriangleAction::Execute()
{
	ReadActionParameters();

	
	CTriangle* R = new CTriangle(P1, P2,P3, triangleGfxInfo);

	
	pManager->AddFigure(R);
}
void AddTriangleAction::UndoExcute()
{
	pManager->deletelastfigure();
}
void AddTriangleAction::RedoExcute()
{
	pManager->drawlast();
}
