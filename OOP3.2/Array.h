
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Array
{
private:
    int* data;
    int size;

    // Допоміжний метод для повідомлення про помилки
    [[noreturn]] static void Error(const string& message);

public:
    // Конструктори та деструктор
    Array();
    Array(int size);
    Array(const Array& other);
    Array& operator=(const Array& other);
    virtual ~Array();

    // Методи отримання значень
    int getSize() const;
    bool IsEmpty() const;
    int GetAt(int index) const;

    // Методи зміни масиву
    void SetAt(int index, int value);
    void Add(int value);
    void Remove(int index);
    void Resize(int newSize);
    void Clear();

    // Введення та виведення
    virtual void Read(istream& in);
    virtual void Display(ostream& out) const;

    // Перетворення до рядка
    virtual operator string() const;

    // Перевантаження операторів
    friend ostream& operator<<(ostream& out, const Array& obj);
    friend istream& operator>>(istream& in, Array& obj);
};


