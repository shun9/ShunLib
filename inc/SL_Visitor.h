//************************************************/
//* @file  :Visitor.h
//* @brief :�r�W�^�[�p�^�[��
//* @date  :2017/11/21
//* @author:S.Katou
//************************************************/
#pragma once

namespace ShunLib
{
	class VisitorNode;

	class Visitor {
	public:
		virtual void Visit(VisitorNode* node) = 0;

		// �r�W�^�[���}�������
		virtual void Accept(Visitor* visitor) = 0;

		//�r�W�^�[��������
		virtual void Reset() = 0;
	};

	class VisitorNode
	{
	public:
		VisitorNode() {}
		virtual ~VisitorNode() {}

		// �r�W�^�[���}�������
		virtual void Accept(Visitor* visitor) = 0;
	};
}
