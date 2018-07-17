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
		bool GetResourceflag() { return AudioResource.Soundtype.CreateFlag; }

		void SetPosition(float x, float y, float z);
		void SetPosition(float pos[3]);

		void SetVelocity(float x, float y, float z);
		void SetVelocity(float vec[3]);

		//void SetOrientation(float AtVec[3], float UpVec[3]);
		//void SetOrientation(float AtOrient[6]);

		void SetDirection(float x, float y, float z);
		void SetDirection(float dir[3]);

		void SetConeOuterGain(float val);
		float GetConeOuterGain();

		void SetConeInnerAngle(float val);
		float GetConeInnerAngle();

		void SetConeOuterAngle(float val);
		float GetConeOuterAngle();

		//float GetMaxVolume();
		//float GetLowVolume();
		//float GetDefaultVolume();

	private:
		bool SetBuffer(ALuint Buf);	// �o�b�t�@�̐ݒ�
		void Init();

		bool Successinit = false;	// ����������

		std::shared_ptr<CLoadSoundFile> AudioSource;	// �o�b�t�@�[���
		SoundResources AudioResource;	// �I�[�f�B�I���

		std::u16string UseMaterialAtt;		// �}�e���A���̐ݒ�
		std::string Filepath;

		//OpenAL�p
		std::array<ALuint,2> Buffers;// �o�b�t�@�̐ݒ�
		ALuint Source;	// Source�̐ݒ�

		// speaker���
		ALfloat Position[3];	// Position
		ALfloat Volume;			// �{�����[��
		ALfloat Velocity[3];	// �ړ����x
		//ALfloat Orientation[6];	// �p��
		ALfloat Direction[3];	// ����
		ALfloat ConeOuterGain;	
		ALfloat InnerAngle;
		ALfloat OuterAngle;

	};

}