#pragma once

#include"../OpenAlCore/OpenALDevice.h"
#include"../FileLoad/LoadSoundFile.h"
#include"../../I3DAudio.h"
#include<string>
#include<memory>
#include<array>
#include<complex.h>
#include<future>

#include<AL/efx.h>
#include<AL/efx-creative.h>

using namespace std;

namespace htAudio
{
	/// <summary>
	/// �T�E���h�̍Đ��p�N���X
	/// �T�E���h�Đ��̑����N���X
	/// </summary>
	class AudioSpeaker
	{
	public:
		// ���w��
		AudioSpeaker(std::string filepath, std::string SoundName, std::string material);
		// ID�w��
		AudioSpeaker(std::string filepath, int id);
		//�w��Ȃ�
		AudioSpeaker(std::string filepath, std::string SoundName);
		
		~AudioSpeaker();// �f�X�g

		bool Update();	// �X�V

		bool GetResourceflag() { return AudioResource.Soundtype.CreateFlag; }
		void StopUpdate();

		bool AddEffects(AudioEffects* effect);

		ALuint GetSpeakerNumb() { return Source; }

	private:
		bool Play();	// �Đ�
		bool Stop();	// ��~
		bool Pause();	// �ꎞ��~

		bool SetBuffer(ALuint Buf);						// �o�b�t�@�̐ݒ�
		void Init();									// ���ʏ���������

		bool Successinit = false;						// �����������t���O
		bool LoopFlag = true;							// updateloop�t���O

		std::shared_ptr<CLoadSoundFile> AudioSource;	// �o�b�t�@�[���
		SoundResources AudioResource;					// �I�[�f�B�I���

		std::string UseMaterialAtt;						// �}�e���A���̐ݒ�
		std::string Filepath;							// �t�@�C���p�X

		std::array<ALuint,2> Buffers;					// �o�b�t�@�̐ݒ�
		ALuint Source;									// Source�̐ݒ�
		
		std::vector<AudioEffects*> EffectSlot;		// �G�t�F�N�g�X���b�g
		
		ALfloat Volume;			// �{�����[��
		I3DAudio* I3D;			// 3DAudio�̐ݒ�

		

	};

}