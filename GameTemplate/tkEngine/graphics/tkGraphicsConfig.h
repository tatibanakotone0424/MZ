/*!
 * @brief	�O���t�B�b�N�X�R���t�B�O�B
 */

#pragma once

namespace tkEngine{
	/*!
	 * @brief	�e�����̃R���t�B�O�B
	 */
	struct SShadowRenderConfig{
		void Init()
		{
			isEnable = false;
			shadowMapWidth = 512;
			shadowMapHeight = 512;
			softShadowLevel = EnSoftShadowQualityLevel::enNone;
			nearPlane = -1.0f;
			farPlane = -1.0f;
			lightHeight = UnitM(20.0f);
			depthOffset[0] = 0.0002f;
			depthOffset[1] = 0.0002f;
			depthOffset[2] = 0.0002f;
			offsetTexelWorld = 0.05f;
		}
		bool 	isEnable;						//!<�e�𗎂Ƃ��������L�����ǂ����̃t���O�B
		int		shadowMapWidth;					//!<�V���h�E�}�b�v�̕��B
		int		shadowMapHeight;				//!<�V���h�E�}�b�v�̍����B
		float	nearPlane;						//!<�ߕ��ʂ܂ł̋����B(�ݒ���s��Ȃ���Ύ����v�Z����܂��B)				
		float	farPlane;						//!<�����ʂ܂ł̋����B(�ݒ���s��Ȃ���Ύ����v�Z����܂��B)				
		float	lightHeight;					//!<���C�g�̍����B
		float	depthOffset[NUM_SHADOW_MAP];	//!<�V���h�E�I�t�Z�b�g�B���̒l��傫������ƁA�e�������ɂ����Ȃ�B
		float	offsetTexelWorld;				//!<�u���[�̎��Ƀt�F�b�`����I�t�Z�b�g���W�B���[���h��Ԃ̗ʁB�l���傫���قǑ傫���{�P��B
		EnSoftShadowQualityLevel	softShadowLevel;				//!<�\�t�g�V���h�E�̕i�����x���B�l���傫���قǕi�����オ��B�ő�Q
												//0�F�n�[�h�V���h�E�A1�FScreenSpaceSoftShadow�A2:ScreenSpaceSoftShadow + PCF
	};
	/*!
	* @brief	Bloom�̃R���t�B�O
	*/
	struct SBloomConfig {		
		bool	isEnable = false;		//!<�u���[�����L�����ǂ����̃t���O�B
	};

	/*!
	* @brief	��ʊE�[�x�̃R���t�B�O�B
	*/
	struct SDofConfig {
		bool isEnable = false;					//��ʊE�[�x���L�����ǂ����̃t���O�B
	};
	/*!
	* @brief	�A���`�G�C���A�X�̃R���t�B�O�B
	*/
	struct SAAConfig {
		bool isEnable = false;					//�A���`�G�C���A�X���L�����ǂ����̃t���O�B
	};
	/*!
	* @brief	���[�V�����u���[�̃R���t�B�O�B
	*/
	struct SMotionBlurConfig {
		bool isEnable = false;
	};
	/*!
	* @brief	�g�[���}�b�v�̃R���t�B�O�B
	*/
	struct STonemapConfig {
		void Init()
		{
			isEnable = false;
			luminance = 0.34f;
		}
		bool isEnable = false;
		float luminance = 0.34f;			//���邳�B�l���傫���قǖ��邭�Ȃ�܂��B
	};
	/*!
	* @brief	�f�B�U�����O�̃R���t�B�O�B
	*/
	struct SDitheringConfig {
		bool isEnable = false;
	};
	/*!
	* @brief	SSR�̃R���t�B�O�B
	*/
	struct SScreenSpaceReflectionConfig {
		bool isEnable = false;
	};
	/*!
	 * @brief	�O���t�B�b�N�X�R���t�B�O�B
	 */
	struct SGraphicsConfig{
		SShadowRenderConfig				shadowRenderConfig;		//!<�e�̏����̃R���t�B�O�B
		SBloomConfig					bloomConfig;			//!<Bloom�̃R���t�B�O�B
		SDofConfig						dofConfig;				//!<��ʊE�[�x�̃R���t�B�O�B
		SAAConfig						aaConfig;				//!<�A���`�G�C���A�X�̃R���t�B�O�B
		SMotionBlurConfig				motionBlurConfig;		//<!���[�V�����u���[�̃R���t�B�O�B
		STonemapConfig					tonemapConfig;			//!<�g�[���}�b�v�̃R���t�B�O�B
		SDitheringConfig				ditheringConfig;		//!<�f�B�U�����O�B
		SScreenSpaceReflectionConfig	ssrConfig;				//!<ssr�R���t�B�O
	};
}
