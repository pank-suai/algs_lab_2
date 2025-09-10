#pragma once

#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>

class LinearFloatList {
public:
  struct Node {
    float value;
    Node *next;
    Node(float val) : value(val), next(nullptr) {}
  };

private:
  Node *head;

public:
  LinearFloatList() : head(nullptr) {}

  ~LinearFloatList() {
    Node *current = head;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }

  /**
   * @brief Получение головного элемента
   */
  Node* getHead() const { return head; }

  /**
   * @brief Проверка, пуст ли список
   */
  bool isEmpty() const {
    return head == nullptr;
  }

  /**
   * @brief Вставляет элемент в начало списка
   */
  void push_front(float value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  /**
   * @brief Вставляет элемент в конец списка
   */
  void push_back(float value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }

  /**
   * @brief Имеется ли элемент с таким значением
   */
  bool hasItem(float value) const {
    Node* current = head;
    while (current != nullptr) {
      if (current->value == value) {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  /**
   * @brief Удаление элемента по значению
   */
  void remove(float value) {
    if (head == nullptr) return;

    if (head->value == value) {
      Node* temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->value != value) {
      current = current->next;
    }

    if (current->next != nullptr) {
      Node* temp = current->next;
      current->next = current->next->next;
      delete temp;
    }
  }

  /**
   * @brief Вывод списка в консоль
   */
  void print() const {
    if (isEmpty()) {
      std::cout << "[]" << std::endl;
      return;
    }
    Node* current = head;
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
