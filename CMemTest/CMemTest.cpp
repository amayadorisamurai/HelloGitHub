/**
*@file CMemTest.cpp
*@brief ���������[�N�e�X�g�p
* @author �t���T��
* @date 2019/05/22
* @details ���������[�N���e�X�g���邽�߂ɈӐ}�I�ɔ��������Ă��܂��B
* @brief 3 �𑫂��֐�
* @param[in] a(���̒l) �v�Z���錳�̐��l
* @param[out] b(�����) �v�Z���ʂ��������
* @return bool ��� true ��ԋp���܂��B
* @details �������� 3 �𑫂��āA�� 2 �����Ɍ��ʂ���
* @brief PointData �N���X�̐���
* @details �ڍׂȃN���X�̐���
*/


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//#include "pch.h"
#include <iostream>

#ifdef _DEBUG
#define DBG_NEW new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

struct PointData {
	int x;
	int y;
	int z;
};
struct CharacterData {
	char name[100];
	int hp;
	int mp;
};

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 160;  //�u���[�N�|�C���g
	PointData*pPointData = DBG_NEW PointData;
	
	for (int i = 0; i < 50; i++) {
		delete pPointData;   //�u���[�N�|�C���g
		pPointData = DBG_NEW PointData;
	}
	_RPT0(_CRT_WARN, "Set Break Point");  //�u���[�N�|�C���g
	delete pPointData;   //�u���[�N�|�C���g

	CharacterData*pCharacterData = DBG_NEW CharacterData;
	for (int i = 0; i < 50; i++) {
		delete pCharacterData;  //�u���[�N�|�C���g
		pCharacterData = DBG_NEW CharacterData;
	}
	delete pCharacterData;  //�u���[�N�|�C���g

		_CrtDumpMemoryLeaks();  //�u���[�N�|�C���g

	return 0;
}


#include<malloc.h>
int main() {
	char*c = (char*)alloca(100);
	*c = 'a';
}

bool function(int a, int &b) {
	b = a + 3;  
	return true;
}

struct PointData {
}; //�t���T�� 20010303