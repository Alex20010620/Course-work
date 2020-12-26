#include "pch.h"
#include "CppUnitTest.h"
#include "..\Курсовая_АлгСтр\Algorithm.cpp"
//#include "..\Курсовая_АлгСтр\NumberStack.h"
//#include "..\Курсовая_АлгСтр\OperatorStack.h"
//#include "..\Курсовая_АлгСтр\PostfixNotation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod0)
		{
			reverse_Polish_Notation* rpn = new reverse_Polish_Notation;
			rpn->infix_string = "(2+2-3*2+2^2)/0.5";
			double result = rpn->infixToPostfix();
			Assert::IsTrue(result == 4);
		}

		TEST_METHOD(TestMethod1)
		{
			reverse_Polish_Notation* rpn = new reverse_Polish_Notation;
			rpn->infix_string = "sin(pi/2)";
			double result = rpn->infixToPostfix();
			Assert::IsTrue(result == 1);
		}

		TEST_METHOD(TestMethod2)
		{
			reverse_Polish_Notation* rpn = new reverse_Polish_Notation;
			rpn->infix_string = "cos(pi)";
			double result = rpn->infixToPostfix();
			Assert::IsTrue(result == -1);
		}

		TEST_METHOD(TestMethod3)
		{
			reverse_Polish_Notation* rpn = new reverse_Polish_Notation;
			rpn->infix_string = "ln(e)";
			double result = rpn->infixToPostfix();
			Assert::IsTrue(result == 1);
		}

		TEST_METHOD(TestMethod4)
		{
			reverse_Polish_Notation* rpn = new reverse_Polish_Notation;
			rpn->infix_string = "log(100)";
			double result = rpn->infixToPostfix();
			Assert::IsTrue(result == 2);
		}

		TEST_METHOD(TestMethod5)
		{
			reverse_Polish_Notation* rpn = new reverse_Polish_Notation;
			rpn->infix_string = "tg(0)";
			double result = rpn->infixToPostfix();
			Assert::IsTrue(result == 0);
		}

		TEST_METHOD(TestMethod6)
		{
			reverse_Polish_Notation* rpn = new reverse_Polish_Notation;
			rpn->infix_string = "sqrt(4)";
			double result = rpn->infixToPostfix();
			Assert::IsTrue(result == 2);
		}

		TEST_METHOD(TestMethod7)
		{
			reverse_Polish_Notation* rpn = new reverse_Polish_Notation;
			rpn->infix_string = "sh(0)";
			double result = rpn->infixToPostfix();
			Assert::IsTrue(result == 0);
		}

		TEST_METHOD(TestMethod8)
		{
			reverse_Polish_Notation* rpn = new reverse_Polish_Notation;
			rpn->infix_string = "(((log(10)+ln(e)+cos(0)+sin(pi)-6)*3)+3^3)/0.5";
			double result = rpn->infixToPostfix();
			Assert::IsTrue(result == 36);
		}
	};
}
