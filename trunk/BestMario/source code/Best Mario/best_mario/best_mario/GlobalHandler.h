#pragma once

#include "DirectX.h"

class GlobalHandler{

public:
	static DirectX *_directX;

	GlobalHandler(void);
	~GlobalHandler(void);

};