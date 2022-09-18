#include <iostream>
using namespace std;
static int cou;
class Fraction {

private:
    int x, y;//x-числитель, y-знаменатель
    long nod = 1l;
public:
    
    Fraction(int _x, int _y){
        if (_y == 0) {
            x = 0;
            y = 1; 
            exit(0);
        }else{
            cou++;
            x = _x;
            y = _y;  
        }
        
    }

    void Print(Fraction fr) {
        cout << fr.x << "/" << fr.y << endl;
    }

    //Нахождение НОД
    int gcd(int x, int y) {
        while (x != y) {
            if (x > y) {
                x = x - y;
            }
            else {
                y = y - x;
            }
        }
        cout << x;
        return x;
        /*for (int i = fr.x; i > 0; i--) {
            if (fr.x % i == 0 && fr.y % i == 0) {
                cout << nod + i << endl;
                   return  nod + i;
;
            }
        }*/
    }
   

    int GetX(Fraction fr) {
        return fr.x;
    }
    //Получение знаменателя
    int GetY(Fraction fr) {
        return fr.y;
    }

    /*void reduce(Fraction fr){
        for (int i = x; i > 1; i--){
            if (x % i == 0 && y % i == 0){
                x = x / i;
                y = y / i;
            }
        }
    }*/
    void reduce(Fraction& a)
    {
        int copyOfNum = a.x;
        int copyOfDen = a.y;
        while (copyOfNum != copyOfDen)
        {                           //|    //True             |         //False       |
            copyOfNum < copyOfDen ? copyOfDen -= copyOfNum : copyOfNum -= copyOfDen; //Если copyOfNum < copyOfDen делаем copyOfDen -= copyOfNum, в противном случае copyOfNum -= copyOfDen.
            
        }
        a.x /= copyOfNum;
        a.y /= copyOfDen;
    }
    //Операторы сложения , вычитания, умножения, деления
    Fraction operator + (Fraction fr) {
        /*return(fr.x = x * fr.y + y * fr.x, fr.y = y * fr.y);*/
        fr.x = x * fr.y + y * fr.x;
        fr.y = y * fr.y;
        return fr;
    }
    Fraction operator - (Fraction fr) {
        fr.x = x * fr.y - y * fr.x;
        fr.y = y * fr.y;
        return fr;
    }
    Fraction operator * (Fraction fr) {
        fr.x = x * fr.x;
        fr.y = y * fr.y;
        reduce(fr);
        return fr;
    }
    Fraction operator / (Fraction fr) {
        fr.x = x * fr.y;
        fr.y = y * fr.x;
        reduce(fr);
        return fr;
    }


};
int main()
{
    setlocale(LC_ALL, "ru");
    Fraction fraction_X(4, 6);
    fraction_X.reduce(fraction_X);
    cout << "*****************************************" << endl;
    cout << "Первая дробь в сокращенном формате" << endl;
    fraction_X.Print(fraction_X);
    cout << "*****************************************\n" << endl;


    Fraction fraction_Y(6, 12);
    fraction_Y.reduce(fraction_Y);
    cout << "*****************************************" << endl;
    cout << "Вторая дробь в сокращенном формате" << endl;
    fraction_Y.Print(fraction_Y);
    cout << "*****************************************" << endl;

    cout << "\nСумма дробей" << endl;
    fraction_X.Print(fraction_X + fraction_Y );
    cout << "\nРазность дробей" << endl;
    fraction_X.Print(fraction_X - fraction_Y);
    cout << "\nПроизведение дробей" << endl;
    fraction_X.Print(fraction_X * fraction_Y);
    cout << "\nЧастное дробей" << endl;
    fraction_X.Print(fraction_X / fraction_Y); 

    cout << "\nНОД дробь 1:" << endl;
    fraction_X.gcd(fraction_X.GetX(fraction_X), fraction_X.GetY(fraction_Y));
    cout << "\nНОД дробь 2:" << endl;
    fraction_Y.gcd(fraction_Y.GetX(fraction_Y), fraction_Y.GetY(fraction_Y));
    std::cout << "\nКоличество объектов типа Fraction : " << cou <<"\n";
    fraction_X.~Fraction();
    fraction_Y.~Fraction();
    
    
    
    

}

