//************************************************/
//* @file  :ConstantNumber.h
//* @brief :�悭�g���萔�܂Ƃ�
//* @date  :2017/05/10
//* @author:S.Katou
//************************************************/
#pragma once

namespace ShunLib
{
	class ConstantNumber
	{
	public:
		//�~����
		static const float PI;
	
		//����
		enum DIRECTION_2D
		{
			TOP,
			BOTTOM,
			RIGHT,
			LEFT,
			num,
		};
	};

}