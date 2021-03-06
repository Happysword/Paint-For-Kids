#include "CTriangle.h"
#include"../ApplicationManager.h"
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	corner1 = P1;
	corner2 = P2;
	corner3 = P3;
	figtype=3;

	if (FigGfxInfo.FillClr == RED)					//figcolor (0:red,1:blue,2:green,3:white,4:black)
	{
		figcolor = 0;
	}
	else if (FigGfxInfo.FillClr == BLUE)
	{
		figcolor = 1;
	}
	else if (FigGfxInfo.FillClr == GREEN)
	{
		figcolor = 2;
	}
	else if (FigGfxInfo.FillClr == WHITE)
	{
		figcolor = 3;
	}
	else if (FigGfxInfo.FillClr == BLACK)
	{
		figcolor = 4;
	}
}

void CTriangle::Draw(Output * pOut) 
{
	pOut->DRAWTri(corner1, corner2, corner3, FigGfxInfo, Selected);
}
int CTriangle::crossproduct (int p1x,int p1y,int p2x,int p2y) 
{
	return -p1x*p2y+p2x*p1y;

}

bool CTriangle::dotproduct(int a,int b) 
{
	long t=a/10000*b;
	if(t>=0) return true;
	return false;
}
bool CTriangle::sameside(int p1x,int p1y,int p2x,int p2y,int p3x,int p3y,int ax,int ay)
{
	int cp1=crossproduct(p1x-p2x,-p1y+p2y,p1x-ax,-p1y+ay);
	int cp2=crossproduct(p1x-p2x,-p1y+p2y,p1x-p3x,-p1y+p3y);
	return dotproduct(cp1,cp2);
}

bool CTriangle::SelectArea (int ax,int ay)
{

	bool test1=sameside ( corner1.x, corner1.y, corner2.x,corner2.y, corner3.x, corner3.y, ax, ay);
	bool test2=sameside ( corner2.x,corner2.y,corner3.x,corner3.y,corner1.x,corner1.y, ax, ay);
	bool test3=sameside ( corner1.x, corner1.y, corner3.x, corner3.y, corner2.x, corner2.y, ax, ay);
	return (test1&&test2&&test3);

}
void CTriangle :: save (ofstream &OutFile, int n) {
	ID = n;
	OutFile<<"Triangle "<<"       ";
	OutFile<<ID<<"        "<<corner1.x<<"      "<<corner1.y<<"     "<<corner2.x<<"      "<<corner2.y<<"     "<<corner3.x<<"      "<<corner3.y<<"     ";
	if (FigGfxInfo.isFilled){
		if (FigGfxInfo.FillClr == BLACK) {
		OutFile<<"BLACK"<<"   ";
		}
		else if (FigGfxInfo.FillClr == RED) {
		OutFile<<"RED"<<"   ";
	}
		else if (FigGfxInfo.FillClr == BLUE) {
		OutFile<<"BLUE"<<"   ";
	}
		else if (FigGfxInfo.FillClr == GREEN) {
		OutFile<<"GREEN"<<"   ";
	}
		else {
		OutFile<<"WHITE"<<"   ";
		}
}
	else {
	OutFile<<"NON_FILL"<<"      ";
	}
	if (FigGfxInfo.DrawClr == BLACK) {
		OutFile<<"BLACK"<<"   ";
		}
	else if (FigGfxInfo.DrawClr == RED) {
		OutFile<<"RED"<<"   ";
	}
	else if (FigGfxInfo.DrawClr == BLUE) {
		OutFile<<"BLUE"<<"   ";
	}
	else if (FigGfxInfo.DrawClr== GREEN) {
		OutFile<<"GREEN"<<"   ";
	}
		else {
		OutFile<<"WHITE"<<"   ";
		}
}
void CTriangle :: load (ifstream &Infile) {
Infile>>ID; 
Infile>>corner1.x;
Infile>>corner1.y;
Infile>>corner2.x;
Infile>>corner2.y;
Infile>>corner3.x; 
Infile>>corner3.y;
string y;
string fil;
Infile>>y;
string  Clr;
Infile>>Clr;
if (Clr=="BLACK") {
	FigGfxInfo.DrawClr = BLACK;
}
else if (Clr=="RED") {
	FigGfxInfo.DrawClr = RED;
}
else if (Clr=="BLUE") {
	FigGfxInfo.DrawClr = BLUE;
}
else if (Clr=="GREEN") {
	FigGfxInfo.DrawClr = GREEN;
}
else   {
	FigGfxInfo.DrawClr = WHITE;
}
if (y== "NON_FILL") {
	FigGfxInfo.isFilled = false;
}
else {
	FigGfxInfo.isFilled = true;
	fil = y; 
 if (fil=="BLACK") {
		FigGfxInfo.FillClr= BLACK;
}
else if (fil=="RED") {
	FigGfxInfo.FillClr = RED;
}
else if (fil=="BLUE") {
	FigGfxInfo.FillClr = BLUE;
}
else if (fil=="GREEN") {
	FigGfxInfo.FillClr = GREEN;
}
else   {
	FigGfxInfo.FillClr = WHITE;
}
}
}
void CTriangle:: PrintInfo(Output* pOut)
{
	string p="triangle ID: "+to_string(3000+ID)+"  Point 1: ";
	p+=to_string(corner1.x)+' '+to_string(corner1.y)+" Point 2:"+to_string(corner2.x)+' '+to_string(corner2.y) +" Point 3: "+to_string(corner3.x)+' '+to_string(corner3.y);
	pOut->PrintMessage(p);


}