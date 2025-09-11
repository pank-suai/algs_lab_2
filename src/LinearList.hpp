#pragma once


#include <iostream>

class LinearFloatList {
public:
  struct Item {
    float value;
    Item *next = nullptr;
    Item(float val) {
	  value = val;
    }
  };

private:
  Item *begin = nullptr;

public:
  ~LinearFloatList() {
    Item *current = begin;
    while (current != nullptr) {
      Item *next = current->next;
      delete current;
      current = next;
    }
  }

  /**
   * Получение первого элемента
   */
  Item* getHead() const { return begin; }

  /**
   * Проверка, пуст ли список
   */
  bool isEmpty() const {
    return begin == nullptr;
  }

  /**
   * Вставляет элемент в начало списка
   */
  void pushBegin(float value) {
    Item* newNode = new Item(value);
    newNode->next = begin;
    begin = newNode;
  }

  /**
   * Вставляет элемент в конец списка
   */
  void pushEnd(float value) {
    Item* newNode = new Item(value);
    if (begin == nullptr) {
      begin = newNode;
      return;
    }
    Item* current = begin;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }

  /**
   * Имеется ли элемент с таким значением
   */
  bool hasItem(float value) const {
    Item* currentItem = begin;
    while (currentItem != nullptr) {
      if (currentItem->value == value) {
        return true;
      }
      currentItem = currentItem->next;
    }
    return false;
  }

  /**
   * @brief Удаление элемента по значению
   */
  void remove(float value) {
    if (begin == nullptr) return;

    if (begin->value == value) {
      Item* temp = begin;
      begin = begin->next;
      delete temp;
      return;
    }

    Item* currentItem = begin;
    while (currentItem->next != nullptr && currentItem->next->value != value) {
      currentItem = currentItem->next;
    }

    if (currentItem->next != nullptr) {
      Item* temp = currentItem->next;
      currentItem->next = currentItem->next->next;
      delete temp;
    }
  }

  /**
   * Вывод списка в консоль
   */
  void print() const {
    if (isEmpty()) {
      std::cout << "[]" << std::endl;
      return;
    }
    Item* current = begin;
    std::cout << "[";
    while (current != nullptr) {
      std::cout << current->value;
      if (current->next != nullptr) {
        std::cout << ", ";
      }
      current = current->next;
    }
    std::cout << "]" << std::endl;
  }
};
