#pragma once

#include"../OpenAlCore/OpenAlCore.h"
#include"../FileLoad/LoadSoundFile.h"
#include<string>
#include<memory>

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
	CLoadSoundFile* AudioSource;	// �o�b�t�@�[���
	SoundResources AudioResource;	// �I�[�f�B�I���

	std::string UseMaterialAtt;

	//OpenAL�p
	ALint Buf;
	ALuint Source;


};

