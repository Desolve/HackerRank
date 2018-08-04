#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

// Define Box and overload operator here.
class Box{
private:
	int l, b, h;
public:
	Box(){ l = b = h = 0; ++BoxesCreated; }
	Box(int len, int bre, int hei){ l=len; b=bre; h=hei; ++BoxesCreated; }
	Box(const Box& b2){ l=b2.l; b=b2.b; h=b2.h; ++BoxesCreated; }
	~Box(){ ++BoxesDestroyed; }
	int getLength(){ return l; }
	int getBreadth(){ return b; }
	int getHeight(){ return h; } 
	long long CalculateVolume(){ return (long long) l * b * h; }
	bool operator< (Box &b2){
		if(l < b2.l) return true;
		if((b < b2.b) && (l == b2.l)) return true;
		if((h < b2.h) && (b == b2.b) && (l == b2.l)) return true;
		return false;
	}
};
ostream& operator<< (ostream& out, Box B){
	out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}

void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}