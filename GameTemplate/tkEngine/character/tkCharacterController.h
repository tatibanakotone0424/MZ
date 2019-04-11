/*!
 * @brief	�L�����N�^�R���g���[���[�B
 */

#pragma once

#include "tkEngine/Physics/tkSphereCollider.h"
#include "tkEngine/Physics/tkCapsuleCollider.h"
#include "tkEngine/Physics/tkRigidBody.h"

namespace tkEngine{
	/*!
	 * @brief	�L�����N�^�R���g���[���[�B
	 */
	class CCharacterController{
	public:
		CCharacterController() {

		}
		~CCharacterController()
		{
			RemoveRigidBoby();
		}
		/*!
		 * @brief	�������B
		 *@param[in]	radius		�J�v�Z���R���C�_�[�̔��a�B
		 *@param[in]	height		�J�v�Z���R���C�_�[�̍����B
		 *@param[in]	position	�����ʒu�B
		 */
		void Init(float radius, float height, const CVector3& position);
		/*!
		 * @brief	���s�B
		 *@param[in, out]	moveSpeed		�ړ����x�B�����ŏd�͉������v�Z����A���̌��ʂ�moveSpeed�ɔ��f����܂��B
		 *@param[in]	deltaTime		�o�ߎ��ԁB�P�ʂ͕b�B�f�t�H���g�ł́A�P�t���[���̌o�ߎ��Ԃ��n����Ă��܂��B
		 *@return �ړ���̃L�����N�^�[�̍��W�B
		 */
		const CVector3& Execute(CVector3& moveSpeed, float deltaTime = GameTime().GetFrameDeltaTime());
		[[deprecated("This function will be delete. please don't use.")]]
		const CVector3& Execute(float deltaTime, CVector3& moveSpeed )
		{
			return Execute(moveSpeed, deltaTime);
		}
		/*!
		 * @brief	���W���擾�B
		 */
		const CVector3& GetPosition() const
		{
			return m_position;
		}
		/*!
		 * @brief	���W��ݒ�B
		 */
		void SetPosition(const CVector3& pos)
		{
			m_position = pos;
		}

		/*!
		 * @brief	�W�����v��������
		 */
		bool IsJump() const
		{
			return m_isJump;
		}
		/*!
		* @brief	�n�ʏ�ɂ��邩����B
		*/
		bool IsOnGround() const
		{
			return m_isOnGround;
		}
		/*!
		* @brief	�R���C�_�[���擾�B
		*/
		CCapsuleCollider* GetCollider()
		{
			return &m_collider;
		}
		/*!
		* @brief	���̂��擾�B
		*/
		CRigidBody* GetRigidBody()
		{
			return &m_rigidBody;
		}
		/*!
		* @brief	���̂𕨗��G���W������폜�B�B
		*/
		void RemoveRigidBoby();
	private:
		bool				m_isInited = false;				//�������ς݁H
		CVector3 			m_position = CVector3::Zero;	//���W�B
		bool 				m_isJump = false;				//�W�����v���H
		bool				m_isOnGround = true;			//�n�ʂ̏�ɂ���H
		CCapsuleCollider	m_collider;						//�R���C�_�[�B
		float				m_radius = 0.0f;
		float				m_height = 0.0f;		
		CRigidBody			m_rigidBody;					//���́B
	};
}