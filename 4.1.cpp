#include <iostream>

// Структура узла списка
struct Node {
    double data;
    Node* next;
    Node(double value) : data(value), next(nullptr) {}
};

// Функция для вставки числа 0.99 перед первым элементом со значением 22
void insertBefore(Node* &head, double value, double newValue) {
    Node* curr = head;
    Node* prev = nullptr;
    // Проходим по списку, пока не найдем элемент со значением value или пока не достигнем конца списка
    while (curr != nullptr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }
        
    // Создаем новый узел со значением newValue
    Node* newNode = new Node(newValue);
    
    // Вставляем новый узел перед элементом со значением value
    if (curr != nullptr) {
        if (prev == nullptr) {
            newNode->next = head;
            head = newNode;
        } else {
            prev->next = newNode;
            newNode->next = curr;
        }
    } else {
        // Если элемент со значением value не найден, добавляем новый узел в конец списка
        if (prev != nullptr) {
            prev->next = newNode;
        } else {
            head = newNode;
        }
    }
}

int main() {
    // Создаем список: 1 -> 3 -> 22 -> 7 -> 11
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(22);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(11);
    // Вставляем число 0.99 перед первым элементом со значением 22
    insertBefore(head, 22, 0.99);

    // Выводим список после вставки
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}
