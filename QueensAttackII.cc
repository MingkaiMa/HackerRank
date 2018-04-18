#include <bits/stdc++.h>

using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector < vector<int> > obstacles) {
    // Complete this function
    int totalNb = 0;
    
    //left
    totalNb += c_q - 1;
    
    //right
    totalNb += n - c_q;
    
    //up
    totalNb += n - r_q;
    
    //down
    totalNb += r_q - 1;
    
    //down_right
    totalNb += min(r_q - 1, n - c_q);
    
    //down_left
    totalNb += min(c_q - 1, r_q - 1);
    
    //up_right
    totalNb += min(n - r_q, n - c_q);
    
    //up_left
    totalNb += min(n - r_q, c_q - 1);
    
    
    int maxLeft = 0;
    int maxRight = 0;
    int maxUp = 0;
    int maxDown = 0;
    int maxDL = 0;
    int maxDR = 0;
    int maxUL = 0;
    int maxUR = 0;
    
    
    for(int i = 0; i < obstacles.size(); i++)
    {
        int row = obstacles[i][0];
        int col = obstacles[i][1];
        
        if(row == r_q)
        {
            if(col < c_q)
            {
                //totalNb -= col;
                
                //left
                
                if(col > maxLeft)
                    maxLeft = col;
                
            }
            else if(col > c_q)
            {
                //totalNb -= (n - col + 1);
                
                //right
                
                if((n - col + 1) > maxRight)
                    maxRight = (n - col + 1);
            }
        }
        else if(col == c_q)
        {
            if(row < r_q)
            {
                //totalNb -= row;
                
                //down
                
                if(row > maxDown)
                    maxDown = row;
                
            }
            else if(row > r_q)
            {
                //totalNb -= (n - row + 1);
                
                //up
                
                if((n - row + 1) > maxUp)
                    maxUp = n - row + 1;
            }
        }
        
        else if((r_q - row) == (c_q - col))
        {
            if(row < r_q)
            {
                
                //totalNb -= (1 + min(row - 1, col - 1));
                
                //down_left
                
                if((1 + min(row - 1, col - 1)) > maxDL)
                    maxDL = (1 + min(row - 1, col - 1));
                
                
            }
            else
            {
                
                //totalNb -= (1 + min(n - row, n - col));
                
                if((1 + min(n - row, n - col)) > maxUR)
                    maxUR = (1 + min(n - row, n - col));
            }
        }
        
        else if((r_q - row) == (-1) * (c_q - col))
        {
            if(col > c_q)
            {
                //totalNb -= (1 + min(row - 1, n - col));
                
                if((1 + min(row - 1, n - col)) > maxUL)
                    maxUL = (1 + min(row - 1, n - col));
                
            }
            else if(col < c_q)
            {
                //totalNb -= (1 + min(n - row, col - 1));
                
                if((1 + min(n - row, col - 1)) > maxDR)
                    maxDR = (1 + min(n - row, col - 1));
            }
        }
    }
    
    return totalNb - maxLeft - maxRight - maxUp - maxDown - maxDL - maxDR - maxUL - maxUR;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    int r_q;
    int c_q;
    cin >> r_q >> c_q;
    vector< vector<int> > obstacles(k,vector<int>(2));
    for(int obstacles_i = 0;obstacles_i < k;obstacles_i++){
       for(int obstacles_j = 0;obstacles_j < 2;obstacles_j++){
          cin >> obstacles[obstacles_i][obstacles_j];
       }
    }
    int result = queensAttack(n, k, r_q, c_q, obstacles);
    cout << result << endl;
    return 0;
}


