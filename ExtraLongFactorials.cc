#include <bits/stdc++.h>

using namespace std;

string multiplyString(string x, string y)
{
    long int len1 = x.size();
    long int len2 = y.size();
    
    int n_size = max(len1, len2);
    vector<int> op1(n_size);    //for large_num
    vector<int> op2(n_size);    //for param
    vector<int> res(len1 + len2);
    
    for(int i = 0; i < len1 + len2; i++){
        res[i] = 0;
    }
    
    int count = abs(len1 - len2);
    
    string large_num = x;
    string str2 = y;
    
    
    for(int i = 0; i < n_size; i++){
        if(n_size == large_num.size()){
            op1[i] = large_num[i] - '0';
        }
        else if(i < count){
            op1[i] = 0;
        }
        else{
            op1[i] = large_num[i - count] - '0';
        }
    }

    for(int i = 0; i < n_size; i++){
        if(n_size == str2.size()){
            op2[i] = str2[i] - '0';
        }
        else if(i < count){
            op2[i] = 0;
        }
        else{
            op2[i] = str2[i - count] - '0';
        }
    }
    reverse(op1.begin(), op1.end());
    reverse(op2.begin(), op2.end());
    
    for(int i = 0; i < n_size; i++){
        for(int j = 0; j < n_size; j++){
            res[i + j] = res[i + j] + op1[i] * op2[j];
        }
    }
    
    int carry = 0;
    for(int i = 0; i < res.size(); i++){
        int rr =res[i];
        res[i] = (res[i] + carry) % 10;
        carry = (rr + carry) / 10;
    }
    
    reverse(res.begin(), res.end());
    
    int flag = 1;
    string R;
    for(int i = 0; i < res.size(); i++){
        if(res[i] == 0 && flag == 1){
            continue;
        }
        else{
            R += to_string(res[i]);
            flag = 0;
        }
    }
    
    return R;
}



void extraLongFactorials(int n) {
    // Complete this function
    int i = 2;
    string res = "1";
    while(i <= n)
    {
        res = multiplyString(to_string(i), res);
        i++;
    }
    
    cout << res << "\n";
}

int main() {
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}


