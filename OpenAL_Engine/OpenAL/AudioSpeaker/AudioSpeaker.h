#pragma once


#include"../OpenAlCore/OpenALDevice.h"
#include"../FileLoad/LoadSoundFile.h"
#include<string>
#include<memory>
#include<array>
#include<complex.h>
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

		bool Play();	// �Đ�
		bool Update();	// �X�V
		bool Stop();	// ��~
		bool Pause();	// �ꎞ��~
		
		void SetPosition(float x, float y, float z);
		void SetPosition(float pos[3]);

	private:
		bool SetBuffer(ALuint Buf);	// �o�b�t�@�̐ݒ�
		void Init();

		bool Successinit = false;	// ����������

		std::shared_ptr<CLoadSoundFile> AudioSource;	// �o�b�t�@�[���
		SoundResources AudioResource;	// �I�[�f�B�I���

		std::u16string UseMaterialAtt;		// �}�e���A���̐ݒ�

		//OpenAL�p
		std::array<ALuint,2> Buffers;// �o�b�t�@�̐ݒ�
		ALuint Source;	// Source�̐ݒ�

		// speaker���
		ALfloat Position[3];	// Position
		ALfloat Volume;		// �{�����[��

	};

}