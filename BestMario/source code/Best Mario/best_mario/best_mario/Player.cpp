#include "GlobalHandler.h"
#include "Player.h"
#include "ListTexture.h"
#include "Define.h"

Player::Player(void){}

Player::~Player(void){}

void Player::Init(int mode,int LastCheckPoint, int Life){

	sprite = new Sprite();
	InitFromFile(mode, LastCheckPoint, Life);
	Vx = 0;
	Vy = 0;

	animatedRate = ListTexture::TT_MARIO_KID_ANIMATED_RATE;
	lastAnimate = GetTickCount();
	lastUpdate = GetTickCount();

	onGround = false;
	jumping = false;
	trace(L"Player::Init(int mode,int LastCheckPoint, int Life)");
}

void Player::InitFromFile(int mode,int LastCheckPoint, int Life){
	if (mode == PLAYER_KID)
		setKid();
	lastCheckPoint = LastCheckPoint;
	//cai nay de khi nao lam cai checkpoint da
	//UpdateRect(GlobalHandler::checkpoint[0][lastCheckPoint], GlobalHandler::checkpoint[1][lastCheckPoint]);
	UpdateRect(15, 470);
	trace(L"Player::InitFromFile(int mode,int LastCheckPoint, int Life)");
}

void Player::setKid(){
	sprite->Reset(ListTexture::TT_MARIO_KID,
		ListTexture::TT_MARIO_KID_WIDTH,
		ListTexture::TT_MARIO_KID_HEIGHT,
		ListTexture::TT_MARIO_KID_COUNT,
		ListTexture::TT_MARIO_KID_SPRITEPERROW);

	isKind = PLAYER_KID;

	width = ListTexture::TT_MARIO_KID_WIDTH;
	height = ListTexture::TT_MARIO_KID_HEIGHT;

	animatedRate = ListTexture::TT_MARIO_KID_ANIMATED_RATE;

	//frame index.
	frame_moving_left_start		= ListTexture::TT_MARIO_KID_MOVING_LEFT_START;
	frame_moving_left_end		= ListTexture::TT_MARIO_KID_MOVING_LEFT_END;
	frame_moving_right_start	= ListTexture::TT_MARIO_KID_MOVING_RIGHT_START;
	frame_moving_right_end		= ListTexture::TT_MARIO_KID_MOVING_RIGHT_END;
	frame_jumping_left_start	= ListTexture::TT_MARIO_KID_JUMPING_LEFT_START;
	frame_jumping_left_end		= ListTexture::TT_MARIO_KID_JUMPING_LEFT_END;
	frame_jumping_right_start	= ListTexture::TT_MARIO_KID_JUMPING_RIGHT_START;
	frame_jumping_right_end		= ListTexture::TT_MARIO_KID_JUMPING_RIGHT_END;

	UpdateSprite();
	trace(L"setKid()");
}

void Player::Render(){

	RECT screen = GlobalHandler::screen;
	sprite->Render(GlobalHandler::_directX->_backBuffer, rectDraw.left - screen.left, rectDraw.top - screen.top);

}

void Player::Update(){

	DWORD now = GetTickCount();
	DWORD t = now - lastUpdate;
	lastUpdate = now;
	int x = rectReal.left;
	int y = rectReal.top;
	x += Vx * t / 100;
	y += Vy * t / 100;	
	if (y < 470)
	{
		Vy += 10;
	} else {
		y = 470;
		Vy = 0;
		jumping = false;
	}
	UpdateRectReal(x, y);
	GlobalHandler::UpdateScreen();
	trace(L"X: %d , Y: %d", x, y);
}

void Player::ProcessInput(){

	if (GlobalHandler::_directX->IsKeyDown(DIK_LEFT))
	{
		Vx = -30;
		Vx_old = Vx;
		//trace(L"DIK_LEFT");
	}
	else if (GlobalHandler::_directX->IsKeyDown(DIK_RIGHT))
	{
		Vx = 30;
		Vx_old = Vx;
		//trace(L"DIK_RIGHT");
	} else {
		Vx = 0;
	}

}

void Player::OnKeyDown(int keyCode){
	switch(keyCode){
		case DIK_UP:
			if (jumping == false)
			{
				onGround = false;
				jumping = true;
				Vy -= 100;
			}			
			break;
	}
}

void Player::UpdateSprite(){}

