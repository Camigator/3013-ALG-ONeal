#include <iostream>

using namespace std;

int main()
{

  int y;
  int Case = 1;

  while(cin >> y && y != 0)
  {
    y = y/2;
    cout << "Case " << Case << ": " << y << endl;
    Case++; 
  }
  
  return 0;
}
