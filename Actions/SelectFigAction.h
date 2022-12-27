#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"
// Select one figure action class
class SelectFigAction : public Action
{
private:
	// I only need to know where the kid clicked
	Point Clicked;
public:
	SelectFigAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	void UnselectPrevious(CFigure* previous);
  
	virtual void UndoExcute();
	virtual void RedoExcute();

	virtual bool CheckRecordability() const;
};