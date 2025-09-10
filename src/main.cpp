#include "LinearList.hpp"
#include <cmath>
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
}

int main() {
  std::cout << "Введите размер массива (m). ";
  int m;
  m = inputPositiveInt();

  LinearFloatList list;

  for (int i = 0; i < m; i++) {
    float num;
    while (true) {
      num = inputPositiveFloat();
      if (!list.hasItem(num))
        break;
      std::cout << "Это число уже есть в массиве" << std::endl;
    }
    list.push_back(num);
  }

  list.print();

  LinearFloatList wholeList;
  LinearFloatList fractList;

  for (auto* item = list.getHead(); item != nullptr; item = item->next) {
    float whole = std::trunc(item->value);
    if (whole != item->value) {
      wholeList.push_back(whole);
      fractList.push_back(item->value - whole);
    }
  }

  std::cout << "Целые части: ";
  wholeList.print();
  std::cout << "Дробные части: ";
  fractList.print();

  return 0;
}
