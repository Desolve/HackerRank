#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    cout << a.size() << " " << b.size() << endl
         << a+b      << endl;
    char a1 = b[0], b1 = a[0];
    a[0] = a1; b[0] = b1;
    cout << a << " " << b;    
  
    return 0;
}