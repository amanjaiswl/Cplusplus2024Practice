#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int karatsuba(int x, int y){
  if(x < 10 && y < 10)
    return x * y;
  int n = max(to_string(x).length(), to_string(y).length());
  int n2 = n/2;
  int p = pow(10, n2);
  int a = x / p;
  int b = x % p;
  int c = y / p;
  int d = y % p;
  int ac = karatsuba(a, c);
  int bd = karatsuba(b, d);
  int ad_bc = karatsuba(a + b, c + d) - ac - bd;
  return ac * pow(10, 2 * n2) + (ad_bc * pow(10, n2));
  
}

int main(){
  int x, y;
  cin >> x >> y;
  cout << karatsuba(x, y) << endl;
  return 0;
}