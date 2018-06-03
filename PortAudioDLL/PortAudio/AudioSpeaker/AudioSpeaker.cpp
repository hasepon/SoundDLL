#include "AudioSpeaker.h"
#include"../FileLoad/Ogg/LoadOgg.h"
#include"../FileLoad/Wave/LoadWave.h"
#include"../AudioFormatData/AudioFormatData.h"
#include"../../Singleton.h"

/// <summary>
/// �Đ����̏�����
/// </summary>
/// <param name="filepath"></param>
/// <param name="SoundName"></param>
/// <param name="material"></param>
AudioSpeaker::AudioSpeaker(std::string filepath, std::string SoundName, std::string material)
{

	// �I�[�f�B�I����xml����擾
	AudioFormatData afd;
	AudioResource.Soundtype = afd.GetAudioFormatData(filepath, SoundName);

	// �������E���Ă���̂ŏ���
	// �擾��񂩂���f�[�^���擾
	for (auto var : AudioResource.Soundtype.Soundinfo)
	{
		// �}�e���A���̓���I�u�W�F�N�g�̌���
		if (material == var.MaterialObj)
		{
			if (var.Extension == "wav")
			{
				AudioSource = new CLoadWave(var.SoundName, AudioResource.Soundtype.Loopflag);
			}
			else if (var.Extension == "ogg")
			{
				AudioSource = new CLoadOgg(var.SoundName, AudioResource.Soundtype.Loopflag);
			}
			else {
				printf("�t�@�C���`�����Ή����Ă��Ȃ��`���ł�");
			}
		}
	}

}

AudioSpeaker::AudioSpeaker(std::string filepath,int id)
{

	// �I�[�f�B�I����xml����擾
	AudioFormatData afd;
	AudioResource.Soundtype = afd.GetAudioFormatData(filepath, id);

	// �}�e���A���̐ݒ肪�Ȃ��ꍇid[0]�̉���炷
	if (AudioResource.Soundtype.Soundinfo[id].Extension == "wav")
	{
		AudioSource = new CLoadWave(AudioResource.Soundtype.Soundinfo[id].SoundName, AudioResource.Soundtype.Loopflag);
	}
	else if (AudioResource.Soundtype.Soundinfo[id].Extension == "ogg")
	{
		AudioSource = new CLoadOgg(AudioResource.Soundtype.Soundinfo[id].SoundName, AudioResource.Soundtype.Loopflag);
	}
	else {
		printf("�t�@�C���`�����Ή����Ă��Ȃ��`���ł�");
	}
}

AudioSpeaker::AudioSpeaker(std::string filepath, std::string SoundName)
{
	// �I�[�f�B�I����xml����擾
	AudioFormatData afd;
	AudioResource.Soundtype = afd.GetAudioFormatData(filepath, SoundName);

	// �}�e���A���̐ݒ肪�Ȃ��ꍇid[0]�̉���炷
	if (AudioResource.Soundtype.Soundinfo[0].Extension == "wav")
	{
		AudioSource = new CLoadWave(AudioResource.Soundtype.Soundinfo[0].SoundName, AudioResource.Soundtype.Loopflag);
	}
	else if (AudioResource.Soundtype.Soundinfo[0].Extension == "ogg")
	{
		AudioSource = new CLoadOgg(AudioResource.Soundtype.Soundinfo[0].SoundName, AudioResource.Soundtype.Loopflag);
	}
	else {
		printf("�t�@�C���`�����Ή����Ă��Ȃ��`���ł�");
	}

	AudioSource->Update();
	Buf = (ALint)AudioSource->GetPrimaryOggbuffer();
	OpenAlCore& OAC = Singleton<OpenAlCore>::get_instance();
	Source = OAC.SetBuffer(Buf);
}

AudioSpeaker::~AudioSpeaker()
{
	OpenAlCore& OAC = Singleton<OpenAlCore>::get_instance();
	OAC.Clear(Source, Buf);
	delete AudioSource;
}

bool AudioSpeaker::Play()
{
	printf("�Đ����܂�\n");
	OpenAlCore& OAC = Singleton<OpenAlCore>::get_instance();
	OAC.Play(Source);
	return true;
}

bool AudioSpeaker::Update()
{
	printf("�X�V���܂�\n"); 
	AudioSource->Update();
	Buf = (ALint)AudioSource->GetPrimaryOggbuffer();
	OpenAlCore& OAC = Singleton<OpenAlCore>::get_instance();
	OAC.SetBuffer(Buf);
	return true;
}

bool AudioSpeaker::Stop()
{
	printf("��~���܂�\n");
	OpenAlCore& OAC = Singleton<OpenAlCore>::get_instance();
	OAC.Stop(Source);
	
	return true;
}

bool AudioSpeaker::Pause() 
{
	printf("���f���܂�\n");
	OpenAlCore& OAC = Singleton<OpenAlCore>::get_instance();
	OAC.Pause(Source);
	return true;
}

