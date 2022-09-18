#include <iostream>
#include <vector> 
#include <iomanip>
#include <cmath>
using namespace std;

class Vector
{
private:

	vector<double> vector; // 😁Динамический массив на стероидах😁. Тип Double 

	//Инициализация одномерного массива через формулу
	void init_Massive_1D() {

		for (int i = 0; i < vector.size(); i++) {
			
			vector[i] = i * sin(3.1415 * i / 25);//заполнение массива числами
			
		}
	}
public:
	//конструктор Вектора
	//------------------------
	Vector(int _size) {
		vector.resize(_size);

		init_Massive_1D();//вызов инициализации массива после resize вектора
	}
	//------------------------_
	void PrintVector() {

		for (int i = 0; i < vector.size(); i++) {

			cout << vector[i] << " ";
		}
		cout << endl << "--------------------------------------------------------------------------------\n";
	}
	//Получаем значение вектора для передачи в класс Matrix
	auto GetVector() {
		return vector;
	}
	//Деструктор класса
	~Vector() {
		vector.clear();
	}
};

class Matrix {

public:
	//Конструктор класса. Принимает длинну и Вектор
	Matrix(int _size, vector<double> vector) {
		size = _size;
		init_Matrix(vector);
	}
	void PrintMatrix() {

		for (int i = 0; i < size; i++) {

			for (int j = 0; j < size; j++) {

				if (j == 0) {//проверка на первый элемент 

					matrix[i][j] = matrix[i][j + 1] + matrix[i][j + 2] + matrix[i][j + 3]; //сумма элементов массива. Первый элемент содержит сумму остальных
				}
				cout << setw(10) << matrix[i][j] << "|";
			}
			cout << endl;
		}

	}
	//Деструктор класса
	~Matrix(){
		delete[] matrix;
	}
private:
	int size =0;	double** matrix;

	double** init_Matrix(vector<double> vector) {//Инициализация двумерного массива

		matrix = new double* [size]; //массив под выход
		for (int i = 0; i < size; ++i){
		
			*(matrix + i) = new double[size];
		}
		for (int i = 0; i < size; ++i){
		
			for (int j = 0; j < size; ++j){
			
				matrix[i][j] = vector[i * size + j];// заполнение массива при помощи вектора
			}
		}
		return matrix;
	}
};
int main()
{
	setlocale(LC_ALL, "ru");

	Vector vector(25);
	vector.PrintVector();
	Matrix matrix(5, vector.GetVector());
	matrix.PrintMatrix();
	
	
}
