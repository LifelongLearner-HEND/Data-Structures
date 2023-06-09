#include <iostream>
#include <algorithm>

using namespace std;
// comment
template<class T>
class Node {
public:
    T data;
    Node *next;
};
// comment
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
        // if the list has more than one item, traverse the list to find the node before the tail
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
//        cout << temp1 << " " << temp2 << endl;
        swap(temp1, temp2);
//        cout << temp1 << " " << temp2 << endl;
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

    ~ SLL() {
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
    /*
    SLL<int> mylist;
    mylist.insertAtHead(1);
    mylist.insertAtHead(2);
    mylist.insertAtHead(3);
    mylist.insertAtHead(4);
    mylist.insertAtHead(5);
    mylist.insertAtHead(6);
    mylist.insertAtHead(7);
    mylist.Swap(1, 2);
    cout << mylist.linkedListSize();
    return 0;
     */
}
