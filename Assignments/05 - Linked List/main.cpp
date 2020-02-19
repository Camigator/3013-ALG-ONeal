/*///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Cameron O'Neal
// Email:            oneal.cameron12@gmail.com
// Label:            P02
// Title:            Linked List Class
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
// Write a program that will read in a dictionary file from dict_w_defs.json and store it // in a linked list.
// Define a wordNode to be a struct or a class to hold a word and definition.
// The linked list should hold wordNodes .
// Time how long it takes to load the data into your linked list (we will use that later as // well).
// After your dictionary (linked list) is loaded, we are going to perform "autosuggestions" // when a user types characters at the console.
// Suggestions will start after 1 character is typed, however only the top 10 suggestions // will be printed along with the total number of matching words (example output below).
// The time it takes to find each suggestion will be displayed in seconds.   
// Usage: 
//      - main.cpp filename
//      - This will read in a file containing whatever values to be read into our 
//        
//      
// Files:            
//      main.cpp    : driver program
//
/////////////////////////////////////////////////////////////////////////////////*/


#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <iomanip>
#include "mygetch.hpp"
#include "Timer.hpp"
#include "JsonFacade.hpp"
#include <time.h>
#include <chrono>

using namespace std;

/*
This nodes holds two values:
    -word
    -Defintion of the word

The usage of this Node is to implement a Linked list connecting all The words in the JSON file together.
*/

struct Node {
    string Word;
    string Definition;    
    Node * next;
    Node( string W, string D)
    {
        Word = W;
        Definition = D;
        next = NULL;
    }

};
/*
Class Linked List:
    - stores the values into our linked list
    - Finds the word we are searching for in our array 
        * storing those values in a temp linked list
    - Deleting the temp array to allow for the search of a more indepth linked list or a different on entirely.

 */
class LinkedList
{

    private: 
        Node * head;            // pointer to first node in dictionary
        Node * H;               // pointer to first node in temp linked list
        Node * Tail;            // pointer to Tail node in dictionary
        Node * T;               // pointer to last node in temp linked list
        

    public: 

    
    LinkedList()
    {
        head = Tail = NULL;
       
    }

    // NewWord string sent from json file
    // D string is the Defintion
    void add(string NewWord, string D)
    {
        if( head == NULL)                           //if first node 
        {
            head = Tail = new Node(NewWord, D);     // set head & tail pointing to node
            head->next = Tail->next = NULL;         // set pointers -> next equal to NULL
        }
        else                                        //if not first node
        {
            Tail -> next = new Node(NewWord,D);     // have tail pointer->next create new node with Values
            Tail = Tail->next;                      // set tail ptr = to new node
        }

    }


    // Helps search for word in Larger array -> stores in smaller array
    void FindWord(string search, int c)
    {
      // creates temp ptr
      Node * Temp = head;

      //check helps us see if our comparisons are equal           
      int check = 0;
     
      
      //temp ptr does not equal NULL
      while(Temp != NULL)
      {
        // do for loop equal to the size fo char type thats stores in c
        for(int i = 0; i < c ; i++)
        {
         if(Temp->Word[i] == search[i]) //if char match
          {
              check++;                  //check counter gets increased
          }
        }

        // if the checks equals that of c ...... the char type equals the word found
        if(check == c)                
        {
          // if temp linked list is empty store that word and definition at the beginning of list
          if(H == NULL )
          {
            H = T = new Node(Temp->Word, Temp->Definition);
            
          }
          else   // other wise create another     
          {
            T -> next = new Node(Temp->Word, Temp -> Definition);
            T = T->next;
           
          } 
        }    
        // pointer moves to next word in large array
        Temp = Temp -> next;

        // allows us to reset our checker
        check = 0;    
      }



    }
    // Print only prints values from temp linked list because those are the words that are related to our search
    void Print()
    {
        Node * temp = H;

        // int Wcounter helps keeps the minimum search to 10
        int Wcounter = 0;
        // if statement checks for if anything is in array or if the word you search for exist.
        if(temp == NULL) 
        {
          cout << " No Results found. " ;
        }
        else // if the word you type exist it will print to screen
        {
          while (temp != NULL && Wcounter != 10)
          {
            //prints out word -> can also print out definition but not for this project
            cout << "[" << temp -> Word << "] ";

            // ptr moves to next node
            temp = temp->next;
            Wcounter++; 
          }
        }       

        
        cout << endl;

    }
    // Delte function delets temp linked list so that you can start over 
    // or if you narrow your search the LL resizes to adjust.
    void Delete()
    {
      Node * temp = H;      // ptr to First node
      while( H != NULL)
      {
      H = H->next;          // send H to next node
      delete temp;          // deletes prev node
      temp = H;             // sets temp back to head
      }
    }

};




int main()
{  
  // open file
  ifstream infile;        
  infile.open("dict_w_defs.json");

  // keeps count of char typed
  int count = 0;

  // creates instance of LL class
  LinkedList L;

  // creatse instance of Timer class
  Timer T;

    char k;             // holder for character being typed
    string word = "";   // var to concatenate letters to

    
    // starts timer
    T.Start();

    JsonFacade J("dict_w_defs.json");   // create instance of json class
    int index = 3;                      // 
    string key;                         // key variable to access json object

    vector<string> keys = J.getKeys();  // list of keys = to the word
    
    // goes through every word in dictionary
    while(index < 102217){
    // finds word
    key = J.getKey(index);

    // send word and word's definition
    L.add(key, J.getValue(key));

    // increments index
    index++;
    }
    
    //stops timer
    T.End();

    double s = T.Seconds();
    long m = T.MilliSeconds();

    cout <<s << " seconds" <<endl;
    cout <<m << " milli" <<endl;

    cout<<"Type keys and watch what happens. Type capital Z to quit."<<endl;

    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z') {
        word += k;          // append char to word

        if((int)k != 10){   // if k is not a space print it
         // cout << "Key: " << k << " = " << (int)k << endl;
            cout << "Word: " << word << endl;

            // counts char typed
            while( word[count] != '\0' )
              {
                count++;
              }

               cout << count << endl;

              // send word and count to findWord
              L.FindWord(word, count);
              // prints ouput
              L.Print();

              // deletes Temp LL
              L.Delete();
        }

        // hitting enter sets word back to empty
        if((int)k == 10 ){
            cout<<"Enter pressed ... Word is empty\nWord: "<<endl;
            word = "";

            // search for new word -> starts with new LL and char counter
            L.Delete();
            count = 0;
        }
    }

    return 0;
}
