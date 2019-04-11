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

	m_skinModel_obake = NewGO<prefab::CSkinModelRender>(0);
	m_skinModel_obake->Init(L"modelData/obake.cmo");
	CVector3 pos;
	pos.x = 0.0f;
	pos.y = 30.0f;
	pos.z = -30.0f;
	m_skinModel_obake->SetPosition(pos);
	return true;
}
void Eney::Update()
{
	return;
}
