//************************************************/
//* @file  :SL_Vec2.cpp
//* @brief :2次元ベクトル用クラス
//* @date  :2017/07/04
//* @author:S.Katou
//************************************************/
#include "SL_Vec2.h"
#include <cmath>
#include <SL_Conversion.h>

using namespace ShunLib;

const Vec2 Vec2::Zero  = Vec2(0, 0);
const Vec2 Vec2::One   = Vec2(1, 1);
const Vec2 Vec2::UnitX = Vec2(1, 0);
const Vec2 Vec2::UnitY = Vec2(0, 1);


/// <summary>
/// 内積
/// </summary>
float ShunLib::Vec2::Dot(const Vec2 & V, const Vec2 & V2)
{
	return (V.m_x*V2.m_x) + (V.m_y*V2.m_y);
}

/// <summary>
/// 2つのベクトルのなす角を返す
/// </summary>
float ShunLib::Vec2::Degree(const Vec2 & V, const Vec2 & V2)
{
	//ベクトルが0の場合は0度を返す
	if (V == Vec2::Zero || V2 == Vec2::Zero) { return 0.0f; }
	
	float cos = Dot(V,V2)/(V.Length()*V2.Length());

	return ToAngle(std::acos(cos));
}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :デフォルトコンストラクタ
//＋ーーーーーーーーーーーーーー＋
Vec2::Vec2()
	:m_x(0)
	,m_y(0)
{

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :値指定コンストラクタ
//｜引数  :X,Y,Z(float,float,float)
//＋ーーーーーーーーーーーーーー＋
Vec2::Vec2(float x, float y)
	:m_x(x)
	,m_y(y)
{

}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :デストラクタ
//＋ーーーーーーーーーーーーーー＋
Vec2::~Vec2()
{

}

/// <summary>
/// ベクトルの長さを返す
/// </summary>
/// <returns></returns>
float ShunLib::Vec2::Length()const
{
	return std::sqrt(m_x*m_x + m_y * m_y);
}



/*--[以下　演算子のオーバーロード]--*/

Vec2& Vec2::operator=(const Vec2& V)
{
	this->m_x = V.m_x;
	this->m_y = V.m_y;

	return *this;
}

Vec2 Vec2::operator+(const Vec2& V)
{
	Vec2 vec;

	vec.m_x = this->m_x + V.m_x;
	vec.m_y = this->m_y + V.m_y;

	return vec;
}

Vec2 Vec2::operator-(const Vec2& V)
{
	Vec2 vec;

	vec.m_x = this->m_x - V.m_x;
	vec.m_y = this->m_y - V.m_y;

	return vec;
}

Vec2 Vec2::operator*(int num)
{
	Vec2 vec;

	vec.m_x = this->m_x * num;
	vec.m_y = this->m_y * num;

	return vec;
}

Vec2 ShunLib::Vec2::operator*(float num)
{
	Vec2 vec;

	vec.m_x = this->m_x * num;
	vec.m_y = this->m_y * num;

	return vec;
}

Vec2 ShunLib::Vec2::operator*(double num)
{
	Vec2 vec;

	vec.m_x = this->m_x * static_cast<float>(num);
	vec.m_y = this->m_y * static_cast<float>(num);

	return vec;
}

bool ShunLib::operator==(const ShunLib::Vec2 & V, const ShunLib::Vec2 & V2)
{
	return (V.m_x == V2.m_x
		&&V.m_y == V2.m_y);
}
