#include "Back.h"
#include "SpriteData.h"

void backUpdate(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0:
        obj->sprData = &sprBack;
        obj->state++;
        break;
    case 1:

        break;
    }
}

void BackManager::init()
{
    OBJ2DManager::init();
    searchSet(backUpdate, { 0, 0 });
}