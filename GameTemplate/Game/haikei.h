#pragma once
class haikei:public IGameObject
{
public:
	haikei();
	~haikei();
	bool Start()override;
	void Update()override;
	prefab::CSkinModelRender* m_skinModelRedner;
	prefab::CSoundSource* m_sound;
};

