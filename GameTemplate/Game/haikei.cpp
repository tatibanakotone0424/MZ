#include "stdafx.h"
#include "haikei.h"

haikei::haikei()
{

}

haikei::~haikei()
{
}
bool haikei::Start()
{
	m_skinModelRedner = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRedner->Init(L"modelData/haikei.cmo");

	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/BTL.wav");
	m_sound->Play(true);
	//m_sound->SetVolume(1.0f);
	return true;

}
void haikei::Update()
{
	return ;
}
