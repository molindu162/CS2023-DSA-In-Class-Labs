#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std::chrono;
using namespace std;

class Stack
{
    int size;
    vector<int> buffer;
    int top = 0;
    bool isEmpty = true;
    bool isFull = false;

public:
    Stack(int size)
    {
        this->size = size;
    }

public:
    void push(int item)
    {
        if (top >= size)
        {
            cout << "stack overflowed" << endl;
        }
        else
        {
            buffer.push_back(item);
            top += 1;
        }
    }

public:
    void pop()
    {
        if (top <= 0)
        {
            cout << "stack underflowed" << endl;
        }
        else
        {
            buffer.pop_back();
            top -= 1;
        }
    }

public:
    void dispaly()
    {
        for (int i = 0; i < top; i++)
        {
            cout << buffer[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stack(14);

    auto start = high_resolution_clock::now();

    for (int i = 0; i < 10; i++)
    {
        stack.push(::rand() % 100);
    }

    stack.dispaly();

    for (int i = 0; i < 5; i++)
    {
        stack.pop();
    }

    stack.dispaly();

    for (int i = 0; i < 4; i++)
    {
        stack.push(::rand() % 100);
    }

    stack.dispaly();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken for stack operations: "
         << duration.count() << " microseconds" << endl;

    return 0;
}