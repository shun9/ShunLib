//************************************************/
//* @file  :Visitor.h
//* @brief :�r�W�^�[�p�^�[��
//* @date  :2017/11/21
//* @author:S.Katou
//************************************************/
#pragma once

class INode;

class Visitor {
public:
	virtual void Visit(INode* pNode) = 0;
};

class VisitorNode
{
public:
	VisitorNode() {}
	virtual ~VisitorNode() {}

	// �r�W�^�[���}�������
	virtual void Accept(Visitor* visitor) = 0;
};
