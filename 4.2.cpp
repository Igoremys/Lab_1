#include <iostream>
#include <string>

using namespace std;

// Структура узла списка
struct Node {
    string data;
    Node* next;
};

//Подсчет латинских букв
int countLatinLetters(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        for (char c : current->data) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                count++;
            }
        }
        current = current->next;
    }
    return count;
}

int main() {
    Node* head = new Node();
    head->data = "Igor";
    head->next = new Node();
    head->next->data = "Muskhazhiev";
    head->next->next = new Node();
    head->next->next->data = "18 years";
    head->next->next->next = nullptr;

    int result = countLatinLetters(head);
    cout << "Total number of Latin letters: " << result << endl;

    return 0;
}              
