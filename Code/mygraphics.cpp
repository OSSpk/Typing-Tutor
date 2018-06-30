//#define _WIN32_WINNT 0x0500

#define _WIN32_WINNT 0x0500

#include <windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void myLine(int x1, int y1, int x2, int y2,COLORREF lineColor)
{

	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
	HPEN pen =CreatePen(PS_SOLID,2,lineColor); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);
}
void myRect(int x1, int y1, int x2, int y2,COLORREF lineColor,COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,lineColor);
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context,brush);

	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);
}
void myEllipse(int x1, int y1, int x2, int y2,COLORREF lineColor,COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,lineColor);
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);

}

void myDrawText(int x,int y,int ht,char str[],COLORREF lineColor,COLORREF fillColor)
{
	RECT rects;
	rects.left = x;
	rects.top = y;
	rects.right = x+ht;
	rects.bottom = y+ht;//(x,y,x+ht,y+ht);
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

	SetTextColor(device_context,lineColor);
	SetBkColor(device_context,fillColor);
	DrawText(device_context,str,-1,&rects,DT_TOP|DT_NOCLIP);
	ReleaseDC(console_handle, device_context);

}

void mySetPixel(int x,int y,COLORREF colorVal)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

	SetPixel(device_context,x,y,colorVal);
	ReleaseDC(console_handle,device_context);
}

