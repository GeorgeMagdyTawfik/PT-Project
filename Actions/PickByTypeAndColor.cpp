#include "PickByTypeAndColor.h"

PickByTypeAndColor::PickByTypeAndColor(ApplicationManager* pApp) : Action(pApp)
{
	CorrectCount = 0;
	WrongCount = 0;
}

void PickByTypeAndColor::ReadActionParameters()
{
}

void PickByTypeAndColor::Execute(bool ReadParamsFirst)
{
}

void PickByTypeAndColor::UndoExcute()
{
}

void PickByTypeAndColor::RedoExcute()
{
}

PickByTypeAndColor::~PickByTypeAndColor()
{
}
