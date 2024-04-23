#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* next;

    Node(T value) : 
        data(value),
        next(nullptr) 
    {
    }
};

template <typename T>
class Stack
{
private:
    Node<T>* top; // Покажчик на вершину стеку

public:
    Stack() : top(nullptr) 
    { }

    ~Stack()
    {
        while (top != nullptr)
        {
            pop();
        }
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    void push(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cerr << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }

    const T& peek() const
    {
        if (isEmpty())
        {
            cerr << "Stack is empty." << endl;

            static T dummy;

            return dummy;
        }

        return top->data;
    }
};

int main()
{
    Stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top of the stack: " << myStack.peek() << endl;

    myStack.pop();
    cout << "After pop:" << endl;
    cout << "Top of the stack: " << myStack.peek() << endl;

    return 0;
}
