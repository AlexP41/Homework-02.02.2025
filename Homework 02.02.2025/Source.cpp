/*
ВИЗНАЧЕННЯ СТРУКТУР
===================


№3
	Обробити інформацію про групу студентів, що містить прізвища, стать та середній бал успішності.
	Вивести повідомлення, чий підсумковий середній бал вище – юнаків чи дівчат.
	У структурі використовувати ключове слово typedef.


Навчальний матеріал за посиланням http://surl.li/umeci
*/

/*
№1
	Ввести в комп'ютер таку інформацію про монітори: найменування, термін гарантії, ціну.
	Відсортувати монітори зі спадання ціни та вивести відповідні повідомлення.
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


	cout << "\033[042mПоточна база даних про комп'ютери: \033[0m";
	cout << endl;
	outputDataBase(myList);

	string pcName;
	string guarantee;
	double price;

	string realPcName;

	while (true)
	{
		cout << endl;
		cout << "\033[033mВведіть найменування комп`ютера(англійською): \033[0m";
		getline(cin, pcName);
		cout << endl;
		realPcName = pcName;
		if (!detectLanguage(pcName))
		{
			cout << "\033[031mБудь ласка, введіть назву англійською мовою!\033[0m";
			cout << endl;
			continue;
		}

		cout << endl << "\033[042m Ваші дані успішно додані! \033[0m"  << endl;
		break;
	}


	while (true) {
		cout << endl;
		cout << "\033[033mВведіть гарантію комп`ютера: \033[0m";
		getline(cin, guarantee);
		cout << endl;

		if (guarantee.empty())
		{
			cout << "\033[031m Помилка! Схоже Ви нічого не ввели.\033[0m\n";
			continue;
		}

		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, введіть корректний термінт гарантії.\033[0m\n";
			cin.clear(); 
			cin.ignore(1000, '\n'); 
			continue;
		}

		cout << endl << "\033[042m Ваші дані успішно додані! \033[0m" << endl;
		break;	
	}

	while (true) {
		cout << endl;
		cout << "\033[033mВведіть ціну комп`ютера: \033[0m";
		cin >> price;
		cout << endl;

		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, введіть ціну числом.\033[0m\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (price < 0)
		{
			cout << "\033[031m Помилка! Ціна комп'ютера не може бути від'ємним числом.\033[0m\n";
			continue;
		}

		cout << endl << "\033[042m Ваші дані успішно додані! \033[0m" << endl;
		break;
	}

	myList.dataBase.push_back({ realPcName, guarantee, price });

	cout << "\033[042mПоточна база даних про комп'ютери: \033[0m";
	cout << endl;
	outputDataBase(myList);



#pragma endregion	


/*
№2
	Авторинок: Марка, Модель, Рік випуску, Ціна, Торг, Дані авто (двигун/колір/кількість власників).
	Вимоги: Використовувати вкладені структури, масив (так як авто може бути декілька) та прототипи функцій.
	Вивести інформацію про автомобілі у вигляді таблиці

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

	if (text.find("є") != string::npos || text.find("ї") != string::npos || text.find("ґ") != string::npos || text.find("і") != string::npos)
		return false;

	if ((text.find("ы") != string::npos) || (text.find("ъ") != string::npos) || (text.find("ё") != string::npos))
	{
		return false;
	}

	if ((firstChar >= 'A' && firstChar <= 'Z') || (firstChar >= 'a' && firstChar <= 'z'))
		return true;

	if (firstChar >= 0xC0 && firstChar <= 0xFF)
		return false;


	return false;
}