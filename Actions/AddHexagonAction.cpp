#include "AddHexagonAction.h"
#include "../Figures/CHexagon.h"
#include "../ApplicationManager.h"
#include "../GUI/input.h"
#include "../GUI/Output.h"
#include<Windows.h>
#include<mmsystem.h>

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
	pManager->addtoundolist(this);
}


void AddHexagonAction::Execute(bool ReadParamsFirst)
{
	if (ReadParamsFirst)
		ReadActionParameters();


	CHexagon* R = new CHexagon(P1, hexaGfxInfo);


	pManager->AddFigure(R);
	saved = R->getpointerfig();
	if (pManager->getcaseofsound() == true)
	{
	 PlaySound(TEXT("draw the hexagon.WAV"), NULL, SND_SYNC);
	
	}
	RecordIfAllowed(this);
}
void AddHexagonAction::UndoExcute()
{

	pManager->DeleteFigure(saved);
	saved = saved;
}
void AddHexagonAction::RedoExcute()
{
	pManager->AddFigure(saved);
	saved = saved;

}


bool AddHexagonAction::CheckRecordability() const
{
	return true;
}