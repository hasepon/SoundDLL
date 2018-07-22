#include "DistortionEffect.h"


namespace htAudio {

	/// <summary>
	/// �T�v :: �f�B�X�g�[�V����
	/// �A�N�Z�X���� :: public
	/// </summary>
	/// <param name="source">�ΏۂƂ���Source</param>
	DistortionEffect::DistortionEffect(ALuint source)
	{
		LPALGENEFFECTS algeneffect = (LPALGENEFFECTS)alGetProcAddress("alGenEffects");

		alGenAuxiliaryEffectSlots(1, &EffectSlot);

		if (alGetError() != AL_NO_ERROR)
			return;

		algeneffect(1, &Effect);

		if (alGetError() != AL_NO_ERROR)
			return;

		if (alIsEffect(Effect))
		{
			alEffecti(Effect, AL_EFFECT_TYPE, AL_EFFECT_DISTORTION);
			if (alGetError() != AL_NO_ERROR)
			{
				printf("���o�[�u�̍쐬�Ɏ��s���Ă܂�\n");
				return;
			}
		}

		alAuxiliaryEffectSloti(EffectSlot, AL_EFFECTSLOT_EFFECT, Effect);

		if (alGetError() == AL_NO_ERROR)
			printf("Successfully loaded effect into effect slot\n");

		alSource3i(source, AL_AUXILIARY_SEND_FILTER, EffectSlot, 0, NULL);
	}


	DistortionEffect::~DistortionEffect()
	{
	}

	/// <summary>
	/// �T�v :: �G�b�W�̒l��ݒ� �����قǘc�݂܂�
	/// �A�N�Z�X���� :: public
	/// </summary>
	/// <param name="val">�G�b�W�̒l</param>
	/// MAX(1.0) :: MIN(0.0) :: Default(0.2)
	void DistortionEffect::SetEdge(float val)
	{
		Info.EDGE = val;
		alEffectf(Effect, AL_DISTORTION_EDGE, Info.EDGE);
	}

	/// <summary>
	/// �T�v :: �}�X�^�[�{�����[���̐ݒ�
	/// �A�N�Z�X���� :: public
	/// </summary>
	/// <param name="gain">�Q�C���̒l</param>
	/// MAX(1.0) :: MIN(0.01) :: Default(0.05)
	void DistortionEffect::SetGain(float gain)
	{
		Info.GAIN = gain;
		alEffectf(Effect, AL_DISTORTION_GAIN, Info.GAIN);
	}

	/// <summary>
	/// �T�v :: ���[�p�X�t�B���^�[�̐ݒ�
	/// �A�N�Z�X���� :: public
	/// </summary>
	/// <param name="val">���g���ш�</param>
	/// MAX(24000.0) :: MIN(80.0) :: Default(8000.0)
	void DistortionEffect::SetLowpassCutOff(float val)
	{
		Info.LOWPASS_CUTOFF = val;
		alEffectf(Effect, AL_DISTORTION_LOWPASS_CUTOFF, Info.LOWPASS_CUTOFF);
	}

	/// <summary>
	/// �T�v :: �|�X�g�f�B�X�g�[�V����
	/// �A�N�Z�X���� :: public
	/// </summary>
	/// <param name="val">�|�X�g�f�B�X�g�[�V�����̒l</param>
	/// MAX(24000.0) :: MIN(80.0) :: Default(3600.0)
	void DistortionEffect::SetEQEnter(float val)
	{
		Info.EQCENTER = val;
		alEffectf(Effect, AL_DISTORTION_EQCENTER, Info.EQCENTER);
	}

	/// <summary>
	/// �T�v :: �|�X�g�f�B�X�g�[�V�����̍������l��ݒ�
	/// �A�N�Z�X���� :: public
	/// </summary>
	/// <param name="val">���̒l</param>
	/// MAX(24000.0) :: MIN(80.0) :: Default(3600.0)
	void DistortionEffect::SetEQBandWidth(float val)
	{
		Info.EQBANDWIDTH = val;
		alEffectf(Effect, AL_DISTORTION_EQBANDWIDTH, Info.EQBANDWIDTH);
	}

}