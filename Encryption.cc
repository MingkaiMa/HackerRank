#include <bits/stdc++.h>
#include <cmath>
using namespace std;

string encryption(string s) {
    // Complete this function
    int count = 0;
    string newS = "";
    for(auto ch: s)
    {
        if(ch != ' ')
        {
            count++;
            newS += ch;
        }
    }

    int row = floor(sqrt(count));
    int col = ceil(sqrt(count));
    
    string res = "";
    
    for(int i = 0; i < col; i++)
    {
        string s1 = "";
        s1 +=  newS[i];
        int start = i + col;
        while(start < s.size())
        {
            s1 += newS[start];
            start += col;
        }
        
        res += s1;
        res += ' ';
    }
    
    
    string r(res.begin(), res.end() - 1);
    
    return r;
}
int main() {
    string s;
    cin >> s;
    string result = encryption(s);
    cout << result << endl;
    return 0;
}


