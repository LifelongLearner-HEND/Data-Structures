#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node *next, *prev;
};

template <class T>
class DLL {
private:
    int Size;
    Node<T> *head, *tail;
public:
    DLL() {
        head = tail = nullptr;
        Size = 0;
    }
    bool isEmpty() {
        return (head == nullptr);
    }
    void insertAtHead(T element) {
        auto *newNode = new Node<T>;
        newNode->data = element;
        if (isEmpty()) {
            head = tail = newNode;
            newNode->next = newNode->prev = nullptr;
        }
        else {
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
            // update the tail pointer to point at the last node
            Node<T> *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            tail = temp;
        }
        Size++;
    }
    void insertAtTail(T element) {
        auto *newNode = new Node<T>;
        newNode->data = element;
        if (isEmpty()) {
            head = tail = newNode;
            newNode->next = newNode->prev = nullptr;
        }
        else {
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        Size++;
    }
    void insertAt(T element, int index) {
        // if index is out of range
        if (index < 0 or index > Size) {
            cout << "Index out of range!\n";
            return;
        }
        // if inserting at first
        if (index == 0) {
            insertAtHead(element);
        }
        // if inserting at the end
        else if (index == Size) {
            insertAtTail(element);
        }
        else {
            auto *newNode = new Node<T>;
            auto *temp = new Node<T>;
            newNode->data = element;
            temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next = newNode;
            temp->next->prev = newNode;
            Size++;
        }
    }
    void insertAfter(Node<T> *preNode, T element) {
        auto *newNode = new Node<T>;
        newNode->data = element;
        newNode->prev = preNode;
        newNode->next = preNode->next;
        preNode->next->prev = newNode;
        preNode->next = newNode;
    }
    void removeAtHead() {
        if (isEmpty()) {
            cout << "Can't remove, list is empty!\n";
            return;
        }
        else if (Size == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            auto *temp = new Node<T>;
            temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        Size--;
    }
    void removeAtTail() {
        if (isEmpty()) {
            cout << "Can't remove, list is empty!\n";
            return;
        }
        else if (Size == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            auto *temp = new Node<T>;
            temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        Size--;
    }
    void removeAt(int index) {
        if (index == 0) {
            removeAtHead();
        }
        else if (index == Size) {
            removeAtTail();
        }
        else {
            auto *temp = new Node<T>;
            temp = head;
            for (int i = 1; i <= index; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            Size--;
        }
    }
    T retrieveAt(int index) {
        // retrieve head data
        if (index == 0) {
            return (head->data);
        }
            // retrieve tail data
        else if (index == Size - 1) {
            return (tail->data);
        } else {
            auto *temp = new Node<T>;
            temp = head;
            for (int i = 1; i <= index; i++) {
                temp = temp->next;
            }
            return (temp->data);
        }
    }
    // Replacing the element at a certain index with another new element
    void replaceAt(T item, int index) {
        if (index == 0) {
            head->data = item;
        } else if (index == Size) {
            tail->data = item;
        } else {
            auto *temp = new Node<T>;
            temp = head;
            for (int i = 1; i <= index; i++) {
                temp = temp->next;
            }
            temp->data = item;
        }
    }
    // checking if an element exists in the list or not
    bool isExist(T item) {
        auto *temp = new Node<T>;
        temp = head;
        while (temp != nullptr) {
            if (temp->data == item) {
                return true;
            } else {
                temp = temp->next;
            }
        }
        return false;
    }
    // check if item at a certain index equal the passed value or not
    bool isItemAtEqual(T item, int index) {
        auto *temp = new Node<T>;
        temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        if (temp->data == item) {
            return true;
        } else {
            return false;
        }
    }
    // swap two nodes without swapping data
    void Swap(int firstIndex, int secondIndex) {
        auto *temp1 = new Node<T>;
        auto *temp2 = new Node<T>;
        temp1 = temp2 = head;
        for (int i = 0; i < firstIndex; i++) {
            temp1 = temp1->next;
        }
        for (int j = 0; j < secondIndex; j++) {
            temp2 = temp2->next;
        }
       // cout << temp1 << " " << temp2 << endl;
        swap(temp1, temp2);
       // cout << temp1 << " " << temp2 << endl;
    }
    void Reverse() {
        auto *curNode = new Node<T>;
        auto *prevNode = new Node<T>;
        curNode = head;
        prevNode = nullptr;
        while (curNode != nullptr) {
            auto *nextNode = new Node<T>;
            nextNode = curNode->next;
            curNode->next = prevNode;
            curNode->prev = nextNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        head = prevNode;
    }

    Node<int> * retrievePointer(int index) {
        if (index == 0) {
            return head;
        }
        else if (index == Size) {
            return tail;
        }
        else {
            auto *temp = new Node<T>;
            temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
    }

    int linkedListSize() {
        return Size;
    }

    void forwardTraversal(){
        Node<T> *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void backwardTraversal() {
        Node<T> *temp = tail;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    ~DLL() {
        auto *temp = new Node<T>;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
        Size = 0;
    }


};

int main() {
    DLL <int> myList;
    myList.insertAtHead(1);
    myList.insertAtHead(2);
    myList.insertAtHead(3);
    myList.insertAtHead(4);
    myList.insertAtHead(5);
    myList.insertAtHead(6);
    myList.insertAfter(myList.retrievePointer(1), 100);
    myList.forwardTraversal();
    return 0;
}
