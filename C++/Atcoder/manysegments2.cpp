#include <bits/stdc++.h>
using namespace std;

int main(){
    //*+0.5 works. 
    //*Dividing into cases just makes the program buggy. 
    //*Never try to divide into cases I guess/ 
    long long n;
    cin >> n;
    vector <vector <double>> arr (n, vector <double> (3));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        if (arr[i][0]==2){
            arr[i][2]-=0.5;
        }
        else if (arr[i][0]==3){
            arr[i][1]+=0.5;
        }
        else if (arr[i][0]==4){
            arr[i][2]-=0.5;
            arr[i][1]+=0.5;
        }
    }
    long long result = 0;
    for (long long i=0;i<n;i++){
        for (long long j=i+1;j<n;j++){
            //*Kind of similar to intersecting square area formula. 
            result += (max(arr[i][1], arr[j][1]) <= min(arr[i][2], arr[j][2]));
        }
    }
    cout << result << endl;
}