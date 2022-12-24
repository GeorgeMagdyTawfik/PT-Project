#include "SaveAction.h"

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	Draw = pOut->getCrntDrawColor();
	Fill = pOut->getCrntFillColor();

	if (Draw == color(0, 87, 231))
		ccode1 = "BLUE";

	if (Fill == color(0, 135, 68))
		ccode2 = "GREEN";
}

void SaveAction::ReadActionParameters()
{
	pOut->PrintMessage("Save Graph: please enter file name: ");

	filename = pIn->GetSrting(pOut);
	filename += ".txt";
}

void SaveAction::Execute()
{
	ReadActionParameters();

	OutFile.open(filename);

	if (OutFile)
	{

		OutFile << setw(10) << left << ccode1 << setw(10) << ccode2 << endl
			<< pManager->GetFigCount() << endl << endl;

		pManager->SaveGraph(OutFile);

		pOut->PrintMessage("File saved successfully");
		OutFile.close();
	}
	else
	{
		pOut->PrintMessage("Error creating file!");
	}
}

SaveAction::~SaveAction()
{
}

