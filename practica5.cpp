#include <iostream>

using namespace std;

#define MAX 10

class Stack
{
    private:
        char array[MAX];
        int top;
    public:
        Stack(){top = -1;};
        bool Push(char);
        char Pop();
        bool Empty();
        bool Full();
        char See_Top();
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

bool Stack::Push(char elem)
{
    if (Full())
    {
        return false;
    }

    top++;
    array[top] = elem;
    return true;
}

char Stack::Pop()
{
    if (Empty())
    {
        exit(0);
    }

    char tmp = array[top];
    top--;
    return tmp;
}

char Stack::See_Top()
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

int main()
{
    Stack n;
    
    string s;
    cout << "Dame la expresion: ";
    getline(cin, s);
    bool flag = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            n.Push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (n.Empty())
            {
                flag = true;
                break;
            }
            
            if (s[i]-1 == n.See_Top())
            {
                n.Pop();
            }
        }
        else if (s[i] == ']' || s[i] == '}')
        {
            if (n.Empty())
            {
                flag = true;
                break;
            }
            
            if (s[i]-2 == n.See_Top())
            {
                n.Pop();
            }
        }
    }

    if (n.Empty() && !flag)
    {
        cout << "La expresion es correcta" << endl;
    }
    else if (!n.Empty() || flag)
    {
        cout << "La expresion es incorrecta";
    }
}