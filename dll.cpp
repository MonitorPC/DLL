#include <iostream>

using namespace std;

template<typename T>
class List
{
  private:

  class Node
  {
    T data;
    T *pNext;
    T *pPrev;

    Node(T data=T(), T *pNext=nullptr, T *pPrev=nullptr)
    {
      this->data = data;
      this->pNext = pNext;
      this->pPrev = pPrev;
    }
  };
  
  Node *head;
  Node *end;
  int size;

  public:
  List();
  ~List();

  

  void push_back(T data);
  void pop();
  
  T get_data();
  int get_size();

  Node * get_node(int index)
  {
    Node *item = head;
    for (int i = 0; i < index; i++)
    {
      item = item->pNext;
    }
  }
  
  
};

template<typename T>
List<T>::List()
{
  size = 0;
  head = nullptr;
}

template<typename T>
List<T>::~List()
{
  
}

template<typename T>
void List<T>::push_back(T data)
{
  if (this->size == 0)
  {
    this->head = new Node(data);
    this->end = head;  
  } else
  {
    this->end->pPrev = new Node(data);
    this->end = this->end->pPrev;
  }
  this->size++;
}

template<typename T>
void List<T>::pop()
{
  this->end = this->end->pPrev;
  this->end->pNext = nullptr;  
  this->size--;
}

int main() 
{
  return 0;
}
