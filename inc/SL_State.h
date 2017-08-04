//************************************************/
//* @file  :State.h
//* @brief :��Ԃ̊��N���X
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_Singleton.h>

namespace ShunLib
{
	template <class T>
	class State
	{
	public:
		//�J�n����
		virtual void Enter(T* obj) = 0;

		//���s����
		virtual void Execute(T* obj) = 0;

		//�I������
		virtual void Exit(T* obj) = 0;

	public:
		State(){}
		virtual ~State() {}

	};
}