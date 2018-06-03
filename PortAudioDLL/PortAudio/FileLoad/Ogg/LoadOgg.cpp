

#include "LoadOgg.h"

CLoadOgg::CLoadOgg(std::string soundlistnumb, bool Loopflag)
{
	m_SoundResouce.DataChunkSample = NULL;
	m_SoundResouce.DataChunkSize = NULL;
	m_SoundResouce.firstSampleOffSet = NULL;
	m_SoundResouce.HasGotWaveFormat = false;
	m_SoundResouce.Format = {};
	m_SoundResouce.LoopSound = Loopflag;
	m_SoundResouce.PresetSoundName = FilePath+soundlistnumb+".ogg";
	m_TotalReadSize = 0;
	
	m_Playbuf = new char[FRAMES_PER_BUFFER];
	m_Secondbuf = new char[FRAMES_PER_BUFFER];
	LoadFormat();
	//�������̓ǂ݂���
	Update();

}


CLoadOgg::~CLoadOgg()
{
	ov_clear(&m_Ovf);
	delete[] m_Playbuf;
	delete[] m_Secondbuf;
	m_SoundResouce.PresetSoundName.clear();
}

void CLoadOgg::LoadFormat()
{
	// oggfile���J��
	if (ov_fopen(m_SoundResouce.PresetSoundName.c_str(), &m_Ovf))
	{
		// �I�[�v�����s
		printf("ogg�t�@�C���̃I�[�v�����s");
		return;
	}

	// oggvorbisfile�����擾
	vorbis_info* vi = ov_info(&m_Ovf, -1);

	m_SoundResouce.Format.wFormatTag = WAVE_FORMAT_PCM;
	m_SoundResouce.Format.nChannels = vi->channels;
	m_SoundResouce.Format.nSamplesPerSec = vi->rate;
	m_SoundResouce.Format.nBlockAlign = vi->channels * 2;
	m_SoundResouce.Format.wBitsPerSample = 16;
	m_SoundResouce.Format.nAvgBytesPerSec = (vi->rate) * (vi->channels * 2);
	m_SoundResouce.Format.cbSize = 0;

	m_SoundResouce.HasGotWaveFormat = true;

}

void CLoadOgg::Update()
{
	// oggvorbisfile�����擾
	vorbis_info* vi = ov_info(&m_Ovf, -1);
	std::size_t readsample;

	if (m_SoundResouce.SubmitTimes == 0)
	{
			readsample = ReadDataRaw(0, 0, m_Playbuf);
			if (readsample > 0)
			{
				m_SoundResouce.SubmitTimes = 1;
			}
	}
	else if (m_SoundResouce.SubmitTimes == 1)
	{
		readsample = ReadDataRaw(0, 0, m_Secondbuf);
		if (readsample > 0)
		{
			m_SoundResouce.SubmitTimes = 0;
		}
	}
	m_TotalReadSize += readsample;
}

/// <summary>
/// �w��T�C�Y�ł̃o�b�t�@�̎擾
/// </summary>
/// <param name="start"></param>
/// <param name="sample"></param>
/// <param name="buffer"></param>
/// <returns></returns>
std::size_t CLoadOgg::ReadDataRaw(const std::size_t start, const std::size_t sample, char* buffer)
{
	if (buffer == 0)
	{
		return 0;
	}

	memset(buffer, 0, FRAMES_PER_BUFFER);
	int requestsize = FRAMES_PER_BUFFER;
	int bitstream = 0;
	int readsize = 0;
	unsigned int comsize = 0;
	bool isadjust = false;

	if (FRAMES_PER_BUFFER < requestsize)
	{
		requestsize = FRAMES_PER_BUFFER;
		isadjust = true;
	}

	int cnt = 0;

	//�ǂݍ��݊J�n
	while (1)
	{
		// ogg�t�@�C���̓ǂݍ���
		readsize = ov_read(&m_Ovf, (char*)(buffer + comsize), requestsize, 0, 2, 1, &bitstream);

		comsize += readsize;

		if (readsize == 0)
		{
			// �t�@�C���G���h
			if (m_SoundResouce.LoopSound == true)
			{
				// ���ɖ߂�
				ov_time_seek(&m_Ovf, 0.0f);
			}
			else
			{
				// �ǂݍ��ݏI��
				return comsize;
			}
		}

		if (comsize >= FRAMES_PER_BUFFER)
		{
			return comsize;
		}

		if (FRAMES_PER_BUFFER - comsize < FRAMES_PER_BUFFER)
		{
			isadjust = true;
			requestsize = FRAMES_PER_BUFFER - comsize;
		}

	}
	// �G���[
	return 0;
}


