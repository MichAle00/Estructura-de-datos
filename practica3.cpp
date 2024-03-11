#include <iostream>
#include <cmath>

using namespace std;

class Racional{
    private:
        int num;
        int den;
    public:
        Racional(){den = 1;};
        Racional(int, int);
        ~Racional(){};
        void print();
        void simplify();
        void compare(Racional);
        Racional operator-(Racional const&);
        Racional operator*(Racional const&);
        Racional operator/(Racional const&);
        Racional operator+(Racional const&);
};

Racional::Racional(int n, int d)
{
    while (d == 0)
    {
        cout << "El denominador no puede ser 0, escriba otro numero: ";
        cin >> d;
    }

    while (n == 0)
    {
        cout << "El numerador no puede ser 0, escriba otro numero: ";
        cin >> n;
    }

    num = n;
    den = d;
}

void Racional::print()
{
    if (num == 0)
    {
        cout << "0" << endl;
    }
    else if (den == 1)
    {
        cout << num << endl;
    }
    else 
    {
        cout << num << "/" << den << endl;
    }
}

void Racional::simplify()
{
    int result = min(abs(num), abs(den));
    while (result > 0) 
    {
        if (num % result == 0 && den % result == 0)
        {
            break;
        }
        result--;
    }
        
    num /= result;
    den /= result;
    
}

Racional Racional::operator-(Racional const& tmp)
{
    Racional res;
    res.num = num * tmp.den - tmp.num * den;
    res.den = den * tmp.den;
    return res;
}

Racional Racional::operator*(Racional const& tmp)
{
    Racional res;
    res.num = num * tmp.num;
    res.den = den * tmp.den;
    return res;
}

Racional Racional::operator/(Racional const& tmp)
{
    Racional res;
    res.num = num * tmp.den;
    res.den = den * tmp.num;
    return res;
}

Racional Racional::operator+(Racional const& rac)
{
    Racional tmp;
    tmp.num = num * rac.den + rac.num * den;
    tmp.den = den * rac.den;
    return tmp;
}

void Racional::compare(Racional x)
{
    x.simplify();

    (num == x.num && den == x.den) ? cout << "Son iguales" : cout << "No son iguales";
}

main(void)
{
    Racional r1, r2, r3;

    int num, den;
    cout << "Dame el numerador 1: ";
    cin >> num;
    cout << "Dame el denominador 1: ";
    cin >> den;
    r1 = Racional(num, den);

    cout << endl << "Dame el numerador 2: ";
    cin >> num;
    cout << "Dame el denominador 2: ";
    cin >> den;
    r2 = Racional(num, den);

    cout << endl << "Primer racional: ";
    r1.print();
    cout << endl << "Segundo racional: ";
    r2.print();
    
    cout << endl << "Suma: " << endl;
    r3 = r1 + r2;
    r3.print();
    cout << "Resultado simplificado: ";
    r3.simplify();
    r3.print();
  
    cout << "Resta: " << endl;
    r3 = r1 - r2;
    r3.print(); 
    cout << "Resultado simplificado: ";
    r3.simplify();
    r3.print(); 
    
    cout << "Multiplicacion: " << endl;
    r3 = r1 * r2;
    r3.print();
    cout << "Resultado simplificado: ";
    r3.simplify();
    r3.print();
    
    cout << "Division: " << endl;
    r3 = r1 / r2;
    r3.print();
    cout << "Resultado simplificado: ";
    r3.simplify();
    r3.print();

    r1.simplify();
    r1.compare(r2); 
}