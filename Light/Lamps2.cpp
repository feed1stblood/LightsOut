#include "StdAfx.h"
#include "Lamps2.h"


Lamps2::Lamps2(int length,int height,CWnd *Main)
{
	Length=length;
	Height=height;
	State=new bool[Height*Length];
	main=Main;
	counts=0;
	bmp[0].LoadBitmapW(IDB_BITMAP1);
	bmp[1].LoadBitmapW(IDB_BITMAP2);
}




void Lamps2::OnClicked(int x,int y)
{
	for(int i=0;i<5;i++)
		Changed[i][0]=-1;
	int i=0;
	if(x<0||x>=Length||y<0||y>=Height)
		return;
	counts++;
	State[y*Length+x]=!State[y*Length+x];
	Changed[i][0]=State[y*Length+x];
	Changed[i][1]=x;
	Changed[i++][2]=y;
	if(x>0)
	{
		State[y*Length+x-1]=!State[y*Length+x-1];
		Changed[i][0]=State[y*Length+x-1];
		Changed[i][1]=x-1;
		Changed[i++][2]=y;
	}
	if(x<Length-1)
	{
		State[y*Length+x+1]=!State[y*Length+x+1];
		Changed[i][0]=State[y*Length+x+1];
		Changed[i][1]=x+1;
		Changed[i++][2]=y;
	}
	if(y>0)
	{
		State[(y-1)*Length+x]=!State[(y-1)*Length+x];
		Changed[i][0]=State[(y-1)*Length+x];
		Changed[i][1]=x;
		Changed[i++][2]=y;
	}
	if(y<Height-1)
	{
		State[(y+1)*Length+x]=!State[(y+1)*Length+x];
		Changed[i][0]=State[(y+1)*Length+x];
		Changed[i][1]=x;
		Changed[i][2]=y+1;
	}
}

int Lamps2::IsAllIdentical()
{
	for(int i=1;i<Height*Length;i++)
		if(State[i]!=State[0])
			return -1;
	return State[0];
}

void Lamps2::Init(bool Data[])
{
	memcpy(State,Data,Height*Length);
}

void Lamps2::Draw()
{
	CClientDC dc(main);
	CDC memDc;
	memDc.CreateCompatibleDC(&dc);
	for(int j=0;j<Height;j++)
		for(int i=0;i<Length;i++)
		{
			memDc.SelectObject(&bmp[State[j*Length+i]]);
			dc.BitBlt(i*40+10,j*40+10,35,35,&memDc,0,0,SRCCOPY);
		}
}

void Lamps2::Rinit(int difficulty)
{
	bool *__temp=new bool[Height*Length];
	memset(State,0,Height*Length*sizeof(bool));
	switch(difficulty)
	{
	case 0:
		srand((unsigned)time(0));
		for(int j=0;j<(Height+1)/2;j++)
			for(int i=0;i<(Length+1)/2;i++)
				__temp[j*Length+i]=rand()%2;
		for(int j=0;j<Height;j++)
			for(int i=0;i<Length;i++)
			{
				if(i<(Length+1)/2&&j<(Height+1)/2)continue;
				__temp[j*Length+i]=__temp[(j>(Height/2)?Height-1-j:j)*Length+(i>(Length/2)?Length-1-i:i)];
			}
		break;
	case 1:
		srand((unsigned)time(0));
		for(int j=0;j<(Height+1)/2;j++)
			for(int i=0;i<Length;i++)
				__temp[j*Length+i]=rand()%2;
		for(int j=(Height+1)/2;j<Height;j++)
			for(int i=0;i<Length;i++)
			{
				__temp[j*Length+i]=__temp[(Length-1-j)*Length+i];
			}
		break;
	case 2:
		srand((unsigned)time(0));
		for(int j=0;j<Height;j++)
			for(int i=0;i<Length;i++)
				__temp[j*Length+i]=rand()%2;
		break;
	}
	for(int j=0;j<Height;j++)
		for(int i=0;i<Length;i++)
			if(__temp[j*Length+i])OnClicked(i,j);
	delete []__temp;
	counts=0;
}