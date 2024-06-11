#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareCondition(string s1, string s2) {
	if (s1.length() == s2.length())
		return s1 < s2;
	else {
		return s1.length() < s2.length();
	}
}

int main(){
    vector<string> v;
    int size;
    string tmpInput;
    cin >> size;

    for(int i=0; i<size; i++){
        cin >> tmpInput;
        if(find(v.begin(), v.end(), tmpInput) == v.end())
            v.push_back(tmpInput);
    }

    sort(v.begin(), v.end(), compareCondition);

    cout << endl;
    for(string s : v){
        cout << s << endl;
    }
    return 0;
}