/*!
 * @brief	�X�L�����f�������_���[
 */

#pragma once

#include "tkEngine/culling/tkObjectFrustumCulling.h"

namespace tkEngine{
namespace prefab{
	class CSkinModelRender : public IGameObject {
	public:
		
		/*!
		 * @brief	�R���X�g���N�^�B
		 */
		CSkinModelRender() {}
		/*!
		* @brief	�������B
		*@param[in]	filePath	�t�@�C���p�X�B
		*@param[in]	animationClips		�A�j���[�V�����N���b�v�B
		*@param[in]	numAnimClip			�A�j���[�V�����N���b�v�̐��B
		*@param[in]	enUpdateAxis		fbx�̏�����B
		*@param[in] maxInstance			�C���X�^���X�̐�
		*/
		void Init(const wchar_t* filePath,
			CAnimationClip* animationClips = nullptr,
			int numAnimationClips = 0,
			EnFbxUpAxis fbxUpAxis = enFbxUpAxisZ,
			int maxInstance = 1 );
		
		/*!
		* @brief	�`��̒��O�Ƀt�b�N�������֐���ݒ肷��B
		*param[in]	func	�t�b�N�֐��B�� void Fook(CRenderContext& rc, CSkinModel& model);
		*/
		void SetPreDrawFookFunction(CSkinModel::OnDrawFookFunction func)
		{
			m_skinModel.SetPreDrawFookFunction(func);
		}
		/*!
		* @brief	�`�悪�I�������Ƀt�b�N�������֐���ݒ肷��B
		*param[in]	func	�t�b�N�֐��B�� void Fook(CRenderContext& rc, CSkinModel& model);
		*/
		void SetPostDrawFookFunction(CSkinModel::OnDrawFookFunction func)
		{
			m_skinModel.SetPostDrawFookFunction(func);
		}
	
		/*!
		* @brief	�A�j���[�V�������Đ��B
		*@param[in]	clipNo	�A�j���[�V�����N���b�v�̔ԍ��B�R���X�g���N�^�ɓn����animClipList�̕��тƂȂ�B
		*@param[in]	interpolateTime		�⊮����(�P�ʁF�b)
		*/
		void PlayAnimation(int animNo, float interpolateTime = 0.0f)
		{
			m_animation.Play(animNo, interpolateTime);
		}
		/*!
		* @brief	�A�j���[�V�����̍Đ����H
		*/
		bool IsPlayingAnimation() const
		{
			return m_animation.IsPlaying();
		}
		/*!
		* @brief	�V���h�E�L���X�^�[�̃t���O��ݒ�B
		*@param[in]	flag	�V���h�E�L���X�^�[�̃t���O�B
		*/
		void SetShadowCasterFlag(bool flag)
		{
			m_skinModel.SetShadowCasterFlag(flag);
		}
		/*!
		* @brief	�V���h�E���V�[�o�[�̃t���O��ݒ�B
		*@param[in]	flag	�V���h�E���V�[�o�[�̃t���O�B
		*/
		void SetShadowReceiverFlag(bool flag)
		{
			m_skinModel.SetShadowReceiverFlag(flag);
		}
		/*!
		*@brief	�t���[�Y�����Ă���{�[���̕��s�ړ��ʂ��擾�B
		*@details
		* �ŏI�|�[�Y�̃A�j���[�V���������B
		*/
		CVector3 GetFreezeBoneTranslate() const
		{
			return m_animation.GetFreezeBoneTranslate();
		}
		/*!
		*@brief	�A�j���[�V�����C�x���g���X�i�[��o�^�B
		*@return
		* �o�^���ꂽ���X�i�[�B
		*/
		void AddAnimationEventListener(std::function<void(const wchar_t* clipName, const wchar_t* eventName)> eventListener)
		{
			m_animation.AddAnimationEventListener(eventListener);
		}
		/*!
		*@brief	���W��ݒ�B
		*/
		void SetPosition(const CVector3& position)
		{
			m_position = position;
		}
		/*!
		*@brief	��]��ݒ�B
		*/
		void SetRotation(const CQuaternion& rotation)
		{
			m_rotation = rotation;
		}
		/*!
		*@brief	�g�嗦��ݒ�B
		*/
		void SetScale(const CVector3& scale)
		{
			m_scale = scale;
		}
		/*!
		*@brief	���W�A��]�A�g������ׂčX�V�B
		*@param[in]	pos			���W�B
		*@param[in]	rot			��]�B
		*@param[in] scale		�g��B
		*/
		void SetPRS(const CVector3& trans, const CQuaternion& rot, const CVector3& scale)
		{
			SetPosition(trans);
			SetRotation(rot);
			SetScale(scale);
		}
		/*!
		*@brief	�C���X�^���V���O�f�[�^���X�V�B
		*@param[in]	pos			���W�B
		*@param[in]	rot			��]�B
		*@param[in] scale		�g��B
		*/
		void UpdateInstancingData(const CVector3& trans, const CQuaternion& rot, const CVector3& scale)
		{
			m_skinModel.UpdateInstancingData(trans, rot, scale);
		}
		/*!
		*@brief	�X�L�����f���f�[�^���擾�B
		*/
		CSkinModelData& GetSkinModelData() 
		{
			return m_skinModelData;
		}
		const CSkinModelData& GetSkinModelData() const
		{
			return m_skinModelData;
		}
		/*!
		*@brief	�X�L�����f���擾�B
		*/
		CSkinModel& GetSkinModel()
		{
			return m_skinModel;
		}
		const CSkinModel& GetSkinModel() const
		{
			return m_skinModel;
		}
		/*!
		*@brief	������J�����O���s�����ǂ����̃t���O��ݒ�E
		*@details
		* ���̃t���O��true�ɂ���Ɖ�ʂɉf���Ă��Ȃ��I�u�W�F�N�g�͕\������Ȃ��Ȃ�܂��B
		*/
		void SetFrustumCulling(bool flag)
		{
			m_isFrustumCulling = flag;
		}
		/*!
		*@brief	���f���}�e���A���̌����B
		*@param[in]	findEffect		�}�e���A�������������ɌĂ΂��R�[���o�b�N�֐�
		*/
		void FindMaterial(std::function<void(CModelEffect*)> findMaterial) const
		{
			m_skinModel.FindMaterial(findMaterial);
		}
		/*!
		*@brief	�A�j���[�V�����̍X�V�t���O��ݒ�B
		*/
		void SetUpdateAnimationFlag(bool flag)
		{
			m_isUpdateAnimation = flag;
		}
		/*!
		*@brief	�t�H���[�h�����_�����O�̃t���O��ݒ�B
		*@details
		* �t���O�𗧂Ă�ƃt�H���[�h�����_�����O���s���܂��B
		* �����x�[�X�����_�����O�ȊO�̓���ȃ����_�����O���s�������ꍇ�͗L���ɂ��Ă��������B
		*/
		void SetForwardRenderFlag(bool flag)
		{
			m_isForwardRender = flag;
		}
		void FindVertexPosition(std::function<void(CVector3* pos)>);
		/*!
		*@brief	�{�[������������B
		*@param[in]	boneName	�{�[���̖��O�B
		*@return	���������{�[���̃A�h���X�B������Ȃ������ꍇ��nullptr��Ԃ��܂��B
		*@details
		* ���̊֐��͌������s�����߁A�������d���ł��B
		* Update�֐��ȂǂŖ��t���[���Ăяo���̂ł͂Ȃ��A
		* �������֐��ȂǂŁA�N���X�̃����o�ϐ��ɃL���b�V������̂��I�X�X�����܂��B
		*/
		CBone* FindBone(const wchar_t* boneName) const
		{
			const auto& skeleton = m_skinModelData.GetSkeleton();
			auto boneId = skeleton.FindBoneID(boneName);
			if (boneId != -1) {
				return skeleton.GetBone(boneId);
			}
			return nullptr;

		}
	private:
		void ForwardRender(CRenderContext& rc) override final;
		/*!
		* @brief	�X�V�O�ɌĂ΂��֐��B
		*/
		bool Start() override final;
		/*!
		* @brief	���O�X�V�B
		*/
		void PreUpdate() override final
		{
			if (m_skinModelData.IsAvailable() == true) {
				m_skinModel.BeginUpdateInstancingData();
			}
		}
		/*!
		* @brief	�X�V�B
		*/
		void Update() override final;
		/*!
		* @brief	�x���X�V�B
		*/
		void PostUpdate() override final
		{
			if (m_skinModelData.IsAvailable() == true) {
				m_skinModel.EndUpdateInstancingData();
			}
		}
		
		/*!
		* @brief	�A�j���[�V�����̏������B
		*/
		void InitAnimation(CAnimationClip* animationClips, int numAnimationClips);
	private:
		bool						m_isForwardRender = false;		//!<�t�H���[�h�����_�����O�B
		CAnimationClip*				m_animationClips = nullptr;			//!<�A�j���[�V�����N���b�v�B
		int							m_numAnimationClips = 0;			//!<�A�j���[�V�����N���b�v�̐��B
		CVector3 					m_position = CVector3::Zero;		//!<���W�B
		CQuaternion	 				m_rotation = CQuaternion::Identity;	//!<��]�B
		CVector3					m_scale = CVector3::One;			//!<�g�嗦�B
		EnFbxUpAxis					m_enFbxUpAxis = enFbxUpAxisZ;		//!<FBX�̏�����B
		CAnimation					m_animation;						//!<�A�j���[�V�����B
		CSkinModel					m_skinModel;						//!<�X�L�����f���B
		CSkinModelData				m_skinModelData;					//!<�X�L�����f���f�[�^�B
		const std::wstring			m_filePath;							//!<�t�@�C���p�X�B
		bool						m_isFrustumCulling = false;			//!<�t���X�^���J�����O���s���H
		CObjectFrustumCulling		m_frustumCulling;					//!<�t���X�^���J�����O�B
		bool						m_isUpdateAnimation = true;			//!<�A�j���[�V�������X�V����H
	};
}
}