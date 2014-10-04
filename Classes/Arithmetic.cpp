#include "Arithmetic.h"

Arithmetic::Arithmetic() {
	m_currentScore = DEFAULT_SCORE_VALUE;
	m_thisValue = 0;
	m_thisTime = 0.0f;
	m_thisCount = 0;
	m_lastestOperaterType = Knone;
}

int Arithmetic::nextValue() {
	m_thisValue = rand() / 12345 % 9 + 1;
	return m_thisValue;
}

float Arithmetic::needTime() {
	m_thisTime = rand() / 12345 % 4 + 3;
	return m_thisTime;
}

int Arithmetic::needCount() {
	m_thisCount = rand() / 12345 % 2 + 3;
	return m_thisCount;
}

std::string Arithmetic::tipString() {
	int l_selectNum = 0;
	int l_selectOpr = rand() / 12345 % 2;
	if (l_selectOpr == 0) {		// <
		l_selectNum = rand() / 12345 % m_thisValue + 1;
		m_thisTipString = StringUtils::format("? <= %d", l_selectNum);
	} else {	// >
		l_selectNum = rand() / 12345 % (9 - m_thisValue) + m_thisValue + 1;
		m_thisTipString = StringUtils::format("? >= %d", l_selectNum);
	}
	return m_thisTipString;
}

int Arithmetic::getCurrentScore() {
	return m_currentScore;
}

int Arithmetic::getThisValue() {
	return m_thisValue;
}

bool Arithmetic::addOperator(int a_operater) {
	if (m_numbers.size() == 0) return false;

	if (m_lastestOperaterType == OperaterType::Koperator) {
		reset();
		return false;
	} else {
		m_lastestOperaterType = OperaterType::Koperator;
		m_operaters.push_back(a_operater);
	}
	return true;
}

bool Arithmetic::addNumber(int a_number) {
	if (m_lastestOperaterType == OperaterType::Knumber) {
		reset();
		return false;
	} else {
		m_lastestOperaterType = OperaterType::Knumber;
		m_numbers.push_back(a_number);
	}
	return true;
}

bool Arithmetic::doResult() {
	if (m_numbers.size() == 0) return false;
	if (m_lastestOperaterType == OperaterType::Koperator || 
		m_lastestOperaterType == OperaterType::Knone) {
			return false;
	}

	int l_value = m_numbers.at(0);
	for (int i = 0; i < m_operaters.size(); i++) {
		int l_num = m_numbers.at(i+1);
		int l_opr = m_operaters.at(i);
		switch (l_opr) {
		case OperatorType::kADD: {
			l_value += l_num;
		} break;
		case OperatorType::kSUB: {
			l_value -= l_num;
		} break;
		default:
			break;
		}
	}
	if (l_value == m_thisValue) {
		m_currentScore += m_thisValue;
		return true;
	} else {
		m_currentScore -= m_thisValue;
	}

	return false;
}

void Arithmetic::reset() {
	m_lastestOperaterType = Knone;
	m_numbers.clear();
	m_operaters.clear();
	m_thisValue = 0;
	m_thisTime = 0.0f;
	m_thisCount = 0;
	m_thisTipString = "none";
}