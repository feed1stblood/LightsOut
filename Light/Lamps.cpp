
#include "Stdafx.h"
#include "Lamps.h"


Lamps::Lamps(int length,CWnd *Main):counts(0)
{
	Length=length;
	State=new bool[Length*Length];
	main=Main;
	bmp[0].LoadBitmapW(IDB_BITMAP1);
	bmp[1].LoadBitmapW(IDB_BITMAP2);
}

void Lamps::OnClicked(int x,int y)
{
	for(int i=0;i<5;i++)
		Changed[i][0]=-1;
	int i=0;
	if(x<0||x>=Length||y<0||y>=Length)
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
	if(y<Length-1)
	{
		State[(y+1)*Length+x]=!State[(y+1)*Length+x];
		Changed[i][0]=State[(y+1)*Length+x];
		Changed[i][1]=x;
		Changed[i][2]=y+1;
	}
}

int Lamps::IsAllIdentical()
{
	for(int i=1;i<Length*Length;i++)
		if(State[i]!=State[0])
			return -1;
	return State[0];
}

void Lamps::Init(bool Data[])
{
	memcpy(State,Data,Length*Length);
}

void Lamps::Draw()
{
	CClientDC dc(main);
	CDC memDc;
	memDc.CreateCompatibleDC(&dc);
	for(int j=0;j<Length;j++)
		for(int i=0;i<Length;i++)
		{
			memDc.SelectObject(&bmp[State[j*Length+i]]);
			dc.BitBlt(i*40+10,j*40+10,35,35,&memDc,0,0,SRCCOPY);
		}
}

void Lamps::Rinit(int difficulty)
{
	bool *__temp=new bool[Length*Length];
	memset(State,0,Length*Length*sizeof(bool));
	switch(difficulty)
	{
	case 0:
		srand((unsigned)time(0));
		for(int j=0;j<(Length+1)/2;j++)
			for(int i=0;i<(Length+1)/2;i++)
				__temp[j*Length+i]=rand()%2;
		for(int j=0;j<Length;j++)
			for(int i=0;i<Length;i++)
			{
				if(i<(Length+1)/2&&j<(Length+1)/2)continue;
				__temp[j*Length+i]=__temp[(j>2?Length-1-j:j)*Length+(i>2?Length-1-i:i)];
			}
		break;
	case 1:
		srand((unsigned)time(0));
		for(int j=0;j<(Length+1)/2;j++)
			for(int i=0;i<Length;i++)
				__temp[j*Length+i]=rand()%2;
		for(int j=(Length+1)/2;j<Length;j++)
			for(int i=0;i<Length;i++)
			{
				__temp[j*Length+i]=__temp[(Length-1-j)*Length+i];
			}
		break;
	case 2:
		srand((unsigned)time(0));
		for(int j=0;j<Length;j++)
			for(int i=0;i<Length;i++)
				__temp[j*Length+i]=rand()%2;
		break;
	}
	for(int j=0;j<Length;j++)
		for(int i=0;i<Length;i++)
			if(__temp[j*Length+i])OnClicked(i,j);
	delete []__temp;
	counts=0;
}

