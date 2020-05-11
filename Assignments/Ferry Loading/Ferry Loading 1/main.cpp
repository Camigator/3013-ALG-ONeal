#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main() {

 
  int c;
  int BoatL, PortSize = 0, StarboardSize = 0;

  cin >> c; //number of cases


  cin >> BoatL;
  BoatL = BoatL *100; // changes from meters to cm
  

  vector<int> boatSize;
  vector<int> StarBoard;

  // This while loops creates the vector of cars in line
  int i = 0;
  while(cin >> c)
  {
    boatSize.push_back(c); //Car is push back into a line   
    i++;    
  }

  /*
   this for loop determines the size of all the cars in line
   I did it this way to figure out how many cars can fit on the Ferry.
   So, if cars in line size > size of boat i start knocking off people who can 
   fit on the boat
  */ 
  int TotalSize = 0;
  for(unsigned int i = 0; i < boatSize.size(); i++)
  {
    TotalSize = TotalSize + boatSize[i];
  }

cout << "Total Length of Cars in Line : " << TotalSize << endl;
cout << "Total length of Cars the boat can hold : " << BoatL*2 << endl;

// this while loop pops back cars that can fit on the Ferry
while(TotalSize > BoatL*2)
{
  boatSize.pop_back(); // deletes car that cant fit on ferry
  TotalSize = 0;
  for(unsigned int i = 0; i < boatSize.size(); i++)
  {
    TotalSize = TotalSize + boatSize[i]; // Calculates new size
    /* 
    if new size fits, there is a combination that will allow for all cars to fit
    */
  }
}


int a = 0; // this is a counter for the starboard side of ferry

for( unsigned int i = 0; i <= boatSize.size(); i++)
{
  //if Port side is less that size of one side of boat add one car
  if(PortSize < BoatL)
  {
    PortSize = PortSize + boatSize[i];
   
  }
  //if number of cars on one side cant we move the next car inline to starboard side
  else if(PortSize > BoatL)
  {
    //we push back value of car to or vector holding values of cars sizes
    StarBoard.push_back(boatSize[a+1]); 
    
    // subtract the size from port side
    PortSize = PortSize - StarBoard[a];
    
    // make value zero to show that the car was moved 
    boatSize[a+1] = 0;
    
    // decrease count value because we did nothing to the line
    // just moved a preexisting to the other side
    i--;

    // add to starboard side counter
    a++;    
  }
  else
  {
    // this checks last car that can fit on ferry and determines which side it will
    // go.
    StarBoard.push_back(boatSize[i]);
    boatSize[i] = 0;
  }

}

// outputs 
cout << 
// "Cars it can fit on Ferry : " << 
boatSize.size() << endl;

// another specific nest for loop

int y = 0;
for (unsigned int i = 0; i < boatSize.size(); i++)
{
  if(boatSize[i] !=0 )
  {
    cout << "port : " << boatSize[i] << endl;
  }
  else
  {
    cout << "starboard : " << StarBoard[y] << endl;
    y++;
  }
}

  return 0;
}
