#pragma once
#include "cCubeNode.h"
class cHeadPNT :
	public cCubeNode
{
public:
	cHeadPNT();
	~cHeadPNT();
	virtual void Setup() override;
};