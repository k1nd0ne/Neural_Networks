#include<iostream>
#include"Neurone.h"
using namespace std;

int main() {
Neurone n1(3);

n1.printWeight();
cout << "\n";

Neurone n2(3);

n2.printWeight();
cout << "\n";
Neurone n4(4);

n4.printWeight();
cout << "\n";

  return 0;
}
