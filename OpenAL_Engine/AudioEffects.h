#pragma once
#include"OpenAL/OpenAlCore/OpenALDevice.h"

class AudioEffects
{
public:
	AudioEffects();
	~AudioEffects();

	void Update();
	
protected:


	ALuint EffectSlot;		// エフェクトスロット
	ALuint Effect;			// エフェクト

};

