#pragma once

#include <cstddef>
#include <iomanip>
#include <iostream>

class LinearFloatList {
private:
  LinearFloatList *next;

public:
  float value;
  LinearFloatList(float value) { this->value = value; }

  /**
     Вставляет элемент после этого
   */
  void addItem(float value) {
    LinearFloatList *newItem = new LinearFloatList(value);
    newItem->next = next;
    next = newItem;
  }

  /**
     Имеется ли элемент с таким значением
   */
  bool hasItem(float value) {
    LinearFloatList *item = this;
    while (item->hasNext()) {
      if (item->value == value) {
        return true;
      }
      item = item->nextItem();
    }
    return item->value == value;
  }

  bool hasNext() { return next != NULL; }
  LinearFloatList *nextItem() { return next; }

  void print() {
    LinearFloatList *item = this;
    std::cout << "[ ";
    std::cout << std::setw(5) << item->value;
    while (item->hasNext()) {
      item = item->nextItem();
      std::cout << std::setw(5) << item->value;
    }
    std::cout << "]" << std::endl;
  }
};
