#include "SwitchToDrawMode.h"

SwitchToDrawMode::SwitchToDrawMode(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToDrawMode::ReadActionParameters()
{
}

void SwitchToDrawMode::Execute(bool ReadParamsFirst)
{
}

void SwitchToDrawMode::UndoExcute()
{
}

void SwitchToDrawMode::RedoExcute()
{
}

bool SwitchToDrawMode::CheckRecordability() const
{
	return false;
}

SwitchToDrawMode::~SwitchToDrawMode()
{
}
