#pragma once

#include "AppMacro.h"

#define ADD_CHAR_OPERATER -1
#define SUB_CHAR_OPERATER -2

typedef enum {
	Knumber = 0,
	Koperator,
	Knone
} OperaterType;		// operator and number enum

typedef enum {
	kADD = 0,
	kSUB,
	kORHTER
} OperatorType;		// only operator enum

/**
	Model
*/
class Arithmetic : public Ref {
private:
	int m_currentScore;			// current score
	int m_thisValue;			// current value
	float m_thisTime;			// ������Ҫ��ʱ��
	int m_thisCount;			// ������Ҫ�����ֵĸ���
	int m_lastestOperaterType;		// ��һ�� ���ţ����ֻ���+-��
	std::string m_thisTipString;
	std::string m_thisSentence;		// current sentence

	std::vector<int> m_numbers;		// ����
	std::vector<int> m_operaters;	// ������
protected:
public:
	Arithmetic();

	/**
		next value between 1-9
		@return int
	*/
	int nextValue();

	/**
		next need time (3-4s) with a controllable rate
		after called nextValue()
		@return float
	*/
	float needTime();

	/**
		next counts needed (1-4)
		after called nextValue()
		@return int
	*/
	int needCount();

	/**
		tip for the value
		after called nextValue()
		@return std::string
	*/
	std::string tipString();

	int getCurrentScore();
	int getThisValue();

	/**
		��Ӳ������������"���"�����Ƿ����
		@return bool
	*/
	bool addOperator(int a_operater);

	/**
		add a number to m_numbers
		return true if the m_numbers.size() is morn than m_thisCount
		@return bool
	*/
	bool addNumber(int a_number);

	/**
		calculate the arithmetic sentence, judge whether the sentence is logical
		@return bool
	*/
	bool doResult();

	/**
		reset the data
	*/
	void reset();
};