#include "SaveAction.h"

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

void SaveAction::Execute()
{
	ReadActionParameters();

	OutFile.open(filename);

	if (OutFile)
	{

		OutFile << setw(10) << left << pOut->EncodeColor(pOut->getCrntDrawColor())
			<< setw(10) << pOut->EncodeColor(pOut->getCrntFillColor()) << endl
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

void SaveAction::UndoExcute()
{
}

SaveAction::~SaveAction()
{
}

void SaveAction::RedoExcute()
{}