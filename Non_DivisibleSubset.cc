#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the nonDivisibleSubset function below.
 */
int nonDivisibleSubset(int k, vector<int> S) {
    /*
     * Write your code here.
     */
    int* f = new int[k];
    for(int i = 0; i < k; i++)
        f[i] = 0;
    
    for(int i = 0; i < S.size(); i++)
        f[S[i] % k]++;
    
    if(k % 2 == 0)
        f[k/2] = min(f[k/2], 1);
    
    int res = min(f[0], 1);
    
    for(int i = 1; i <= k/2; i++)
        res += max(f[i], f[k - i]);
    
    return res;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string S_temp_temp;
    getline(cin, S_temp_temp);

    vector<string> S_temp = split_string(S_temp_temp);

    vector<int> S(n);

    for (int S_itr = 0; S_itr < n; S_itr++) {
        int S_item = stoi(S_temp[S_itr]);

        S[S_itr] = S_item;
    }

    int result = nonDivisibleSubset(k, S);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
