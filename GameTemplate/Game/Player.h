#pragma once
class Player:public IGameObject
{
public:
	Player();
	~Player();
	bool Start()override;
	void Update()override;
	enum {
		Animation_R,
		Animation_LR,
		AnimationNoKazu,
	};
	enum {
	  JOUTAI_R,
	  JOUTAI_RL,
	  JOUTAI_TAIKI
	};
	CAnimationClip m_animClips[AnimationNoKazu];
	prefab::CSkinModelRender* m_skinModel;
	prefab::CFontRender* m_font;
	int geizi = 0;
};

