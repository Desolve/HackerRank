#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int pidcnt = 0, sidcnt = 0;

class Person{
public:
	char name[101];
	int age, id;
	virtual void getdata() = 0;
	virtual void putdata() = 0;	
};
class Professor: public Person{
public:
	int pubs;
	void getdata(){
		scanf("%s %d %d", name, &age, &pubs);
		id = ++pidcnt;
	}
	void putdata(){        
		printf("%s %d %d %d\n", name, age, pubs, id);        
	}
};
class Student: public Person{
public:
	int score = 0;
	void getdata(){
		scanf("%s %d ", name, &age);
		for(int i = 0; i < 6; i++){
			int tmp;
			scanf("%d", &tmp);
			score += tmp;
		}
		id = ++sidcnt;
	}
	void putdata(){
		printf("%s %d %d %d\n", name, age, score, id);
	}
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}