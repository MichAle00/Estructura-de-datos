#include <iostream>
#define MAX 10

using namespace std;

class Queue
{
    private:
        int start, end, cuenta;
        int array[MAX];
    public:
        Queue();
        void insertar(int);
        int eliminar();
        bool empty();
        bool full();
};

Queue::Queue()
{
    start = 0;
    end = 0;
}

void Queue::insertar(int a)
{
    
}

int main()
{

}