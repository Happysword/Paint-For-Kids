#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point corner1, corner2, corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
<<<<<<< HEAD
	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);
	 float area(int x1, int y1, int x2, int y2, int x3, int y3) ;

};
=======

	virtual void Draw(Output* pOut) ;
	 virtual bool SelectArea(int x,int y);

	//virtual void Draw(Output* pOut) ;

};
>>>>>>> db46d93509c2ce146a4e9203fd87cfe2f0cc7b22
