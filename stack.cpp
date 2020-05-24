#include <iostream>

using namespace std;

class Stack {
    
    private:
        int *values;
        int top;
        int capacity;

    public:
        Stack(int size) {
            values = new int[size];
            capacity = size;
            top = -1;
        };
        
        void push(int value) {
            if(top == capacity - 1) {
                cout << "Stack Overflow!" << endl;
                exit(EXIT_FAILURE);
            } else {
                values[++top] = value;
            }
        }

        int pop() {
            if(top == -1) {
                cout << "Nothing to pop!" << endl;
                exit(EXIT_FAILURE);
            } else {
                return values[top--];
            }
        }

        int peek() {
            if(top == -1) {
                cout << "Stack is empty!" << endl;
                exit(EXIT_FAILURE);
            } else {
                return values[top];
            }
        }
};

int main() {

    Stack mystack = Stack(5);

    mystack.push(5);
    mystack.push(10);
    mystack.push(19);
    mystack.push(3);
    mystack.push(2);
    
    cout << mystack.peek() << endl;
    cout << mystack.pop() << endl;
    
    mystack.push(100);

    for(int i = 0; i < 5; i++) {
        cout << mystack.pop() << endl;
    }

    mystack.pop(); // Error 

    return 0;
}