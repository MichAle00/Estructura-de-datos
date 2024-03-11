#include <iostream>

using namespace std;

#define MAX 10

class Conjunto
{
    private:
        int array[MAX];
        int card;
    public:
        Conjunto(){card = 0;};
        bool addElement(int);
        void print();
        bool belongs(int);
        bool unite(Conjunto, Conjunto &);
        bool deleteElement(int);
        bool compare(Conjunto);
        Conjunto intersect(Conjunto);
        void cartesian(Conjunto);
};

bool Conjunto::addElement(int element)
{
    if (card == MAX)
    {
        return false;
    }

    if (belongs(element))
    {
        return false;
    }

    array[card] = element;
    card++;
    return true;
}

void Conjunto::print()
{
    cout << "{";
    for (int i = 0; i < card ; i++)
    {
        if (i == card - 1)
        {
            cout << array[i];
        }
        else 
        {
            cout << array[i] << ", ";
        }  
    }
    cout << "}" << endl;
}

bool Conjunto::belongs(int element)
{
    for (int i = 0; i < card; i++)
    {
        if (array[i] == element)
        {
            return true;
        }
    }
    return false;
}

Conjunto Conjunto::intersect(Conjunto X)
{
    Conjunto tmp;
    for (int i = 0; i < card; i++)
    {
        if (X.belongs(array[i]))
        {
            tmp.addElement(array[i]);
        }
    }
    return tmp;
}

bool Conjunto::deleteElement(int element)
{
    for (int i = 0; i < card; i++)
    {
        if (array[i] == element)
        {
            int tmp = array[card-1];
            array[card-1] = array[i];
            array[i] = tmp;
            card--;
            return true;
        }
    }
    return false;
}

bool Conjunto::unite(Conjunto x, Conjunto &y)
{
    if (((card) + (x.card)) > MAX)
    {
        return false;
    }

    for (int i = 0; i < card; i++)
    {
        y.addElement(array[i]);
    }

    for (int i = 0; i < x.card; i++)
    {
        y.addElement(x.array[i]);
    }

    return true;
}

bool Conjunto::compare(Conjunto x)
{
    for (int i = 0; i < card; i++)
    {
        if(!belongs(x.array[i]))
        {
            return false;
        }
    }
    return true;
}

void Conjunto::cartesian(Conjunto x)
{
    if (card == 0 || x.card == 0)
    {
        cout << "{}";
        exit(0);
    }

    cout << "{";

    for (int i = 0; i < card; i++)
    {
        for (int j = 0; j < x.card; j++)
        {
            cout << "(" << array[i] << "," << x.array[j] << ")";
        }
        if (i != card - 1)
        {
            cout << ",";
        }
    }
    cout << "}";
}

int main()
{
    Conjunto c1, c2, c3;
    int tmp;
    int input;

    cout << "Cuantos elementos quiere ingresar (maximo 10): ";
    cin >> input;
    while (input > 10)
    {
        cout << "Maximo 10 numeros, ingrese otro numero: ";
        cin >> input;
    }

    for (int i = 0; i < input; i++)
    {
        cout << "Elemento que quieres agregar al conjunto 1: ";
        cin >> tmp;
        if (c1.addElement(tmp))
        {
            cout << "El elemento fue agregado con exito." << endl;
        }
        else
        {
            cout << "El elemento no pudo ser agregado con exito." << endl;
        }
    }
    cout << "Conjunto 1:" << endl;
    c1.print();

    for (int i = 0; i < input; i++)
    {
        cout << "Elemento que quieres agregar al conjunto 2: ";
        cin >> tmp;
        if (c2.addElement(tmp))
        {
            cout << "El elemento fue agregado con exito." << endl;
        }
        else
        {
            cout << "El elemento no pudo ser agregado con exito." << endl;
        }
    }
    cout << "Conjunto 2:" << endl;
    c2.print();

    c3 = c1.intersect(c2);
    cout << "El conjunto interseccion es: " << endl;
    c3.print();

    cout << "Que elemento deseas borrar del conjunto 1: ";
    cin >> tmp;
    cout << "Conjunto 1 original: ";
    c1.print();
    c1.deleteElement(tmp);
    cout << "Conjunto 1 despues de borrar el elemento " << tmp << ": ";
    c1.print();

    cout << "c1: ";
    c1.print();
    cout << "c2: ";
    c2.print();
    cout << "Union de c1 con c2: " << endl; 
    c1.unite(c2, c3);
    c3.print();

    if (c1.compare(c2))
    {
        cout << "c1 y c2 son iguales" << endl;
    }
    else
    {
        cout << "c1 y c2 no son iguales" << endl;
    }
    cout << "Producto cartesiano de c1 y c2: ";
    c1.cartesian(c2);
}