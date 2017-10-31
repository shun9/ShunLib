//************************************************/
//* @file  :Conversion.h
//* @brief :�ϊ��n�֐��u����
//* @date  :2017/02/20
//* @author:S.Katou
//************************************************/
#pragma once
#include <string>

namespace ShunLib
{
	//�p�x���烉�W�A���ɕϊ�
	float ToRadian(float angle);

	//���W�A������p�x�ɕϊ�
	float ToAngle(float radian);

	//���C�h�����񂩂�}���`�o�C�g������
	void ToNarrow(const std::wstring &src, std::string &dest);

	//�}���`�o�C�g�����񂩂烏�C�h������
	void ToWiden(const std::string &src, std::wstring &dest);
}
