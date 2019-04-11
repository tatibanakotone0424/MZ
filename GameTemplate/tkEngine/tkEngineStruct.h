/*!
 *@brief	tkEngine�p�̊e��\���́B
 */

#pragma once

namespace tkEngine{
	/*!
	 *@brief	�G���W���������p�̃p�����[�^�B
	 */
	struct SInitParam{
		SInitParam(){
			memset(this, 0, sizeof(SInitParam));
			graphicsConfing.shadowRenderConfig.Init();
			graphicsConfing.tonemapConfig.Init();
			gameObjectPrioMax = 32;
		}
		HINSTANCE hInstance;				//!<�A�v���P�[�V�����C���X�^���X�B
		int	screenWidth;					//!<�X�N���[���̕��B
		int	screenHeight;					//!<�X�N���[���̍����B
		int frameBufferHeight;				//!<�t���[���o�b�t�@�̕��B���ꂪ�����𑜓x�B
		int frameBufferWidth;				//!<�t���[���o�b�t�@�̍����B���ꂪ�����𑜓x�B
		int nCmdShow;						//!<
		unsigned char gameObjectPrioMax;	//!<�Q�[���I�u�W�F�N�g�̗D��x�̍ő�l(32�܂�)
		SGraphicsConfig graphicsConfing;	//!<�`��R���t�B�O�B
	};
}