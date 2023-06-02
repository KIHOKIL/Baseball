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
		if(guessNumber == "")
			throw std::invalid_argument("값을 넣어야 함");

		if (guessNumber.length() != 3)
			throw std::invalid_argument("자리수 오류");

		//for(char ch : guessNumber)
		//{
		//	if (!(ch >= '0' && ch <= '9')) continue;
		//	throw std::invalid_argument("숫자로만");
		//}

		if(isIncludeChar(guessNumber)) throw std::invalid_argument("숫자로만");


		if (isDuplicateNumber(guessNumber))
		{
			throw std::invalid_argument("중복수 금지");
		}
	}

	Result guess(string guessNumber)
	{
		isIllegalArgument(guessNumber);

		Result result = { true,3,0 };

		return result;
	}

private:
	string question;
};