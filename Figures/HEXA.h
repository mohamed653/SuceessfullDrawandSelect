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

	virtual void DrawMe(GUI* pOut) const;
	bool insideFigure(int x, int y);
	string GetFigureInfo();

};

#endif