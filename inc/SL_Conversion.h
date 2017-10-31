//************************************************/
//* @file  :Conversion.h
//* @brief :変換系関数置き場
//* @date  :2017/02/20
//* @author:S.Katou
//************************************************/
#pragma once
#include <string>

namespace ShunLib
{
	//角度からラジアンに変換
	float ToRadian(float angle);

	//ラジアンから角度に変換
	float ToAngle(float radian);

	//ワイド文字列からマルチバイト文字列
	void ToNarrow(const std::wstring &src, std::string &dest);

	//マルチバイト文字列からワイド文字列
	void ToWiden(const std::string &src, std::wstring &dest);
}
