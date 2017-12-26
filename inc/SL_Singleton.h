//************************************************/
//* @file  :Singleton.h
//* @brief :�V���O���g��
//* @date  :2017/06/26
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_MacroConstants.h>
#include <SL_SingletonDestroyer.h>

namespace ShunLib
{
	class ISingleton
	{
	public:
		//���̍폜
		virtual void DestroyInstance() = 0;

	protected:
		//�h���N���X�ȊO����쐬�ł��Ȃ��悤�ɂ���
		ISingleton() { SingletonDestroyer::AddSingleton(this); }
		virtual ~ISingleton() {}

		//�R�s�[�ł��Ȃ��悤��
		ISingleton(const ISingleton& single) = delete;

		//����ł��Ȃ��悤��
		const ISingleton& operator = (const ISingleton& single) = delete;
	};

	template<class T>
	class Singleton : public ISingleton
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

	public:
		//���̍폜
		virtual void DestroyInstance() {
			DELETE_POINTER(m_instance);
		}

	protected:
		//�h���N���X�ȊO����쐬�ł��Ȃ��悤�ɂ���
		Singleton() {}
		virtual ~Singleton() {}
	};

	template<class T>
	T* ShunLib::Singleton<T>::m_instance = nullptr;
}
