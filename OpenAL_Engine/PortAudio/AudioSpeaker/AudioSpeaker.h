#pragma once


#include"../OpenAlCore/OpenALDevice.h"
#include"../FileLoad/LoadSoundFile.h"
#include<string>
#include<memory>

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
		
	private:
		bool SetBuffer(ALuint Buf);	// �o�b�t�@�̐ݒ�
		void Init();

		CLoadSoundFile * AudioSource;	// �o�b�t�@�[���
		SoundResources AudioResource;	// �I�[�f�B�I���

		std::string UseMaterialAtt;		// �}�e���A���̐ݒ�

		//OpenAL�p
		ALuint Buffers[2];// �o�b�t�@�̐ݒ�
		ALuint Source;	// Source�̐ݒ�

	};

}