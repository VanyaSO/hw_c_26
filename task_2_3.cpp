#include <iostream>
using namespace std;

template<class T>
class Queue
{
    T* _wait;
    int* _priorityWait;
    int _maxQueueLen;
    int _queueLen;

public:
    Queue(int);
    ~Queue();

    bool isEmpty() const;
    bool isFull() const;

    void insertWithPriority(T, int);
    T pullHighestPriorityElement();
    int getMaxIndexPri() const;
    T peek() const;
    void show() const;
};

template<class T>
Queue<T>::Queue(int len)
{
    _maxQueueLen = len;
    _wait = new T[len];
    _priorityWait = new int[len];
    _queueLen = 0;
}

template<class T>
Queue<T>::~Queue()
{
    delete[] _wait;
    delete[] _priorityWait;
};

template<class T>
bool Queue<T>::isEmpty() const
{
    return _queueLen == 0;
}

template<class T>
bool Queue<T>::isFull() const
{
    return _queueLen == _maxQueueLen;
}

template<class T>
void Queue<T>::insertWithPriority(T el, int pri)
{
    if (!isFull())
        _wait[_queueLen] = el;
        _priorityWait[_queueLen] = pri;
        _queueLen++;
}

template<class T>
T Queue<T>::pullHighestPriorityElement()
{
    if (!isEmpty())
    {
        int index = getMaxIndexPri();
        T deleteEl = _wait[index];
        for (int i = index; i < _queueLen; ++i) {
            _wait[i] = _wait[i+1];
            _priorityWait[i] = _priorityWait[i+1];
        }
        _queueLen--;
        return deleteEl;
    }
}

template<class T>
T Queue<T>::peek() const
{
    if (!isEmpty())
    {
        int index = getMaxIndexPri();
        return _wait[index];
    }
}

template<class T>
int Queue<T>::getMaxIndexPri() const
{
    int max = _priorityWait[0];
    int index = 0;
    for (int i = 0; i < _queueLen; ++i) {
        if (_priorityWait[i] > max)
        {
            max = _priorityWait[i];
            index = i;
        }
    }
    return index;
}

template<class T>
void Queue<T>::show() const
{
    for (int i = 0; i < _queueLen; ++i) {
        cout << _wait[i] << " " << _priorityWait[i] << endl;
    }
    cout << endl;
}


int main()
{
    Queue<double> queue(7);

    queue.insertWithPriority(10.2/3, 77);
    for (int i = 0; i < 5; ++i) {
        queue.insertWithPriority(11.2+i/3.3, i+2);
    }
    queue.insertWithPriority(4.13/3.5, 76);

    queue.show();

    cout << "Удалили елемент по приоритету в очереди:  " << queue.pullHighestPriorityElement() << endl;
    cout << "Получили елемент по приоритету в очереди:  " << queue.peek() << endl;
    queue.show();

    cout << "-----------------------------------------------------------------" << endl;
    Queue<int> queueInt(7);

    queueInt.insertWithPriority(10, 73);
    for (double i = 0; i < 5; ++i) {
        queueInt.insertWithPriority(1+i, i+2);
    }
    queueInt.insertWithPriority(4, 1);

    queueInt.show();

    cout << "Удалили елемент по приоритету в очереди:  " << queueInt.pullHighestPriorityElement() << endl;
    cout << "Получили елемент по приоритету в очереди:  " << queueInt.peek() << endl;
    queueInt.show();



    return 0;
}



