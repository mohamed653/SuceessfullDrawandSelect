#ifndef GUI_H
#define GUI_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"


//This class is responsible for Grphical User Interface handling
//All user input and program outputs MUST be done through this class
//No other class is allowed to perform direct i/o
class GUI	
{
public:	
	window* pWind;	//Pointer to the Graphics Window
public:
	GUI();	
	~GUI();	
	window* CreateWind(int, int, int , int) const; //creates the application window

	/////////// Input Functoinality  /////////////////
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting() const ;	 //Returns a string entered by the user
	ActionType MapInputToActionType() const; //Read the user click and map to an action


	/////////// Output Functoinality  ////////////////
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateColorBar() const; //create Color Bar
	/////
	void CreateResizeToolBar() const;

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	/////
	void GUI::ClearToolBarArea() const; //Clear Tool bar area

	// -- Figures Drawing functions
	void DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a Square
	void DrawEllipse(Point first, Point second, GfxInfo ELPSGfxInfo, bool Selected=false) const;//draw ellipse
	void DrawHexagon(Point P1, Point P2, GfxInfo HexGfxInfo, bool selected) const;



	// Color Functions

	bool GUI::getIsFilled() const;


	///TODO: Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar


	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	void GUI::setCrntDrawColor(color c);
	void GUI::setCrntFillColor(color c);//fill color
	void GUI::setIsFilled(bool isF);//fill status

	int getCrntPenWidth() const;		//get current pen width


};


#endif