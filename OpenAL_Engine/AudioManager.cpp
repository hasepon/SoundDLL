#include "AudioManager.h"


namespace htAudio {

	AudioManager::AudioManager()
	{
		AlDevice = new OpenALDevice();

		Updateflag = true;

		// Updateのスレッド化
		UpdateThread = std::thread(&AudioManager::ThreadUpdate , this);

	}

	AudioManager::~AudioManager()
	{
		for(auto var : SpeakerMap)
		{
			delete var.second;
		}

		SpeakerMap.clear();

		if (AlDevice == nullptr)
		{
			return;
		}
		delete AlDevice;
	}

	int AudioManager::AddSpeaker(std::string filepath, std::string SoundName, std::string material)
	{
		ALuint numb;
		AudioSpeaker* speaker;

		speaker = new AudioSpeaker(filepath, SoundName, material);
		numb = speaker->GetSpeakerNumb();

		SpeakerMap.insert( std::make_pair(numb,speaker) );

		return numb;

	}

	int AudioManager::AddSpeaker(std::string filepath, uint16_t id)
	{
		ALuint numb;
		AudioSpeaker* speaker;

		speaker = new AudioSpeaker(filepath, id);
		numb = speaker->GetSpeakerNumb();

		SpeakerMap.insert(std::make_pair(numb, speaker));

		return numb;
	}

	int AudioManager::AddSpeaker(std::string filepath, std::string soundname)
	{
		ALuint numb;
		AudioSpeaker* speaker;

		speaker = new AudioSpeaker(filepath, soundname);
		numb = speaker->GetSpeakerNumb();

		SpeakerMap.insert(std::make_pair(numb, speaker));

		return numb;
	}

	void AudioManager::RemoveSpeaker(int numb)
	{
		auto itr = SpeakerMap.find(numb);

		// あった場合の処理
		if (SpeakerMap.end() != itr)
		{
			delete SpeakerMap[numb];
			SpeakerMap.erase(itr);
		}

	}

	bool AudioManager::SpeakerFormat(int numb)
	{
		auto itr = SpeakerMap.find(numb);

		if (SpeakerMap.end() != itr)
		{
			return SpeakerMap[numb]->GetResourceflag();
		}

		return false;
	}

	/// <summary>
	/// 
	/// </summary>
	void AudioManager::ThreadUpdate()
	{
		while (Updateflag)
		{
			for (auto itr = SpeakerMap.begin(); itr != SpeakerMap.end(); itr++)
			{
				itr->second->Update();
			}
		}
	}

	void AudioManager::AllDelete()
	{
		Updateflag = false;

		UpdateThread.join();

		for (auto itr = SpeakerMap.begin(); itr != SpeakerMap.end(); itr++)
		{
			delete itr->second;
			SpeakerMap.erase(itr);
		}

		SpeakerMap.clear();
	}

	bool AudioManager::AddEffect(AudioEffects* effect, int speakerId)
	{
		SpeakerMap[speakerId]->AddEffects(effect);
	}

}