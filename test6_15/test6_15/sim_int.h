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

Sim& Sim::GitSim()//优势在与有人调用单利sim在会有如果没有人调用就不会存在（静态的性质！）
{
	static Sim a;
	return a;
}
