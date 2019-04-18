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
	m_font = NewGO<prefab::CFontRender>(0);
	return true;
}
void Player::Update()
{
	if (joutai == JOUTAI_R) {
		m_font->SetText(L"");
		//if (/*アニメーションの再生が終わったら*/) {
		//	//待機状態に戻る。
		//}

	}
	else if (joutai == JOUTAI_RL) {
		m_font->SetText(L"");
	}
	else if (joutai == JOUTAI_TAIKI) {
		//ゲージを加算して、ゲージの値が10になったら、
		//joutaiにKOMANDOを代入する。
		geizi++;
		if (geizi == 120) {
			joutai = KOMANDO;
		}
	}
	else if (joutai == KOMANDO)
	{
		wchar_t text[50];
		swprintf(text, L"Aボタン::攻撃する\nBボタン::防御する");
		m_font->SetText(text);
		m_font->SetPosition({ -100.0f,-300.0f });
		m_font->SetPivot({ 0.0f,0.0f });
		if (Pad(0).IsTrigger(enButtonA)) {
			joutai = JOUTAI_R;
		}
		if (Pad(0).IsTrigger(enButtonB)) {
			joutai = JOUTAI_RL;
		}

	}
#if 0
		if (geizi == 10) {
			wchar_t text[50];
			swprintf(text,L"Aボタン::攻撃する\nBボタン::防御する");
			m_font->SetText(text);
			m_font->SetPosition({ -100.0f,-300.0f });
			m_font->SetPivot({ 0.0f,0.0f });
			/*swprintf(text, L"Bボタン::防御する\n");
			m_font->SetText(text);
			m_font->SetPosition({ -500.0f,100.0f });
			m_font->SetPivot({ 0.0f,0.0f });*/
			
			if (Pad(0).IsTrigger(enButtonA)) {
				joutai= JOUTAI_R;
				m_skinModel->PlayAnimation(Animation_R);

			}
			if (Pad(0).IsTrigger(enButtonB)) {
				joutai = JOUTAI_RL;
				m_skinModel->PlayAnimation(Animation_LR);
			}
		}
#endif
		return;
	}
	
