/*
���������� ��������
===================


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
#include <iomanip>

using namespace std;

// EXERCISE 1

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



// EXERCISE 2

struct CarDetails {
	string engine;    
	string color;      
	int ownersCount; 
};


struct Car {
	string brand;      
	string model;     
	int year;         
	double price;      
	bool isNegotiable; 
	CarDetails details; 
};


// EXERCISE 3

typedef struct {
	string lastName;  
	char gender;      // ����� ('M' - ����, 'F' - ������)
	double avgGrade;  
} Student;



#pragma region Functions Prototypes 

// EXERCISE 1
void exercise(int numberOfExercise);

void outputDataBase(const listOfComputers& myList);

void to_lower(string& text);

bool detectLanguage(string& text);




// EXERCISE 2

void inputCarData(Car& car);

void printCarData(const Car& car);



// EXERCISE 3

void inputStudentData(Student& student);

void calculateAndCompareAverageGrades(Student students[], int n);

#pragma endregion

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

#pragma region Exercise 2

	exercise(2);

	const int carCount = 3;
	Car cars[carCount];  

	cin.ignore();

	for (int i = 0; i < carCount; i++) {
		cout << "\033[042m������ ��� ��� ��������� #" << i + 1 << ":\033[0m\n" << endl;
		inputCarData(cars[i]);
		cout << endl;
	}

	cout << left << setw(20) << "\033[45m �����"
		<< setw(20) << "������"
		<< setw(10) << "г�"
		<< setw(15) << "ֳ��"
		<< setw(10) << "����"
		<< setw(15) << "������"
		<< setw(15) << "����"
		<< setw(20) << "ʳ������ �������� \033[0m" << endl;

	for (int i = 0; i < carCount; i++) {
		printCarData(cars[i]);
	}

#pragma endregion




/*
�3
	�������� ���������� ��� ����� ��������, �� ������ �������, ����� �� ������� ��� ��������.
	������� �����������, ��� ���������� ������� ��� ���� � ����� �� �����.
	� �������� ��������������� ������� ����� typedef.
*/

#pragma region Exercise 3

	const int numStudents = 5;  
	Student students[numStudents];  

	
	for (int i = 0; i < numStudents; i++) {
		cout << "\033[042m������ ��� ��� �������� #" << i + 1 << ":\033[0m\n" << endl;
		inputStudentData(students[i]);
		cout << endl;
	}


	calculateAndCompareAverageGrades(students, numStudents);


#pragma endregion

	return 0;
}









// EXERCISE 1

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

void to_lower(string& text) {
	transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
		return tolower(c);
		});
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



// EXERCISE 2

void inputCarData(Car& car) {
	cout << "�����: ";
	getline(cin, car.brand);
	cout << "������: ";
	getline(cin, car.model);
	cout << "г� �������: ";
	cin >> car.year;
	cout << "ֳ��: ";
	cin >> car.price;
	cout << "�� � ����? (1 - ���, 0 - �): ";
	cin >> car.isNegotiable;
	cin.ignore(); 

	cout << endl << "\033[042m����� ����:\033[0m\n" << endl;
	cout << "��� �������: ";
	getline(cin, car.details.engine);
	cout << "����: ";
	getline(cin, car.details.color);
	cout << "ʳ������ ��������: ";
	cin >> car.details.ownersCount;
	cin.ignore(); 
}

void printCarData(const Car& car) {
	cout << left << setw(20) << car.brand
		<< setw(20) << car.model
		<< setw(10) << car.year
		<< setw(15) << fixed << setprecision(2) << car.price
		<< setw(10) << (car.isNegotiable ? "���" : "ͳ")
		<< setw(15) << car.details.engine
		<< setw(15) << car.details.color
		<< setw(20) << car.details.ownersCount << endl;
}



// EXERCISE 3

void inputStudentData(Student& student) {
	cout << "�������: ";
	getline(cin, student.lastName);
	cout << "����� (M - ����, F - ������): ";
	cin >> student.gender;
	cout << "������� ���: ";
	cin >> student.avgGrade;
	cin.ignore();  
}


void calculateAndCompareAverageGrades(Student students[], int n) {
	double sumM = 0, sumF = 0;
	int countM = 0, countF = 0;


	for (int i = 0; i < n; i++) {
		if (students[i].gender == 'M' || students[i].gender == 'm') {
			sumM += students[i].avgGrade;
			countM++;
		}
		else if (students[i].gender == 'F' || students[i].gender == 'f') {
			sumF += students[i].avgGrade;
			countF++;
		}
	}

	double avgM = (countM > 0) ? sumM / countM : 0;
	double avgF = (countF > 0) ? sumF / countF : 0;
	cout << fixed << setprecision(2);
	cout << "\033[034m������� ��� �����: \033[0m" << avgM << endl;
	cout << fixed << setprecision(2);
	cout << "\033[031m������� ��� �����: \033[0m" << avgF << endl;

	cout << endl;
	cout << fixed << setprecision(2);

	if (avgM > avgF) {
		cout << "\033[035m����� ����� ����� ������� ���: \033[0m" << avgM << endl;
	}
	else if (avgF > avgM) {
		cout << "\033[035mĳ����� ����� ����� ������� ���: \033[0m" << avgF << endl;
	}
	else {
		cout << "\033[035m������� ��� ����� �� ����� ���������: \033[0m" << avgM << endl;
	}
}