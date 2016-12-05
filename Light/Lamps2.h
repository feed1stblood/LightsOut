#pragma once
#include "lamps.h"

class Lamps2 :
	public Lamps
{
protected:
	int Height;
public:
	Lamps2(int,int,CWnd *);
	//���캯��,lengthΪ���̳���

	virtual void OnClicked(int x,int y);
	//��x,y���ĵƽ��е��
	
	virtual int GetState(int x,int y)
	{
		if(x>=0&&x<Length&&y>=0&&y<Height)
			return State[y*Length+x];
		else return -1;
	}
	//���x,y���ĵƵ�״̬ 0Ϊ��,1Ϊ��

	virtual int IsAllIdentical();
	//�ж��Ƿ����е��Ѿ�ͳһ,����ͳһ�򷵻�ͳһ��״̬(0 or 1),����ͳһ�ڷ���-1

	virtual void Rinit(int difficulty); 

	void Get_preChanged(int get[5][3]); 
	//����ֱ����get������Ϊ����ֵ,��Ÿı��˵ĵƵ�λ��
	//get[i][0]��Ÿı��Ƶ�״̬,��get[i][0]Ϊ-1���ʾδ�ı�
	//get[i][1]��get[i][2](0<=i<5)��Ÿı�ĵƵ�λ��(x,y)

	virtual void Draw();
	virtual void Init(bool Data[]);
	//��һ�����鳤��Ϊ ���̳�*�� ��bool��������г�ʼ��
	//Ϊ0��ʾ��,Ϊ1��ʾ��
};