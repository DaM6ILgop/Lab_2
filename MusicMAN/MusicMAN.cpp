
#include <iostream>
#include <iomanip>
#include <vector> 
#include <random>
#include <algorithm>


using namespace std;
class Human {

private:
	
	string name="";

	string fatherName="";

	string sex ="";

	int age = NULL;
	
	string musicalInstruments = "";

	int performanceScore = NULL;
	
public:
	Human(){
		
	}

	Human(string _name, string _fatherName, string _sex, int _age, string _musicialInstruments, int _performanceScore) {

		name = _name;
		fatherName = _fatherName;
		sex =  _sex;
		age = _age;
		musicalInstruments = _musicialInstruments;
		performanceScore = _performanceScore;
	}
	

	void Print(Human human) {
		cout << "\n";
		cout << "Возраст: " << human.age
			<< "\n" << "Имя:" << human.name
			<< "\nОтчество: " << human.fatherName
			<< "\nПол: " << human.sex
			<< "\nВозраст: " << human.age
			<< "\nМузыкальный инструмент: " << human.musicalInstruments
			<< "\nБалы учасника: " << human.performanceScore;
		cout << "\n";
	}
	
	int GetScore(Human human) {
		return human.performanceScore;
	}
	string GetMusicalInstruments(Human human) {
		return musicalInstruments;
	}
	~Human() {};
};


int SetScore() {//Генерация от 1 до 10. От 1 до 5 не получается 
	int sc=0;
	for (int i = 0; i < 10; i++) {
		sc = 1 + (rand() % 8) + 1;
	}
	return sc;
}

bool comp(Human a, Human b) {// компаратор для сортировки
	return(a.GetScore(a) > b.GetScore(b));
}

int main(){

	setlocale(LC_ALL, "ru");

	vector<Human> fields;
	
	Human ms("Алексей", "Калоша", "Муж", 19, "Пианино", SetScore());
	
	Human ms2("Володя", "Романов", "Муж", 19, "Гитара", SetScore());
	
	Human ms3("Михаил", "Вода", "Муж", 34, "Пианино", SetScore());

	Human ms4("Николай", "Басков", "Муж", 90, "Скрипка",SetScore());

	Human ms5("Алексей", "Калоша", "Муж", 19, "Кларнет", SetScore());

	fields.push_back(ms);
	fields.push_back(ms2);
	fields.push_back(ms3);  
	fields.push_back(ms4);
	fields.push_back(ms5);
	
	Human temp;// временная переменная для вывода 

	sort(fields.begin(), fields.end(), comp); //сортировка объектов
	
	for (int i = 0; i < fields.size(); i++) {

		if (fields[i].GetMusicalInstruments(fields[i]) == "Пианино") {

			temp = fields[i];//////
			
			fields[i].Print(temp);
		}
	}
	for (int i = 0; i < fields.size()-1; i++) {
		
		if (fields[i].GetMusicalInstruments(fields[i]) == "Пианино") {

			fields.erase(fields.begin() + i);//удаление объектов 
		}
		fields[i].Print(fields[i]);//вывод
	}
	
}
