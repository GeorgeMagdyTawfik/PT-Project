#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddSquareAction.h"
#include"Actions\AddCircleAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions\AddHexagonAction.h"
#include"Actions/UndoAction.h"
#include"Actions/RedoAction.h"

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
	for (int i = 0; i < 5; i++)
		undolist[i] = NULL;
	undocount = 0;
	undoexcuted = 0;
	redocount = 0;
	redoexcuted = 0;
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
	case UNDO:
		pAct = new UndoAction(this);
		break;
	case REDO:
		pAct = new RedoAction(this);
		break;

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
		if (ua == NULL&&ra==NULL)
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
				undolist[undocount] = pAct;
				undocount++;
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
	undoexcuted = 0;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
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
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::Undo()
{
	
	undolist[undocount - 1]->UndoExcute();
	redolist[redocount] = undolist[undocount - 1];
	redocount++;
	if (undocount > 1)
		undocount--;
	undoexcuted++;
	redoexcuted++;
	//FigCount--;
}

int ApplicationManager::GetFigCount()
{
	return FigCount;
}
int  ApplicationManager::GetUndoExcuted()
{
	return undoexcuted;

}
//////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::deletefigure()
{
	Been_undo_list[FigCount - 1] = FigList[FigCount - 1];
	//FigList[FigCount - 1] = NULL;
	FigCount--;
}
//////////////////////////////////////////////////////
void ApplicationManager::redo()
{
	redolist[redocount - 1]->RedoExcute();
	redoexcuted--;

}
void ApplicationManager::redofigure()
{
	
	undoexcuted = 0;
	Been_undo_list[FigCount ]->Draw(pOut);
	FigCount++;
}
int ApplicationManager::getredoexcuted()
{
	return  redoexcuted;
}