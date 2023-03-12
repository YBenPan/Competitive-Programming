#include <iostream>
using namespace std;
#define SIZE 10

class Stack {
    int *arr;
    int size;
    int top;

    public: 

        Stack() {
            arr = new int[SIZE];
            this->size = SIZE;
            this->top = -1;
            cout << "Stack created!" << endl;
        }
        Stack(int size) {
            arr = new int[size];
            this->size = size;
            this->top = -1;
            cout << "Stack created!" << endl;
        }
        ~Stack() {
            delete[] arr;
            cout << "Stack deleted!" << endl;
        }

        int getTop() {
            return arr[top];
        }

        int getSize() {
            return top + 1;
        }

        bool isEmpty() {
            return top == -1;
        }
        
        bool isFull() {
            return top == size - 1;
        }

        void push(int x) {
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
    Stack st(5);
    st.push(1);
    st.push(3);
    st.push(5);
    st.push(7);
    st.push(9);
    cout << st.getSize() << " " << st.getTop() << endl;
    st.push(50);
    st.pop();
    cout << st.getSize() << " " << st.getTop() << endl;
    for (int i = 0; i < 4; i++) st.pop();
    cout << st.isEmpty() << endl;
    st.pop();
    return 0;
}
