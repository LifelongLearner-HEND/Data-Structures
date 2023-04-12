#include <iostream>
using namespace std;

template <class T>
class Array {
private:
    int Size;
    int len;
    T *data;
public:
    /*
     initialize size and
     allocate dynamic array
     */
    Array(int S) {
        Size = S;
        len = 0;
        data = new T[S];
    }
    // check is array is full
    bool isFull() {
        return (len == Size);
    }
    // check if array is empty
    bool isEmpty() {
        return (len == 0);
    }
    // get array Size
    int listSize() {
        return len;
    }
    // get max size of the array
    int maxListSize() {
        return Size;
    }
    /*
    check if the array is not full
    then push back the element.
   */
    void Insert(T element) {
        if (isFull()) {
            cout << "Array is Full !\n";
        }
        else if (len < Size)  {
            data[len] = element;
            len++;
        }
    }
    /*
     insert an element at a specific position
     by shifting all array elements to the right.
     */
    void InsertAt(T element, int index) {
        if (isFull()) {
            cout << "Can't insert. Array is Full!\n";
        }
        else if (index > len or index < 0) {
            cout << "Index out of range!\n";
        }
        else {
            for (int i = len; i > index; i--) {
                data[i] = data[i - 1];
            }
            data[index] = element;
            len++;
        }
    }
    /*
     return the element at a certain position.
     */
    T retrieveAt(int index) {
        return (data[index]);
    }
    /*
     remove an element at a certain index
     by shifting elements to the left.
     */
    void RemoveAt(int index) {
        if (isEmpty()) {
            cout << "Can't remove. Array is Empty!\n";
        }
        else if (index > len or index < 0) {
            cout << "Index out of range!\n";
        }
        else {
            for (int i = index; i < len; i++) {
                data[i] = data[i + 1];
            }
            len--;
        }
    }
    /*
     replacing an element at a certain index
     by another element.
     */
    void replaceAt(T element, int index) {
        if (index > len or index < 0) {
            cout << "Index out of range!\n";
        }
        else {
            data[index] = element;
        }
    }
    /*
     Check if an element at a certain index
     equals another element
     */
    bool isItemAtEqual(T element, int index) {
        if (index > len or index < 0) {
            cout << "Index out of range!\n";
        } else if (data[index] == element) {
            return true;
        }
        return false;
    }
    // print array
    void print() {
        cout << "Array elements: ";
        for (int i = 0; i < len; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    // clear array and free up memory
    void CLear() {
        delete [] data;
        len = 0;
        Size = 0;
    }
};

int main() {
    /*
    Array<int> arr(7);
    arr.Insert(1);
    arr.Insert(3);
    arr.Insert(5);
    arr.Insert(10);
    arr.Insert(12);
    arr.print();
    arr.CLear();
    cout << arr.listSize() << endl << arr.maxListSize() << endl;
    arr.print();
    return 0;
     */
}
