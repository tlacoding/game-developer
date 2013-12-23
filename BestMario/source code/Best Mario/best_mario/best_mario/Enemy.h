#pragma once
#include "DynamicObject.h"
#include <list>
#include "StaticObject.h"
#include "Box.h"
using namespace std;

class Enemy : public DynamicObject{

public:
	
	StaticObject* brick; // de kiem tra chet khi bi tung vien gach

	bool preparing;
	bool onGround;
	bool ConUpdate;

	float VxF, VyF; // V per frame

	Box ObjBox;
public:

	Enemy(void);
	~Enemy(void);

	virtual void Update();
	virtual void UpdateSprite();
	virtual void UpdateSpriteDying();

	//Kiem tra va cham
	virtual void CollideWithStaticObj();
	virtual void CollideWithDynamicObj();

	virtual void CollideWithGround(float normalx, float normaly, float collisiontime,  StaticObject *obj);
	virtual void CollideWithPiPe(float normalx, float normaly, float collisiontime,  StaticObject *obj);
	virtual void CollideWithHardBrick(float normalx, float normaly, float collisiontime,  StaticObject *obj);

	//Cac ham khac
	virtual void ProcessDying();

	virtual void PrepareToMove(int t);
	virtual void NormalMove(int t);

	virtual void MoveToHell();
	virtual void CheckOutScreen();
	virtual void UpdateObjBox(float ix, float iy, float iw, float ih, float ivx, float ivy);
};