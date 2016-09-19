#include <iostream>
#include <cstdio>
using namespace std;

void printNum(int num){
   if(num == 1) cout << "one";
   else if(num == 2) cout << "two";
   else if(num == 3) cout << "three";
   else if(num == 4) cout << "four";
   else if(num == 5) cout << "five";
   else if(num == 6) cout << "six";
   else if(num == 7) cout << "seven";
   else if(num == 8) cout << "eight";
   else if(num == 9) cout << "nine";  
   else if(num % 2 == 0) cout << "even";
   else cout << "odd";
   
   cout << endl;
       
   return;
}

int main() {
    int start, end;
    cin >> start >> end;
    for(int i = start; i <= end; i++)
        printNum(i);
    return 0;
}