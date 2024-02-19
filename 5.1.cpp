#include <iostream>
#include <list>

using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAfterNegative(std::list<Node>& myList, int value) {
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        if (it->data < 0) {
            Node newNode = {value, &(*it), it->next};
            if (it->next) {
                it->next->prev = &newNode;
            }
            it->next = &newNode;
            myList.insert(std::next(it), newNode);
            ++it; // Skip the newly inserted node
        }
    }
}

int main() {
    list<Node> myList = {{-5, nullptr, nullptr}, {10, nullptr, nullptr}, {-3, nullptr, nullptr}, {7, nullptr, nullptr}};

    // Вставка числа 66 после каждого элемента с отрицательным значением
    insertAfterNegative(myList, 66);

    // Вывод списка
    for (const auto& node : myList) {
        cout << node.data << " ";
    }
    cout << endl;

    return 0;
}
