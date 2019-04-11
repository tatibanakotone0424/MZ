/*!
 * @brief	�ÓI�I�u�W�F�N�g�B
 */


#include "tkEngine/tkEnginePreCompile.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/physics/tkBoxCollider.h"
#include "tkEngine/physics/tkSphereCollider.h"

using namespace std;
namespace tkEngine{
	CPhysicsGhostObject::CPhysicsGhostObject()
	{
	}
	CPhysicsGhostObject::~CPhysicsGhostObject()
	{
		Release();
	}
	
	void CPhysicsGhostObject::Release()
	{
		if (m_isRegistPhysicsWorld == true) {
			PhysicsWorld().RemoveCollisionObject(m_ghostObject);
			m_isRegistPhysicsWorld = false;
		}
	}
	void CPhysicsGhostObject::CreateCommon(CVector3 pos, CQuaternion rot, std::unique_ptr<ICollider> collider)
	{
		m_collider = move(collider);
		m_ghostObject.setCollisionShape(m_collider->GetBody());
		btTransform btTrans;
		btTrans.setOrigin({ pos.x, pos.y, pos.z });
		btTrans.setRotation({ rot.x, rot.y, rot.z, rot.w });
		m_ghostObject.setWorldTransform(btTrans);

		//�����G���W���ɓo�^�B
		PhysicsWorld().AddCollisionObject(m_ghostObject);
		m_isRegistPhysicsWorld = true;
	}
	void CPhysicsGhostObject::CreateBox(CVector3 pos, CQuaternion rot, CVector3 size)
	{
		Release();
		auto boxCollider = make_unique<CBoxCollider>();
		boxCollider->Create(size);
		CreateCommon(pos, rot, move(boxCollider));
	}
	void CPhysicsGhostObject::CreateCapsule(CVector3 pos, CQuaternion rot, float radius, float height )
	{
		Release();
		auto capusuleCollider = make_unique<CCapsuleCollider>();
		capusuleCollider->Create(radius, height);
		CreateCommon(pos, rot, move(capusuleCollider));
	}
	
	void CPhysicsGhostObject::CreateSphere(CVector3 pos, CQuaternion rot, float radius)
	{
		Release();
		auto sphereCollider = make_unique<CSphereCollider>();
		sphereCollider->Create(radius);
		CreateCommon(pos, rot, move(sphereCollider));
	}
	/*!
	* @brief	���b�V���`��̃S�[�X�g�I�u�W�F�N�g���쐬�B
	*@param[in]	pos					���W�B
	*@param[in]	rot					��]�B
	*@param[in]	skinModelData		�X�L�����f���f�[�^�B
	*/
	void CPhysicsGhostObject::CreateMesh(CVector3 pos, CQuaternion rot, const CSkinModelData& skinModelData)
	{
		Release();
		auto meshCollider = make_unique<CMeshCollider>();
		meshCollider->CreateFromSkinModel(skinModelData, nullptr);
		CreateCommon(pos, rot, move(meshCollider));
	}

}
