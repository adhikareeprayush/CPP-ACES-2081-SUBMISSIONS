/*
 * Program: Finding the Greater Number
 * Description: Program to find the greater number between two values
 *              using function overloading for different data types
 * Date: July 5, 2025
 */
#include <iostream>
using namespace std;
int max(int &a, int &b)
{
  int max = a > b ? a : b;
  return max;
}

int main()
{
  // INT
  int a = 6;
  int b = 7;
  cout << "The greater NUmber is : " << max(a, b) << endl;

  // FlOAT
  float c = 6.67;
  float d = 7.76;
  cout << "The greater NUmber is : " << max(c, d) << endl;

  return 0;
}