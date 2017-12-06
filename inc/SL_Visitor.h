//************************************************/
//* @file  :Visitor.h
//* @brief :ビジターパターン
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

		// ビジターを迎え入れる
		virtual void Accept(Visitor* visitor) = 0;

		//ビジターを初期化
		virtual void Reset() = 0;
	};

	class VisitorNode
	{
	public:
		VisitorNode() {}
		virtual ~VisitorNode() {}

		// ビジターを迎え入れる
		virtual void Accept(Visitor* visitor) = 0;
	};
}
