#include"stdafx.h"
#include"Point.h"
#include"MainData.h"
#include "FileMessageProvider.h"
#include "IMessageProvider.h"
#include"Hash.h"
#include"Check.h"

using namespace std;

/*class Encrypt
{
public:
	Encrypt(int a) : _a(a) {};
	int CountPartialHash(const IMessageProvider& messageProvider)
	{
		string message = messageProvider.GetMessage();
		return 0;
	}
private:
	const int _a;
};*/


int main()
{	
	setlocale(LC_ALL, "rus");
	string Name = "";
	cout << "������� �������� ���������: ";
	cin >> Name;
	const IMessageProvider & messageProvider = FileMessageProvider(Name); 
	std::vector<uint8_t> line = messageProvider.GetMessage();
	
	HashProvider hash = HashProvider(line);
	int MainHash = hash.CountHash();
	
	Data data = Data(MainHash);
	Point result = data.CountSomething();
	
	cout << "����������� ������� ������� ��������� ����� (" << result.x << "," << result.y << ")"<< endl;

	Check Ck = Check(MainHash, result.x, result.y);
	if (Ck.IsCorrect())
		cout << "������� ���������" << endl;
	else
		cout << "������� �����������" << endl;
	system("pause");
}
