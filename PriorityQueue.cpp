#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() : head(nullptr) {}

PriorityQueue::PriorityQueue(const PriorityQueue& other) : head(nullptr) {
    Node* current = other.head;
    while (current) {
        add(current->value, current->priority);
        current = current->next;
    }
}

PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other) {
    if (this != &other) {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
        Node* current = other.head;
        while (current) {
            add(current->value, current->priority);
            current = current->next;
        }
    }
    return *this;
}

PriorityQueue::~PriorityQueue() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void PriorityQueue::add(int value, int priority) {
    Node* newNode = new Node(value, priority);
    if (!head || head->priority < priority) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

bool PriorityQueue::get(int& value, int& priority) {
    if (!head) return false;
    Node* temp = head;
    value = head->value;
    priority = head->priority;
    head = head->next;
    delete temp;
    return true;
}

int PriorityQueue::count(int priority) const {
    int count = 0;
    Node* current = head;
    while (current) {
        if (priority == 0 || current->priority == priority)
            count++;
        current = current->next;
    }
    return count;
}

bool PriorityQueue::peek(int& value, int& priority) const {
    if (!head) return false;
    value = head->value;
    priority = head->priority;
    return true;
}

int PriorityQueue::get(int priority, int*& buffer) {
    int count = this->count(priority);
    if (count == 0) return 0;

    buffer = new int[count];
    int index = 0;
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->priority == priority) {
            buffer[index++] = current->value;
            Node* temp = current;
            if (prev)
                prev->next = current->next;
            else
                head = current->next;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return count;
}

bool PriorityQueue::exist(int value, int priority) const {
    Node* current = head;
    while (current) {
        if (current->value == value && (priority == 0 || current->priority == priority))
            return true;
        current = current->next;
    }
    return false;
}

PriorityQueue PriorityQueue::operator+(const PriorityQueue& other) {
    PriorityQueue result(*this);
    Node* current = other.head;
    while (current) {
        result.add(current->value, current->priority);
        current = current->next;
    }
    return result;
}

PriorityQueue PriorityQueue::operator-(const PriorityQueue& other) {
    PriorityQueue result;
    Node* current = head;
    while (current) {
        if (!other.exist(current->value, current->priority)) {
            result.add(current->value, current->priority);
        }
        current = current->next;
    }
    return result;
}

PriorityQueue PriorityQueue::operator&(const PriorityQueue& other) {
    PriorityQueue result;
    Node* current = head;
    while (current) {
        if (other.exist(current->value, current->priority)) {
            result.add(current->value, current->priority);
        }
        current = current->next;
    }
    return result;
}

bool PriorityQueue::operator==(const PriorityQueue& other) const {
    Node* current = head;
    Node* otherCurrent = other.head;
    while (current && otherCurrent) {
        if (current->priority != otherCurrent->priority || current->value != otherCurrent->value)
            return false;
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    return current == nullptr && otherCurrent == nullptr;
}

// Остальные операторы сравнения (>, <, >=, <=) могут быть реализованы аналогично, ориентируясь на число и приоритет элементов.

std::ostream& operator<<(std::ostream& os, const PriorityQueue& queue) {
    PriorityQueue::Node* current = queue.head;
    while (current) {
        os << "(" << current->value << ", " << current->priority << ") ";
        current = current->next;
    }
    return os;
}