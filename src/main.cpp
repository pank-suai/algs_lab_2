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
    next = next->addItem(num);
  }

  list->print();

  LinearFloatList *wholeList = new LinearFloatList();
  LinearFloatList *fractList = new LinearFloatList();
  auto wholeItem = wholeList;
  auto fractItem = fractList;

  LinearFloatList *item = list;
  LinearFloatList *prev = NULL;
  while(true) {
    int whole = std::trunc(item->value);
    if (whole == item->value) {
      goto cont;
    }
    wholeItem = wholeItem->addItem(whole);
    fractItem = fractItem->addItem(item->value - whole);

  cont:
    // prev = item;
    if (item->hasNext())
      item = item->nextItem();
    else break;
  }
  std::cout << "Целые части: ";
  wholeList->print();
  std::cout << "Дробные части: ";

  fractList->print();
  return 0;
}
