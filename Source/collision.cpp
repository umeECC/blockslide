//#include "all.h"
////#include "Gimmick.h"
//#include <algorithm>  // std::find
//#include"map.h"
////using namespace MapManager;
//
//// �����蔻�肪���菈�������s����}�b�v�`�b�v
//const int collisionTiles[] = { 1,2,3 };
//
//// �����蔻��Ȃ��ŏ��������s����}�b�v�`�b�v
//const int gimmickTiles[] = { 9, 10, 11, 12, 13, 14, 15,16,17,18,19,21 }; // �M�~�b�N��ID�������Ŏw��
//
//// �v���C���[�̓����蔻��p�̕��ƍ���
//const float playerWidth = 64.0f;  // �v���C���[�̕�
//const float playerHeight = 64.0f; // �v���C���[�̍���
//
//const int stepsize = 64;
//
//bool checkCollision(float x, float y) {
//    bool isCollision = false; // �����蔻��̃t���O
//
//
//    // �v���C���[����߂�̈�̍���ƉE���̍��W�����߂�
//    int left = (int)(x / stepsize);
//    int top = (int)(y / stepsize);
//    int right = (int)((x + playerWidth) / stepsize);
//    int bottom = (int)((y + playerHeight) / stepsize);
//
//    // �}�b�v�͈̔͊O�̏ꍇ�̓`�F�b�N���Ȃ�
//    if (left < 0 || right >= MapManager::MAP_WIDTH || top < 0 || bottom >= MapManager::MAP_HEIGHT) {
//        return false; // �͈͊O�͖���
//    }
//
//    for (int tileY = top; tileY <= bottom; tileY++) {
//        for (int tileX = left; tileX <= right; tileX++) {
//            /*int tile = mapData[tileY][tileX];
//            int gimmickTile = MapManager::gimickMap[tileY][tileX];*/
//
//
//
//            // �Փ˃^�C���̏���
//            //if (std::find(std::begin(collisionTiles), std::end(collisionTiles), tile) != std::end(collisionTiles)) {
//            //    isCollision = true;
//
//            //    if (y + playerHeight > tileY * stepsize && y + playerHeight <= (tileY + 1) * stepsize) {
//            //        //isGrounded = true; // �v���C���[�̉��[���^�C���͈͓̔��ɂ���ꍇ
//            //    }
//            //}
//            ////if (gimmickTile == 16 || gimmickTile == 17 || gimmickTile == 18) {
//            //    isCollision = true;
//            //    if (y + playerHeight > tileY * stepsize && y + playerHeight <= (tileY + 1) * stepsize) {
//            //        isGrounded = true; // �v���C���[�̉��[���^�C���͈͓̔��ɂ���ꍇ
//            //    }
//            //}
//            // �M�~�b�N�^�C���̏���
//            //if (std::find(std::begin(gimmickTiles), std::end(gimmickTiles), gimmickTile) != std::end(gimmickTiles)) {
//            //    //handleGimmick(gimmickTile, tileX, tileY, x, y, isCollision, bottom);
//
//            //}
//
//            //debug::setString("player.speed.y : %f", playerSpeedY);
//
//
//        }
//    }
//
//
//    //return isCollision; // �Փ˔���̌��ʂ�Ԃ�
//}