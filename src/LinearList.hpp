#pragma once

#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>

class LinearFloatList {
private:
  LinearFloatList *next;

public:
  float value;
  LinearFloatList(float value) { this->value = value; }
  LinearFloatList() { this->value = std::nanf("EMPTYLIST"); }

  bool isEmpty() {
    return isnanf(value) && next == NULL;
  };

  /**
     Вставляет элемент после этого

     @returns вставленный элемент
   */
  LinearFloatList *addItem(float value) {
    if (isEmpty()) {
      this->value = value;
      return this;
    }
    LinearFloatList *newItem = new LinearFloatList(value);
    newItem->next = next;
    next = newItem;
    return next;
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

  /**
     Вывод списка в консоль
   */
  void print() {
    if (this->isEmpty()) {
      std::cout << "[]" << std::endl;
      return;
    }
    LinearFloatList *item = this;
    std::cout << "[";
    std::cout << item->value;
    while (item->hasNext()) {
      item = item->nextItem();
      std::cout << ", " << item->value;
    }
    std::cout << "]" << std::endl;
  }

  /**
     Удаление следующего элемента с указанием предыдущего
  */
  void removeNext() {
    if (this->hasNext()) {
      auto nextItem = this->next;
      this->next = this->next->next;
      delete nextItem;
    }
    
  }
};
