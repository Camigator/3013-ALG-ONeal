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
//       This program implements a class that allows a linked list to be used just like 
//       an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
//       array elements, but really it traverses the list to find the specified node using
//       an index value. It also overloads the "+" and "-" signs allowing a user to "add"
//       or "push" items onto the end of the list, as well as "pop" items off the end of our 
//       array. This class is not meant to replace the STL vector library, its simply a project
//       to introduce the beginnings of creating complex / abstract data types. 
//       
// Usage: 
//      - $ ./main filename
//      - This will read in a file containing whatever values to be read into our list/array. 
//      
// Files:            
//      main.cpp    : driver program 
//      list.h      : header file with list defintion
//      list.cpp    : list implementation
/////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>

using namespace std;

int A[100];                             //intiallize a new array

struct Node {
    //vairable x holds values for each node
    int x;
    //pointer to next node
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    //intialize first node to n & pointer n to NULL
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 * Class Name : List
 * 
 * Description:
 *      Class List alloew you to push, pop, add, output to screen, insert values into a linked list
 * 
 * Public Methods:
 *      void push
 *      void insert
 *      void printTrail
 *      string print
 *      int pop
 *      List Operator+
 *      int operator[]
 *      friend ostream &operator<<
 * 
 * Private Methods:
 *      Node * head                     //pointer to head
 *      Node * Tail                     //pointer to tail
 *      Int Size                        //size of list
 * 
 * Usage: 
 * 
 *      Will create 2 list of different intergers
 *      that will the add the 2 list together creating a list 3
 *      The list will print out all the values inn list 3
 *      And lastly print out ther first 5 values in List 3
 *      
 */

class List {
private:
   
    Node *Head;                         //pointer to front of list
    Node *Tail;                         //pointer to rear of the list
    int Size;                           // Tracks the size of the list


public:
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    void Push(int val) {
        
        Node *Temp = new Node(val);     // allocate new memory and init node
        if (!Head && !Tail) {           // create new node with in list

            Head = Tail = Temp;         //head and tail point to new node

        } else {
           
            Tail->next = Temp;          //new tail pointer
            Tail = Temp;
        }
        
        Size++;                         //increases size of list counter
    }

    void Insert(int val) {
        
        Node *Temp = new Node(val);     // allocate new memory and init node

        
        Temp->next = Head;              // figure out where it goes in the list
                                        // inserting at the begining of the list
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
                                        // also i dont get Why if temp pointer is not pointing at "tail" why would
                                        // we pointer the tail pointer at head??
        Size++;
    }
   
    void PrintTail() {                  //prints values stored in each node to screen.
        cout << Tail->x << endl;
    }
    string Print() {                    // print the value stored in our x above and converting to a string to print out

        Node *Temp = Head;              //intializing temp to point to head

        string list;
        while (Temp != NULL) {          // while the temp pointer is not pointing to null conver value to string

            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }
        
        return list;
    }

                                        // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    List operator+(const List &Rhs) {
        
        List NewList;                   // Create a new list that will contain both when done

        
        Node *Temp = Head;              // Get a reference to beginning of local list

        
        while (Temp != NULL) {          // Loop through local list and Push values onto new list
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

       
        Temp = Rhs.Head;                // Get a reference to head of Rhs

        
        while (Temp != NULL) {          // Same as above, loop and push
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        
        return NewList;                 // Return new concatenated version of lists
    }

   
    int operator[](int index) {         // Implementation of [] operator.  This function returns an
                                        // int value as if the list were an array.
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    List L1;
    List L2;
    
    for (int i = 0; i < 25; i++) {      //pusing values into list 1 from 1-25
        L1.Push(i);
    }
    for (int i = 50; i < 100; i++) {    // pushing values from 50-100 into list 2

        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();
    List L3 = L1 + L2;                  // conjoining list 1 & 2 together

    cout << L3 << endl;                 // print out list 3

    cout << L3[5] << endl;              // print out the first 5 nodes in conjoined list

    return 0;
}
