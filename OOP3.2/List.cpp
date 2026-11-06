
#include "List.h"
#include <sstream>
#include <cstdlib>
#include <new>
#include <climits>

using namespace std;

// Повідомлення про помилку
void List::Error(const string& message)
{
    cout << "Помилка: " << message << endl;
    exit(1);
}

// Конструктор без параметрів
List::List()
    : head(nullptr), tail(nullptr), count(0)
{
}

// Конструктор копіювання
List::List(const List& other)
    : List()
{
    const Node* current = other.head;

    while (current != nullptr)
    {
        Add(current->data);
        current = current->next;
    }
}

// Оператор присвоєння
List& List::operator=(const List& other)
{
    if (this != &other)
    {
        List temp(other);

        Node* oldHead = head;

        head = temp.head;
        tail = temp.tail;
        count = temp.count;

        temp.head = oldHead;

        // Деструктор temp видалить старий список
    }

    return *this;
}

// Деструктор
List::~List()
{
    Clear();
}

// Отримання кількості елементів
int List::getCount() const
{
    return count;
}

// Перевірка, чи список порожній
bool List::IsEmpty() const
{
    return count == 0;
}

// Отримання вузла за індексом
List::Node* List::GetNode(int index)
{
    if (index < 0 || index >= count)
        Error("Індекс виходить за межі списку!");

    Node* current = head;

    for (int i = 0; i < index; i++)
        current = current->next;

    return current;
}

// Константний варіант отримання вузла
const List::Node* List::GetNode(int index) const
{
    if (index < 0 || index >= count)
        Error("Індекс виходить за межі списку!");

    const Node* current = head;

    for (int i = 0; i < index; i++)
        current = current->next;

    return current;
}

// Отримання значення елемента
int List::GetAt(int index) const
{
    return GetNode(index)->data;
}

// Додавання елемента в кінець
void List::Add(int value)
{
    if (count == INT_MAX)
        Error("Досягнуто максимальної кількості елементів!");

    Node* newNode = nullptr;

    try
    {
        newNode = new Node{ value, nullptr };
    }
    catch (const bad_alloc&)
    {
        Error("Не вдалося виділити пам'ять!");
    }

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    count++;
}

// Видалення елемента за індексом
void List::Remove(int index)
{
    if (index < 0 || index >= count)
        Error("Неправильний індекс для видалення!");

    Node* temp;

    if (index == 0)
    {
        temp = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;
    }
    else
    {
        Node* previous = GetNode(index - 1);

        temp = previous->next;
        previous->next = temp->next;

        if (temp == tail)
            tail = previous;
    }

    delete temp;
    count--;
}

// Зміна значення елемента
void List::SetAt(int index, int value)
{
    GetNode(index)->data = value;
}

// Очищення списку
void List::Clear()
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    count = 0;
}

// Введення списку
void List::Read(istream& in)
{
    int n;

    cout << "Кількість елементів: ";

    if (!(in >> n))
        Error("Некоректне введення кількості елементів!");

    if (n < 0)
        Error("Кількість елементів не може бути від'ємною!");

    List temp;

    for (int i = 0; i < n; i++)
    {
        int value;

        cout << "Елемент " << i + 1 << ": ";

        if (!(in >> value))
            Error("Некоректне значення елемента!");

        temp.Add(value);
    }

    *this = temp;
}

// Виведення списку
void List::Display(ostream& out) const
{
    const Node* current = head;

    out << "[ ";

    while (current != nullptr)
    {
        out << current->data << " ";
        current = current->next;
    }

    out << "]";
}

// Перетворення списку до рядка
List::operator string() const
{
    stringstream ss;
    const Node* current = head;

    ss << "[ ";

    while (current != nullptr)
    {
        ss << current->data << " ";
        current = current->next;
    }

    ss << "]";

    return ss.str();
}

// Оператор виведення
ostream& operator<<(ostream& out, const List& obj)
{
    obj.Display(out);
    return out;
}

// Оператор введення
istream& operator>>(istream& in, List& obj)
{
    obj.Read(in);
    return in;
}

