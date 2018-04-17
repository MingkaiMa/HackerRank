#include <bits/stdc++.h>

using namespace std;

string appendAndDelete(string s, string t, int k) {
    // Complete this function
    if(s == t)
    {
 
        if(k % 2 == 0)
            return "Yes";
        
        if(k >= 2 * s.size())
            return "Yes";
        return "No";
    }
    
    
    
    if(k >= s.size() + t.size())
        return "Yes";
    
    
    int diff = 0;
    
    diff = s.size() - t.size() >= 0 ? s.size() - t.size() : t.size() - s.size();
    
    if(k < diff)
        return "No";
    
    

    int i = 0, j = 0;
    
    while(i < s.size() && j < t.size())
    {
        if(s[i] != t[j])
        {
            int sModi = s.size() - i;
            int tModi = t.size() - j;
            
            if(k >= sModi + tModi)
                return "Yes";
            return "No";
        }
        
        i++;
        j++;
    }
    
    if(j == t.size())
    {
        int diff = s.size() - j;
        
        if(diff & 1)
        {
            if(k & 1)
                return "Yes";
            else
                return "No";
        }
        else
        {
            if(k & 1)
                return "No";
            else
                return "Yes";
        }
    }
    
    if(i == s.size())
    {
        int diff = t.size() - i;
        if(diff & 1)
        {
            if(k & 1)
                return "Yes";
            else
                return "No";
        }
        else
        {
            if(k & 1)
                return "No";
            else
                return "Yes";
        }
        
    }
    

    return "";
}

int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
    string result = appendAndDelete(s, t, k);
    cout << result << endl;
    return 0;
}


