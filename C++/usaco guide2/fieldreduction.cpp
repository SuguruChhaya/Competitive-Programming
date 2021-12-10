#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> sortedX, sortedY;
long long ans = 9999999999;
long long n;

//!Solution uses constructs the 4^4 possible rectangles first, check whether the number of points in it is valid, and updates answer. O(256*n)
void dfs(long long xLeft, long long xRight, long long yLeft, long long yRight, long long num){
    
    //!The only real reason we need exclusion is to stop infinite DFS. 
    //cout << "passed" << endl;
    ans = min(ans, ((sortedX[xRight].first-sortedX[xLeft].first) * (sortedY[yRight].first-sortedY[yLeft].first)));
    /*
    if (ans<0){
        cout << "";
    }
    cout << ans << endl;
    */
    if (num<min(n, 3ll)){
        long long newXLeft = xLeft+1;
        //!Need to make sure that they are the SAME. 
        //!Have to check whether the current ones are the SAME!!
        pair <long long, long long> reversedXLeft = {sortedX[xLeft].second, sortedX[xLeft].first};
        if (sortedY[yLeft]==reversedXLeft){
            dfs(newXLeft, xRight, yLeft+1, yRight, num+1);
        }
        else if (sortedY[yRight]==reversedXLeft){
            dfs(newXLeft, xRight, yLeft, yRight-1, num+1);
        }
        else{
            dfs(newXLeft, xRight, yLeft, yRight, num+1);
        }
        long long newXRight = xRight-1;
        pair <long long, long long> reversedXRight = {sortedX[xRight].second, sortedX[xRight].first};
        if (sortedY[yLeft]==reversedXRight){
            dfs(xLeft, newXRight, yLeft+1, yRight, num+1);
        }
        else if (sortedY[yRight]==reversedXRight){
            dfs(xLeft, newXRight, yLeft, yRight-1, num+1);
        }
        else{
            dfs(xLeft, newXRight, yLeft, yRight, num+1);
        }
        long long newYLeft = yLeft+1;
        pair <long long, long long> reversedYLeft = {sortedY[yLeft].second, sortedY[yLeft].first};
        if (sortedX[xLeft]==reversedYLeft){
            dfs(xLeft+1, xRight, newYLeft, yRight, num+1);
        }
        else if (sortedX[xRight]==reversedYLeft){
            dfs(xLeft, xRight-1, newYLeft, yRight, num+1);
        }
        else{
            dfs(xLeft, xRight, newYLeft, yRight, num+1);
        }
        long long newYRight = yRight-1;
        pair<long long, long long>reversedYRight = {sortedY[yRight].second, sortedY[yRight].first};
        if (sortedX[xLeft]==reversedYRight){
            dfs(xLeft+1, xRight, yLeft, newYRight, num+1);
        }
        else if (sortedX[xRight]==reversedYRight){
            dfs(xLeft, xRight-1, yLeft, newYRight, num+1);
        }
        else{
            dfs(xLeft, xRight, yLeft, newYRight, num+1);
        }
        
    }
}

int main(){
    //!The whole unit square vs coordinate thing too. 
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    cin >> n;
    for (long long i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        sortedX.push_back({x, y});
        sortedY.push_back({y, x});
    }
    sort(sortedX.begin(), sortedX.end());
    sort(sortedY.begin(), sortedY.end());
    //cout << "sortedX" << endl;
    /*
    for (long long i=0;i<n;i++){
        cout << sortedX[i].first << " " << sortedX[i].second << endl;  
    }
    cout << "sortedY" << endl;
    for (long long i=0;i<n;i++){
        cout << sortedY[i].first << " " << sortedY[i].second << endl;
    }
    */
    //for (long long i=0;i<n;i++)
    dfs(0, n-1, 0, n-1, 0);
    cout << ans << endl;
}