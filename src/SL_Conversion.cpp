//************************************************/
//* @file  :Conversion.cpp
//* @brief :�ϊ��n�֐��u����
//* @date  :2017/02/21
//* @author:S.Katou
//************************************************/
#include "SL_Conversion.h"
#include <SL_ConstantNumber.h>

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�p�x���烉�W�A���ɕϊ�
//�b����  :�p�x		(float)
//�b�߂�l:���W�A�� (float)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
float ShunLib::ToRadian(float angle)
{
	float radian = 0.0f;

	radian = angle * ConstantNumber::PI / 180.0f;

	return radian;
}



//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���W�A������p�x�ɕϊ�
//�b����  :���W�A��(float)
//�b�߂�l:�p�x�@�@(float)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
float ShunLib::ToAngle(float radian)
{
	float angle = 0.0f;

	angle = radian * 180.0f / ConstantNumber::PI;

	return angle;
}


//���C�h�����񂩂�}���`�o�C�g������
//���P�[���ˑ�
void ShunLib::ToNarrow(const std::wstring &src, std::string &dest) {
	size_t size = src.length() * MB_CUR_MAX + 1;
	char *mbs = new char[size];
	size_t tmp = 0;
	wcstombs_s(&tmp, mbs, size, src.c_str(), size);
	dest = mbs;
	delete[] mbs;
}

//�}���`�o�C�g�����񂩂烏�C�h������
//���P�[���ˑ�
void ShunLib::ToWiden(const std::string &src, std::wstring &dest) {
	size_t size = src.length()+1;
	wchar_t *wcs = new wchar_t[size];
	size_t tmp = 0;
	mbstowcs_s(&tmp, wcs, size,src.c_str(),size);
	dest = wcs;
	delete[] wcs;
}