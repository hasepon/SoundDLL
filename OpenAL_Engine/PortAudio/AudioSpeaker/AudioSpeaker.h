#pragma once


#include"../OpenAlCore/OpenALDevice.h"
#include"../FileLoad/LoadSoundFile.h"
#include<string>
#include<memory>
#include<array>
#include <complex.h>
#include<AL/alc.h>
#include<fftw3.h>

#pragma comment(lib, "libfftw3-3.lib")
#pragma comment(lib, "libfftw3f-3.lib")
#pragma comment(lib, "libfftw3l-3.lib")

using namespace std;

namespace htAudio
{
	/// <summary>
	/// サウンドの再生用クラス
	/// サウンド再生の窓口クラス
	/// </summary>
	class AudioSpeaker
	{
	public:
		// 情報指定
		AudioSpeaker(std::string filepath, std::string SoundName, std::string material);
		// ID指定
		AudioSpeaker(std::string filepath, int id);
		//指定なし
		AudioSpeaker(std::string filepath, std::string SoundName);
		
		~AudioSpeaker();// デスト

		bool Play();	// 再生
		bool Update();	// 更新
		bool Stop();	// 停止
		bool Pause();	// 一時停止
		
		void SetPosition(float x, float y, float z);
		void SetPosition(float pos[3]);

		void FFT();

	private:
		bool SetBuffer(ALuint Buf);	// バッファの設定
		void Init();

		std::shared_ptr<CLoadSoundFile> AudioSource;	// バッファー情報
		SoundResources AudioResource;	// オーディオ情報

		std::string UseMaterialAtt;		// マテリアルの設定

		//OpenAL用
		std::array<ALuint,2> Buffers;// バッファの設定
		ALuint Source;	// Sourceの設定

		// speaker情報
		ALfloat Position[3];	// Position
		ALfloat Volume;		// ボリューム

	};

}