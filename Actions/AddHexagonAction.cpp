#include "AddHexagonAction.h"
#include "..\Figures\CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexagonAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at center");

	pIn->GetPointClicked(P1.x, P1.y);



	hexaGfxInfo.isFilled = false;
	hexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	hexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}


void AddHexagonAction::Execute()
{
	ReadActionParameters();


	CHexagon* R = new CHexagon(P1, hexaGfxInfo);


	pManager->AddFigure(R);
}
