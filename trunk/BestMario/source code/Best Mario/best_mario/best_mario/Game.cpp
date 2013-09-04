#include "Game.h"

Game::Game(void){}

Game::Game(HINSTANCE hInstance, UINT _nCmdShow){
	_hInstance = hInstance;
	nCmdShow = _nCmdShow;
	_d3ddv = NULL;
}

Game::~Game(void){}

void Game::Init(){
	GlobalHandler::_directX->Init(_hInstance);
}

bool Game::Run(){
	if (GlobalHandler::quitGame)
		return false;
	GlobalHandler::_directX->BeginScene();

	GlobalHandler::_directX->EndScene();
	GlobalHandler::_directX->_d3ddv->Present(NULL, NULL, NULL, NULL);

	return true;
}