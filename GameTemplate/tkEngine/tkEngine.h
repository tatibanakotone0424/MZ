/*!
 *@brief	�G���W���B
 */
#pragma once

#include "tkEngine/graphics/tkRenderTarget.h"
#include "tkEngine/timer/tkStopwatch.h"
#include "tkEngine/Sound/tkSoundEngine.h"
#include "tkEngine/graphics/tkGraphicsEngine.h"
#include "tkEngine/tkEngineStruct.h"
#include "tkEngine/physics/tkPhysics.h"
#include "tkEngine/random/tkRandom.h"
#include "tkEngine/graphics/font/tkFont.h"
#include "tkEngine/debug/math/tkVectorRender.h"

namespace tkEngine{
	/*!
	 *@brief	�G���W���B
	 */
	class CEngine : Noncopyable {
	private:
		/*!
		 *@brief	�R���X�g���N�^�B
		 */
		CEngine();
		/*!
		 *@brief	�f�X�g���N�^�B
		 */
		~CEngine();
	public:
		/*!
		 *@brief	�������B
		 *@param[in]	initParam		�������p�����[�^�B
		 */
		bool Init(const SInitParam& initParam);
		/*!
		 *@brief	�I�������B
		 */
		void Final();
		/*!
		 *@brief	�Q�[�����[�v�����s�B
		 */
		void RunGameLoop();
		/*!
		 *@brief	�C���X�^���X���擾�B
		 */
		static CEngine& GetInstance()
		{
			static CEngine* instance = nullptr;
			if (instance == nullptr) {
				instance = new CEngine;
			}
			return *instance;
		}

		/*!
		* @brief	�Q�[���p�b�h�̎擾�B
		*@param[in]	padNo	�p�b�h�ԍ�
		*/
		CPad& GetPad(int padNo)
		{
			TK_ASSERT(padNo < CPad::CONNECT_PAD_MAX && padNo >= 0, "padNo is invalid");
			return m_pad[padNo];
		}
		/*!
		* @brief	�T�E���h�G���W���̎擾�B
		*/
		CSoundEngine& GetSoundEngine()
		{
			return m_soundEngine;
		}
		/*!
		* @brief	�O���t�B�b�N�X�G���W���̎擾�B
		*/
		CGraphicsEngine& GetGraphicsEngine()
		{
			return m_graphicsEngine;
		}
		/*!
		 *@brief	�������[���h�̎擾�B
		 */
		CPhysicsWorld& GetPhysicsWorld()
		{
			return m_physicsWorld;
		}
		/*!
		*@brief	���C���J�������擾�B
		*/
		CCamera& GetMainCamera()
		{
			return m_graphicsEngine.GetMainCamera();
		}
		/*!
		*@brief	2D�J�������擾�B
		*/
		CCamera& GetMainCamera2D()
		{
			return m_graphicsEngine.Get2DCamera();
		}
		/*!
		 *@brief	�����擾�B
		 */
		CRandom& GetRandom()
		{
			return m_random;
		}
		/*!
		*@brief		���\�[�X�̃A�����[�h�B
		*@details
		* �풓���\�[�X�ȊO�̃��\�[�X�����ׂăA�����[�h���܂��B
		* �V�[���̐؂�ւ��ȂǂŁA���\�[�X�̃A�����[�h���K�v�ȏꍇ�Ɏg�p���Ă��������B
		*/
		void ResourceUnload();
#if BUILD_LEVEL != BUILD_LEVEL_MASTER
		prefab::CVectorRender* GetVectorRender()
		{
			return m_vectorRender;
		}
#endif
	private:
		/*!
		 *@brief	�E�B���h�E�������B
		 */
		bool InitWindow( const SInitParam& initParam );

		/*!
		* @brief	�E�B���h�E�v���V�[�W���B
		*/
		static LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		/*!
		* @brief	�X�V�B
		*/
		void Update();
	private:
		HINSTANCE				m_hInst = nullptr;	//!<�A�v���P�[�V�����̃C���X�^���X�B
		HWND					m_hWnd = nullptr;	//!<�E�B���h�E�n���h���B
		CGraphicsEngine			m_graphicsEngine;							//!<�O���t�B�b�N�G���W���B
		CSoundEngine			m_soundEngine;								//!<�T�E���h�G���W���B
		CPhysicsWorld			m_physicsWorld;								//!<�������[���h�B
		int						m_screenWidth = 0;							//!<�X�N���[���̕��B
		int						m_screenHeight = 0;							//!<�X�N���[���̍����B
		CPad					m_pad[CPad::CONNECT_PAD_MAX];				//!<�Q�[���p�b�h�B
		CRandom					m_random;									//!<�����B
#if BUILD_LEVEL != BUILD_LEVEL_MASTER
		std::unique_ptr<CFont>	m_font;
		float					m_fps = 30.0f;
		float					m_timeTotal = 0.0f;
		prefab::CVectorRender*  m_vectorRender = nullptr;					//!<�x�N�g�������_���[�B
#endif
	public:
		CStopwatch				m_sw;
	};

	/*!
	* @brief	Engine�̃C���X�^���X���擾�B
	*/
	static inline CEngine& Engine()
	{
		return CEngine::GetInstance();
	}
	/*!
	* @brief	CPad�̃C���X�^���X���擾�B
	*/
	static inline CPad& Pad(int padNo)
	{
		return Engine().GetPad(padNo);
	}
	/*!
	* @brief	CSoundEngine�̃C���X�^���X���擾�B
	*/
	static inline CSoundEngine& SoundEngine()
	{
		return Engine().GetSoundEngine();
	}
	/*!
	* @brief	CGraphicsEngine�̃C���X�^���X���擾�B
	*/
	static inline CGraphicsEngine& GraphicsEngine()
	{
		return Engine().GetGraphicsEngine();
	}
	/*!
	 *@brief	CPhysicsWorld�̃C���X�^���X���擾�B
	 */
	static inline CPhysicsWorld& PhysicsWorld()
	{
		return Engine().GetPhysicsWorld();
	}
	/*!
	* @brief	���C���J�����̃C���X�^���X���擾�B
	*/
	static inline CCamera& MainCamera()
	{
		return GraphicsEngine().GetMainCamera();
	}
	/*!
	* @brief	���C���J����(2D)�̃C���X�^���X���擾�B
	*/
	static inline CCamera& MainCamera2D()
	{
		return GraphicsEngine().Get2DCamera();
	}
	/*!
	* @brief	CLightManager�̃C���X�^���X���擾�B
	*/
	static inline CLightManager& LightManager()
	{
		return GraphicsEngine().GetLightManager();
	}
	/*!
	* @brief	GPU�C�x���g�̊J�n�B
	*/
	static inline void BeginGPUEvent(const wchar_t* name)
	{
		GraphicsEngine().BeginGPUEvent(name);
	}
	/*!
	* @brief	GPU�C�x���g�̏I���B
	*/
	static inline void EndGPUEvent()
	{
		GraphicsEngine().EndGPUEvent();
	}
	/*!
	 *@brief	�������擾�B
	 */
	static inline CRandom& Random()
	{
		return Engine().GetRandom();
	}
	/*!
	*@brief	G-Buffer��SRV���擾�B
	*/
	static inline CShaderResourceView& GetGBufferSRV(EnGBuffer gBuffer)
	{
		return Engine().GetGraphicsEngine().GetGBufferRender().GetRenderTarget(gBuffer).GetRenderTargetSRV();
	}
}


