#pragma once
class Eney :public IGameObject
{
public:
	Eney();
	~Eney();
	bool Start()override;
	void Update()override;
	prefab::CSkinModelRender* m_skinModel_obake;
};

