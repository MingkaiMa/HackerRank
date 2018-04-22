//reference: http://gotitt.blogspot.com.au/2016/09/absolute-permutation.html

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the absolutePermutation function below.
 */
vector<int> absolutePermutation(int n, int k) {
    /*
     * Write your code here.
     */

    vector<int> array;
    for(int i = 1; i <= n; i++)
        array.push_back(i);
    

    if(k == 0)
        return array;
    
    vector<int> res(n);
    if((k <= n / 2) && (n % k == 0) &&((n / k) % 2 == 0))
    {
        for(int i = 0; i < n; i++)
        {
            if((i / k) % 2 == 0)
                res[i] = i + k + 1;
            else
                res[i] = i - k + 1;
        }
        
        return res;
    }
    
    else
        return {-1};

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        vector<int> result = absolutePermutation(n, k);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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


