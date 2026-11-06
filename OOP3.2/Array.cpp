
#include "Array.h"
#include <sstream>
#include <cstdlib>
#include <new>
#include <climits>

using namespace std;

// Повідомлення про помилку
void Array::Error(const string& message)
{
    cout << "Помилка: " << message << endl;
    exit(1);
}

// Конструктор без параметрів
Array::Array()
    : data(nullptr), size(0)
{
}

// Конструктор із параметром
Array::Array(int size)
    : data(nullptr), size(0)
{
    if (size < 0)
        Error("Розмір масиву не може бути від'ємним!");

    if (size > 0)
    {
        data = new (nothrow) int[size];

        if (data == nullptr)
            Error("Не вдалося виділити пам'ять!");

        this->size = size;

        for (int i = 0; i < this->size; i++)
            data[i] = 0;
    }
}

// Конструктор копіювання
Array::Array(const Array& other)
    : data(nullptr), size(0)
{
    if (other.size > 0)
    {
        data = new (nothrow) int[other.size];

        if (data == nullptr)
            Error("Не вдалося виділити пам'ять!");

        size = other.size;

        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
}

// Оператор присвоєння
Array& Array::operator=(const Array& other)
{
    if (this != &other)
    {
        Array temp(other);

        int* oldData = data;

        data = temp.data;
        size = temp.size;

        temp.data = oldData;
    }

    return *this;
}

// Деструктор
Array::~Array()
{
    Clear();
}

// Отримання розміру масиву
int Array::getSize() const
{
    return size;
}

// Перевірка на порожній масив
bool Array::IsEmpty() const
{
    return size == 0;
}

// Отримання елемента за індексом
int Array::GetAt(int index) const
{
    if (index < 0 || index >= size)
        Error("Індекс виходить за межі масиву!");

    return data[index];
}

// Зміна елемента за індексом
void Array::SetAt(int index, int value)
{
    if (index < 0 || index >= size)
        Error("Індекс виходить за межі масиву!");

    data[index] = value;
}

// Додавання елемента в кінець
void Array::Add(int value)
{
    if (size == INT_MAX)
        Error("Досягнуто максимальної кількості елементів!");

    int* newData = new (nothrow) int[size + 1];

    if (newData == nullptr)
        Error("Не вдалося виділити пам'ять!");

    for (int i = 0; i < size; i++)
        newData[i] = data[i];

    newData[size] = value;

    delete[] data;
    data = newData;
    size++;
}

// Видалення елемента за індексом
void Array::Remove(int index)
{
    if (index < 0 || index >= size)
        Error("Неправильний індекс для видалення!");

    int newSize = size - 1;
    int* newData = nullptr;

    if (newSize > 0)
    {
        newData = new (nothrow) int[newSize];

        if (newData == nullptr)
            Error("Не вдалося виділити пам'ять!");

        for (int i = 0; i < index; i++)
            newData[i] = data[i];

        for (int i = index; i < newSize; i++)
            newData[i] = data[i + 1];
    }

    delete[] data;
    data = newData;
    size = newSize;
}

// Зміна розміру масиву
void Array::Resize(int newSize)
{
    if (newSize < 0)
        Error("Розмір масиву не може бути від'ємним!");

    if (newSize == size)
        return;

    int* newData = nullptr;

    if (newSize > 0)
    {
        newData = new (nothrow) int[newSize];

        if (newData == nullptr)
            Error("Не вдалося виділити пам'ять!");

        int copySize = (size < newSize) ? size : newSize;

        for (int i = 0; i < copySize; i++)
            newData[i] = data[i];

        // Нові елементи заповнюються нулями
        for (int i = copySize; i < newSize; i++)
            newData[i] = 0;
    }

    delete[] data;
    data = newData;
    size = newSize;
}

// Очищення масиву
void Array::Clear()
{
    delete[] data;
    data = nullptr;
    size = 0;
}

// Введення масиву
void Array::Read(istream& in)
{
    int n;

    cout << "Кількість елементів: ";

    if (!(in >> n))
        Error("Некоректне введення кількості елементів!");

    if (n < 0)
        Error("Кількість елементів не може бути від'ємною!");

    Array temp(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Елемент " << i + 1 << ": ";

        if (!(in >> temp.data[i]))
            Error("Некоректне значення елемента!");
    }

    *this = temp;
}

// Виведення масиву
void Array::Display(ostream& out) const
{
    out << "[ ";

    for (int i = 0; i < size; i++)
        out << data[i] << " ";

    out << "]";
}

// Перетворення масиву до рядка
Array::operator string() const
{
    stringstream ss;

    ss << "[ ";

    for (int i = 0; i < size; i++)
        ss << data[i] << " ";

    ss << "]";

    return ss.str();
}

// Оператор виведення
ostream& operator<<(ostream& out, const Array& obj)
{
    obj.Display(out);
    return out;
}

// Оператор введення
istream& operator>>(istream& in, Array& obj)
{
    obj.Read(in);
    return in;
}

