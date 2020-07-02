#include "deque.h"
#include "test_runner.h"

void TestDeque()
{
    {
        Deque<int> deque;
        ASSERT_EQUAL(deque.Empty(), true);
        deque.PushBack(5);
        ASSERT_EQUAL(deque.Empty(), false);
        deque.PushFront(5);
        ASSERT_EQUAL(deque.Empty(), false);
    }

    {
        Deque<int> deque;
        deque.PushBack(5);
        ASSERT_EQUAL(deque.Back(), 5);
        deque.PushBack(7);
        ASSERT_EQUAL(deque.Back(), 7);

        ASSERT_EQUAL(deque.Front(), 5);
    }
    {
        Deque<int> deque;
        deque.PushFront(5);
        deque.PushFront(6);
        ASSERT_EQUAL(deque.Back(),5);
    }
    {
        Deque<int> deque;
        deque.PushFront(5);
        deque.PushFront(7);
        ASSERT_EQUAL(deque[0], 7);
        deque.PushBack(3);
        deque.PushBack(9);
        ASSERT_EQUAL(deque[3], 9);
        ASSERT_EQUAL(deque.Size(), 4);
    }
    {
        Deque<int> deque;
        //ASSERT_EQUAL(deque.At(2), 4);
        deque.PushFront(4);
        ASSERT_EQUAL(deque.At(0),4);
    }
    {
        Deque<int> deque;
        deque.PushBack(4);
        ASSERT_EQUAL(deque.At(0),4);
    }
    {
        Deque<int> deque;
        deque.PushBack(4);
        deque.PushFront(5);
        ASSERT_EQUAL(deque.At(1), 4);
    }
    {
        Deque<int> deque;
        deque.PushFront(5);
        deque.PushFront(16);
        deque.PushFront(32);
        deque.PushBack(-5);
        deque.PushBack(-16);
        deque.PushBack(-32);
        ASSERT_EQUAL(deque.At(5), -32);
        ASSERT_EQUAL(deque.At(0), 32);
        ASSERT_EQUAL(deque.At(5), deque[5]);
        ASSERT_EQUAL(deque.At(0), deque[0]);

        try{
            deque.At(10);
        }catch(const out_of_range& ex)
        {
            ASSERT(ex.what());
        }

        try{
            deque[6];
        }catch(const out_of_range& ex)
        {
            ASSERT(ex.what());
        }
        


    }
}
int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestDeque);
    return 0;
}