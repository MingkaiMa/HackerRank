#include <bits/stdc++.h>

using namespace std;

string biggerIsGreater(string w) {
    // Complete this function
    
    if(w.size() <= 1)
        return "no answer";
    
    
    
    bool found = false;
    
    
    for(int i = w.size() - 2; i >= 0; i--)
    {
        int minIndex = -1;
        
        for(int j = i + 1; j < w.size(); j++)
        {
            if(w[i] - 'a' < w[j] - 'a')
            {
                found = true;
                if(minIndex == -1)
                    minIndex = j;
                else
                {
                    if(w[minIndex] - 'a' > w[j] - 'a')
                        minIndex = j;
                }
                
            }
        }
        
        if(found == true)
        {
            swap(w[i], w[minIndex]);
            sort(w.begin() + i + 1, w.end());
            break;
        }
            
    }
    
    if(found == false)
        return "no answer";
    
    return w;
    
    
}

int main() {
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        string w;
        cin >> w;
        string result = biggerIsGreater(w);
        cout << result << endl;
    }
    return 0;
}


