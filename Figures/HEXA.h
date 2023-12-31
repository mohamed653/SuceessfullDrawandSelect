#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"
#include "..\ApplicationManager.h"

class HEXA : public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
	int VerticalLen;
	int HorizentalLen;
public:
	ApplicationManager* pManager = NULL;	//Actions needs AppMngr to do their job
	int Area;

	HEXA(Point, Point, GfxInfo FigureGfxInfo); // Constructor
	HEXA();
	virtual void DrawMe(GUI* pOut) const;
	bool insideFigure(int x, int y);

	virtual void Resize(GUI* pGUI, float size);

	string GetFigureInfo();

};

#endif