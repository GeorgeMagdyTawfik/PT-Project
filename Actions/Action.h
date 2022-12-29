#ifndef ACTION_H
#define ACTION_H
#include "..\ApplicationManager.h"
#include "..\DefS.h"
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute(bool ReadParamsFirst = true) =0;
	virtual void UndoExcute() = 0;
	virtual void RedoExcute() = 0;

	virtual bool CheckRecordability() const = 0; // We don't need this anymore

	//virtual void Preview() {} now we don't need this 

	void RecordIfAllowed(Action* Aptr) // non virtual function in base class
	{
		Output* pOut = pManager->GetOutput();
		if (pManager->GetRecordedActionsCount() == 20 && pManager->GetRecordingState() == true)
		{
			pManager->SetRecordingState(false);
			pOut->PrintMessage("Recording Stopped; Reached maximum number of recorded actions (20)");
		}
		if (pManager->GetRecordingState() && pManager->GetRecordedActionsCount() < 20)
		{
			pManager->AddToRecordingList(Aptr);
		}
	}
};

#endif