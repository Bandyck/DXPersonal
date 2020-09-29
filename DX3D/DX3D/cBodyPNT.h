#pragma once
#include "cCubeNode.h"
class cBodyPNT :
	public cCubeNode
{
public:
	cBodyPNT();
	~cBodyPNT();

	virtual void Setup() override;
};

