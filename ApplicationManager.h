#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
//#include "Actions/Action.h"
class Action;

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

	enum { MaxUndoCount = 5 };	//Max no of figures
	enum { MaxRecord = 20 }; // Maximum number of recorded actions
private:
	int FigCount;		//Actual number of figures
	int RecordedActionsCount;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	Action** RecordingList = new Action*[MaxRecord]; /// all the currently recorded actions
	//CFigure* Been_undo_list[MaxFigCount];
	CFigure* SelectedFig; //Pointer to the selected figure
	bool RecordingState;
	bool playsound;
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
	Action* undolist[MaxUndoCount];
	int undocount;
	//int undoexcuted; //number of undo action that achueved
	//Action* redolist[5];
	int redocount;
	//int redoexcuted;
	CFigure* deletedlist[5];
	int deletecount;
	
	Action* LastAction;
	//void ToRecord_orNot(Action* last);
public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure


	//These 2 functions are EXTRA but needed
	void SetSelectedFigure(CFigure*);
	// 
	CFigure* GetSelectedFig() const;

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	// -- Functions which Loop on FigList
	void SaveGraph(ofstream& OutFile);
	void DeleteAll();

	// -- Setters and Getters
	int GetFigCount() const;
	void SetFigcount(int x); //this is needed for loading
	void SetRecordingState(bool b);
	bool GetRecordingState() const;
	int GetRecordedActionsCount() const;
	// Action** GetRecordingList() const; NOT ALLOWED
	void PreviewRecordedActs();
	void RemovePastRecording(); /// Important ; will call this when starting a new recording & in CLEARALL
	void SetRecordedActionsCount(int); /// Important
	void AddToRecordingList(Action*);

	// -- Functions which Loop on FigList
	void DeleteFigure(CFigure* pFig);
	//
	//int GetUndoExcuted();
	//void SetUndoExcuted();
	void deletelastfigure();
	//Action* GetExcutedAction();
	
	//////////////////////////
//void setExcutedeundoAction(Action*);
	//Action* getundoedaction();
	//void setExcutedeundoAction(Action*);
	//Action* getundoedaction();
	void drawlast();
	
	int getredocount();
	//int getredoExcuted();
	///////////////////////////////////
	int getundocount();
	//void setredoExcute();
	////////////////////////////////
	void addtoundolist(Action*);
	void Undo();
	void Redo();
	//void DeleteByID(CFigure*);
	void EmptyUndoList();
	void changethestateofsound();
	bool getcaseofsound();
};

#endif
