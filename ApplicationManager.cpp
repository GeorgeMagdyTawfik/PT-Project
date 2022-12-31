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
#include "Actions/PickByType.h"
#include "Actions/PickByColor.h"
#include "Actions/PickByTypeAndColor.h"

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

	RecordingState = false;

	LastAction = NULL;

	ResetCounts();

	ResetFillColors();
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
	case PICK_BY_TYPE:
		pAct = new PickByType(this);
		break;
	case PICK_BY_CLR:
		pAct = new PickByColor(this);
		break;
	case PICK_BY_TYPE_AND_CLR:
		pAct = new PickByTypeAndColor(this);
		break;
	case EXIT:
		///create ExitAction here
		/*for (int i = 0; i < RecordedActionsCount; i++)
		{
			delete RecordingList[i];
		}
		delete[]RecordingList;*/
		pAct = new ClearAllAction(this);
		pAct->Execute();
		pAct = NULL;
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
void ApplicationManager::DeleteFigure(CFigure* pFig)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == pFig)
		{
			//delete FigList[i];
			if (i != FigCount - 1)
				FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			SelectedFig = NULL;						//does this cause a problem?
			
			FigCount--;
		}
	}
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


}
/*Action* ApplicationManager::GetExcutedAction()
{
	return undolist[undocount - 1];

}
*/
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
void ApplicationManager::addtoundolist(Action* ac)
{
	redocount = 0;
	if (undocount > 4)
	{
		/*if (RecordingState == false)
			delete undolist[0]; // senario :: if it is recored ??? */
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

void ApplicationManager::AddToRecordingList(Action* ptr)
{
	if (RecordedActionsCount < 20)
		RecordingList[RecordedActionsCount++] = ptr;
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
void ApplicationManager::DeleteByID(CFigure* c)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetID() == c->GetID())
		{
			//delete FigList[i];
			if (i != FigCount - 1)
				FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			//SelectedFig = NULL;
			
			FigCount--;
			


		}

	}
}
void ApplicationManager::EmptyUndoList()
{
	for (int i = 0; i < undocount; i++)
	{
		delete undolist[i];
		undolist[i] = NULL;
	}
	undocount = 0;
	redocount = 0;
}

void ApplicationManager::CountTypes()
{
	ResetCounts(); // solves a simple bug
	for (int i = 0; i < FigCount; i++)
	{
		char type = FigList[i]->GetMyType();

		if (type == 'c')
			CircleCount++;
		if (type == 'r')
			RectCount++;
		if (type == 'h')
			HexaCount++;
		if (type == 't')
			TriangleCount++;
		if (type == 's')
			SquareCount++;
	}
}

void ApplicationManager::CountFillColors()
{
	ResetFillColors(); // solves a simple bug
	for (int i = 0; i < FigCount; i++)
	{
		if (!FigList[i]->IsFilled())
			NoFillFigs++;
		else
		{
			color c = FigList[i]->GetFillClr();

			if (c == BLACK)
				BlackFigs++;
			if (c == RED)
				RedFigs++;
			if (c == ORANGE)
				OrangeFigs++;
			if (c == color(255, 215, 0))
				YellowFigs++;
			if (c == color(0, 87, 231))
				BlueFigs++;
			if (c == color(0, 135, 68))
				Greenfigs++;
		}
	}
}

FillColors ApplicationManager::GetRandomFillColor(int index)
{
	return FigList[index]->GetFillClrENUM();
}

char ApplicationManager::GetRandomType(int index)
{
	return FigList[index]->GetMyType();
}

int ApplicationManager::GetCircleCount() const
{
	return CircleCount;
}

int ApplicationManager::GetRectCount() const
{
	return RectCount;
}

int ApplicationManager::GetHexaCount() const
{
	return HexaCount;
}

int ApplicationManager::GetSquareCount() const
{
	return SquareCount;
}

int ApplicationManager::GetTriangleCount() const
{
	return TriangleCount;
}

int ApplicationManager::GetBlackFigs()
{
	return BlackFigs;
}

int ApplicationManager::GetRedFigs()
{
	return RedFigs;
}

int ApplicationManager::GetOrangeFigs()
{
	return OrangeFigs;
}

int ApplicationManager::GetYellowFigs()
{
	return YellowFigs;
}

int ApplicationManager::GetGreenFigs()
{
	return Greenfigs;
}

int ApplicationManager::GetBlueFigs()
{
	return BlueFigs;
}

int ApplicationManager::GetNoFillFigs()
{
	return NoFillFigs;
}

void ApplicationManager::ResetCounts()
{
	SquareCount = 0;
	CircleCount = 0;
	HexaCount = 0;
	TriangleCount = 0;
	RectCount = 0;
}

void ApplicationManager::ResetFillColors()
{
	NoFillFigs = 0;
	RedFigs = 0;
	BlackFigs = 0;
	BlueFigs = 0;
	Greenfigs = 0;
	YellowFigs = 0;
	OrangeFigs = 0;
}

int ApplicationManager::GetCountForTypeAndColor(char type, FillColors clr)
{
	int TotalCount = 0;

	for (int i = 0; i < FigCount; i++)
	{
		if ((FigList[i]->GetMyType() == type) && (FigList[i]->GetFillClrENUM() == clr))
			TotalCount++;
	}
	return TotalCount;
}
