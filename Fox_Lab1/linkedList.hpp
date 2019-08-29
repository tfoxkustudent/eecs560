#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;


template <typename T>
class Node
{
  public:
    Node()
    {
      ptrNext = NULL;
      ptrPrev = NULL;
    }

    T data;
    Node* ptrNext;
    Node* ptrPrev;
};

template <typename T>
class LinkedList
{
  private:
    Node<T>* ptrFront;
    Node<T>* ptrEnd;
    int m_size;

  public:
    LinkedList()
    {
      ptrFront = NULL;
      ptrEnd = NULL;
      m_size = 0;
    }
    ~LinkedList()
    {
        while ( ptrFront != NULL)
        {
            if (m_size == 0 )
            {
                return;
            }
            else if (ptrFront == ptrEnd)
            {
                delete ptrFront;
                ptrFront = NULL;
                ptrEnd = NULL;
                m_size = 0;
            }
            else
            {
                Node<T>* second2last = ptrEnd->ptrPrev;
                delete ptrEnd;
                ptrEnd = second2last;
                ptrEnd->ptrNext = NULL;
                m_size--;
            }
        }

    };

    void Delete (int value2delete)
    {
        if (m_size == 0)
        {
            return;
        }
        if(ptrFront->data == value2delete)
        {
            if ( m_size == 0)
            {
               return;
            }
            else if (ptrFront == ptrEnd)
            {
                delete ptrFront;
                ptrFront = NULL;
                ptrEnd = NULL;
                m_size = 0;
                return;
            }
            else
            {
                Node<T>* next = ptrFront->ptrNext;
                delete ptrFront;
                ptrFront = next;
                ptrFront->ptrPrev = NULL;
                m_size--;
                return;
            }
        }
        Node<T>* ptrCurrent = ptrFront;
        while (ptrCurrent != NULL)
        {
          Node<T>* next = ptrCurrent->ptrNext;
          Node<T>* prev = ptrCurrent->ptrPrev;
          Node<T>* temp = ptrCurrent;

          if (ptrCurrent->data == value2delete && ptrCurrent->ptrNext != NULL)
          {
            prev->ptrNext= next;
            next->ptrPrev= prev;
            delete temp;
            m_size --;
            return;
          }
          else if (ptrCurrent->data == value2delete && ptrCurrent->ptrNext == NULL)
          {
            if (m_size == 0 )
            {
                return;
            }
            else if (ptrFront == ptrEnd)
            {
                delete ptrFront;
                ptrFront = NULL;
                ptrEnd = NULL;
                m_size = 0;
                return;
            }
            else
            {
                Node<T>* second2last = ptrEnd->ptrPrev;
                delete ptrEnd;
                ptrEnd = second2last;
                ptrEnd->ptrNext = NULL;
                m_size--;
                return;
             }
          }
          ptrCurrent = ptrCurrent->ptrNext;
        }
        cout << "Delete Failed.  Number was not found in the list" << endl;
        return;
    }

    void Insert( T data )
    {
      Node<T>* newNode = new Node<T>;
      newNode->data = data;

      if ( ptrFront == NULL && ptrEnd == NULL )
      {
        ptrFront = newNode;
        ptrEnd = newNode;
      }
      else
      {
          newNode->ptrPrev = ptrEnd;
          ptrEnd->ptrNext = newNode;
          ptrEnd = newNode;
      }
      m_size++;
    }

    int Smallest()
    {
      if (m_size == 0)
      {
        cout << " List is empty" << endl;

      }
      int smallest;
      Node<T>* ptrCurrent = ptrFront;
      smallest = ptrCurrent->data;
      while (ptrCurrent != NULL)
      {

        if (ptrCurrent->data < smallest)
        {
          smallest = ptrCurrent->data;
        }
        else
        {
          smallest = smallest;
        }
        ptrCurrent = ptrCurrent->ptrNext;
      }
      return smallest;
    }
    int Largest()
    {
      if (m_size == 0)
      {
        cout << " List is empty" << endl;

      }
      int largest;
      Node<T>* ptrCurrent = ptrFront;
      largest = ptrCurrent->data;
      while (ptrCurrent != NULL)
      {


          if (ptrCurrent->data > largest)
          {
            largest = ptrCurrent->data;
          }
          else
          {
            largest = largest;
          }
          ptrCurrent = ptrCurrent->ptrNext;
      }
      return largest;
    }

    double Average()
    {
      if (m_size == 0)
      {
        cout << "List is empty" << endl;

      }
      double sum = 0;
      Node<T>* ptrCurrent = ptrFront;
      while (ptrCurrent != NULL)
      {
        sum += ptrCurrent->data;
        ptrCurrent = ptrCurrent->ptrNext;
      }
      return sum/m_size;
    }

    void ReverseList()
    {
      if (m_size ==0)
      {
        cout << "List is empty" << endl;
        return;
      }
      else
      {
        Node<T>* ptrCurrent = ptrFront;
        Node<T>* prev = NULL;
        Node<T>* next = NULL;
        while (ptrCurrent != NULL)
        {
            next = ptrCurrent->ptrNext;
            ptrCurrent->ptrNext = prev;
            prev = ptrCurrent;
            ptrCurrent = next;
        }
        ptrFront = prev;
      }
    }

    int GetFirst()
    {
      return ptrFront->data;
    }

    int GetLast()
    {
      return ptrEnd->data;
    }

    int Size()
    {
      return m_size;
    }

    void Print()
    {
      Node<T>* ptrCurrent = ptrFront;
      int counter = 0;
      while (ptrCurrent != NULL)
      {
        cout << ptrCurrent->data << " ";
        ptrCurrent = ptrCurrent->ptrNext;
      }
    }
};

#endif