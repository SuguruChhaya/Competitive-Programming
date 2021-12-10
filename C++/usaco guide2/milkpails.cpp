#include <bits/stdc++.h>
using namespace std;
long long x, y, k, m, ans=999999999;
set <vector <long long>> s;
void dfs(long long num1, long long num2, long long depth){
    if (depth<=k && !s.count({num1, num2})){
        if (num1==13 && num2==0){
            cout << "" << endl;
        }
        s.insert({num1, num2});
        ans = min(ans, abs(m-(num1+num2)));
        //!Just because debugger caught it for the first time doesn't mean shortest node. 
        //!Basically it finds the previous version at the last stage so that that version happening in before stages cannot be expanded. 
        //*BFS is the best solution here. 
        //!But if found, it should record it anyways!!
        dfs(x, num2, depth+1);
        dfs(num1, y, depth+1);
        //!No one said that it could be full!
        //!Carefully put if-statments. 
        //*Moving to the left cup.
        if (num1+num2<x){
            dfs(num1+num2, 0, depth+1);
        }
        else{
            dfs(x, num2-(x-num1), depth+1);
        }
        if (num1+num2<y){
            dfs(0, num1+num2, depth+1);
        }
        else{
            dfs(num1-(y-num2), y, depth+1);
        }
        
        dfs(0, num2, depth+1);
        dfs(num1, 0, depth+1);
    }

}

int main(){
    //freopen("pails.in", "r", stdin);
    //freopen("pails.out", "w", stdout);
    cin >> x >> y >> k >> m;
    dfs(0, 0, 0);
    if (s.count({0, 0})){
        cout << "0"<< endl;
    }
    if (s.count({0, 13})){
        cout << "1"<< endl;
    }
    if (s.count({13, 0})){
        cout << "2"<< endl;
    }
    if (s.count({13, 13})){
        cout << "3"<< endl;
    }

    cout << ans << endl;
}