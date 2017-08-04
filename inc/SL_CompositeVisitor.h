#pragma once

class INode;

class Visitor {
public:
	virtual void Visit(INode* pNode) = 0;
};

class INode
{
public:
	INode() {}
	virtual ~INode() {}

	// �q�m�[�h��ǉ�����
	virtual void AddChild(INode* node) = 0;

	// �r�W�^�[���}�������
	virtual void Accept(Visitor* visitor) = 0;
};
