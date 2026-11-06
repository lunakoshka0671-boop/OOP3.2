
#pragma once
#include "Array.h"
#include <iostream>
#include <string>
using namespace std;

class Queue : public Array
{
private:
    [[noreturn]] static void Error(const string& message);

public:
    // Конструктори та деструктор
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    ~Queue();

    // Основні операції черги
    void Enqueue(int value);
    void Dequeue();
    int Front() const;

    // Введення та виведення
    void Read(istream& in) override;
    void Display(ostream& out) const override;

    // Перетворення до рядка
    operator string() const override;

    // Перевантаження операторів
    friend ostream& operator<<(ostream& out, const Queue& obj);
    friend istream& operator>>(istream& in, Queue& obj);
};


