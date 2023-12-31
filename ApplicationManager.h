#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures

	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)


	int selectedCount;					//Number of selected figures				*** Important ***
	CFigure* SelectedFigures[MaxFigCount];	//List of all selected figures			*** Important ***

	int FigCountBackup;		//Actual number of figures
	CFigure* FigListBackup[MaxFigCount];	//Clone version of FigList (Array of pointers)
	CFigure* selectedfigure; //The Selected Figure

	//Pointers to Input and Output classes
	GUI* pGUI;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application

	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action

	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure

		


	//Colors Functions 
	bool ApplicationManager::GetColor(color& inputColor);
	void ApplicationManager::changeFillColor(color FillClr);
	bool ApplicationManager::AnySelected();
	void ApplicationManager::changeDrawColor(color drawClr);

	// Bring back and forward functions
	int GetSelectedFigureIndex();
	//void BringToFront(int);
	//void SendToBack(int);

	// Select Figure Functions
	CFigure* const* ApplicationManager::GetSelectedFigures() const;
	int ApplicationManager::GetSelectedCount() const;
	void ApplicationManager::AddSelectedFigure(CFigure* sf);
	void RemoveSelectedFigure(CFigure* sf);
	void setselectedfigure(CFigure* pFig);
	CFigure* getselectedfigure() const;
	string getColorName(color c);
	//void UnselectAll();
	
	//Delete Functions 
	void ApplicationManager::RemoveFig(int ID);
	void ApplicationManager::ClearSelectedFigs();


	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window	


//play mode functions


	int getSelectedFigure();
	CFigure* GetSelectedFigure() const;

};

#endif