//*****************************************************************************************************

#include <iostream>
#include <string>
#include "Stock.h"
using namespace std;

//*****************************************************************************************************

template<typename T>
struct Node 
{
    T data;
    Node* next;
};

//*****************************************************************************************************

template <typename T>
class LinkedList
{
private:
    Node<T>* front;

public:
    LinkedList();
    void display() const;
    void insertOrder(const T& item);
    void insertOrder(Node<T>* &listPtr, const T& item);
    void deleteNode(const T& item);
    void deleteNode(Node<T>*& listPtr, const T& item);
};

//*****************************************************************************************************

template <typename T>
LinkedList<T>::LinkedList() 
{
    front = nullptr;
}

//*****************************************************************************************************

template <typename T>
void LinkedList<T>::display() const
{
    Node<T>* current = front;
    while(current != nullptr)
    {
        current->data.display();
        current = current->next;
    }

}

//*****************************************************************************************************

template <typename T>
void LinkedList<T>::insertOrder(Node<T>*& listPtr, const T& item)
{
    if ((listPtr == nullptr) || (item > listPtr->data))
    {
        Node<T>* tempPtr = listPtr;
        listPtr = new Node<T>;
        listPtr->data = item;
        listPtr->next = tempPtr;
    }

    else
    {
        insertOrder(listPtr->next, item);
    }
}

//*****************************************************************************************************

template <typename T>
void LinkedList<T>::insertOrder(const T& item)
{
    insertOrder(front, item);
}

//*****************************************************************************************************

template <typename T>
void LinkedList<T>::deleteNode(Node<T>* &listPtr, const T& item)
{
    if (listPtr != nullptr)
    {
        if (listPtr->data == item)
        {
            Node<T>* tempPtr = listPtr;
            listPtr = listPtr->next;
            delete tempPtr;
        }
        else
        {
            deleteNode(listPtr->next, item);
        }
    }

}

//*****************************************************************************************************

template <typename T>
void LinkedList<T>::deleteNode(const T& item)
{
    deleteNode(front, item);
}

//*****************************************************************************************************

int main()
{
    LinkedList<Stock> stockList;

    stockList.insertOrder(Stock("Apple Inc.", "APPL", 239.69));
    stockList.insertOrder(Stock("Microsoft Inc.", "MSFT", 495.00));
    stockList.insertOrder(Stock("Tesla Inc.", "TESL", 350.84));
    stockList.insertOrder(Stock("Amazon.com Inc.", "AMZN", 232.33));
    stockList.insertOrder(Stock("Nvidia Corp.", "NVDA", 167.02));

    cout << "Stocks in decending order: " << endl;
    stockList.display();
    cout << endl;

    stockList.deleteNode(Stock("Amazon.com Inc.", "AMZN", 232.33));

    cout << "List with Amazon Removed: " << endl;
    stockList.display();
    cout << endl;

    return 0;
}

/*
Stocks in decending order:
Amazon.com Inc. (AMZN) - $232.33
Apple Inc. (APPL) - $239.69
Microsoft Inc. (MSFT) - $495
Nvidia Corp. (NVDA) - $167.02
Tesla Apple Inc. (TESL) - $350.84

List with Amazon Removed:
Apple Inc. (APPL) - $239.69
Microsoft Inc. (MSFT) - $495
Nvidia Corp. (NVDA) - $167.02
Tesla Apple Inc. (TESL) - $350.84
*/