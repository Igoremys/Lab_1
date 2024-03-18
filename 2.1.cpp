#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void print() {
        Node* curr = top;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    string findMinLengthString() {
        Node* curr = top;
        int minLength = curr->data.length();
        string minString = curr->data;
        while (curr != NULL) {
            if (curr->data.length() < minLength) {
                minLength = curr->data.length();
                minString = curr->data;
            }
            curr = curr->next;
        }
        return minString;
    }
};

int main() {
    Stack stack;
    // Добавляем строки в стек
    stack.push("sdf");
    stack.push("2");
    stack.push("ssd4");
    stack.push("hello");
    // Распечатываем содержимое стека
    stack.print();
    // Удаляем 2 элемента из стека
    stack.pop();
    stack.pop();
    // Распечатываем содержимое стека еще раз
    stack.print();
    // Найдем строку минимальной длины, принадлежащую стеку, и распечатаем ее
    cout << "Минимальная строка: " << stack.findMinLengthString() << endl;

    return 0;
}
