#pragma once

namespace tkEngine{

	class ICollider;

	//���̏��B
	struct RigidBodyInfo {
		RigidBodyInfo() :
			collider(NULL),
			mass(0.0f)
		{
			pos = CVector3::Zero;
			rot = CQuaternion::Identity;
		}
		CVector3 pos;				//���W�B
		CQuaternion rot;			//��]�B
		ICollider* collider;		//�R���C�_�[�B
		float mass;					//���ʁB

	};
	//���̃N���X�B
	class CRigidBody
	{
		std::unique_ptr<btRigidBody>			m_rigidBody;		//���́B
		std::unique_ptr<btDefaultMotionState>	m_myMotionState;	//���[�V�����X�e�[�g�B
		bool m_isAddPhysicsWorld = false;			//�������[���h�ɒǉ�����Ă���H
	public:
		~CRigidBody();
		void Release();
		void Create(RigidBodyInfo& rbInfo);
		btRigidBody* GetBody()
		{
			return m_rigidBody.get();
		}
		//�������[���h�ɓo�^���̈������B
		void SetMarkAddPhysicsWorld()
		{
			m_isAddPhysicsWorld = true;
		}
		//�������[���h�ɓo�^���̈���O���B
		void SetUnmarkAddPhysicsWorld()
		{
			m_isAddPhysicsWorld = false;
		}
		//�������[���h�ɒǉ�����Ă���H
		bool IsAddPhysicsWorld() const
		{
			return m_isAddPhysicsWorld;
		}
	};
}
