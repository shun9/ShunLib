//************************************************/
//* @file  :SL_StateMachine.h
//* @brief :��ԊǗ��p�̃N���X
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>
#include <SL_MacroConstants.h>

namespace ShunLib
{

	template <class T>
	class StateMachine
	{
	private:

		//���݂̏��
		State<T>* m_currentState;

		//��Ԃ��g�p����I�u�W�F�N�g
		T* m_obj;

	public:
		StateMachine(T* obj) :m_currentState(nullptr), m_obj(obj) {}
		~StateMachine() { DELETE_POINTER(m_currentState); }

		/// <summary>
		/// ��Ԃ̐؂�ւ�
		/// </summary>
		/// <param name="state">���̏��</param>
		void ChangeState(State<T>* state) {
			//���݂̏�Ԃ����݂���Ȃ�ΏI������
			if (m_currentState != nullptr) {
				m_currentState->Exit(m_obj);
				DELETE_POINTER(m_currentState);
			}
			m_currentState = state;
			m_currentState->Enter(m_obj);
		}

		/// <summary>
		/// ��Ԃ̍X�V����
		/// </summary>
		void Update() {
			//���݂̏�Ԃ����݂���Ȃ�΍X�V����
			if (m_currentState != nullptr) {
				m_currentState->Execute(m_obj);
			}
		}
	};
}