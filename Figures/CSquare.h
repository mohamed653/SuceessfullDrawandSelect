#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"
#include "..\ApplicationManager.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	ApplicationManager* pManager = NULL;	//Actions needs AppMngr to do their job

	CSquare(Point , int, GfxInfo FigureGfxInfo );
	CSquare();
	virtual void DrawMe(GUI* pOut) const;
	bool insideFigure(int x, int y);
	string GetFigureInfo();
};

#endif