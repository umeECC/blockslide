#pragma once
#include<memory>
#include "../GameLib/game_lib.h"

class AudioManager
{

private:
    std::unique_ptr<DirectX::AudioEngine> audioEngine;
    std::unordered_map<std::wstring, std::unique_ptr<DirectX::SoundEffect>> soundEffects;
    std::unordered_map<std::wstring, std::unique_ptr<DirectX::SoundEffectInstance>> soundInstances;

public:
    AudioManager();
    ~AudioManager();

    static AudioManager& getInstance()
    {
        static AudioManager instance;
        return instance;
    }

    void init();
    void loadSound(const std::wstring& soundName, const std::wstring& filePath);
    void playSound(const std::wstring& soundName, float volume = 1.0f, bool loop = false);
    void stopSound(const std::wstring& soundName);
    bool isPlaying(const std::wstring& soundName);
    void update();
};

