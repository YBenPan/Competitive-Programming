#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 10

template <class T>
class Stack {
    T *arr;
    size_t size;
    int top;

    public: 

        Stack(int size = SIZE) {
            arr = new T[size];
            this->size = size;
            this->top = -1;
            cout << "Stack created!" << endl;
        }
        ~Stack() {
            delete[] arr;
            cout << "Stack deleted!" << endl;
        }

        T getTop() {
            return arr[top];
        }

        size_t getSize() {
            return top + 1;
        }

        bool isEmpty() {
            return top == -1;
        }
        
        bool isFull() {
            return top == size - 1;
        }

        void push(T x) {
            if (isFull()) {
                cout << "Error: Stack is full!" << endl;
                return;
            }
            arr[++top] = x;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Error: Stack is empty!" << endl;
                return;
            }
            top--;
        }

};

int main() {
    Stack<int> st(5);
    st.push(1);
    st.push(3);
    st.push(5);
    st.push(7);
    st.push(9);
    cout << st.getSize() << " " << st.getTop() << endl;
    st.push(50); // Returns stack is full error
    st.pop();
    cout << st.getSize() << " " << st.getTop() << endl;
    for (int i = 0; i < 4; i++) st.pop();
    cout << st.isEmpty() << endl;
    st.pop(); // Returns stack is empty error

    Stack<string> str_st(5);
    str_st.push("Alpha");
    str_st.push("Bravo");
    str_st.push("Charlie");
    str_st.push("Delta");
    cout << str_st.getSize() << " " << str_st.getTop() << endl;
    return 0;
}
