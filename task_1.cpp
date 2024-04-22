#include <iostream>
using namespace std;

class Queue
{
    int* _wait;
    int _maxQueueLen;
    int _queueLen;

public:
    Queue(int len);
    ~Queue();

    bool isEmpty() const;
    bool isFull() const;

    void enqueue(int);
    int dequeue();

    void show() const;
};

Queue::Queue(int len)
{
    _maxQueueLen = len;
    _wait = new int[len];
    _queueLen = 0;
}

Queue::~Queue()
{
    delete[] _wait;
};

bool Queue::isEmpty() const
{
    return _queueLen == 0;
}

bool Queue::isFull() const
{
    return _queueLen == _maxQueueLen;
}

void Queue::enqueue(int el)
{
    if (!isFull())
        _wait[_queueLen++] = el;
}

int Queue::dequeue()
{
    if (!isEmpty())
    {
        int next = _wait[0];

        for (int i = 1; i < _queueLen; ++i)
        {
            _wait[i - 1] = _wait[i];
        }
        _queueLen--;

        return next;
    }
}

void Queue::show() const
{
    for (int i = 0; i < _queueLen; ++i) {
        cout << _wait[i] << " ";
    }
    cout << endl;
}


int main()
{
    Queue queue(7);
    for (int i = 0; i < 5; ++i) {
        queue.enqueue(rand() % 10);
    }
    queue.show();
    cout << endl;
    cout << queue.dequeue() << endl;
    queue.show();



    return 0;
}



