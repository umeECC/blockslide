#include "Effect.h"
#include "SpriteData.h"
#include "Audio.h"

void EffectManager::init()
{
    AudioManager::getInstance().loadSound(L"exsSound", L"./Data/Sounds/se_dead1.wav");
}

void effectExplos(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:        
        AudioManager::getInstance().playSound(L"exsSound", 0.5f, false);
        obj->timer = 0;
        obj->state++;
        [[fallthrough]];

    case 1:
        obj->timer++;
        //obj->sprData = sprBomb[obj->timer >> 2];
        if (!obj->sprData) obj->clear();
        break;
    }
}

