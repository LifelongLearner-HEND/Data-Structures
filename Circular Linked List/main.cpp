#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next;
};

template<class T>
class CLL {
public:
    Node<T> *head, *tail;
    int Size;

    CLL() {
        head = tail = nullptr;
        Size = 0;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    void insertAtHead(T element) {
        auto *newNode = new Node<T>;
        newNode->data = element;
        // if the list is already empty
        if (isEmpty()) {
            newNode->next = nullptr;
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        Size++;
    }

    void insertAtTail(T element) {
        auto *newNode = new Node<T>;
        newNode->data = element;
        if (isEmpty()) {
            newNode->next = nullptr;
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        Size++;
    }

    void insertAt(T element, int index) {
        // if index is out of range
        if (index < 0 or index > Size) {
            cout << "Index out of range!\n";
            return;
        } else {
            // if inserting at first
            if (index == 0) {
                insertAtHead(element);
            }
            // if inserting at the end
            else if (index == Size) {
                insertAtTail(element);
            }
            // if inserting at the middle
            else {
                auto *newNode = new Node<T>;
                newNode->data = element;
                auto *temp = new Node<T>;
                temp = head;
                for (int i = 1; i < index; i++) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                Size++;
            }
        }
    }

    void removeAtHead() {
        // if the list is empty, you can't remove
        if (Size == 0) {
            cout << "Can not remove. List is empty!\n";
            return;
        }
        // if the list has only one item
        else if (Size == 1) {
            delete head;
            delete tail;
            head = tail = nullptr;
        }
        // if the list has more than one item
        else {
            auto *temp = new Node<T>;
            temp = head;
            head = head->next;
            delete temp;
            // update the next of the tail
            tail->next = head;
        }
        Size--;
    }

    void removeAtTail() {
        // if the list is empty, you can't remove
        if (Size == 0) {
            cout << "Can not remove. List is empty!\n";
            return;
        }
        // if the list has only one item
        else if (Size == 1) {
            delete head;
            delete tail;
            head = tail = nullptr;
        }
        // if the list has more than one item, traverse the list to find the node before the tail
        else {
            auto *temp = new Node<T>;
            temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
        }
        Size--;
    }

    void removeAt(int index) {
        if (index < 0 or index > Size) {
            cout << "Index out of range!\n";
        } else if (index == 0) {
            removeAtHead();
        } else if (index == Size) {
            removeAtTail();
        } else {
            // cur pointer points to the node to be deleted
            auto *prev = new Node<T>;
            auto *cur = new Node<T>;
            prev = cur = head;
            for (int i = 1; i <= index; i++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;
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
    void replaceAt(T element, int index) {
        if (index < 0 or index > Size - 1) {
            cout << "Index out of range!\n";
        }
        if (index == 0) {
            head->data = element;
        } else if (index == Size - 1) {
            tail->data = element;
        } else {
            auto *temp = head;
            for (int i = 1; i <= index; i++) {
                temp = temp->next;
            }
            temp->data = element;
        }
    }

    // checking if an element exists in the list or not
    bool isExist(T element) {
        if (isEmpty()) {
            return false;  // return false if the list is empty
        }
        Node<T> *temp = head;
        while (temp->next != head) {
            if (temp->data == element) {
                return true;
            }
            temp = temp->next;
        }
        // Check the last node outside the loop
        if (temp->data == element) {
            return true;
        }
        return false;
    }

    // check if item at a certain index equal the passed value or not
    bool isItemAtEqual(T element, int index) {
        auto *temp = new Node<T>;
        temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        if (temp->data == element) {
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
//        cout << temp1 << " " << temp2 << endl;
        swap(temp1, temp2);
//        cout << temp1 << " " << temp2 << endl;
    }

    int linkedListSize() {
        return Size;
    }

    void print() {
        Node<T> *temp = head;
        while (temp->next != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        // print the last node
        cout << temp->data << " ";
        cout << endl;
    }

    ~ CLL() {
        auto *temp = head;
        auto *cur = new Node<T>;
        while (head->next != temp) {
            cur = head;
            head = head->next;
            delete cur;
        }
        head = tail = nullptr;
        Size = 0;
    }
};

int main() {
    /*
    CLL<int> mylist;
    mylist.insertAtHead(1);
    mylist.insertAtHead(2);
    mylist.insertAtHead(3);
    mylist.insertAtHead(4);
    mylist.insertAtHead(5);
    mylist.insertAtHead(6);
    mylist.insertAtHead(7);
    cout << mylist.isExist(4) << endl;
    mylist.print();
    cout << mylist.linkedListSize();
    return 0;
     */
}
