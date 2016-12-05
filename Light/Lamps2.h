#pragma once
#include "lamps.h"

class Lamps2 :
	public Lamps
{
protected:
	int Height;
public:
	Lamps2(int,int,CWnd *);
	//构造函数,length为棋盘长度

	virtual void OnClicked(int x,int y);
	//对x,y处的灯进行点击
	
	virtual int GetState(int x,int y)
	{
		if(x>=0&&x<Length&&y>=0&&y<Height)
			return State[y*Length+x];
		else return -1;
	}
	//获得x,y处的灯的状态 0为黑,1为白

	virtual int IsAllIdentical();
	//判断是否所有灯已经统一,若已统一则返回统一的状态(0 or 1),若不统一在返回-1

	virtual void Rinit(int difficulty); 

	void Get_preChanged(int get[5][3]); 
	//函数直接用get数组作为返回值,存放改变了的灯的位置
	//get[i][0]存放改变后灯的状态,若get[i][0]为-1则表示未改变
	//get[i][1]和get[i][2](0<=i<5)存放改变的灯的位置(x,y)

	virtual void Draw();
	virtual void Init(bool Data[]);
	//用一个数组长度为 棋盘长*宽 的bool型数组进行初始化
	//为0表示黑,为1表示白
};
