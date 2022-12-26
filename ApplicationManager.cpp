#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddSquareAction.h"
#include"Actions\AddCircleAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions\AddHexagonAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"

#include "Actions/SelectFigAction.h"
#include "Actions/DeleteAction.h"
#include"Actions/Action.h"
#include"Actions/UndoAction.h"
#include"Actions/RedoAction.h"
#include"Actions/ClearAllAction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	//this is EXTRA
	SetSelectedFigure(NULL);
	for (int i = 0; i < 5; i++)
		undolist[i] = NULL;
	undocount = 0;
	undoexcuted = 0;
	redocount = 0;
	
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
	case UNDO:
		pAct = new UndoAction(this);
		break;
	case REDO:
	pAct=new RedoAction(this);
		break;
	case CLEAR_ALL:
		pAct = new ClearAllAction(this);
	case EXIT:
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		UndoAction* ua = dynamic_cast<UndoAction*>(pAct);
		RedoAction* ra = dynamic_cast<RedoAction*>(pAct);
		if (ua == NULL && ra == NULL)
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

		}
		//delete pAct;	//You may need to change this line depending to your implementation
		//pAct = NULL;
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
	
	undoexcuted =0;
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

void ApplicationManager::UnselectPrevious()
{
	if (SelectedFig != NULL)
	{
		SelectedFig->SetSelected(false);
		SelectedFig->ChngDrawClr(UI.DrawColor);
		SetSelectedFigure(NULL);
	}
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

int  ApplicationManager::GetUndoExcuted()
{
	return undoexcuted;

}

void  ApplicationManager::SetUndoExcuted()
{
	undoexcuted++;

}
//////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::deletefigure()
{
	FigCount--;
	//FigList[FigCount - 1] = NULL;
}
Action* ApplicationManager::GetExcutedAction()
{
	return undolist[undocount - 1];

}
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
Action* ApplicationManager::getundoedaction()
{

	return redolist[redocount - 1];
}
void ApplicationManager::drawlast()
{
	FigList[FigCount++]->Draw(pOut);
	redocount--;
	undoexcuted-- ;
}
int ApplicationManager::getredocount()
{
	return redocount;
}
