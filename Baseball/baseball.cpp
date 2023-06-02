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
			throw std::invalid_argument("���� �־�� ��");

		if (guessNumber.length() != 3)
			throw std::invalid_argument("�ڸ��� ����");

		//for(char ch : guessNumber)
		//{
		//	if (!(ch >= '0' && ch <= '9')) continue;
		//	throw std::invalid_argument("���ڷθ�");
		//}

		if(isIncludeChar(guessNumber)) throw std::invalid_argument("���ڷθ�");


		if (isDuplicateNumber(guessNumber))
		{
			throw std::invalid_argument("�ߺ��� ����");
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