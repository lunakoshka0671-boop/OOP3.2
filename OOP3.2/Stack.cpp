
#include "Stack.h"
#include <sstream>
#include <cstdlib>

using namespace std;

// Повідомлення про помилку
void Stack::Error(const string& message)
{
    cout << "Помилка: " << message << endl;
    exit(1);
}

// Конструктор без параметрів
Stack::Stack()
{
}

// Конструктор копіювання
Stack::Stack(const Stack& other)
{
    list = other.list;
}

// Оператор присвоєння
Stack& Stack::operator=(const Stack& other)
{
    if (this != &other)
        list = other.list;

    return *this;
}

// Деструктор
Stack::~Stack()
{
}

// Отримання кількості елементів
int Stack::getCount() const
{
    return list.getCount();
}

// Перевірка на порожній стек
bool Stack::IsEmpty() const
{
    return list.IsEmpty();
}

// Додавання елемента на вершину стека
void Stack::Push(int value)
{
    list.Add(value);
}

// Видалення верхнього елемента
void Stack::Pop()
{
    if (IsEmpty())
        Error("Неможливо видалити елемент: стек порожній!");

    list.Remove(list.getCount() - 1);
}

// Отримання верхнього елемента
int Stack::Top() const
{
    if (IsEmpty())
        Error("Неможливо отримати елемент: стек порожній!");

    return list.GetAt(list.getCount() - 1);
}

// Очищення стека
void Stack::Clear()
{
    list.Clear();
}

// Введення стека
void Stack::Read(istream& in)
{
    int n;

    cout << "Кількість елементів стека: ";

    if (!(in >> n))
        Error("Некоректне введення кількості елементів!");

    if (n < 0)
        Error("Кількість елементів не може бути від'ємною!");

    Stack temp;

    for (int i = 0; i < n; i++)
    {
        int value;

        cout << "Елемент " << i + 1 << ": ";

        if (!(in >> value))
            Error("Некоректне значення елемента!");

        temp.Push(value);
    }

    *this = temp;
}

// Виведення стека
void Stack::Display(ostream& out) const
{
    out << list;
}

// Перетворення до рядка
Stack::operator string() const
{
    stringstream ss;
    ss << list;
    return ss.str();
}

// Оператор виведення
ostream& operator<<(ostream& out, const Stack& obj)
{
    obj.Display(out);
    return out;
}

// Оператор введення
istream& operator>>(istream& in, Stack& obj)
{
    obj.Read(in);
    return in;
}

