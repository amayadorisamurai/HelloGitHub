/**
*@file CMemTest.cpp
*@brief メモリリークテスト用
* @author 舩岡慎吾
* @date 2019/05/22
* @details メモリリークをテストするために意図的に発生させています。
* @brief 3 を足す関数
* @param[in] a(元の値) 計算する元の数値
* @param[out] b(代入先) 計算結果を代入する先
* @return bool 常に true を返却します。
* @details 第一引数に 3 を足して、第 2 引数に結果を代入
* @brief PointData クラスの説明
* @details 詳細なクラスの説明
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
	//_crtBreakAlloc = 160;  //ブレークポイント
	PointData*pPointData = DBG_NEW PointData;
	
	for (int i = 0; i < 50; i++) {
		delete pPointData;   //ブレークポイント
		pPointData = DBG_NEW PointData;
	}
	_RPT0(_CRT_WARN, "Set Break Point");  //ブレークポイント
	delete pPointData;   //ブレークポイント

	CharacterData*pCharacterData = DBG_NEW CharacterData;
	for (int i = 0; i < 50; i++) {
		delete pCharacterData;  //ブレークポイント
		pCharacterData = DBG_NEW CharacterData;
	}
	delete pCharacterData;  //ブレークポイント

		_CrtDumpMemoryLeaks();  //ブレークポイント

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
}; //舩岡慎吾 20010303