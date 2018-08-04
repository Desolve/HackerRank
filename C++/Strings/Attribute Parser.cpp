/* This answer is referenced from someone else on HackerRank, 
   and not using too much nested things, beautiful. 
   But noticed that it doesn't really establish the structure for these nested tags, though.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

void trim(string &s){
    s.erase(0, s.find_first_not_of(" \n\r\t"));
    s.erase(s.find_last_not_of(" \n\r\t>")+1);
}

string sumK (vector<string> &vs){
	// get tag1.tag2.... the stuffs before "~"
    bool first = true;
    string ret = "";
    for(auto v : vs){
        if(first) first = false;
        else ret += ".";
        ret += v;
    }
    return ret;
}

int main() {
    vector<string> stack;
    map<string,string> attrs;
    string inp;

    int n, q;
    cin >> n >> q;
    cin.ignore();

    for(int i=0; i < n; i++){
        getline(cin,inp);
        if (inp.find("</")==0 || inp.find("< /")==0){
            stack.pop_back();
            continue;
        }
		// Follow the order: <, tag, attr, = ," ,val ,"
        stringstream ss(inp);
        char c;
        ss >> c;
        string tag;
        ss >> tag;
        trim(tag);
        stack.push_back(tag);

        string attr, val;
        while(getline(ss, attr, '=')) {
            trim(attr);
            if (attr.length() == 0) continue;
			// take out the middle value between two "
            getline(ss, val, '"');
            getline(ss, val, '"');
			// and put into the map.
            attrs[sumK(stack) + "~" + attr] = val;
        }
		// And actually we don't really care about closure tags, 
		// that is, this code won't check data integrity.
    }
    for(int i=0; i < q; i++){
        getline(cin,inp);
        trim(inp);
		// Just find the pair on the map, if found then print out second value.
        auto it = attrs.find(inp);
        if( it == attrs.end())
            cout << "Not Found!" << endl;
        else
            cout << it->second << endl;
    }

    return 0;
}