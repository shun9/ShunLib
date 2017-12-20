//************************************************/
//* @file  :SL_Vec2.cpp
//* @brief :2�����x�N�g���p�N���X
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
/// ����
/// </summary>
float ShunLib::Vec2::Dot(const Vec2 & V, const Vec2 & V2)
{
	return (V.m_x*V2.m_x) + (V.m_y*V2.m_y);
}

/// <summary>
/// 2�̃x�N�g���̂Ȃ��p��Ԃ�
/// </summary>
float ShunLib::Vec2::Degree(const Vec2 & V, const Vec2 & V2)
{
	//�x�N�g����0�̏ꍇ��0�x��Ԃ�
	if (V == Vec2::Zero || V2 == Vec2::Zero) { return 0.0f; }
	
	float cos = Dot(V,V2)/(V.Length()*V2.Length());

	return ToAngle(std::acos(cos));
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�t�H���g�R���X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Vec2::Vec2()
	:m_x(0)
	,m_y(0)
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�l�w��R���X�g���N�^
//�b����  :X,Y,Z(float,float,float)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Vec2::Vec2(float x, float y)
	:m_x(x)
	,m_y(y)
{

}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Vec2::~Vec2()
{

}

/// <summary>
/// �x�N�g���̒�����Ԃ�
/// </summary>
/// <returns></returns>
float ShunLib::Vec2::Length()const
{
	return std::sqrt(m_x*m_x + m_y * m_y);
}



/*--[�ȉ��@���Z�q�̃I�[�o�[���[�h]--*/

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
