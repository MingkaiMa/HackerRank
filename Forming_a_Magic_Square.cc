#include <bits/stdc++.h>

using namespace std;

int formingMagicSquare(vector < vector<int> > s) {
    // Complete this function
    int magic0[3][3] = {{8,1,6}, {3,5,7}, {4,9,2}};
    int magic1[3][3] = {{6,1,8}, {7,5,3}, {2,9,4}};
    int magic2[3][3] = {{4,9,2}, {3,5,7}, {8,1,6}};
    int magic3[3][3] = {{2,9,4}, {7,5,3}, {6,1,8}};
    int magic4[3][3] = {{8,3,4}, {1,5,9}, {6,7,2}};
    int magic5[3][3] = {{4,3,8}, {9,5,1}, {2,7,6}};
    int magic6[3][3] = {{6,7,2}, {1,5,9}, {8,3,4}};
    int magic7[3][3] = {{2,7,6}, {9,5,1}, {4,3,8}};
    
    int sum[8] = {0};
    
    for(int i = 0; i < 3; i++)
    {
        int temp = 0;
        for(int j = 0; j < 3; j++)
        {
            sum[0] += abs(s[i][j] - magic0[i][j]);
            sum[1] += abs(s[i][j] - magic1[i][j]);
            sum[2] += abs(s[i][j] - magic2[i][j]);
            sum[3] += abs(s[i][j] - magic3[i][j]);
            sum[4] += abs(s[i][j] - magic4[i][j]);
            sum[5] += abs(s[i][j] - magic5[i][j]);
            sum[6] += abs(s[i][j] - magic6[i][j]);
            sum[7] += abs(s[i][j] - magic7[i][j]);
        }
    }
    
    int res = sum[0];
    for(int i = 1; i < 8; i++)
    {
        if(res > sum[i])
            res = sum[i];
    }
    
    return res;
}

int main() {
    vector< vector<int> > s(3,vector<int>(3));
    for(int s_i = 0;s_i < 3;s_i++){
       for(int s_j = 0;s_j < 3;s_j++){
          cin >> s[s_i][s_j];
       }
    }
    int result = formingMagicSquare(s);
    cout << result << endl;
    return 0;
}


