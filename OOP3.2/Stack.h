
#pragma once
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    List list;

    [[noreturn]] static void Error(const string& message);

public:
    // Конструктори та деструктор
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    // Методи отримання значень
    int getCount() const;
    bool IsEmpty() const;
    int Top() const;

    // Основні операції стека
    void Push(int value);
    void Pop();
    void Clear();

    // Введення та виведення
    void Read(istream& in);
    void Display(ostream& out) const;

    // Перетворення до рядка
    operator string() const;

    // Перевантаження операторів
    friend ostream& operator<<(ostream& out, const Stack& obj);
    friend istream& operator>>(istream& in, Stack& obj);
};


