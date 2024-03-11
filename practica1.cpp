#include <iostream>

using namespace std;

void fill(int array[], int size);
int alta(int array[], int size);
int baja(int array[], int size);
void print(int array[], int size);
float media(int array[], int size);

int main(void)
{
    int n;
    cout << "Cuantos alumnos hay?" << endl;
    cin >> n;
    int students[n];
    fill(students, n);
    cout << endl;
    cout << "La calificacion mas alta es: " << alta(students, n) << endl;
    cout << endl;
    cout << "La calificacion mas baja es: " << baja(students, n) << endl;
    cout << endl;
    cout << "La lista de calificaciones es: " << endl;
    cout << endl;
    print(students, n);
    cout << endl;
    cout << "La calificacion media es: " << media(students, n) << endl;
    cout << endl;
    cout << "La calificacion mas alta es: " << alta(students, n) << endl;
    cout << endl;
    cout << "La calificacion mas baja es: " << baja(students, n) << endl;
    cout << endl;
}

void fill(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Calificacion del alumno " << i+1 <<": ";
        cin >> array[i];
        while (array[i] < 0 || array[i] > 10)
        {
            cout << "La calificacion debe ser un numero entre 0 y 10" << endl;
            cout << "Calificacion del alumno " << i+1 <<":";
            cin >> array[i];
        }
    }
}

int alta(int array[], int size)
{
    int alta = array[0];
    for (int i = 1; i < size; i++)
    {
        if (alta < array[i])
        {
            alta = array[i];
        }
    }
    return alta;
}

int baja(int array[], int size)
{
    int baja = array[0];
    for (int i = 1; i < size; i++)
    {
        if (baja > array[i])
        {
            baja = array[i];
        }
    }
    return baja;
}

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Calificacion del alumno "<< i+1 << ": " << array[i] << endl;
    }
}

float media(int array[], int size)
{
    float media = 0;
    for (int i = 0; i < size; i++)
    {
        media += array[i];
    }
    return media/size;
}