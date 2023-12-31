#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"
static int newID = 0;
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool PlayHidden;
	/// Add more parameters if needed.

public:

	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	virtual bool insideFigure(int, int) = 0; // select

	//ID Setter / Getter
	int CFigure::GetID() const;
	//color StringToColor(string s);
	//string ColorToString(color c);
	void CFigure::SetID(int id);

	bool HiddenStatus() const;
	//virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file
	//virtual string getShapeType() = 0;  // to get type of the shape
	//virtual CFigure* Clone() = 0;
	////color getFillColor();
	//virtual void Resize(GUI* pGUI, float size) = 0;

	virtual string GetFigureInfo() = 0;	//print figure info on the status bar

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual void Resize(GUI* pGUI, float size)=0;

	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif