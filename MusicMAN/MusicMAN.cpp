#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
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
		cout<< "\n" << "Имя:" << human.name
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

	void Serialize(string filename, Human human) {//запись в файл
		fstream fstream;
		SetConsoleCP(1251);
		fstream.open(filename, fstream.in | fstream.app);
		if (!fstream.is_open()) {
			cout << "Файла не существует" << endl;
			exit(0);
		}
		else {
			cout << "Данные успешно записаны в файл";
			
				fstream << name << "\n" 
				<< fatherName << "\n"
				<< sex << "\n"
				<< age << "\n" 
				<< musicalInstruments << "\n" 
				<< performanceScore;
	
				fstream.close();
		}
		
		SetConsoleCP(866);
	}

	void Deserialize(string filename) {//десериализатор
		/*fstream fs;*/
		ifstream out;
		out.open(filename);
		if (!out.is_open()) {
			cout << "Ошибка открытия файла!" << std::endl;
			exit(0);
		}
		else {
			while (getline(out, filename)) {
				string name_;
				string fatherName_;
				string sex_;
				int age_;
				string musicalInstruments_;
				int performanceScore_;

				out	>> name_
					>> fatherName_ 
					>> sex_ 
					>> age_ 
					>> musicalInstruments_ 
					>> performanceScore_;
					

				cout << "\n";
				cout<< "\n" << "Имя:" << name_
					<< "\nОтчество: " << fatherName_
					<< "\nПол: " << sex_
					<< "\nВозраст: " << age_
					<< "\nМузыкальный инструмент: " << musicalInstruments_
					<< "\nБалы учасника: " << performanceScore_;
				cout << "\n"<<endl;
					
				out.close();
			}
			
		}
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

	Human ms5("Мерил", "ICE", "Жен", 19, "Кларнет", SetScore());

	fields.push_back(ms);
	fields.push_back(ms2);
	fields.push_back(ms3);  
	fields.push_back(ms4);
	fields.push_back(ms5);
	
	Human temp;// временная переменная для вывода 

	sort(fields.begin(), fields.end(), comp); //сортировка объектов
	
	for (int i = 0; i < fields.size(); i++) {

		if (fields[i].GetMusicalInstruments(fields[i]) == "Пианино") {

			temp = fields[i];
			
			fields[i].Print(temp);
		}
	}

	for (int i = 0; i < fields.size()-1; i++) {
		
		if (fields[i].GetMusicalInstruments(fields[i]) == "Пианино") {

			fields.erase(fields.begin() + i);//удаление объектов 
		}
		fields[i].Print(fields[i]);//вывод
		continue;
	}

	int yourAction;
	
	string path = "Musician.txt";
	cout << "\n1 - запись в файл, 2 - вывод на консоль содержимого файла\n";
	cin >> yourAction;
	switch (yourAction) {

		case 1:
			fields[fields.size()-1].Serialize(path, fields[fields.size()-1]);
		break;

		case 2:
			for (size_t i = 0; i < fields.size(); i++){
			
				fields[i].Deserialize(path);
			}
		break;

		default:
			cout << "NOT FOUND" << endl;//Дефолтное значение
		break;
	}
}
