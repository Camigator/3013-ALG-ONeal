#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std; 


struct Node
{
  
  Node * next;
  int value;
  int Vcount = 0;

  Node(int v, int c)
  {
  value = v;
  Vcount = c;  
  }
};

class Rendundacy
{
  private:
    Node * head;
    Node * tail;
    Node * p;
    Node * n;


    public:

    Rendundacy()
    {
      head = p = NULL;
    }



    void check(int x)
    {
      p = head;
     if(head == NULL)
     {
      CreateNode(x);
      TONULL();
     }
     while(p != NULL)
     {
       if(x == p->value)
        {
            AddOne();
            TONULL();
        }     
        else if(p == tail)
        {
          AtEnd(x);
          TONULL();      
        }
        else
        {
          p = p->next;
        }
     }
    }

    //Create First Node
    void CreateNode(int x)
    {
      head = p = tail = new Node(x,1);
      tail->next =NULL;
    }

    // Adds one to out number counter
    void AddOne()
    {
      int c;
      c = p->Vcount;
      c++;
      p->Vcount = c;
    }

    //adds node at the end of list
    void AtEnd(int x)
    {
      tail = new Node(x,1);
      tail->next = NULL;
      p->next = tail;
      p = tail;
    }

    void TONULL()
    {
      while(p != NULL)
      p = p->next;
    }

    void Print()
    { 
      p = head;
      while(p != NULL)
      {
      cout << p->value << " " << p->Vcount << endl;
      p = p->next;     
      }
    }

};




int main()
{
  
  int x, y ,z ;
  Rendundacy r;

  while(cin >> x)
    r.check(x);

  r.Print();
  return 0;
}


