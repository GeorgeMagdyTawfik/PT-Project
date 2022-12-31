#include "SaveAction.h"
#include "SelectFigAction.h"

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void SaveAction::ReadActionParameters()
{
	pOut->PrintMessage("Save Graph: please enter file name: ");

	filename = pIn->GetSrting(pOut);
	filename += ".txt";
}

void SaveAction::Execute(bool ReadParamsFirst)
{
	// this action will not be recorded but when switching from draw to play mode we need to 
	// save the current sketch in a file without asking the kid to do it explicitly
	if (ReadParamsFirst)
		ReadActionParameters();
	else
		filename = "temp.txt";

	CFigure* pFig = pManager->GetSelectedFig();

	if (pFig)								//If there is a selected figure, we need to unselect it
	{
		SelectFigAction* pAct = new SelectFigAction(pManager);
		pAct->UnselectPrevious(pFig);
		delete pAct;
	}

	OutFile.open(filename);

	if (OutFile)
	{

		OutFile << setw(10) << left << pOut->EncodeColor(pOut->getCrntDrawColor())
			<< setw(10) << pOut->EncodeColor(pOut->getCrntFillColor()) << endl
			<< pManager->GetFigCount() << endl << endl;

		pManager->SaveGraph(OutFile);

		if (ReadParamsFirst)
			pOut->PrintMessage("File saved successfully");
		OutFile.close();
	}
	else
	{
		pOut->PrintMessage("Error creating file!");
	}
}

void SaveAction::UndoExcute()
{
}

SaveAction::~SaveAction()
{}

void SaveAction::RedoExcute()
{}
