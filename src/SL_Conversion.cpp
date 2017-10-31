//************************************************/
//* @file  :Conversion.cpp
//* @brief :変換系関数置き場
//* @date  :2017/02/21
//* @author:S.Katou
//************************************************/
#include "SL_Conversion.h"
#include <SL_ConstantNumber.h>

//＋ーーーーーーーーーーーーーー＋
//｜機能  :角度からラジアンに変換
//｜引数  :角度		(float)
//｜戻り値:ラジアン (float)
//＋ーーーーーーーーーーーーーー＋
float ShunLib::ToRadian(float angle)
{
	float radian = 0.0f;

	radian = angle * ConstantNumber::PI / 180.0f;

	return radian;
}



//＋ーーーーーーーーーーーーーー＋
//｜機能  :ラジアンから角度に変換
//｜引数  :ラジアン(float)
//｜戻り値:角度　　(float)
//＋ーーーーーーーーーーーーーー＋
float ShunLib::ToAngle(float radian)
{
	float angle = 0.0f;

	angle = radian * 180.0f / ConstantNumber::PI;

	return angle;
}


//ワイド文字列からマルチバイト文字列
//ロケール依存
void ShunLib::ToNarrow(const std::wstring &src, std::string &dest) {
	size_t size = src.length() * MB_CUR_MAX + 1;
	char *mbs = new char[size];
	size_t tmp = 0;
	wcstombs_s(&tmp, mbs, size, src.c_str(), size);
	dest = mbs;
	delete[] mbs;
}

//マルチバイト文字列からワイド文字列
//ロケール依存
void ShunLib::ToWiden(const std::string &src, std::wstring &dest) {
	size_t size = src.length()+1;
	wchar_t *wcs = new wchar_t[size];
	size_t tmp = 0;
	mbstowcs_s(&tmp, wcs, size,src.c_str(),size);
	dest = wcs;
	delete[] wcs;
}