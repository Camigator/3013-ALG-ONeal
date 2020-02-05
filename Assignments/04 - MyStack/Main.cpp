///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Cameron O'Neal
// Email:            oneal.cameron12@gmail.com
// Label:            A04
// Title:            Linked List Class
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
// 
//    This programs pops and pushes number onto a stack. If the number is an 
//    even number the number is pushes onto the stack. If the number were to be odd it  
//    would take the previous even number pushed onto the stack and pop it. We do this by
//    using a dynamic array with pointers.
// Usage:
// 
//      - $ ./main filename
//      - This will read in a file containing whatever values to be read into our 
//        List/array. 
//      
// Files:            
//      main.cpp    : driver program
//
/////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ostream>

using namespace std;

// #define ListSize 10                   // size of our original stack
#define IncSize 2                     // Mupltiplier to increase size of stack
#define decSize .5                    // Mupltiplier to decrease size of stack

class MyStack
{
  private:

    int number, ListSize;     // Number we send to the stack
    int count;                        // keeps track of our stack Size
    int * p;                          // pointer P points to our array of numbers
    int * q;                          // Temp ptr that creates the new array
    

  public:

  int ReSize;
 //  int StackArray[ListSize];

  MyStack()
  {
    ReSize = 0;
    ListSize = 10;
    number = -99;
    count = -1; 
    p = new int [ListSize];   
  }


  void push( int n)                   // Push takes a interger if even and pushes the value
  {
    if ( IsFull() == true )           // Checks if the Stack is full
    count++;                          // keeps track of size
    p[count] = n;                     // inserts interger at array location = to count val.
    
  }

  void pop()                           
  {
      int n;                        // temp value to display later
      n = p[count];                 // stores value in n
      count--;                      // decrease size of stack

      if(count < -1)
      {
        count = -1;
      }
  }

  bool IsFull()                     // Boolean statement  to check if stack is full
  {
    
    if ( (count + 1) == ListSize)          // If Count + 1 equal sizes number 
    {
      ListSize = ListSize * IncSize;       // double size of list
      q = new int [ListSize];              // creates new array
      for(int i = 0; i <= count ; i++)     // for loop that sets or values in ould array to new array 
      {
        q[i] = p[i];                       // set new values
      }
      p = q;                               // set pointer p to q
      delete q;                            // free up memory
      ReSize++;
    }
  
  return true;  
  }

  bool IsHalfFull()                        // Boolean statement  to check if stack is  is half full
  {
    if ( (count - 1) < ListSize / 2)       // if count -1 is less than size of list we can decrease
        {
          ListSize = ListSize * decSize;   // Cuts size of list by half
          q = new int [ListSize];          // creates new array
          for(int i = 0; i <= count ; i++) // for loop that sets or values in ould array to new array
          {
            q[i] = p[i];                   // set new values
          }
          p = q;                           // set pointer p to q
          delete q; 
          ReSize++;                        // free up memory
        }
    return true;        
  }
  
  bool IsEmpty()                          // checks is empty
  {
    if(count == -1)                       // start of stack
    return true;   

    return false;
  }


};




int main() {

ifstream infile;
infile.open("nums.dat");

  MyStack S;                                          // creates object
  int push1 = 0, pop1 = 0;                            // stores numbers pop / pushes

int x;                                                // holds value of integer thats pushed
int p;                                                // holds the value of pushed

while(infile >> x)                                    // for loop that generates random numbers
{
 // x = (rand() % 100);
  if( x % 2 == 0 )                                    // if integer is even push on stack
  {
    S.push(x);
    push1++;

  }
  else                                                // else pop last int pushed on stack
  {
    S.pop();
    pop1++;
  }
}

// cout << S.StackArray << endl;

cout << "Total of pushed numbers " << push1 <<endl;
cout << "Total of popped numbers " << pop1 <<endl;
cout << "Number of Resizes: " << S.ReSize << endl; 
 
}
