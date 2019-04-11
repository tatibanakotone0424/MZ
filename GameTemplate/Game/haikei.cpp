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
	return true;

}
void haikei::Update()
{
	return ;
}
