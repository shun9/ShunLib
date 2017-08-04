//************************************************/
//* @file  :Singleton.h
//* @brief :�V���O���g��
//* @date  :2017/06/26
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_MacroConstants.h>

namespace ShunLib
{
	template<class T>
	class Singleton
	{
	private:
		//����
		static T* m_instance;

	public:
		/// <summary>
		/// ���̂̎擾
		/// </summary>
		/// <returns>����</returns>
		static T* GetInstance() {
			//������΍쐬
			if (m_instance == nullptr) {
				m_instance = new T();
			}
			return m_instance;
		}


		/// /// <summary>
		/// ���̂̔j��
		/// </summary>
		static void Destroy() {
			DELETE_POINTER(m_instance);
		}


	protected:
		//�h���N���X�ȊO����쐬�ł��Ȃ��悤�ɂ���
		Singleton() {}
		virtual ~Singleton() {}

	private:
		//�R�s�[�ł��Ȃ��悤��
		Singleton(const Singleton& single);

		//����ł��Ȃ��悤��
		const Singleton& operator = (const Singleton& single) {};
	};

	template<class T>
	T* ShunLib::Singleton<T>::m_instance = nullptr;
}
