#include <iostream>
#include <cstring>
#include <stdexcept>
#define SIZE 10
using namespace std;

template <class T>
class Queue {
    T *arr;
    int front, back; // front is inclusive, back is exclusive
    int capacity;

    public: 
        Queue(int size = SIZE);
        ~Queue();

        bool isEmpty();
        bool isFull();
        int size();

        void push(T x);
        void pop();
        T peek();
        
};

template <class T>
Queue<T>::Queue(int size) {
    arr = new T[size];
    capacity = size;
    front = 0;
    back = 0;
    cout << "Queue created!" << endl;
}

template <class T>
Queue<T>::~Queue() {
    delete[] arr;
    cout << "Queue deleted!" << endl;
}

template <class T> 
int Queue<T>::size() {
    return back - front;
}

template <class T>
bool Queue<T>::isEmpty() {
    return size() == 0;
}

template <class T>
bool Queue<T>::isFull() {
    return size() == capacity;
}

template <class T>
void Queue<T>::push(T x) {
    if (isFull()) {
        cout << "Error: Queue is full!" << endl;
        return;
    } 
    arr[back % capacity] = x;
    back++;
}

template <class T>
void Queue<T>::pop() {
    if (isEmpty()) {
        cout << "Error: Queue is empty!" << endl;
        return;
    }
    front++;
}

template <class T>
T Queue<T>::peek() {
    // printf("\n Front: %d; Back: %d. \n", front, back);
    if (isEmpty()) {
        cout << "Error: Queue is empty!" << endl;
        return nullptr;
    }
    return arr[front % capacity];
}

int main() {
    Queue<string> q(3);
    q.push("Apple");
    q.push("Orange");
    q.push("Pear");
    q.pop();
    q.pop();
    // q.pop();
    cout << q.size() << " " << q.peek() << endl;
    q.push("Watermelon"); // Should return "Queue is full" error
    cout << q.size() << " " << q.peek() << endl;
    q.pop();
    cout << q.size() << " " << q.peek() << endl;
    q.pop();
    cout << q.size() << endl;
    q.push("Apple");
    q.push("Orange");
    q.push("Pear");
    cout << q.size() << " " << q.peek() << endl;

    return 0;
}





