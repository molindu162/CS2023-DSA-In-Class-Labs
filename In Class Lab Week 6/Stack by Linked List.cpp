#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std::chrono;
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void append(int data)
    {
        Node *node = new Node(data);
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            Node *lastNode = head;
            while (lastNode->next != NULL)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = node;
        }
    }

    void delLastNode()
    {
        Node *lastNode = head;
        while (lastNode->next->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = NULL;
    }

    void display()
    {
        Node *node = head;

        if (head == NULL)
        {
            cout << "empty" << endl;
            return;
        }

        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }
};

class Stack
{
    int size;
    LinkedList *buffer = new LinkedList();
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
            buffer->append(item);
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
            buffer->delLastNode();
            top -= 1;
        }
    }

public:
    void dispaly()
    {
        buffer->display();
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