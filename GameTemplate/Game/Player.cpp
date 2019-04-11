#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}
bool Player::Start()
{
	m_animClips[Animation_R].Load(L"animData/Player/Hand1.tka");
	m_animClips[Animation_LR].Load(L"animData/Player/Hand1.2.tka");

	m_skinModel = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel->Init(L"modelData/Player1.cmo");
	CVector3 pos;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 300.0f;
	m_skinModel->SetPosition(pos);
	return true;
}
void Player::Update()
{
	geizi++; {

		if (geizi == 10) {
			printf("Aボタン::攻撃,Bボタン::防御");
			if (Pad(0).IsTrigger(enButtonA)) {


			}
			if (Pad(0).IsTrigger(enButtonB)) {

			}
		}
	}
	return;
}