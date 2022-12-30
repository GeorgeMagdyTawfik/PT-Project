#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddRectAction : public Action
{
private:
	 Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CFigure* saved;
	CFigure* savedredo;
public:
	AddRectAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();

	virtual bool CheckRecordability() const;
};

#endif