/*
���������� ��������
===================


�3
	�������� ���������� ��� ����� ��������, �� ������ �������, ����� �� ������� ��� ��������.
	������� �����������, ��� ���������� ������� ��� ���� � ����� �� �����.
	� �������� ��������������� ������� ����� typedef.


���������� ������� �� ���������� http://surl.li/umeci
*/

/*
�1
	������ � ����'���� ���� ���������� ��� �������: ������������, ����� ������, ����.
	³���������� ������� � �������� ���� �� ������� ������� �����������.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  
#include <cctype>

using namespace std;

typedef struct
{
	string name;
	string guarantee;
	double price;
} Computers;

typedef struct
{
	vector<Computers>dataBase;
} listOfComputers;


void exercise(int numberOfExercise);

void outputDataBase(const listOfComputers& myList);

void to_lower(string& text) {
	transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
		return tolower(c);
		});
}

bool detectLanguage(string& text); 

int main()
{
	system("chcp 1251>null");
	srand(time(0));

#pragma region Exercise 1

	exercise(1);

	listOfComputers myList;

	myList.dataBase.push_back({ "ASUS ROG Strix", "2 years", 1500.99 });
	myList.dataBase.push_back({ "Dell XPS 15", "1 year", 1899.50 });
	myList.dataBase.push_back({ "MacBook Pro", "3 years", 2499.00 });


	cout << "\033[042m������� ���� ����� ��� ����'�����: \033[0m";
	cout << endl;
	outputDataBase(myList);

	string pcName;
	string guarantee;
	double price;

	string realPcName;

	while (true)
	{
		cout << endl;
		cout << "\033[033m������ ������������ ����`�����(����������): \033[0m";
		getline(cin, pcName);
		cout << endl;
		realPcName = pcName;
		if (!detectLanguage(pcName))
		{
			cout << "\033[031m���� �����, ������ ����� ���������� �����!\033[0m";
			cout << endl;
			continue;
		}

		cout << endl << "\033[042m ���� ��� ������ �����! \033[0m"  << endl;
		break;
	}


	while (true) {
		cout << endl;
		cout << "\033[033m������ ������� ����`�����: \033[0m";
		getline(cin, guarantee);
		cout << endl;

		if (guarantee.empty())
		{
			cout << "\033[031m �������! ����� �� ����� �� �����.\033[0m\n";
			continue;
		}

		if (cin.fail()) {
			cout << "\033[031m �������! ���� �����, ������ ���������� ������ ������.\033[0m\n";
			cin.clear(); 
			cin.ignore(1000, '\n'); 
			continue;
		}

		cout << endl << "\033[042m ���� ��� ������ �����! \033[0m" << endl;
		break;	
	}

	while (true) {
		cout << endl;
		cout << "\033[033m������ ���� ����`�����: \033[0m";
		cin >> price;
		cout << endl;

		if (cin.fail()) {
			cout << "\033[031m �������! ���� �����, ������ ���� ������.\033[0m\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (price < 0)
		{
			cout << "\033[031m �������! ֳ�� ����'����� �� ���� ���� ��'����� ������.\033[0m\n";
			continue;
		}

		cout << endl << "\033[042m ���� ��� ������ �����! \033[0m" << endl;
		break;
	}

	myList.dataBase.push_back({ realPcName, guarantee, price });

	cout << "\033[042m������� ���� ����� ��� ����'�����: \033[0m";
	cout << endl;
	outputDataBase(myList);



#pragma endregion	


/*
�2
	���������: �����, ������, г� �������, ֳ��, ����, ��� ���� (������/����/������� ��������).
	������: ��������������� ������� ���������, ����� (��� �� ���� ���� ���� �������) �� ��������� �������.
	������� ���������� ��� �������� � ������ �������

*/

#pragma region Exercise 1

	exercise(2);

#pragma endregion


	return 0;
}











void exercise(int numberOfExercise)
{
	cout << endl << endl << "\t\t\t\t\033[032mExercise " << numberOfExercise << "\033[0m" << endl << endl;
}

void outputDataBase(const listOfComputers& myList) {
	cout << endl;
	for (size_t i = 0; i < myList.dataBase.size(); i++) {
		cout << "Computer " << i + 1 << ":" << endl;
		cout << "Name: " << myList.dataBase[i].name << endl;
		cout << "Guarantee: " << myList.dataBase[i].guarantee << endl;
		cout << "Price: $" << myList.dataBase[i].price << endl;
		cout << "----------------------" << endl;
	}
	cout << endl;

}

bool detectLanguage(string& text) {
	if (text.empty()) return false;

	to_lower(text);

	size_t i = 0;
	while (
		i < text.size() &&
		(
			isspace(static_cast<unsigned char>(text[i])) ||
			isdigit(static_cast<unsigned char>(text[i]))) ||
			ispunct(static_cast<unsigned char>(text[i])
		)

		)
	{
		i++;
	}

	if (i == text.size()) return false;

	unsigned char firstChar = text[i];

	if (text.find("�") != string::npos || text.find("�") != string::npos || text.find("�") != string::npos || text.find("�") != string::npos)
		return false;

	if ((text.find("�") != string::npos) || (text.find("�") != string::npos) || (text.find("�") != string::npos))
	{
		return false;
	}

	if ((firstChar >= 'A' && firstChar <= 'Z') || (firstChar >= 'a' && firstChar <= 'z'))
		return true;

	if (firstChar >= 0xC0 && firstChar <= 0xFF)
		return false;


	return false;
}