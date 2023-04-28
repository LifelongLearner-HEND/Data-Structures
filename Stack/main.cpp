// Linked Stack
#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next;
};

template<class T>
class stack {
private:
    Node<T> *top;
    int Size;
public:
    stack() {
        Size = 0;
        top = nullptr;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void push(T element) {
        auto *newNode = new Node<T>;
        if (newNode == nullptr) {
            cout << "Stack Push can not allocate memory\n";
        }
        newNode->data = element;
        newNode->next = top;
        top = newNode;
        Size++;
    }

    //return the first element and remove it
    T pop() {
        T topElement = top->data;
        if (isEmpty()) {
            cout << "Stack is Empty\n";
        } else {
            auto *temp = top;
            top = top->next;
            temp->next = nullptr;
            delete temp;
            Size--;
        }
        return topElement;
    }

    //return the first element without removing it
    T getTop() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        return (top->data);
    }

    int stackSize() {
        return Size;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        } else {
            auto *temp = new Node<T>;
            temp = top;
            cout << "Stack: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void clear() {
        auto *temp = new Node<T>;
        while (top != nullptr) {
            temp = top;
            top = top->next;
            delete temp;
        }
        top = nullptr;
        Size = 0;
    }
};

int main() {
    /*
    stack<int> mystack;
    mystack.push(1);
    mystack.push(50);
    mystack.push(200);
    mystack.push(20);
    mystack.push(3);
    mystack.push(9);
    mystack.push(87);
    mystack.push(65);
    cout << mystack.pop() << endl;
    mystack.print();
    cout << mystack.stackSize();
    return 0;
     */
}
