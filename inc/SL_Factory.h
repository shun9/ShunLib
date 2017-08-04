//************************************************/
//* @file  :SL_Factory.h
//* @brief :�I�u�W�F�N�g�����N���X
//* @date  :2017/07/20
//* @author:S.Katou
//************************************************/
#pragma once
#include <vector>
#include <SL_MacroConstants.h>

namespace ShunLib
{
	template<class T>
	class Factory
	{
	private:
		//�����������̂�ۑ����Ă���(�폜���邽��)
		std::vector<T*>m_createdList;

	public:
		//�I�u�W�F�N�g�̐���
		T* Create() {
			//�����R�s�[
			T* instance = new T;
			m_createdList.emplace_back(instance);
			return instance;
		}

		Factory() { }
		virtual ~Factory() { }

		//�w�肳�ꂽ�v�f���폜
		void Delete(T* pointer){
			auto itr = std::find(m_createdList.begin(), m_createdList.end(), pointer);
			DELETE_POINTER((*itr));
			m_createdList.erase(itr);
		}

		//Factory���琶�ݏo���ꂽ���̂����ׂč폜
		void AllDelete() {
			for (auto itr = m_createdList.begin(); itr != m_createdList.end(); itr++)
			{
				DELETE_POINTER((*itr));
			}
			m_createdList.clear();
			m_createdList.shrink_to_fit();
		}
	};
}