#pragma once

#include "../LoadSoundFile.h"

//-----------------------------------------------------------
//	WaveFile�������T�E���h���\�[�X�ǂݍ���
//	�Q�l https://gist.github.com/xrated/2700516
//------------------------------------------------------------
class CLoadWave : public CLoadSoundFile
{
public:
	CLoadWave(std::string soundlistnumb, bool Loopflag);
	~CLoadWave();
	std::size_t PreloadBuffer();
	std::size_t PrepareStreamBuffer();
	std::size_t UpdateStreamBuffer();

private:
	void LoadFormat();
	// ���f�[�^�̓ǂݍ���
	std::size_t ReadDataRaw(long first, long end,void* buffer);
	// ���K���ς݃f�[�^�ǂݍ���
	std::size_t ReadNormalize(long first, long end, float* left, float* right);
};
