#include <iostream>
#include <stack>
#include <string>

struct Phone {
    std::string name;
    double price;
};

int main() {
    std::stack<Phone> phoneQueue;

    // Добавляем информацию о телефонах в очередь
    phoneQueue.push({"iPhone 12", 999.99});
    phoneQueue.push({"Samsung Galaxy S21", 899.99});
    phoneQueue.push({"Google Pixel 5", 799.99});

    // Удаляем информацию о первом телефоне
    if (!phoneQueue.empty()) {
        phoneQueue.pop();
    }
    else {
        std::cout << "Очередь пуста" << std::endl;
    }

    // Просмотр данных в очереди
    std::cout << "Информация о телефонах в очереди:" << std::endl;
    std::stack<Phone> tempStack = phoneQueue;
    while (!tempStack.empty()) {
        Phone phone = tempStack.top();
        std::cout << "Телефон: " << phone.name << ", Цена: $" << phone.price << std::endl;
        tempStack.pop();
    }   
    return 0;
}
