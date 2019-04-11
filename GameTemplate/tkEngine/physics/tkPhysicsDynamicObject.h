/*!
 * @brief	���I�����I�u�W�F�N�g�B
 */

#pragma once

#include "tkEngine/physics/tkMeshCollider.h"
#include "tkEngine/physics/tkRigidBody.h"

namespace tkEngine{
	/*!
	 * @brief	���I�����I�u�W�F�N�g
	 *@details
	 * �������[
	 */
	class CPhysicsDynamicObject{
	public:
		/*!
		 * @brief	�R���X�g���N�^�B
		 */
		CPhysicsDynamicObject();
		/*!
		 * @brief	�f�X�g���N�^�B
		 */
		~CPhysicsDynamicObject();
		/*!
		 * @brief	���b�V���̐ÓI�I�u�W�F�N�g���쐬�B
		 *@param[in]	skinModel	�X�L�����f���B
		 *@param[in]	pos			���W�B
		 *@param[in]	rot			��]�B
		 *@param[in]	scale		�g�嗦�B
		 */
		void CreateMeshObject(CSkinModel& skinModel, CVector3 pos, CQuaternion rot, CVector3 scale);
		void CreateMeshObject(prefab::CSkinModelRender* skinModelRender, CVector3 pos, CQuaternion rot, CVector3 scale);
	private:
		CMeshCollider m_meshCollider;		//!<���b�V���R���C�_�[�B
		CRigidBody m_rigidBody;				//!<���́B
	};
}