#pragma once
#include "head.h"
class SimInt
{
public:
	static SimInt& GitSimInt()
	{
		return a;
	}

private:
	SimInt();
	SimInt(const SimInt& SI);
	static SimInt a;
};




class Sim
{
public:
	static Sim& GitSim();

private:
	Sim();
	Sim(const SimInt& SI);
};

Sim& Sim::GitSim()//�����������˵��õ���sim�ڻ������û���˵��þͲ�����ڣ���̬�����ʣ���
{
	static Sim a;
	return a;
}
