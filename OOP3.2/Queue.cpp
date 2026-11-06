
#include "Queue.h"
#include <sstream>
#include <cstdlib>

using namespace std;

// Повідомлення про помилку
void Queue::Error(const string& message)
{
    cout << "Помилка: " << message << endl;
    exit(1);
}

// Конструктор без параметрів
Queue::Queue()
    : Array()
{
}

// Конструктор копіювання
Queue::Queue(const Queue& other)
    : Array(other)
{
}

// Оператор присвоєння
Queue& Queue::operator=(const Queue& other)
{
    if (this != &other)
        Array::operator=(other);

    return *this;
}

// Деструктор
Queue::~Queue()
{
}

// Додавання елемента в кінець черги
void Queue::Enqueue(int value)
{
    Add(value);
}

// Видалення першого елемента черги
void Queue::Dequeue()
{
    if (IsEmpty())
        Error("Неможливо видалити елемент: черга порожня!");

    Remove(0);
}

// Отримання першого елемента
int Queue::Front() const
{
    if (IsEmpty())
        Error("Неможливо отримати елемент: черга порожня!");

    return GetAt(0);
}

// Введення черги
void Queue::Read(istream& in)
{
    int n;

    cout << "Кількість елементів черги: ";

    if (!(in >> n))
        Error("Некоректне введення кількості елементів!");

    if (n < 0)
        Error("Кількість елементів не може бути від'ємною!");

    Queue temp;

    for (int i = 0; i < n; i++)
    {
        int value;

        cout << "Елемент " << i + 1 << ": ";

        if (!(in >> value))
            Error("Некоректне значення елемента!");

        temp.Enqueue(value);
    }

    *this = temp;
}

// Виведення черги
void Queue::Display(ostream& out) const
{
    Array::Display(out);
}

// Перетворення черги до рядка
Queue::operator string() const
{
    return Array::operator string();
}

// Оператор виведення
ostream& operator<<(ostream& out, const Queue& obj)
{
    obj.Display(out);
    return out;
}

// Оператор введення
istream& operator>>(istream& in, Queue& obj)
{
    obj.Read(in);
    return in;
}

