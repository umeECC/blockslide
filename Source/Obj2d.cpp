#include "Obj2d.h"



void OBJ2D::update()
{
    if (mover) mover(this);
}

void OBJ2D::draw()
{
    if (sprData)
    {
        auto oldState = GameLib::getBlendMode();
        GameLib::setBlendMode(blendState);
        sprData->draw(position, scale, rotation, color);
        GameLib::setBlendMode(oldState);
    }
}

bool OBJ2D::checkpress()
{
    //// 挟まれチェック：上下 + 左右の両方が埋まっていたら
    if ((hitLeft && hitRight) || (hitTop && hitBottom))
    {

        return true;
    }
    return false;
}

bool OBJ2D::checkhit()
{
    if ((hitLeft || hitRight || hitTop || hitBottom))
    {
        return true;
    }
    return false;
}

void OBJ2DManager::init()
{
    for (auto& obj : *this)
    {
        obj.clear();
    }
}

void OBJ2DManager::update()
{
    for (auto& obj : *this)
    {
        obj.update();
    }
}

void OBJ2DManager::draw()
{
    for (auto& obj : *this)
    {
        obj.draw();
    }
}

OBJ2D* OBJ2DManager::searchSet(OBJ2D::MOVER mover, const VECTOR2& position)
{
    for (auto& obj : *this)
    {
        if (obj.mover != nullptr) { continue; }

        obj.clear();
        obj.position = position;
        obj.mover = mover;
        return &obj;
    }
    return nullptr;
}

/// <summary>
/// //////////////
/// </summary>
void OBJ2DManager::clearHit()
{
    for (auto& obj : *this)
    {
        obj.clearHit();
    }
}

bool OBJ2DManager::checkpress()
{
    bool press = false;

    for (auto& obj : *this)
    {
        if (obj.checkpress())
        {
            press = true;
        }

    }
    return press;
}

bool OBJ2DManager::checkhit()
{
    bool toge = false;

    for (auto& obj : *this)
    {
        if (obj.checkhit())
        {
            toge = true;
        }

    }
    return toge;
}