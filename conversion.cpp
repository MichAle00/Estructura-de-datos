#include <iostream>
#include <cctype>
using namespace std;

#define MAX 5

class Stack
{
    private:
        int array[MAX];
        int top;
    public:
        Stack(){top = -1;};
        bool Push(int);
        int Pop();
        bool Empty();
        bool Full();
        int See_Top();
        void Print();
};

bool Stack::Full()
{
    if (top == MAX - 1)
    {
        return true;
    }
    return false;
}

bool Stack::Empty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

bool Stack::Push(int elem)
{
    if (Full())
    {
        return false;
    }

    top++;
    array[top] = elem;
    return true;
}

int Stack::Pop()
{
    if (Empty())
    {
        exit(0);
    }

    char tmp = array[top];
    top--;
    return tmp;
}

int Stack::See_Top()

{
    if (Empty())
    {
        exit(0);
    }

    return array[top];
}

void Stack::Print()
{
    for (int i = 0; i <= top; i++)
    {
        cout << array[i] << endl;
    }
}

int operation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;

    case '-':
        return a - b;
        break;

    case '*':
        return a * b;
        break;

    case '/':
        return a / b;
        break;
    
    default:
        exit(1);
        break;
    }
}

int main()
{
    string input;
    Stack s;

    cout << "Introduzca la expresion: ";
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        int op1, op2, tmp;
        cout << input[i] << endl;
        if (isdigit(input[i]))
        {
            tmp = (int) input[i];
            s.Push(tmp);
        }
        else
        {
            op2 = s.Pop();
            op1 = s.Pop();
            s.Push(operation(op1, op2, input[i]));
        }
    }

    cout << "Resultado: " << s.Pop();
}