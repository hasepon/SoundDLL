#pragma once

#include"OpenAL/OpenAlCore/OpenALDevice.h"
#include"OpenAL/AudioSpeaker/AudioSpeaker.h"

#include<map>
#include <utility>
#include <functional>

namespace htAudio {

	/// <summary>
	/// Device�̊Ǘ��ƃX�s�[�J�[�̊Ǘ�������N���X
	/// </summary>
	class AudioManager
	{
	public:
		AudioManager();
		~AudioManager();

		int AddSpeaker(std::string filepath, std::string SoundName, std::string material);
		int AddSpeaker(std::string filepath, uint16_t id);
		int AddSpeaker(std::string filepath, std::string soundname);

		void ThreadUpdate();

		bool SpeakerFormat( int numb );
		void RemoveSpeaker( int numb );

		void AllDelete();

	private:
		OpenALDevice* AlDevice;						// �f�o�C�X�|�C���^
		std::map<ALuint, AudioSpeaker*> SpeakerMap;	// speaker��map �Ǘ�������
		std::thread UpdateThread;	// �����A�b�v�f�[�g�p�̃X���b�h

	};

}