#include "LinearList.hpp"
#include <iostream>
#include <limits>

int inputPositiveInt() {
  int num;

  while (true) {
    std::cout << "Введите положительное число: ";
    std::cin >> num;

    if (std::cin.good() && num > 0) {
      return num;
    }
    std::cout << "Ошибка! Пожалуйста, введите целое положительное число.\n";

    std::cin.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return num;
}

float inputPositiveFloat() {
  float num;

  while (true) {
    std::cout << "Введите действительное число: ";
    std::cin >> num;

    if (std::cin.good()) {
      return num;
    } else {
      std::cout
          << "Ошибка! Пожалуйста, введите корректное действительное число.\n";

      std::cin.clear();

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return num;
}

int main() {
  std::cout << "Введите размер массива (m). ";
  int m;
  m = inputPositiveInt();

  float num = inputPositiveFloat();
  LinearFloatList *list = new LinearFloatList(num);
  LinearFloatList *next = list;
  

  for (int i = 1; i < m; i++) {
    while (true) {
      num = inputPositiveFloat();
      if (!list->hasItem(num))
        break;
      std::cout << "Это число уже есть в массиве" << std::endl;
    }
    next->addItem(num);
    next = next->nextItem();
  }
  list->print();

  return 0;
}
