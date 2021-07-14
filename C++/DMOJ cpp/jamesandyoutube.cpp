#include <iostream>
#include <vector>

using namespace std;

int main(){
    //*Basically just create array and loop through the location. 
    //*I don't think it will TLE but if it does, might have to use some prefix array shit. 

    vector <bool> arr;
    for (int i=0;i<1440;i++){
        arr.push_back(0);
    }

    int m, n, a, b;
    cin >> m;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        for (int j=a;j<=b;j++){
            arr[j] = 1;
        }
    }

    cin >> n;
    bool watch;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        watch = false;
        for (int j=a;j<=b;j++){
            if (arr[j]==1){
                watch = true;
                break;
            }
        }
        if (watch){
            cout << "Break is Over! Stop playing games! Stop watching Youtube!" << "\n";
        }
        else{
            cout << ":eyy:" << "\n";
        }
    }
}