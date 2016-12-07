#include <stdlib.h>
#include <iostream>

using namespace std;

void Euclidean_GCD(int x, int y);
int NoName_GCD(int x, int y);

int main()
{
  int num_one, num_two;

  //cout << "Enter the first number: ";
  //cin >> num_one;

  //cout << "Enter the second number: ";
  //cin >> num_two;

  Euclidean_GCD(45, 15);
  NoName_GCD(45, 15);
  return 0;
}


void Euclidean_GCD(int x, int y)
{
  if (y > 0)
  {
    int temp_x = x;
    x = y;
    y = temp_x % y;
    Euclidean_GCD(x, y);
  }
  else
    cout << "Euclidean_GCD is: " << x << endl;
}

int NoName_GCD(int x, int y)
{
  if (y > x)
  {
    int temp = y;
    y = x;
    x = temp;
  }

  if (x == y)
    cout << "NoName_GCD is: " << x << endl;
  else if ((x%2) == 0 && (y%2) == 0)
    return (2 * NoName_GCD((x/2), (y/2)));
  else if ((x%2) != 0 && (y%2) == 0)
    return (NoName_GCD(x, (y/2)));
  else if ((x%2) == 0 && (y%2) != 0)
    return (NoName_GCD((x/2), y));
  else if ((x%2) != 0 && (y%2) != 0)
    return (NoName_GCD((x-y), y));

}
