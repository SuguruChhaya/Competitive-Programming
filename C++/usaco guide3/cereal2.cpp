#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("cereal.in", "r", stdin);
    freopen("test", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> arr(n, vector<long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    map<long long, long long> lastInLine;
    vector<long long> eating (n, -1);
    map<long long, long long> nextInLine;
    long long ans = 0;
    for (long long i=0;i<n;i++){
        //cin >> arr[i][0] >> arr[i][1];
        if (!lastInLine.count(arr[i][0])){
            //First choice. 
            ans++;
            eating[i] = arr[i][0];
            lastInLine[arr[i][0]] = i;
        }
        else if (!lastInLine.count(arr[i][1])){
            ans++;
            eating[i] = arr[i][1];
            nextInLine[lastInLine[arr[i][0]]] = i;
            lastInLine[arr[i][1]] = i;
        }
        else{
            nextInLine[lastInLine[arr[i][1]]] = i;
            lastInLine[arr[i][1]] = i;
        }
    }
    cout << "eating" << endl;
    for (auto e:eating){
        cout << e << " ";
    }
    cout << endl;
    cout << "nextInLine" << endl;
    for (auto p:nextInLine){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    cout << "lastInLine" << endl;
    for (auto p:lastInLine){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    for (long long i=0;i<n-1;i++){
        ans--;
        long long currEating = eating[i];
        long long nextCow = -1, secondChoice=-1;
        if (nextInLine.count(i)){
            nextCow = nextInLine[i];
            //eating[nextCow] = arr[i][0];
            secondChoice = arr[i][0];
            //*Already becoming like a loop. 
        }

        while (nextCow!=-1 && secondChoice!=-1){
            eating[nextCow] = secondChoice;
            if (secondChoice==arr[nextCow][1]){
                secondChoice = -1;
            }
            else{
                secondChoice = arr[nextCow][1];
            }
            nextCow = -1;
            if (nextInLine.count(nextCow)){
                nextCow = nextInLine[nextCow];
            }
        }
        if (nextCow!=-1){
            ans++;
        }
        cout << ans << endl;
        
        
    }
}