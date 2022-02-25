﻿#include <iostream>
#include <string>
using namespace std;


class EMPLOYEE {
private:
	string organization;
	string position;
	double experience;
	string name;
	char gender;
	int age;
	double salary;
public:
	static int count;
	EMPLOYEE(string organization, string position, double experience, string name, char gender, int age, double salary)
	{
		this->organization = organization;
		this->position = position;
		this->experience = experience;
		this->name = name;
		this->gender = gender;
		this->age = age;
		this->salary = salary;
		count++;
	}
	void GetWorkInfo() {
		cout << "Место работы- " << organization << endl;
		cout << "Занимаемая должность- " << position << endl;		// получение информации о месте работы, занимаемой должности, стаже работы, заработной плате
		cout << "Стаж работы- " << experience << endl;
		cout << "Заработная плата- " << salary << endl;
	}
	void SetPosition(string position) {
		this->position = position;			// изменение должности
	}
	void SetSalary(double valueSalary) {
		salary = valueSalary + salary;			// начисление заработной платы
	}
	void GetPersonalInfo() {
		cout << "Фамилия,Имя,Отчество- " << name << endl;
		cout << "Пол- " << gender << endl;		// вывод личных данных: ФИО, пол, возраст
		cout << "Возраст- " << age << endl;
	}
	static void showCount()
	{
		cout << "Количество сотрудников: " << count << endl;
	}
	void SalaryComparsion(EMPLOYEE& second) {
		if (*this < second) {
			cout << second.name << "зарплата больше чем у кого-то" << this->name << endl;			// операция сравнения
		}
		else if (*this == second) {
			cout << second.name << "одинаковая зарплата с кем-то " << this->name << endl;
		}
		else cout << this->name << "зарплата меньше чем у кого-то" << second.name << endl;
	}
	bool operator < (EMPLOYEE const& other) {
		return this->salary < other.salary;
	}															// перегрузка операций
	bool operator == (EMPLOYEE const& other) {
		return this->salary == other.salary;
	}
	void SalaryAssignment(EMPLOYEE& second) {
		this->salary = second.salary;				// операция присваивания
	}
	~EMPLOYEE() {
		count--;
	}
};
int EMPLOYEE::count = 0;


int main() {
	setlocale(LC_ALL, "Russian");
	EMPLOYEE emp1("Shale", "Translator", 2, "Shaposhnikov Lev Valentinovich", 'М', 18, 2000000);
	EMPLOYEE emp2("Shale", "Manager", 1, "Trushina Yuliya Vladimirovna", 'Ж', 18, 35000);
	EMPLOYEE emp3("Shale", "Cleaner", 45, "Raisa Zyulminishna Pupova", 'Ж', 61, 1000);
	EMPLOYEE employees[3] = { emp1, emp2, emp3 };
	EMPLOYEE::showCount();
	for (int i = 0; i < 3; i++)
	{
		employees[i].GetPersonalInfo();
		employees[i].GetWorkInfo();
		cout << endl;
	}
	employees[0].SalaryComparsion(employees[1]);
	employees[0].SetPosition("Supervisor");
	cout << "Изменить первому сотруднику должность" << endl;
	employees[0].SetSalary(100000);
	cout << "добавить зарплату в 100000" << endl;
	employees[1].SalaryAssignment(employees[2]);
	cout << "Установить второму сотруднику зарплату третьего" << endl;
	for (int i = 0; i < 3; i++)
	{
		employees[i].GetPersonalInfo();
		employees[i].GetWorkInfo();
		cout << endl;
	}
}