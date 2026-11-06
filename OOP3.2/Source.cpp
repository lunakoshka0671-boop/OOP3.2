
#include <iostream>
#include <string>

#include "List.h"
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include <Windows.h>

using namespace std;

// Функція приймає об'єкт базового класу Array
// змінює його та повертає об'єкт цього ж класу
Array ProcessArray(Array obj)
{
    if (!obj.IsEmpty())
    {
        obj.SetAt(0, obj.GetAt(0) + 1);
    }

    return obj;
}

// Функція приймає посилання на базовий клас Array
// Тому їй можна передати також об'єкт похідного класу Queue
void ShowArray(const Array& obj)
{
    obj.Display(cout);
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::setlocale(LC_ALL, "Ukrainian");
    // =========================================
    // 1. РОБОТА З КЛАСОМ LIST
    // =========================================

    cout << "========== LIST ==========" << endl;

    List list1;

    list1.Add(10);
    list1.Add(20);
    list1.Add(30);

    cout << "Початковий список: " << list1 << endl;

    cout << "Кiлькiсть елементiв: "
        << list1.getCount() << endl;

    cout << "Перший елемент: "
        << list1.GetAt(0) << endl;

    list1.SetAt(1, 25);

    cout << "Пiсля змiни другого елемента: "
        << list1 << endl;

    list1.Remove(0);

    cout << "Пiсля видалення першого елемента: "
        << list1 << endl;

    // Конструктор копіювання
    List list2(list1);

    cout << "Копiя списку: " << list2 << endl;

    // Оператор присвоєння
    List list3;
    list3 = list1;

    cout << "Присвоєний список: " << list3 << endl;

    // Перетворення об'єкта в string
    string listText = (string)list1;

    cout << "Список у виглядi рядка: "
        << listText << endl;

    // Масив об'єктів List
    List lists[2];

    lists[0].Add(1);
    lists[0].Add(2);

    lists[1].Add(3);
    lists[1].Add(4);

    cout << "Масив спискiв:" << endl;

    for (int i = 0; i < 2; i++)
    {
        cout << "lists[" << i << "] = "
            << lists[i] << endl;
    }

    list3.Clear();

    cout << "Пiсля очищення list3: "
        << list3 << endl;

    cout << "list3 порожнiй: "
        << (list3.IsEmpty() ? "так" : "нi") << endl;


    // =========================================
    // 2. РОБОТА З КЛАСОМ ARRAY
    // =========================================

    cout << "\n========== ARRAY ==========" << endl;

    // Конструктор із параметром
    Array array1(3);

    array1.SetAt(0, 10);
    array1.SetAt(1, 20);
    array1.SetAt(2, 30);

    cout << "Початковий масив: "
        << array1 << endl;

    cout << "Розмiр масиву: "
        << array1.getSize() << endl;

    cout << "Елемент з iндексом 1: "
        << array1.GetAt(1) << endl;

    array1.Add(40);

    cout << "Пiсля додавання: "
        << array1 << endl;

    array1.Remove(1);

    cout << "Пiсля видалення елемента: "
        << array1 << endl;

    array1.Resize(5);

    cout << "Пiсля збiльшення розмiру: "
        << array1 << endl;

    // Конструктор копіювання
    Array array2(array1);

    cout << "Копiя масиву: "
        << array2 << endl;

    // Оператор присвоєння
    Array array3;
    array3 = array1;

    cout << "Присвоєний масив: "
        << array3 << endl;

    // Функція, яка приймає та повертає Array
    Array array4 = ProcessArray(array1);

    cout << "Результат ProcessArray: "
        << array4 << endl;

    // Масив об'єктів Array
    Array arrays[2];

    arrays[0].Resize(3);
    arrays[0].SetAt(0, 1);
    arrays[0].SetAt(1, 2);
    arrays[0].SetAt(2, 3);

    arrays[1].Resize(2);
    arrays[1].SetAt(0, 4);
    arrays[1].SetAt(1, 5);

    cout << "Масив об'єктiв Array:" << endl;

    for (int i = 0; i < 2; i++)
    {
        cout << "arrays[" << i << "] = "
            << arrays[i] << endl;
    }

    array3.Clear();

    cout << "Пiсля очищення array3: "
        << array3 << endl;


    // =========================================
    // 3. РОБОТА З КЛАСОМ STACK
    // =========================================

    cout << "\n========== STACK ==========" << endl;

    Stack stack1;

    stack1.Push(10);
    stack1.Push(20);
    stack1.Push(30);

    cout << "Стек: " << stack1 << endl;

    cout << "Верхнiй елемент: "
        << stack1.Top() << endl;

    cout << "Кiлькiсть елементiв: "
        << stack1.getCount() << endl;

    stack1.Pop();

    cout << "Пiсля видалення верхнього елемента: "
        << stack1 << endl;

    // Конструктор копіювання
    Stack stack2(stack1);

    cout << "Копiя стека: "
        << stack2 << endl;

    // Оператор присвоєння
    Stack stack3;
    stack3 = stack1;

    cout << "Присвоєний стек: "
        << stack3 << endl;

    // Перетворення в string
    string stackText = (string)stack1;

    cout << "Стек у виглядi рядка: "
        << stackText << endl;

    // Масив об'єктів Stack
    Stack stacks[2];

    stacks[0].Push(1);
    stacks[0].Push(2);

    stacks[1].Push(3);
    stacks[1].Push(4);

    cout << "Масив стекiв:" << endl;

    for (int i = 0; i < 2; i++)
    {
        cout << "stacks[" << i << "] = "
            << stacks[i] << endl;
    }

    stack3.Clear();

    cout << "Пiсля очищення stack3: "
        << stack3 << endl;


    // =========================================
    // 4. РОБОТА З КЛАСОМ QUEUE
    // =========================================

    cout << "\n========== QUEUE ==========" << endl;

    Queue queue1;

    queue1.Enqueue(10);
    queue1.Enqueue(20);
    queue1.Enqueue(30);

    cout << "Черга: "
        << queue1 << endl;

    cout << "Перший елемент: "
        << queue1.Front() << endl;

    cout << "Розмiр черги: "
        << queue1.getSize() << endl;

    queue1.Dequeue();

    cout << "Пiсля видалення першого елемента: "
        << queue1 << endl;

    // Конструктор копіювання
    Queue queue2(queue1);

    cout << "Копiя черги: "
        << queue2 << endl;

    // Оператор присвоєння
    Queue queue3;
    queue3 = queue1;

    cout << "Присвоєна черга: "
        << queue3 << endl;

    // Перетворення в string
    string queueText = (string)queue1;

    cout << "Черга у виглядi рядка: "
        << queueText << endl;

    // Масив об'єктів Queue
    Queue queues[2];

    queues[0].Enqueue(5);
    queues[0].Enqueue(6);

    queues[1].Enqueue(7);
    queues[1].Enqueue(8);

    cout << "Масив черг:" << endl;

    for (int i = 0; i < 2; i++)
    {
        cout << "queues[" << i << "] = "
            << queues[i] << endl;
    }

    queue3.Clear();

    cout << "Пiсля очищення queue3: "
        << queue3 << endl;


    // =========================================
    // 5. ДЕМОНСТРАЦІЯ УСПАДКУВАННЯ
    // =========================================

    cout << "\n========== INHERITANCE ==========" << endl;

    // Queue є похідним класом від Array.
    // Тому об'єкт Queue можна передати туди,
    // де очікується об'єкт базового класу Array.

    Array& baseRef = queue1;

    cout << "Виведення Queue через посилання Array: ";
    baseRef.Display(cout);
    cout << endl;

    cout << "Виклик функцiї ShowArray для Queue: ";
    ShowArray(queue1);

    cout << "\nПрограма завершила роботу." << endl;

    return 0;
}
