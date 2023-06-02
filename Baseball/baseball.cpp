#include <stdexcept>
#include <string>
using namespace std;

struct Result
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:

	Baseball(){}
	explicit Baseball(const string& q) : question(q) {}

	auto isDuplicateNumber(string length)
	{
		return length[0] == length[1] ||
			length[0] == length[2] ||
			length[1] == length[2];
	}

	bool isIncludeChar(const string& guessNumber) {
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}

	void isIllegalArgument(string guessNumber)
	{
		if(guessNumber == "")	throw std::invalid_argument("값을 넣어야 함");
		if (guessNumber.length() != 3)	throw std::invalid_argument("자리수 오류");
		if(isIncludeChar(guessNumber)) throw std::invalid_argument("숫자로만");
		if (isDuplicateNumber(guessNumber))	throw std::invalid_argument("중복수 금지");
	}

	bool getResultSuccess(int strike)
	{
		if (strike != 3) return false;
		return true;
	}

	Result guess(string guessNumber)
	{
		isIllegalArgument(guessNumber);

		int numStrikes = getNumStrkes(guessNumber);
		int numBall = getNumBall(guessNumber);

		Result result = { getResultSuccess(numStrikes),numStrikes,numBall };
		return result;
	}

private:
	int getNumStrkes(string guessNumber)
	{
		int result = 0;
		for (int i = 0; i < 3;++i)
		{
			int index = question.find(guessNumber[i]);
			if (index == -1)continue;
			if (index == i)
			{
				result++;
				continue;
			}
		}
		return result;
	}

	int getNumBall(string guessNumber)
	{
		int result = 0;
		for (int i = 0; i < 3;++i)
		{
			int index = question.find(guessNumber[i]);
			if (index == -1)continue;
			if (index == i) continue;
			result++;
		}
		return result;
	}
	string question;
};