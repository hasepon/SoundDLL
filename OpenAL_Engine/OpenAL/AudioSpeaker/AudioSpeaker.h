#pragma once


#include"../OpenAlCore/OpenALDevice.h"
#include"../FileLoad/LoadSoundFile.h"
#include<string>
#include<memory>
#include<array>
#include<complex.h>

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

		bool Play();	// �Đ�
		bool Update();	// �X�V
		bool Stop();	// ��~
		bool Pause();	// �ꎞ��~
		bool GetResourceflag() { return AudioResource.Soundtype.CreateFlag; }

		void SetPosition(float x, float y, float z);
		void SetPosition(float pos[3]);

		void SetVelocity(float x, float y, float z);
		void SetVelocity(float vec[3]);

		void SetDirection(float x, float y, float z);
		void SetDirection(float dir[3]);

		void SetConeOuterGain(float val);
		float GetConeOuterGain();

		void SetConeInnerAngle(float val);
		float GetConeInnerAngle();

		void SetConeOuterAngle(float val);
		float GetConeOuterAngle();

		bool AddEffects(EFFECTSNUM num);
		
		void SetReverb(float density, float diffusion, float gain, float decayTime);
		
	private:
		bool SetBuffer(ALuint Buf);						// �o�b�t�@�̐ݒ�
		void Init();									// ���ʏ���������
		bool SettingEffect(EFFECTSNUM,int EffectDef);	// �G�t�F�N�g������

		bool Successinit = false;						// �����������t���O

		std::shared_ptr<CLoadSoundFile> AudioSource;	// �o�b�t�@�[���
		SoundResources AudioResource;					// �I�[�f�B�I���

		std::string UseMaterialAtt;						// �}�e���A���̐ݒ�
		std::string Filepath;							// �t�@�C���p�X

		std::array<ALuint,2> Buffers;					// �o�b�t�@�̐ݒ�
		ALuint Source;									// Source�̐ݒ�
		
		std::array<ALuint, MAX_EFFECTS> EffectSlot;		// �G�t�F�N�g�X���b�g
		std::array<ALuint, MAX_EFFECTS> Effect;			// �G�t�F�N�g

		// speaker���
		ALfloat Position[3];	// Position
		ALfloat Volume;			// �{�����[��
		ALfloat Velocity[3];	// �ړ����x
		ALfloat Direction[3];	// ����
		ALfloat ConeOuterGain;	// �R�[���̊O���Q�C�����l
		ALfloat InnerAngle;		// �����̊p�x
		ALfloat OuterAngle;		// �O���̊p�x

	};

}