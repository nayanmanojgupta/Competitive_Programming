#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

int algo(string now){
    int ret = 0; bool removed = true; string s = now;
    while(s.length() > 0 && removed){
        int curRun = 1; char curLetter = s[0];
        string temp = "";
        removed = false;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == curLetter) curRun++;
            else{
                ret += curRun/2;
                if(curRun/2 > 0) removed = true;
                if(curRun%2 == 1) temp += s[i-1];
                curRun = 1; curLetter = s[i];
            }
        }
        if(curRun/2 > 0) removed = true;
        if(curRun%2 == 1) temp += s[s.length()-1];
        ret += curRun/2; s = temp;
    }
    return ret+s.length()/3;
}

int ans;
string s;

int main(){
    string s; cin >> s;
    ans = algo(s);
    if(s.length() > 2 && s[0] == s[s.length()-1]) ans = max(ans, 1+algo(s.substr(1, s.length()-2)));
    cout << ans << '\n';
    return 0;
}

/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

int algo(string s){
    int ret = 0, curRun = 1; char curLetter = s[0];
    vector<int> runs, residual;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == curLetter) curRun++;
        else{
            ret += curRun/2; runs.push_back(curRun); residual.push_back(curRun%2);
            curRun = 1; curLetter = s[i];
        }
    }
    ret += curRun/2; runs.push_back(curRun); residual.push_back(curRun%2);
    for(int i = 2; i < residual.size(); i++)
        if(residual[i] == 1 && residual[i-2] == 1){
            ret++;
            i += 2;
        }
    return ret;
}

int ans;
string s;

int main(){
    string s; cin >> s;
    ans = algo(s);
    if(s.length() > 2 && s[0] == s[s.length()-1]) ans = max(ans, 1+algo(s.substr(1, s.length()-2)));
    cout << ans << '\n';
    return 0;
}*/