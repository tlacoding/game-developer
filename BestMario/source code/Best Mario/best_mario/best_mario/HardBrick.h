#pragma once
#include "StaticObject.h"

class HardBrick : public StaticObject{
public:
	HardBrick(void);
	HardBrick(int left, int top, int iid);
	~HardBrick(void);
};