#include <bits/stdc++.h>
using namespace std;

bool compareEast(vector<long long>arr1, vector<long long>arr2){
    return arr1[1] < arr2[1];
}
int main(){
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    long long n;
    cin >> n;
    vector<vector<long long>> xSort, ySort;
    for (long long i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        xSort.push_back({x, y});
        ySort.push_back({x, y});
    }
    sort(xSort.begin(), xSort.end());
    sort(ySort.begin(), ySort.end(), compareEast);

    vector<vector<long long>> rightY(n, vector<long long>(2)), topX(n, vector<long long>(2));
    /*
    for (long long i=0;i<n;i++){
        if (i==0){
            leftY[i][0] = xSort[i][1];
            leftY[i][1] = xSort[i][1];
        }
        else{
            leftY[i][0] = min(leftY[i-1][0], xSort[i][1]);
            leftY[i][1] = max(leftY[i-1][1], xSort[i][1]);
        }
    }
    */
    for (long long i=n-1;i>=0;i--){
        if (i==n-1){
            rightY[i][0] = xSort[i][1];
            rightY[i][1] = xSort[i][1];
        }
        else{
            rightY[i][0] = min(rightY[i+1][0], xSort[i][1]);
            rightY[i][1] = max(rightY[i+1][1], xSort[i][1]);
        }
    }
    for (long long i=n-1;i>=0;i--){
        if (i==n-1){
            topX[i][0] = ySort[i][0];
            topX[i][1] = ySort[i][0];
        }
        else{
            topX[i][0] = min(topX[i+1][0], ySort[i][0]);
            topX[i][1] = max(topX[i+1][1], ySort[i][0]);
        }
    }

    long long original = (xSort[n-1][0]-xSort[0][0]) * (ySort[n-1][1]-ySort[0][1]);

    long long minY = 9999999999999999, maxY = 0, currMin = 99999999999999999;
    for (long long i=1;i<n;i++){
        minY = min(minY, xSort[i-1][1]);
        maxY = max(maxY, xSort[i-1][1]);
        currMin = min(currMin, ((xSort[i-1][0]-xSort[0][0]) * (maxY-minY) + (xSort[n-1][0]-xSort[i][0])*(rightY[i][1]-rightY[i][0])));
    }
    long long minX = 9999999999999999, maxX = 0;
    for (long long i=1;i<n;i++){
        minX = min(minX, ySort[i-1][0]);
        maxX = max(maxX, ySort[i-1][0]);
        currMin = min(currMin, ((ySort[i-1][1]-ySort[0][1])*(maxX-minX)+(ySort[n-1][1]-ySort[i][1])*(topX[i][1]-topX[i][0])));
    }
    cout << original-currMin << endl;
}