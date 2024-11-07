#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

class PriorityQueue {
private:
    struct Node {
        int value;
        int priority;
        Node* next;
        Node(int val, int pri) : value(val), priority(pri), next(nullptr) {}
    };

    Node* head;

public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& other);               // Конструктор копирования
    PriorityQueue& operator=(const PriorityQueue& other);    // Оператор присваивания
    ~PriorityQueue();                                        // Деструктор

    void add(int value, int priority);                       // Добавление элемента
    bool get(int& value, int& priority);                     // Извлечение элемента с удалением
    int count(int priority = 0) const;                       // Подсчет элементов
    bool peek(int& value, int& priority) const;              // Чтение элемента без удаления
    int get(int priority, int*& buffer);                     // Извлечение всех элементов с определенным приоритетом
    bool exist(int value, int priority = 0) const;           // Проверка наличия элемента

    PriorityQueue operator+(const PriorityQueue& other);     // Объединение двух очередей
    PriorityQueue operator-(const PriorityQueue& other);     // Разность двух очередей
    PriorityQueue operator&(const PriorityQueue& other);     // Пересечение двух очередей

    bool operator==(const PriorityQueue& other) const;
    bool operator!=(const PriorityQueue& other) const;
    bool operator>(const PriorityQueue& other) const;
    bool operator<(const PriorityQueue& other) const;
    bool operator>=(const PriorityQueue& other) const;
    bool operator<=(const PriorityQueue& other) const;

    friend std::ostream& operator<<(std::ostream& os, const PriorityQueue& queue);
};

#endif // PRIORITYQUEUE_H
