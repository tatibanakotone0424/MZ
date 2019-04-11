#pragma once
class Eney :public IGameObject
{
public:
	Eney();
	~Eney();
	bool Start()override;
	void Update()override;
	enum {
		OBAKE_UGOKI,
		AnimationNokazu
	};
	enum {
		JOUTAI_TAIKI
	};
	prefab::CSkinModelRender* m_skinModel_obake;
	CAnimationClip m_animation[AnimationNokazu];
	int joutai = 0;
};

