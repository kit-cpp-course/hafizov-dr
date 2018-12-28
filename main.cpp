#include"stdafx.h"
#include"Point.h"
#include"MainData.h"
#include "FileMessageProvider.h"
#include "IMessageProvider.h"
#include"Hash.h"
#include"Check.h"

using namespace std;



int main()
{	
	setlocale(LC_ALL, "rus");
	string Name = "";
	cout << "Введите название документа: ";
	cin >> Name;
	const IMessageProvider & messageProvider = FileMessageProvider(Name); 
	std::vector<uint8_t> line = messageProvider.GetMessage();
	
	HashProvider hash = HashProvider(line);
	int MainHash = hash.CountHash();
	
	Data data = Data(MainHash);
	Point result = data.CountSomething();
	
	cout << "Электронная подпись данного документа равна (" << result.x << "," << result.y << ")"<< endl;

	Check Ck = Check(MainHash, result.x, result.y);
	if (Ck.IsCorrect())
		cout << "Подпись корректна" << endl;
	else
		cout << "Подпись некорректна" << endl;
	system("pause");
}
