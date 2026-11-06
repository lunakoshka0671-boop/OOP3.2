#include "pch.h"
#include "CppUnitTest.h"

#include "../OOP3.2/List.cpp"
#include "../OOP3.2/Array.cpp"
#include "../OOP3.2/Stack.cpp"
#include "../OOP3.2/Queue.cpp"

#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace OOP32Tests
{
    TEST_CLASS(ListTests)
    {
    public:

        TEST_METHOD(TestAddAndGet)
        {
            List list;

            list.Add(10);
            list.Add(20);
            list.Add(30);

            Assert::AreEqual(3, list.getCount());
            Assert::AreEqual(10, list.GetAt(0));
            Assert::AreEqual(20, list.GetAt(1));
            Assert::AreEqual(30, list.GetAt(2));
        }

        TEST_METHOD(TestSetAt)
        {
            List list;

            list.Add(10);
            list.Add(20);

            list.SetAt(1, 50);

            Assert::AreEqual(50, list.GetAt(1));
        }

        TEST_METHOD(TestRemove)
        {
            List list;

            list.Add(10);
            list.Add(20);
            list.Add(30);

            list.Remove(1);

            Assert::AreEqual(2, list.getCount());
            Assert::AreEqual(10, list.GetAt(0));
            Assert::AreEqual(30, list.GetAt(1));
        }

        TEST_METHOD(TestCopyConstructor)
        {
            List list1;

            list1.Add(5);
            list1.Add(10);

            List list2(list1);

            Assert::AreEqual(2, list2.getCount());
            Assert::AreEqual(5, list2.GetAt(0));
            Assert::AreEqual(10, list2.GetAt(1));
        }

        TEST_METHOD(TestAssignment)
        {
            List list1;
            list1.Add(10);
            list1.Add(20);

            List list2;
            list2 = list1;

            Assert::AreEqual(2, list2.getCount());
            Assert::AreEqual(10, list2.GetAt(0));
            Assert::AreEqual(20, list2.GetAt(1));
        }

        TEST_METHOD(TestClear)
        {
            List list;

            list.Add(1);
            list.Add(2);

            list.Clear();

            Assert::IsTrue(list.IsEmpty());
            Assert::AreEqual(0, list.getCount());
        }
    };


    TEST_CLASS(ArrayTests)
    {
    public:

        TEST_METHOD(TestConstructorAndGet)
        {
            Array arr(3);

            Assert::AreEqual(3, arr.getSize());
            Assert::AreEqual(0, arr.GetAt(0));
            Assert::AreEqual(0, arr.GetAt(1));
            Assert::AreEqual(0, arr.GetAt(2));
        }

        TEST_METHOD(TestSetAt)
        {
            Array arr(2);

            arr.SetAt(0, 15);
            arr.SetAt(1, 25);

            Assert::AreEqual(15, arr.GetAt(0));
            Assert::AreEqual(25, arr.GetAt(1));
        }

        TEST_METHOD(TestAdd)
        {
            Array arr(2);

            arr.SetAt(0, 10);
            arr.SetAt(1, 20);

            arr.Add(30);

            Assert::AreEqual(3, arr.getSize());
            Assert::AreEqual(30, arr.GetAt(2));
        }

        TEST_METHOD(TestRemove)
        {
            Array arr(3);

            arr.SetAt(0, 10);
            arr.SetAt(1, 20);
            arr.SetAt(2, 30);

            arr.Remove(1);

            Assert::AreEqual(2, arr.getSize());
            Assert::AreEqual(10, arr.GetAt(0));
            Assert::AreEqual(30, arr.GetAt(1));
        }

        TEST_METHOD(TestResize)
        {
            Array arr(2);

            arr.SetAt(0, 10);
            arr.SetAt(1, 20);

            arr.Resize(4);

            Assert::AreEqual(4, arr.getSize());
            Assert::AreEqual(10, arr.GetAt(0));
            Assert::AreEqual(20, arr.GetAt(1));
            Assert::AreEqual(0, arr.GetAt(2));
            Assert::AreEqual(0, arr.GetAt(3));
        }

        TEST_METHOD(TestCopyConstructor)
        {
            Array arr1(2);

            arr1.SetAt(0, 10);
            arr1.SetAt(1, 20);

            Array arr2(arr1);

            Assert::AreEqual(2, arr2.getSize());
            Assert::AreEqual(10, arr2.GetAt(0));
            Assert::AreEqual(20, arr2.GetAt(1));
        }

        TEST_METHOD(TestAssignment)
        {
            Array arr1(2);

            arr1.SetAt(0, 5);
            arr1.SetAt(1, 15);

            Array arr2;
            arr2 = arr1;

            Assert::AreEqual(2, arr2.getSize());
            Assert::AreEqual(5, arr2.GetAt(0));
            Assert::AreEqual(15, arr2.GetAt(1));
        }

        TEST_METHOD(TestClear)
        {
            Array arr(3);

            arr.Clear();

            Assert::IsTrue(arr.IsEmpty());
            Assert::AreEqual(0, arr.getSize());
        }
    };


    TEST_CLASS(StackTests)
    {
    public:

        TEST_METHOD(TestPushAndTop)
        {
            Stack stack;

            stack.Push(10);
            stack.Push(20);
            stack.Push(30);

            Assert::AreEqual(3, stack.getCount());
            Assert::AreEqual(30, stack.Top());
        }

        TEST_METHOD(TestPop)
        {
            Stack stack;

            stack.Push(10);
            stack.Push(20);
            stack.Push(30);

            stack.Pop();

            Assert::AreEqual(2, stack.getCount());
            Assert::AreEqual(20, stack.Top());
        }

        TEST_METHOD(TestCopyConstructor)
        {
            Stack stack1;

            stack1.Push(10);
            stack1.Push(20);

            Stack stack2(stack1);

            Assert::AreEqual(2, stack2.getCount());
            Assert::AreEqual(20, stack2.Top());
        }

        TEST_METHOD(TestAssignment)
        {
            Stack stack1;

            stack1.Push(5);
            stack1.Push(10);

            Stack stack2;
            stack2 = stack1;

            Assert::AreEqual(2, stack2.getCount());
            Assert::AreEqual(10, stack2.Top());
        }

        TEST_METHOD(TestClear)
        {
            Stack stack;

            stack.Push(10);
            stack.Push(20);

            stack.Clear();

            Assert::IsTrue(stack.IsEmpty());
            Assert::AreEqual(0, stack.getCount());
        }
    };


    TEST_CLASS(QueueTests)
    {
    public:

        TEST_METHOD(TestEnqueueAndFront)
        {
            Queue queue;

            queue.Enqueue(10);
            queue.Enqueue(20);
            queue.Enqueue(30);

            Assert::AreEqual(3, queue.getSize());
            Assert::AreEqual(10, queue.Front());
        }

        TEST_METHOD(TestDequeue)
        {
            Queue queue;

            queue.Enqueue(10);
            queue.Enqueue(20);
            queue.Enqueue(30);

            queue.Dequeue();

            Assert::AreEqual(2, queue.getSize());
            Assert::AreEqual(20, queue.Front());
        }

        TEST_METHOD(TestCopyConstructor)
        {
            Queue queue1;

            queue1.Enqueue(5);
            queue1.Enqueue(10);

            Queue queue2(queue1);

            Assert::AreEqual(2, queue2.getSize());
            Assert::AreEqual(5, queue2.Front());
        }

        TEST_METHOD(TestAssignment)
        {
            Queue queue1;

            queue1.Enqueue(15);
            queue1.Enqueue(25);

            Queue queue2;
            queue2 = queue1;

            Assert::AreEqual(2, queue2.getSize());
            Assert::AreEqual(15, queue2.Front());
        }

        TEST_METHOD(TestInheritance)
        {
            Queue queue;

            queue.Enqueue(10);
            queue.Enqueue(20);

            // Використання Queue через базовий клас Array
            Array& baseRef = queue;

            Assert::AreEqual(2, baseRef.getSize());
            Assert::AreEqual(10, baseRef.GetAt(0));

            // Перевірка роботи успадкованого методу
            baseRef.Add(30);

            Assert::AreEqual(3, queue.getSize());
            Assert::AreEqual(30, queue.GetAt(2));
        }

        TEST_METHOD(TestVirtualRead)
        {
            Queue queue;

            Array& baseRef = queue;

            istringstream input("2 40 50");

            input >> baseRef;

            Assert::AreEqual(2, queue.getSize());
            Assert::AreEqual(40, queue.GetAt(0));
            Assert::AreEqual(50, queue.GetAt(1));
        }
    };
}
