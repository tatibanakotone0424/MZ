/*!
 *@brief	�O�l�̎��_�̃Q�[���J�����̃R���W�����\���o�[
 */

#pragma once

#include "tkEngine/Physics/tkSphereCollider.h"

namespace tkEngine{
	/*!
	 *@brief	�J�����̃R���W�����\���o�[�B
	 *@details
	 * ��ʓI�ȎO�l�̎��_�̃Q�[���J�����̃R���W�����\���o�[��񋟂��܂��B
	 */
	class CCameraCollisionSolver{
	public:
		/*!
		 *@brief	�R���X�g���N�^�B
		 */
		CCameraCollisionSolver();
		/*!
		 *@brief	�f�X�g���N�^�B
		 */
		~CCameraCollisionSolver();
		/*!
		 *@brief	�������B
		 *@param[in]	radius		�J�����̃o�E���f�B���O�X�t�B�A�̔��a�B
		 */
		void Init(float radius);
		/*!
		 *@brief	�R���W���������̎��s�B
		 *@param[out]	result		�R���W�����������s�������ʂ̃J�����̎��_�̍��W���i�[�����B
		 *@param[in]	position	�J�����̎��_�B
		 *@param[in]	target		�J�����̒����_�B
		 *@return	�R���W�����������s�����ꍇ��true���Ԃ��Ă���B
		 */
		bool Execute(CVector3& result, const CVector3& position, const CVector3& target);
	private:
		CSphereCollider		m_collider;		 //�R���C�_�[�B
		float				m_radius = 0.0f; //���a�B
	};
}