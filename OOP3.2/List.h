
#pragma once
#include <iostream>
#include <string>
using namespace std;

class List
{
private:
    // Структура одного елемента списку
    struct Node
    {
        int data;
        Node* next;
    };

    Node* head;
    Node* tail;
    int count;

    // Допоміжні методи
    [[noreturn]] static void Error(const string& message);
    Node* GetNode(int index);
    const Node* GetNode(int index) const;

public:
    // Конструктори та деструктор
    List();
    List(const List& other);
    List& operator=(const List& other);
    ~List();

    // Методи отримання значень
    int getCount() const;
    bool IsEmpty() const;
    int GetAt(int index) const;

    // Методи зміни списку
    void Add(int value);
    void Remove(int index);
    void SetAt(int index, int value);
    void Clear();

    // Введення та виведення
    void Read(istream& in);
    void Display(ostream& out) const;

    // Перетворення до рядка
    operator string() const;

    // Перевантаження операторів
    friend ostream& operator<<(ostream& out, const List& obj);
    friend istream& operator>>(istream& in, List& obj);
};


