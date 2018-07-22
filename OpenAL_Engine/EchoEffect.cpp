#include "EchoEffect.h"

namespace htAudio {

	/// <summary>
	/// �T�v :: �G�R�[�̐ݒ�
	/// �A�N�Z�X���� :: public
	/// </summary>
	/// <param name="source">�ΏۂƂ���Source</param>
	EchoEffect::EchoEffect(ALuint source)
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
			alEffecti(Effect, AL_EFFECT_TYPE, AL_EFFECT_ECHO);
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

	EchoEffect::~EchoEffect()
	{
	}

	/// <summary>
	/// �T�v :: �f�B���C�̐ݒ�
	/// �A�N�Z�X���� :: public
	/// </summary>
	/// <param name="delay">delay�̒l�̐ݒ�</param>
	/// MAX(0.207) :: MIN(0.0) :: Default(0.1)
	void EchoEffect::SetDelay(float delay)
	{
		Info.DELAY = delay;
		alEffectf(Effect, AL_ECHO_DELAY, Info.DELAY);
	}

	/// <summary>
	/// �T�v :: LR�̃f�B���C�̐ݒ�
	/// </summary>
	/// <param name="lrdelay"></param>
	void EchoEffect::SetLRDelay(float lrdelay)
	{
		Info.LRDELAY = lrdelay;
		alEffectf(Effect, AL_ECHO_LRDELAY, Info.LRDELAY);
	}

	void EchoEffect::SetDamping(float damping)
	{
		Info.DAMPING = damping;
		alEffectf(Effect, AL_ECHO_DAMPING, Info.DAMPING);
	}

	void EchoEffect::SetFeedBack(float feedback)
	{
		Info.FEEDBACK = feedback;
		alEffectf(Effect, AL_ECHO_FEEDBACK, Info.FEEDBACK);
	}

	void EchoEffect::SetSpRead(float spread)
	{
		Info.SPREAD = spread;
		alEffectf(Effect, AL_ECHO_SPREAD, Info.SPREAD);
	}

}