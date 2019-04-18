#include "stdafx.h"
#include "Eney.h"


Eney::Eney()
{
}


Eney::~Eney()
{
}
bool Eney::Start()
{

	m_animation[OBAKE_UGOKI].Load(L"animData/Player/obake_ugoki.tka");
	m_skinModel_obake = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel_obake->Init(L"modelData/obake.cmo", m_animation, AnimationNokazu);
	CVector3 pos;
	pos.x = 0.0f;
	pos.y = 30.0f;
	pos.z = -30.0f;
	m_skinModel_obake->SetPosition(pos);
	return true;
}
void Eney::Update()
{
	geizi++;
	if (geizi == 10) {
		if (joutai == JOUTAI_TAIKI) {

			joutai = JOUTAI_TAIKI;
			m_skinModel_obake->PlayAnimation(OBAKE_UGOKI);

		}
	}
	return;
}
