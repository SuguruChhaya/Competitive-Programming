#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Do we have to use priority queue? Can't I just use normal vector and sort it?
    long long x, n;
    cin >> x >> n;
    vector <vector <long long>> arr (n, vector <long long> (2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    sort(arr.begin(), arr.end());

    //!If the expiration is also sorted in case of a try, can't I just sort it and loop from beginning?
    long long currTime = 0, result=0;
    for (long long i=0;i<n;i++){
        currTime = max(currTime, arr[i][0]-x);
        if (arr[i][1]>=currTime){
            result++;
            currTime++;
        }
    }
    cout << result << endl;
    //!I think where this becomes a problem is that we get stuck. 
    /*
    bool ok = true;
    long long i = 0, result = 0, currTime = 0;
    while (i<n){
        vector <vector <long long>> temp;
        long long curr_min = arr[i][0];
        long long j=i;
        while (j<n && arr[j][0]==curr_min){
            temp.push_back({arr[j][1], arr[j][0]});
            j++;
        }
        i=j;
        sort(temp.begin(), temp.end());
        if (temp[0][0]<currTime){
            break;
        }
        else{
        }

    }
    */
}