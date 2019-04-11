/*!
 * @brief	�x�N�g�������_���[
 */

#pragma once

namespace tkEngine {
#if BUILD_LEVEL != BUILD_LEVEL_MASTER
	
	/*!
	 * @brief	�x�N�g���̃f�o�b�O�o�́B
	 */
	static inline void OutputDebugVector(CVector3 vector, CVector3 origin, const char* name = "no name")
	{
		prefab::CVectorRender::SRenderData renderData = { name, vector, origin  };
		Engine().GetVectorRender()->AddVector(renderData);
	}
	/*!
	* @brief	�x�N�g���̃f�o�b�O�o�̗͂L���t���O��ݒ肷��B
	*/
	static inline void SetOutputDebugVectorEnable(bool flag)
	{
		Engine().GetVectorRender()->SetRenderFlag(flag);
	}
	static inline void SetOutputDebugVectorNameList(const std::vector<std::string>& list)
	{
		Engine().GetVectorRender()->SetRenderVectorNameList(list);
	}
#else
	static inline void OutputDebugVector( CVector3 vector, CVector3 origin )
	{
	}
	static inline void SetEnableOutputDebugVector(bool flag)
	{
	}
	static inline void SetRenderVectorNameList(const std::vector<std::string>& list)
	{
	}
#endif
}
