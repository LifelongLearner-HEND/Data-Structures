#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next;
};

template<class T>
class SLL {
public:
    Node<T> *head, *tail;
    int Size;

    SLL() {
        head = tail = nullptr;
        Size = 0;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    void insertAtHead(T item) {
        auto *newNode = new Node<T>;
        newNode->data = item;
        if (isEmpty()) {
            newNode->next = nullptr;
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
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

    void insertAtTail(T item) {
        auto *newNode = new Node<T>;
        newNode->data = item;
        newNode->next = nullptr;
        // if list is empty
        if (tail == nullptr) {
            head = tail = newNode;
        }
            // if list is not empty, insert a new node at the end of the list
        else {
            tail->next = newNode;
            tail = newNode;
        }
        Size++;
    }

    void insertAt(T item, int index) {
        // if index is out of range
        if (index < 0 or index > Size) {
            cout << "Index out of range!\n";
            return;
        } else {
            // if inserting at first
            if (index == 0) {
                insertAtHead(item);
            }
                // if inserting at the end
            else if (index == Size) {
                insertAtTail(item);
            }
                // if inserting at the middle
            else {
                auto *newNode = new Node<T>;
                newNode->data = item;
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
            /* if the list has more than one item,
               traverse the list to find the node before the tail
            */
        else {
            auto *temp = new Node<T>;
            temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = nullptr;
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

    int linkedListSize() {
        return Size;
    }

    void print() {
        Node<T> *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SLL<int> mylist;
    mylist.insertAtHead(1);
    mylist.insertAtHead(2);
    mylist.insertAtHead(3);
    mylist.insertAtHead(4);
    mylist.insertAtHead(5);
    mylist.insertAtHead(6);
    mylist.insertAtHead(7);
    cout << mylist.retrieveAt(4) << endl;

    mylist.print();
    cout << mylist.linkedListSize();
    return 0;
}
