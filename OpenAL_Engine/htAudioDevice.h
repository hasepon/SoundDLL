#pragma once


#include"OpenAL/OpenAlCore/OpenALDevice.h"
#include"Definclude.h"

using namespace htAudio;

/// <summary>
/// �I�[�f�B�I�f�o�C�X���쐬���邽�߂̐錾
/// </summary>
extern "C"
{
	UNITY_INTERFACE_EXPORT OpenALDevice* UNITY_INTERFACE_API htaCreate();
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API htaDelete(OpenALDevice* Instance);
}