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
	explicit Baseball(string& q) : question(q) {}

	auto get_value(string& length)
	{
		return length[0] == length[1] ||
			length[0] == length[2] ||
			length[1] == length[2];
	}

	bool isNonNumbers(string& length)
	{
		
	}

	void isIllegalArgument(string guessNumber)
	{
		if(guessNumber == "")
			throw std::invalid_argument("���� �־�� ��");

		if (guessNumber.length() != 3)
			throw std::invalid_argument("�ڸ��� ����");

		for(char ch : guessNumber)
		{
			if (!(ch >= '0' && ch <= '9')) continue;
			throw std::invalid_argument("���ڷθ�");
		}

		//if(isNonNumber(guessNumber)) throw std::invalid_argument("���ڷθ�");


		if (get_value(guessNumber))
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