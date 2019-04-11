#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include"haikei.h"
#include"Eney.h"
#include"Player.h"

Game::Game()
{
	DeleteGO(m_skinModelRender);
}


Game::~Game()
{

}
bool Game::Start()
{
	//ƒJƒƒ‰‚ğİ’èB
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(1000.0f);
	MainCamera().SetPosition({ 0.0f, 200.0f, 500.0f });
	MainCamera().Update();

	NewGO<haikei>(0);
	NewGO<Eney>(0);
	NewGO<Player>(0);
	
	return true;
}

void Game::Update()
{
}