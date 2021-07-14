#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    //*Wouldn't the minimum always be either 1 or 2?
    //*Just create one space and move the next one in. 
    //*Or if there is already one space then easy. 
    
    //!Maximum is the harder one. 
    //*I can first move the one with greater difference then do easy math. 

    long long a, b, c;
    cin >> a >> b >> c;

    //*Not necessarily sorted so I could sort then in an array. 
    vector <long long> arr = {a, b, c};

    sort(arr.begin(), arr.end());

    if (arr[0]+1==arr[1] && arr[1]+1==arr[2]){
        //*Already in correct order. 
        cout << 0 << endl;
    }
    else if (arr[0]+2==arr[1] || arr[1]+2==arr[2]){
        //*There is exactly one space to fit in. 
        cout << 1 << endl;
    }
    else{
        cout << 2 << endl;
    }

    //*Pick the longer one. 
    cout << max(arr[1]-arr[0]-1, arr[2]-arr[1]-1) << endl;
}