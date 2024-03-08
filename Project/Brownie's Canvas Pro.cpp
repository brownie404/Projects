#include "iGraphics.h"

/*VARIABLE DECLARATIONS*/
int pointerx;
int pointery;
int rcol, gcol, bcol;
int col[3];
int getx, gety;
int printx, printy;
int w = 10;
int tool;
int tltp = 0;
int rec;
int clickx, clicky;
int posx = -100;
int posy = 375;
int linex[2000000];
int liney[2000000];
int ptx;
int last = 1;
int filled=0;




// rectangle tool//
void rectangle0(int m, int n)
{	
	if(n<(750-w*4+10)){
	if(filled==0){
	for(int i=0;i<10;i++){
	iRectangle(m - w * 8 / 2+i, n - w * 8 / 2+i, w * 8-2*i, w * 8-2*i);
	}
	}
	else {
		iFilledRectangle(m - w * 8 / 2, n - w * 8 / 2, w * 8, w * 8);
	}
	}
}

void rectangle1(int m, int n)
{
	if(n<(750-w*3+10)){
	if(filled==0){
	for(int i=0;i<10;i++){
	iRectangle(m - w * 10 / 2+i, n - w * 6 / 2+i, w * 10-2*i, w * 6-2*i);
	}
	}
	else {
		iFilledRectangle(m - w * 10 / 2, n - w * 6 / 2, w * 10, w * 6);
	}
	}
}

void rectangle2(int m, int n)
{
	if(n<(750-w*5+10)){
	if(filled==0){
	for(int i=0;i<10;i++){
	iRectangle(m - w * 6 / 2+i, n - w * 10 / 2+i, w * 6-2*i, w * 10-2*i);
	}
	}
	else {
		iFilledRectangle(m - w * 6 / 2, n - w * 10 / 2, w * 6, w * 10);
	}
	}
}





/*Oval TOOL*/
void oval0(int m, int n)
{	
	if(n<(750-w*5+10)){
	if(filled==0){
	for(int i=0;i<10;i++){
	iEllipse(m, n, w * 5-i, w * 5-i, 1000);
	}
	}
	else {
		iFilledEllipse(m, n, w * 5, w * 5, 1000);
	}
	}
}

void oval1(int m, int n)
{
	if(n<(750-w*4+10)){
	if(filled==0){
	for(int i=0;i<10;i++){
	iEllipse(m, n, w * 7-i, w * 4-i, 1000);
	}
	}
	else {
		iFilledEllipse(m, n, w * 7, w * 4, 1000);
	}
	}
}

void oval2(int m, int n)
{
	if(n<(750-w*7+10)){
	if(filled==0){
	for(int i=0;i<10;i++){
	iEllipse(m, n, w * 4-i, w * 7-i, 1000);
	}
	}
	else {
		iFilledEllipse(m, n, w * 4, w * 7, 1000);
	}
	}
}





/*MAIN IDRAW FUNCTION START*/
void iDraw()
{

	/*STARTING ANIMATION*/
	if (posx < 1500)
	{
		iFilledCircle(posx, posy, 375, 1000);
		iFilledCircle(posx + 10, posy, 375, 1000);
		iShowBMP(posx + 100, posy - 300, "start.bmp");
		posx += 20;
	}

	/*APP FUNCS*/
	if (posx == 1500)
	{

		iGetPixelColor(getx, gety, col);
		rcol = col[0];
		gcol = col[1];
		bcol = col[2];
		iSetColor(rcol, gcol, bcol);



		// BRUSH TOOL
		if (pointerx < 1500 && pointery < 750 && tool == 0)
		{

			for (int i = last; i < ptx; i++)
			{

				if (linex[i - 1] < 0)
					continue;
				if (linex[i] < 0)
					continue;

				if (linex[i] < 1500 && liney[i] < 750 && tool == 0)
				{

					for (int dx = -w; dx <= w; dx++)
					{
						for (int dy = -w; dy <= w; dy++)
						{

							iLine(linex[i] + dx, liney[i] + dy, linex[i - 1] + dx, liney[i - 1] + dy);
						}
					}
				}
			}
		}




		/*TOOLS*/

		/*Tooltype terminator*/
		if (tool == 0)
		{
			iSetColor(0, 0, 0);
			iFilledRectangle(700, 775, 600, 100);
		}

		/*OVAL TOOL*/
		if (tool == 1)
		{

			/*MENU BUILDING*/
			iSetColor(255, 255, 255);
			iFilledRectangle(700, 775, 600, 100);

			iSetColor(0, 0, 0);
			iFilledRectangle(705, 780, 590, 90);

			iSetColor(255, 255, 255);
			iFilledRectangle(900, 775, 10, 100);
			iFilledRectangle(1100, 775, 10, 100);

			iFilledCircle(800, 825, 35, 1000);
			iFilledEllipse(1000, 825, 45, 30, 1000);
			iFilledEllipse(1200, 825, 30, 45, 1000);

			/*DRAW OVAL*/
			if (tltp == 0)
			{
				iSetColor(rcol, gcol, bcol);
				if (clickx < 1500 && clicky < 750)
				{
					oval0(clickx, clicky);
				}
			}

			if (tltp == 1)
			{
				iSetColor(rcol, gcol, bcol);
				if (clickx < 1500 && clicky < 750)
				{
					oval1(clickx, clicky);
				}
			}

			if (tltp == 2)
			{
				iSetColor(rcol, gcol, bcol);
				if (clickx < 1500 && clicky < 750)
				{
					oval2(clickx, clicky);
				}
			}
		}



		/*RECTANGLE TOOL*/
		if (tool == 2)
		{
			/*MENU BUILDING*/
			iSetColor(255, 255, 255);
			iFilledRectangle(700, 775, 600, 100);

			iSetColor(0, 0, 0);
			iFilledRectangle(705, 780, 590, 90);

			iSetColor(255, 255, 255);
			iFilledRectangle(900, 775, 10, 100);
			iFilledRectangle(1100, 775, 10, 100);

			iFilledRectangle(770, 795, 60, 60);
			iFilledRectangle(950, 795, 100, 60);
			iFilledRectangle(1180, 790, 40, 70);

			/*DRAW REC*/
			if (tltp == 0)
			{
				iSetColor(rcol, gcol, bcol);
				if (clickx < 1500 && clicky < 750)
				{
					rectangle0(clickx, clicky);
				}
			}

			if (tltp == 1)
			{
				iSetColor(rcol, gcol, bcol);
				if (clickx < 1500 && clicky < 750)
				{
					rectangle1(clickx, clicky);
				}
			}

			if (tltp == 2)
			{
				iSetColor(rcol, gcol, bcol);
				if (clickx < 1500 && clicky < 750)
				{
					rectangle2(clickx, clicky);
				}
			}
		}



		/*ERASE ALL*/
		if (tool == 3)
		{
			iSetColor(255, 255, 255);
			iFilledRectangle(0, 0, 1500, 750);
		}





		/*LINES AND DECORATION*/
		iSetColor(255, 204, 153);
		iFilledRectangle(0, 750, 1500, 10);
		iFilledRectangle(0, 0, 1500, 10);
		iFilledRectangle(0, 0, 10, 1035);
		iFilledRectangle(1490, 0, 10, 1035);
		iFilledRectangle(0, 1025, 1500, 10);

		/*BMP DECOR FILES*/
		iShowBMP(1325, 850, "logo.bmp");
		iShowBMP(1325, 775, "title.bmp");

		/*COLOR PALETTE*/
		iSetColor(255, 0, 0);
		iFilledRectangle(250, 940, 50, 40);

		iSetColor(0, 255, 0);
		iFilledRectangle(300, 940, 50, 40);

		iSetColor(0, 0, 255);
		iFilledRectangle(350, 940, 50, 40);

		iSetColor(255, 255, 0);
		iFilledRectangle(400, 940, 50, 40);

		iSetColor(0, 255, 255);
		iFilledRectangle(450, 940, 50, 40);

		iSetColor(255, 0, 255);
		iFilledRectangle(500, 940, 50, 40);

		iSetColor(192, 192, 192);
		iFilledRectangle(550, 940, 50, 40);

		iSetColor(128, 128, 128);
		iFilledRectangle(600, 940, 50, 40);

		iSetColor(128, 0, 0);
		iFilledRectangle(650, 940, 50, 40);

		iSetColor(128, 128, 0);
		iFilledRectangle(700, 940, 50, 40);

		iSetColor(0, 128, 0);
		iFilledRectangle(750, 940, 50, 40);

		iSetColor(128, 0, 128);
		iFilledRectangle(800, 940, 50, 40);

		iSetColor(0, 0, 128);
		iFilledRectangle(850, 940, 50, 40);

		iSetColor(0, 128, 128);
		iFilledRectangle(850, 940, 50, 40);

		iSetColor(255, 228, 225);
		iFilledRectangle(900, 940, 50, 40);

		iSetColor(255, 102, 0);
		iFilledRectangle(250, 900, 50, 40);

		iSetColor(255, 153, 0);
		iFilledRectangle(300, 900, 50, 40);

		iSetColor(255, 204, 0);
		iFilledRectangle(350, 900, 50, 40);

		iSetColor(153, 204, 0);
		iFilledRectangle(400, 900, 50, 40);

		iSetColor(51, 204, 204);
		iFilledRectangle(450, 900, 50, 40);

		iSetColor(51, 102, 255);
		iFilledRectangle(500, 900, 50, 40);

		iSetColor(255, 204, 153);
		iFilledRectangle(550, 900, 50, 40);

		iSetColor(255, 153, 204);
		iFilledRectangle(600, 900, 50, 40);

		iSetColor(153, 204, 255);
		iFilledRectangle(650, 900, 50, 40);

		iSetColor(255, 255, 153);
		iFilledRectangle(700, 900, 50, 40);

		iSetColor(204, 255, 204);
		iFilledRectangle(750, 900, 50, 40);

		iSetColor(204, 255, 255);
		iFilledRectangle(800, 900, 50, 40);

		iSetColor(0, 204, 255);
		iFilledRectangle(850, 900, 50, 40);

		iSetColor(102, 102, 153);
		iFilledRectangle(850, 900, 50, 40);

		iSetColor(204, 204, 255);
		iFilledRectangle(900, 900, 50, 40);

		/*outline of pallette*/
		iSetColor(255, 255, 255);
		iFilledRectangle(250, 900, 700, 3);
		iFilledRectangle(250, 900, 3, 80);
		iFilledRectangle(250, 977, 700, 3);
		iFilledRectangle(947, 900, 3, 80);

		/*Stroke size MENU BUILDING*/
		iSetColor(255, 255, 255);
		iFilledCircle(250, 850, 5, 200);
		iFilledCircle(300, 850, 10, 200);
		iFilledCircle(360, 850, 15, 200);

		iSetColor(255, 204, 153);
		iFilledRectangle(225, 820, 175, 3);
		iFilledRectangle(225, 880, 175, 3);
		iFilledRectangle(225, 820, 3, 60);
		iFilledRectangle(397, 820, 3, 60);
		iFilledRectangle(327, 820, 3, 60);
		iFilledRectangle(267, 820, 3, 60);




		/*STROKE SIZE GREEN INDICATOR*/
		if (w == 5)
		{
			iSetColor(50, 205, 50);
			iFilledCircle(250, 850, 5, 200);
		}

		if (w == 10)
		{
			iSetColor(50, 205, 50);
			iFilledCircle(300, 850, 10, 200);
		}

		if (w == 15)
		{
			iSetColor(50, 205, 50);
			iFilledCircle(360, 850, 15, 200);
		}




		/*TOOLS SELECT MENU BUILD*/
		iSetColor(255, 204, 153);
		iFilledRectangle(440, 820, 100, 60);
		iFilledRectangle(560, 820, 100, 60);

		iSetColor(0, 0, 0);
		iFilledRectangle(580, 830, 60, 40);
		iFilledEllipse(490, 850, 35, 25, 100);

		iSetColor(255, 204, 153);
		iFilledRectangle(585, 835, 50, 30);
		iFilledEllipse(490, 850, 30, 20, 100);




		/*ERASER TOOL MENU BUILD*/
		iSetColor(255, 255, 255);
		iRectangle(1080, 940, 80, 40); /*eraser*/
		iRectangle(1180, 940, 80, 40); /*erase all*/

		iSetColor(255, 255, 255);
		iFilledRectangle(1083, 945, 72, 30);




		/*PEN TOOL*/
		iSetColor(255, 255, 255);
		iRectangle(980, 940, 80, 40);

		iSetColor(0, 0, 0);
		iFilledRectangle(980, 945, 72, 30);




		/*CURRENTLY SELECTED COLOR*/
		iSetColor(255, 255, 255);
		iFilledCircle(110, 820, 25, 1000);
		iSetColor(rcol, gcol, bcol);
		iFilledCircle(110, 820, 20, 1000);




		/*TOOL GREEN INDICATORS*/
		if (tool == 1)
		{
			iSetColor(50, 205, 50);
			iFilledEllipse(490, 850, 30, 20, 100);
		}

		if (tool == 2)
		{
			iSetColor(50, 205, 50);
			iFilledRectangle(585, 835, 50, 30);
		}




		/*TOOLTYPE GREEN INDICATOR*/
		/*OVAL*/
		if (tool == 1 && tltp == 0)
		{
			iSetColor(50, 205, 50);
			iFilledCircle(800, 825, 30, 1000);
		}

		if (tool == 1 && tltp == 1)
		{
			iSetColor(50, 205, 50);
			iFilledEllipse(1000, 825, 40, 25, 1000);
		}

		if (tool == 1 && tltp == 2)
		{
			iSetColor(50, 205, 50);
			iFilledEllipse(1200, 825, 25, 40, 1000);
		}

		/*REC*/
		if (tool == 2 && tltp == 0)
		{
			iSetColor(50, 205, 50);
			iFilledRectangle(775, 800, 50, 50);
		}

		if (tool == 2 && tltp == 1)
		{
			iSetColor(50, 205, 50);
			iFilledRectangle(955, 800, 90, 50);
		}

		if (tool == 2 && tltp == 2)
		{
			iSetColor(50, 205, 50);
			iFilledRectangle(1185, 795, 30, 60);
		}




		/*ERASER AND PEN INDICATOR*/
		if (rcol == 0 && gcol == 0 && bcol == 0)
		{
			w = 5;
			iSetColor(50, 205, 50);
			iFilledCircle(1020, 1000, 10, 50);
		}

		else
		{
			iSetColor(0, 0, 0);
			iFilledCircle(1020, 1000, 10, 50);
		}

		if (rcol == 255 && gcol == 255 && bcol == 255)
		{
			iSetColor(50, 205, 50);
			iFilledCircle(1120, 1000, 10, 50);
		}

		else
		{
			iSetColor(0, 0, 0);
			iFilledCircle(1120, 1000, 10, 50);
		}



		/*TEXTS*/
		iSetColor(255, 255, 255);
		iText(30, 960, "COLOR PALETTE", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1004, 910, "PEN", GLUT_BITMAP_HELVETICA_18);
		iText(1084, 910, "ERASER", GLUT_BITMAP_HELVETICA_18);
		iText(1175, 910, "ERASE ALL", GLUT_BITMAP_HELVETICA_18);

		if (tool == 0)
		{
			iSetColor(0, 0, 0);
			iFilledRectangle(230, 780, 200, 40);
			iSetColor(255, 255, 255);
			iText(240, 790, "STROKE WIDTH", GLUT_BITMAP_HELVETICA_18);
		}

		else if (tool == 1 || tool == 2)
		{
			iSetColor(0, 0, 0);
			iFilledRectangle(230, 780, 200, 40);
			iSetColor(255, 255, 255);
			iText(245, 790, "SHAPE SIZES", GLUT_BITMAP_HELVETICA_18);
		}

		/*iText(240, 790, "STROKE WIDTH", GLUT_BITMAP_HELVETICA_18);*/
		iSetColor(255, 255, 255);
		iText(450, 790, "SHAPES", GLUT_BITMAP_HELVETICA_18);

		iText(575, 795, "'F'  Filled", GLUT_BITMAP_HELVETICA_18);
		iText(575, 775, "'G' Hollow", GLUT_BITMAP_HELVETICA_18);

		iText(60, 885, "SELECTED", GLUT_BITMAP_HELVETICA_18);
		iText(75, 865, "COLOR", GLUT_BITMAP_HELVETICA_18);
	}
}

/*MAIN IDRAW FUNCTION END*/




void iMouseMove(int mx, int my)
{
	pointerx = mx;
	pointery = my;
	if (mx <= 1500 && my <= 750)
	{
		linex[ptx] = mx;
		liney[ptx++] = my;
	}
	printf("(%d,%d)", mx, my);
}



void iMouse(int button, int state, int mx2, int my2)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if (mx2 < 1500 && my2 < 750)
		{
			clickx = mx2;
			clicky = my2;
		}

		if (my2 > 900 && my2 < 980 && mx2 > 250 && mx2 < 950 || my2 > 945 && my2 < 975 && mx2 > 1080 && mx2 < 1150 || my2 > 945 && my2 < 975 && mx2 > 980 && mx2 < 1060)
		{
			getx = mx2;
			gety = my2;
			pointerx = 1500;
			pointery = 1035; /*Color and erase and pen*/
			tool = 0;
		}

		else if (my2 > 820 && my2 < 880 && mx2 > 225 && mx2 < 267)
		{
			w = 5;
			pointerx = 1500;
			pointery = 1035;
			tool = 0;
		} /*Stroke width*/

		else if (my2 > 820 && my2 < 880 && mx2 > 267 && mx2 < 327)
		{
			w = 10;
			pointerx = 1500;
			pointery = 1035;
			tool = 0;
		} /*Stroke width*/

		else if (my2 > 820 && my2 < 880 && mx2 > 327 && mx2 < 400)
		{
			w = 15;
			pointerx = 1500;
			pointery = 1035;
			tool = 0;
		} /*Stroke width*/

		/*TOOL SELECTOR*/
		else if (my2 > 820 && my2 < 880 && mx2 > 440 && mx2 < 540)
		{
			tool = 1;
			clickx = 2000;
			clicky = 2000;
		}

		else if (my2 > 820 && my2 < 880 && mx2 > 560 && mx2 < 660)
		{
			tool = 2;
			clickx = 2000;
			clicky = 2000;
		}

		else if (my2 > 940 && my2 < 980 && mx2 > 1180 && mx2 < 1260)
		{
			tool = 3;
		}

		/*TOOL TYPE SELECTION*/
		if (my2 > 775 && my2 < 875 && mx2 > 700 && mx2 < 900)
		{
			tltp = 0;
			clickx = 2000;
			clicky = 2000;
		}

		else if (my2 > 775 && my2 < 875 && mx2 > 900 && mx2 < 1100)
		{
			tltp = 1;
			clickx = 2000;
			clicky = 2000;
		}

		else if (my2 > 775 && my2 < 875 && mx2 > 1100 && mx2 < 1300)
		{
			tltp = 2;
			clickx = 2000;
			clicky = 2000;
		}
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (linex[ptx - 1] >= 0 && liney[ptx - 1] >= 0)
		{
			last = ptx;
			linex[ptx] = -1;
			liney[ptx++] = -1;
		}
	}
}



void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}

	
	if (key == 'f') {
		filled=1;
		clickx=2000;
		clicky=2000;
	}


	if (key == 'g') {
		filled=0;
		clickx=2000;
		clicky=2000;
	}
	
}



void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}



int main()
{
	iInitialize(1500, 1035, "Brownie's Canvas");
	return 0;
}