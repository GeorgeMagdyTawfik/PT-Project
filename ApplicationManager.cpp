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
#include"Actions/SoundAction.h"
#include"Actions/movebydragging.h"

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
	playsound = false;
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
	case SOUND:
		pAct = new SoundAction(this);
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
	case MOVE_BY_DRAGGING:
		pAct = new movebydragging(this);
		break;
		
	case EXIT:
		///create ExitAction here
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
	{
		FigList[FigCount++] = pFig;
		pFig->SetSelected(false);  //add this line enyone check
		pFig->UseFigGfxInfo();
	}
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
			FigList[i]->SetSelected(false);
			FigList[i]->UseFigGfxInfo();
			FigList[FigCount - 1] = NULL;
			SelectedFig = NULL;
			
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
	FigCount = 0;
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
//////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::getredocount()
{
	return redocount;
}
int ApplicationManager::getundocount()
{
	return undocount;
}
void ApplicationManager::addtoundolist(Action* ac)
{
	redocount = 0;
	if (undocount > 4)
	{
		if (RecordingState == false)
			delete undolist[0]; // senario :: if it is recored ???
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
	
	undolist[--undocount]->UndoExcute();
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

bool ApplicationManager::SearchForActInRecording(Action* pAct)
{
	bool found = false;

	for (int i = 0; i < RecordedActionsCount; i++)
	{
		if (RecordingList[i] == pAct)
			return true;
	}
	return false;
}

void ApplicationManager::PreviewRecordedActs()
{
	for (int i = 0; i < RecordedActionsCount; i++)
	{
		_sleep(1000);
		RecordingList[i]->Execute(0);
		UpdateInterface();
	}
}

void ApplicationManager::RemovePastRecording()
{
	for (int i = 0; i < RecordedActionsCount; i++)
	{
		delete RecordingList[i];
		RecordingList[i] = NULL;
	}
	RecordedActionsCount = 0;
}

void ApplicationManager::EmptyUndoList()
{
	//the implementation of this function makes it search first for the ptrs 
	//contained in the undolist in the recording list
	bool found;

	for (int i = 0; i < undocount; i++)
	{
		found = SearchForActInRecording(undolist[i]);
		if (!found)
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

void ApplicationManager::ChangeStateOfSound()
{
	if (playsound == true)
		playsound = false;
	else
		playsound = true;
}

void ApplicationManager::SetStateOfSound(bool b)
{
	playsound = b;
}

bool ApplicationManager::GetStateOfSound()
{
	return playsound;
}
