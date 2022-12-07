#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1400;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	
	UI.DrawColor = color(0, 87, 231); ///google's blue
	UI.FillColor = color(0, 135, 68);	///google's green : why is this not working ?
	UI.MsgColor = color(255, 167, 0);		///google's yellow 
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = color(0, 135, 68); /// google's green
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SWITCH] = "images\\MenuItems\\Switch_to_play_mode.jpg";
	MenuItemImages[ITM_SAVE_GRAPH] = "images\\MenuItems\\Save_graph.jpg";
	MenuItemImages[ITM_LOAD_GRAPH] = "images\\MenuItems\\Load_graph.jpg";
	MenuItemImages[ITM_START_REC] = "images\\MenuItems\\Start_recording.jpg";
	MenuItemImages[ITM_STOP_REC] = "images\\MenuItems\\stop_recording.jpg";
	MenuItemImages[ITM_PLAY_REC] = "images\\MenuItems\\play_recording.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Select_1.jpg";
	MenuItemImages[ITM_CHANGE_DRAWING_CLR] = "images\\MenuItems\\Change_drawing_clr.jpg";
	MenuItemImages[ITM_CHANGE_FILL_CLR] = "images\\MenuItems\\Change_fill_clr.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Move_icon.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Delete_icon.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Undo_icon.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Redo_icon.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\U_rectangle.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\U_square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\U_triangle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\U_hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\U_circle.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Black_clr.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Red_clr.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Orange_clr.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Yellow_clr.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Green_clr.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Blue_clr.jpg";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\Clear_all.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\U_exit.jpg";
	

	//TODO: Prepare images for each menu item and add it to the list
	// make the background of the toolbar while
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	 


	//Draw a line under the toolbar
	pWind->SetPen(color(2, 179, 228), 3); // making the colors more homogenous
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string PlayItemImages[PLAY_ITM_COUNT];
	PlayItemImages[ITM_SWITCH_BACK] = "images\\MenuItems\\Switch_to_draw_mode.jpg";
	PlayItemImages[ITM_PICK_AND_HIDE] = "images\\MenuItems\\pick_and_hide.jpg";
	PlayItemImages[ITM_PICK_BY_TYPE] = "images\\MenuItems\\pick_by_type.jpg";
	PlayItemImages[ITM_PICK_BY_CLR] = "images\\MenuItems\\pick_by_color.jpg";
	PlayItemImages[ITM_PICK_BY_TYPE_AND_CLR] = "images\\MenuItems\\pick_by_type_and_color.jpg";
	PlayItemImages[ITM_RESTART] = "images\\MenuItems\\restart.jpg";
	PlayItemImages[ITM_EXIT_PLAY] = "images\\MenuItems\\U_exit.jpg";
	// do i have to draw a white rectangle on top of this ?
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	// i think so

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth ,UI.ToolBarHeight);

	pWind->SetPen(color(2, 179, 228), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawSquare(Point P1, GfxInfo squareGfxInfo, bool selected) const
{
	int squareside = 50;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = squareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (squareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(squareGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x - squareside, P1.y - squareside, P1.x + squareside, P1.y + squareside, style);

}
void Output::Drawcircle(Point P1, Point P2, GfxInfo circleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = circleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (circleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(circleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, int(sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2))), style);

}
void Output::DrawTraingle(Point P1, Point P2, Point P3, GfxInfo traingleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = traingleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (traingleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(traingleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
void Output::DrawHexagon(Point P1, GfxInfo hexagonGfxInfo, bool selected) const
{
	int hexagonside =50;
	int arrx[6] =
	{
		P1.x + hexagonside /2.
		,P1.x+ hexagonside,
		P1.x+ hexagonside /2.
		,P1.x- hexagonside /2.
		,P1.x- hexagonside
		,P1.x - hexagonside / 2.
	};
	int arry[6] =
	{
		 P1.y + hexagonside / 2. * sqrt(3)
		,  P1.y ,
		 P1.y - hexagonside / 2. * sqrt(3)
		 ,P1.y - hexagonside / 2. * sqrt(3)
		, P1.y ,
		 P1.y + hexagonside / 2. * sqrt(3)
	};

	
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = hexagonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (hexagonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(hexagonGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawPolygon(arrx, arry,6, style);
	
}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

