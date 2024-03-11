#include <bits/stdc++.h>

using namespace std;

void fill(int array[], int size);
void print(int array[], int size);
void insertionSort(int array[], int size);
void print20(int array[], int size);

int main(void)
{
    int answer = 1;
    cout << "Quieres llenar el arreglo?" << endl << "1-Si" << endl << "2-No" << endl;
    cin >> answer;
    int time;

    while (answer == 1)
    {
        int size;
        cout << "Cuantos numeros vas a guardar?" << endl;
        cin >> size;
        cout << endl;
        int array[size];
        fill(array, size);
        cout << "Arreglo desordenado" << endl;
        print(array, size);
        cout << endl;
        cout << "Arreglo ordenado" << endl;
        insertionSort(array, size);
        print(array, size);
        cout << endl;
        print20(array, size);
        cout << endl;

        cout << "Quieres llenar el arreglo de nuevo?" << endl << "1-Si" << endl << "2-No" << endl;
        cin >> answer;
    }
}

void fill(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
    }
}

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

void print20(int array[], int size)
{
    int percent = 0.2 * size;
    cout << "El primer 20 % es: " << endl;
    for (int i = 0; i < percent; i++)
    {
        cout << array[i] << endl;
    }
    cout << endl;
    cout << "El ultimo 20% es: " << endl;
        for (int i = size - percent; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

void insertionSort(int array[], int size)
{
    clock_t start, end;
    start = clock();
    
    for (int i = 1; i < size; i++)
    {
        int j = i-1;
        int tmp = array[i];
        while (array[j] > tmp && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j+1] = tmp;
    }

    end = clock();
    double timeTaken = double(end-start) / double(CLOCKS_PER_SEC);
    cout << "El tiempo que tarda en ordenar el arreglo es: " << fixed << timeTaken << "seg" << endl;
}