#include "Audio.h"
#include <iostream>

AudioManager::AudioManager()
{
    audioEngine = std::make_unique<DirectX::AudioEngine>();
}

AudioManager::~AudioManager()
{
    if (audioEngine)
    {
        audioEngine->Suspend();
    }
}

void AudioManager::init()
{
    if (audioEngine)
    {
        for (auto& instance : soundInstances)
        {
            instance.second->Stop();
        }
        soundInstances.clear();

        audioEngine->Reset();

    }
}

void AudioManager::loadSound(const std::wstring& soundName, const std::wstring& filePath)
{
    auto soundEffect = std::make_unique<DirectX::SoundEffect>(audioEngine.get(), filePath.c_str());
    soundEffects[soundName] = std::move(soundEffect);
}

void AudioManager::playSound(const std::wstring& soundName, float volume, bool loop)
{
    auto it = soundEffects.find(soundName);
    if (it != soundEffects.end())
    {
        auto instance = it->second->CreateInstance();
        if (!instance)
        {
            std::wcerr << L"Failed to create sound instance for: " << soundName << std::endl;
            return;
        }
        instance->SetVolume(volume);
        instance->Play(loop);
        soundInstances[soundName] = std::move(instance);
        std::wcout << L"Playing sound: " << soundName << std::endl;
    }
    else
    {
        std::wcout << L"Sound not found: " << soundName << std::endl;
    }
}


void AudioManager::stopSound(const std::wstring& soundName)
{
    auto it = soundInstances.find(soundName);
    if (it != soundInstances.end())
    {
        it->second->Stop();
    }
}

bool AudioManager::isPlaying(const std::wstring& soundName)
{
    auto it = soundInstances.find(soundName);
    if (it != soundInstances.end())
    {
        return it->second->GetState() == DirectX::SoundState::PLAYING;
    }
    return false;
}

void AudioManager::update()
{
    if (audioEngine)
    {
        audioEngine->Update();
    }
}
