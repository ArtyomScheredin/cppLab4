#include "PriorityQueue.h"
#include <iostream>

void displayMenu() {
    std::cout << "1. Добавить элемент\n"
              << "2. Извлечь элемент\n"
              << "3. Просмотреть элемент\n"
              << "4. Посчитать элементы\n"
              << "5. Проверить существование элемента\n"
              << "6. Напечатать очередь\n"
              << "0. Выйти\n";
}

int main() {
    PriorityQueue queue;
    int choice, value, priority;

    do {
        displayMenu();
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Введите значение и приоритет: ";
                std::cin >> value >> priority;
                queue.add(value, priority);
                break;
            case 2:
                if (queue.get(value, priority))
                    std::cout << "Извлечено: (" << value << ", " << priority << ")\n";
                else
                    std::cout << "Очередь пуста.\n";
                break;
            case 3:
                if (queue.peek(value, priority))
                    std::cout << "Просмотрено: (" << value << ", " << priority << ")\n";
                else
                    std::cout << "Очередь пуста.\n";
                break;
            case 4:
                std::cout << "Введите приоритет (0 для всех): ";
                std::cin >> priority;
                std::cout << "Количество: " << queue.count(priority) << "\n";
                break;
            case 5:
                std::cout << "Введите значение и приоритет: ";
                std::cin >> value >> priority;
                std::cout << (queue.exist(value, priority) ? "Существует\n" : "Не существует\n");
                break;
            case 6:
                std::cout << "Очередь: " << queue << "\n";
                break;
            case 0:
                std::cout << "Выход...\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте еще раз.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
