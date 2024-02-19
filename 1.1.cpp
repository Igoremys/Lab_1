#include <iostream>
#include <stack>
#include <string>

struct Student {
  std::string surname;
  float average_grade;
};

void printStack(std::stack<Student> s) {
  while (!s.empty()) {
    Student student = s.top();
    std::cout << "Имя: " << student.surname << ", Средний Бал: " << student.average_grade << std::endl;
    s.pop();
  }
}

int main() {
  std::stack<Student> studentStack;

  // Добавление нового студента в стек
  Student student1 = {"Мусхажиев", 5.0};
  studentStack.push(student1);

  // Просмотр данных в стеке
  printStack(studentStack);

  return 0;
}
