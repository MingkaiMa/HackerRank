#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    
    // for(int i = 0; i < s.size(); i++)
    // {
    //     cout << i << "  " << s[i]<< endl; 
    // }
    // cout << s[8] << endl;
    // cout << s.size() << endl;
    if(s[8] == 'P' && s[0] == '1' && s[1] == '2')
    {

        return string(s.begin(), s.begin() + 8);
    }
    
    if(s[8] == 'A' && s[0] == '1' && s[1] == '2')
        return "00:" + string(s.begin() + 3, s.begin() + 8);
    
    
    string hour(s.begin(), s.begin() + 2);
    
    int hourNb = stoi(hour);
    
    if(s[8] == 'P')
        hourNb += 12;
    
    string newHour = to_string(hourNb);
    
    
    if(s[8] == 'A')
        return string(s.begin(), s.begin() + 8);
    
    if(s[8] == 'P')
        return newHour + ":" + string(s.begin() + 3, s.begin() + 8);
    

    
    return "";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
