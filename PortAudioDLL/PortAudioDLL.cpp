// PortAudioDLL.cpp : アプリケーションのエントリ ポイントを定義します。
//
#include<Windows.h>
#include<stdio.h>

#include<tchar.h>

#include"Singleton.h"
#include"PortAudio/OpenAlCore/OpenAlCore.h"
#include"PortAudio/AudioSpeaker/AudioSpeaker.h"

/// <summary>
/// 再生テスト
/// </summary>
/// <returns></returns>
int main()
{
	OpenAlCore& OAC = Singleton<OpenAlCore>::get_instance();
	
	std::string path = _T("../Data/Xml/SoundList.xml");
	std::string soundname = _T("TestBGM");
	
	AudioSpeaker* speaker;
	speaker = new AudioSpeaker(path, soundname);
	speaker->Play();

	// ループ処理をするよ
	while (1)
	{
		speaker->Update();
	}

	delete speaker;
	SingletonFinalizer::finalize();

    return 0;
}

