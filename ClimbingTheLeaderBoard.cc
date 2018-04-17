#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the climbingLeaderboard function below.
 */
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    /*
     * Write your code here.
     */

    map<int, int> Map;
    for(auto i: scores)
        Map[i]++;
    
    map<int, int>::reverse_iterator it;

    

    
    

    vector<int> res;
    
    bool pushFlag = false;
    
    for(auto as: alice)
    {
        
        if(as >= scores[0])
        {
            res.push_back(1);
            continue;
        }
        
        if(as == scores[scores.size() - 1])
        {
            res.push_back(Map.size());
            continue;
        }
        
        if(as < scores[scores.size() - 1])
        {
            res.push_back(Map.size() + 1);
            continue;
        }
        
        int count = 1;
        pushFlag = false;
        for(it = Map.rbegin(); it != Map.rend(); it++)
        {
            if(as >= it->first)
            {
                pushFlag = true;
                res.push_back(count);
                break;
            }
            else
            {
                count++;
            }
        }
        
        if(!pushFlag)
            res.push_back(count);
            
    }
    
    return res;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int scores_itr = 0; scores_itr < scores_count; scores_itr++) {
        int scores_item = stoi(scores_temp[scores_itr]);

        scores[scores_itr] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int alice_itr = 0; alice_itr < alice_count; alice_itr++) {
        int alice_item = stoi(alice_temp[alice_itr]);

        alice[alice_itr] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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


