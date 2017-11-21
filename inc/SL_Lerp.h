#pragma once
#include <cmath>
#include <SL_ConstantNumber.h>

namespace ShunLib
{
	class Lerp
	{
	public:
		//���`���
		static float Linearity(float time)
		{
			return time;
		}


		//�񎟕��
		static float EaseIn(float time)
		{
			float vt = 0.0f;

			vt = time * time;

			return vt;
		}


		//�񎟕��
		static float EaseOut(float time)
		{
			float vt = 0.0f;

			vt = time * (2 - time);

			return vt;
		}


		//�O�����
		static float Cubic(float time)
		{
			float vt = 0.0f;

			vt = time * time * (3 - 2 * time);
			return vt;
		}

		//cos���
		static float Cos(float time)
		{
			float vt = 0.0f;

			vt = (1.0f - std::cosf(time * ConstantNumber::PI)) / 2.0f;

			return vt;
		}
	};
}