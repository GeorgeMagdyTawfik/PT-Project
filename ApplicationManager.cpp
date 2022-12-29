#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddSquareAction.h"
#include"Actions\AddCircleAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions\AddHexagonAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions/SelectFigAction.h"
#include "Actions/SwitchToPlayMode.h"
#include "Actions/DeleteAction.h"
#include"Actions/Action.h"
#include"Actions/UndoAction.h"
#include"Actions/RedoAction.h"
#include"Actions/ClearAllAction.h"
#include "Actions/ChangeDrawClrAction.h"
#include "Actions/ChangeFillClrAction.h"
#include "Actions/MoveAction.h"
#include "Actions/StartRecordingAction.h"
#include "Actions/StopRecordingAction.h"
#include "Actions/PlayRecordingAction.h"
#include "Actions\SwitchToDrawMode.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	RecordedActionsCount = 0;
	//create an array of action pointers and set them to NULL
	for (int i = 0; i < MaxRecord; i++)
		RecordingList[i] = NULL;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	//this is EXTRA
	SetSelectedFigure(NULL);
	for (int i = 0; i < 5; i++)
		undolist[i] = NULL;
	undocount = 0;
	
	redocount = 0;
	deletecount = 0;



	LastAction = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case SAVE_GRAPH:
		pAct = new SaveAction(this);
		break;
	case LOAD_GRAPH:
		pAct = new LoadAction(this);
		break;
	case DELETE_SHAPE:
		pAct = new DeleteAction(this);
		break;
	case CHANGE_DRAW_CLR:
		pAct = new ChangeDrawClrAction(this);
		break;
	case CHANGE_FILL_CLR:
		pAct = new ChangeFillClrAction(this);
		break;
	case MOVE:
		pAct = new MoveAction(this);
		break;
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_SQUARE:
		pAct = new AddSquareAction(this);
		break;
	case DRAW_CIRCLE:
		pAct = new AddCircleAction(this);
		break;
	case DRAW_TRIANGLE:
		pAct = new AddTriangleAction(this);
		break;
	case DRAW_HEXAGON:
		pAct = new AddHexagonAction(this);
		break;
	case SELECT:
		pAct = new SelectFigAction(this);
		break;
	case TO_PLAY:
		pAct = new SwitchToPlayMode(this);
		break;
	case TO_DRAW:
		pAct = new SwitchToDrawMode(this);
		break;
	case UNDO:
		pAct = new UndoAction(this);
		break;
	case BLACKCLR:
		pOut->PrintMessage("Please select an operation first!");
		break;
	case REDCLR:
		pOut->PrintMessage("Please select an operation first!");
		break;
	case ORANGECLR:
		pOut->PrintMessage("Please select an operation first!");
		break;
	case YELLOWCLR:
		pOut->PrintMessage("Please select an operation first!");
		break;
	case GREENCLR:
		pOut->PrintMessage("Please select an operation first!");
		break;
	case BLUECLR:
		pOut->PrintMessage("Please select an operation first!");
		break;
	case REDO:
		pAct = new RedoAction(this);
		break;
	case CLEAR_ALL:
		pAct = new ClearAllAction(this);
		break; // don't forget this
	case START_REC:
		pAct = new StartRecordingAction(this);
		break;
	case STOP_REC:
		pAct = new StopRecordingAction(this);
		break;
	case PLAY_REC:
		pAct = new PlayRecordingAction(this);
		break;
	case EXIT:
		///create ExitAction here
		for (int i = 0; i < RecordedActionsCount; i++)
		{
			delete RecordingList[i];
		}
		delete[]RecordingList;
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		
		/*UndoAction* ua = dynamic_cast<UndoAction*>(pAct);
		RedoAction* ra = dynamic_cast<RedoAction*>(pAct);
		SelectFigAction* SFA = dynamic_cast<SelectFigAction*>(pAct);
		if (ua == NULL && ra == NULL&&SFA==NULL)
		{
			if (undocount > 4)
			{
				undolist[0] = NULL;
				for (int i = 0; i < 3; i++)
				{
					undolist[i] = undolist[i + 1];

				}
				undolist[4] = pAct;
				undocount = 4;
			}
			else
			{
				undolist[undocount++] = pAct;

			}

		}*/
		//delete pAct;	//You may need to change this line depending to your implementation
		//pAct = NULL; 
		LastAction = pAct;

		ToRecord_orNot(LastAction); // Auto check

		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->CheckInside(x, y) == true)
		{
			return FigList[i];
		}
	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}

void ApplicationManager::SetSelectedFigure(CFigure* pFig)
{
	SelectedFig = pFig;
}

CFigure* ApplicationManager::GetSelectedFigure() const
{
	return SelectedFig;
}


// this function is repeated,I left it to resolve a conflict
CFigure* ApplicationManager::GetSelectedFig() const
{
	return SelectedFig;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea(); /// this is important
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);	//Call Draw function (virtual member fn)



}
bool ApplicationManager::DeleteFigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			if (i != FigCount - 1)
				FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			SelectedFig = NULL;
			FigCount--;
			return true;
		}
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							Functions which Loop on FigList 						//
//==================================================================================//

void ApplicationManager::SaveGraph(ofstream& OutFile)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}
}

void ApplicationManager::DeleteAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	undocount = 0;
	redocount = 0;
	SetFigcount(0);/// This was desparately needed

}

int ApplicationManager::GetFigCount() const
{
	return FigCount;
}

void ApplicationManager::SetFigcount(int x)
{
	FigCount = x;
}

//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
////////////////////////////////////////////////////////////////////////////////////
/*void ApplicationManager::Undo()
{
	AddRectAction* adr = dynamic_cast<AddRectAction*>(undolist[undocount - 1]);
	if (adr != NULL)
	{
		FigList[FigCount - 1] = NULL;
		FigCount--;
		if(undocount>1)
		undocount--;
		undoexcuted++;
	}
	AddSquareAction* ads = dynamic_cast<AddSquareAction*>(undolist[undocount - 1]);
	if (ads != NULL)
	{
		FigList[FigCount - 1] = NULL;
		if (undocount > 1)
		undocount--;
		FigCount--;
		undoexcuted++;
	}
	AddTriangleAction* adt = dynamic_cast<AddTriangleAction*>(undolist[undocount - 1]);
	if (adt != NULL)
	{
		FigList[FigCount - 1] = NULL;
		if (undocount >1)
		undocount--;
		FigCount--;
		undoexcuted++;
	}
	AddCircleAction* adc = dynamic_cast<AddCircleAction*>(undolist[undocount - 1]);
	if (adc != NULL)
	{
		FigList[FigCount - 1] = NULL;
		if (undocount > 1)
		undocount--;
		FigCount--;
		undoexcuted++;
	}
	AddHexagonAction* adh = dynamic_cast<AddHexagonAction*>(undolist[undocount - 1]);
	if (adh != NULL)
	{
		FigList[FigCount - 1] = NULL;
		if (undocount > 1)
		undocount--;
		FigCount--;
		undoexcuted++;
	}

	//undolist[undocount - 1]->UndoExcute();
	//if (undocount > 1)
		//undocount--;
	//undoexcuted++;

}*/

/*int  ApplicationManager::GetUndoExcuted()
{
	return undoexcuted;

}
*/

/*void  ApplicationManager::SetUndoExcuted()
{
	undoexcuted++;

}
*/
//////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::deletelastfigure()
{
	FigCount--;
	
	//FigList[FigCount - 1] = NULL;
}
/*Action* ApplicationManager::GetExcutedAction()
{
	return undolist[undocount - 1];

}
*/

bool ApplicationManager::MoveFigure(Point destination)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->Move(destination);
			FigList[i]->ChngDrawClr(UI.DrawColor);
			FigList[i]->UseFigGfxInfo();
			return true;
		}
	}
	return false;
}
/*void ApplicationManager::setExcutedeundoAction(Action* undoed)
void ApplicationManager::setExcutedeundoAction(Action* undoed)
{

	if (redocount > 4)
	{
		redolist[0] = NULL;
		for (int i = 0; i < 3; i++)
		{
			redolist[i] = redolist[i + 1];

		}
		redolist[4] = undoed;
		redocount = 4;
	}
	else
	{
		redolist[redocount++] = undoed;

	}

}
*/
/*Action* ApplicationManager::getundoedaction()
{

	return redolist[redocount - 1];
}
*/
void ApplicationManager::drawlast()
{
	FigList[FigCount++]->Draw(pOut);
	//redocount--;
	//undoexcuted--;
}
int ApplicationManager::getredocount()
{
	return redocount;
}
/*int ApplicationManager::getredoExcuted()
{
	return redoexcuted;
}
*/
int ApplicationManager::getundocount()
{
	return undocount;
}
/*void ApplicationManager::setredoExcute()
{
	redoexcuted++;
}
*/
void ApplicationManager::addtoundolist(Action*ac)
{
	redocount = 0;
		if (undocount > 4)
		{
			undolist[0] = NULL;
			for (int i = 0; i <= 3; i++)
			{
				undolist[i] = undolist[i + 1];

			}
			undolist[4] = ac;
			undocount = 4;
			undocount++;
		}
		else
		{
			undolist[undocount++] = ac;

		}

	
}
void ApplicationManager::Undo()
{
	undolist[undocount-- - 1]->UndoExcute();
	redocount++;
}
void ApplicationManager::Redo()
{
	undolist[undocount++]->RedoExcute();
	redocount--;
}

///////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::SetRecordingState(bool b)
{
	RecordingState = b;
}

int ApplicationManager::GetRecordedActionsCount() const
{
	return RecordedActionsCount;
}

bool ApplicationManager::GetRecordingState() const
{
	return RecordingState;
}

void ApplicationManager::ToRecord_orNot(Action* last)
{
	if (last->CheckRecordability() && RecordingState && RecordedActionsCount < 20)
	{
		RecordingList[RecordedActionsCount++] = last; // Store the last action in the list

		if (RecordedActionsCount == 20) // when reaching maxRecord Warn the user then stop
		{
			pOut->PrintMessage("Recording Stopped automatically (20 actions were recorded)");
			SetRecordingState(false);
		}
	}
}

void ApplicationManager::PreviewRecordedActs()
{
	DeleteAll();
	pOut->ClearDrawArea();
	pOut->PrintMessage("Started Playing");
	for (int i = 0; i < RecordedActionsCount; i++)
	{
		_sleep(1000);
		RecordingList[i]->Execute(0);
		UpdateInterface();
	}
	pOut->PrintMessage("Finished the recorded actions");
}

void ApplicationManager::RemovePastRecording()
{
	for (int i = 0; i < RecordedActionsCount; i++)
	{
		delete RecordingList[i];
		RecordingList[i] = NULL;
	}
	SetRecordedActionsCount(0);
}

void ApplicationManager::SetRecordedActionsCount(int a)
{
	RecordedActionsCount = a;
}