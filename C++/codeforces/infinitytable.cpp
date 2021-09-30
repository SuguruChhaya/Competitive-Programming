#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long k;cin >> k;
    //*I can easily see binary search coming in. 
    //*Also, if I do get WA, it should be easy to stress test because brute force is just simulation. 
    //*Just store in vector so I just need to create once and then binary search. 


}

int main(){
    long long t;cin>>t;
    vector <long long> q;
    long long m = 0;
    for (long long i=0;i<t;i++){
        long long k;cin >> k;
        q.push_back(k);
        m = max(m, k);
    }

    vector <long long>diagonals = {1};
    long long increment = 2;
    while (diagonals[diagonals.size()-1] < m){
        diagonals.push_back(diagonals[diagonals.size()-1]+increment);
        increment += 2;
    }
    for (long long i=0;i<t;i++){
        //*Implement binary search to find the middle. 
        long long l=0, r=diagonals.size()-1;
        while(l<=r){
            long long mid = (l+r) / 2;
            if (diagonals[mid]==q[i]){
                l = r = mid;
                break;
            }
            else if (diagonals[mid]<q[i]){
                l = mid+1;
            }
            else if (diagonals[mid]>q[i]){
                r = mid-1;
            }
        }
        //*I think if l and r keep moving then eventually l is gonna be on the bigger one and r is on the smaller one. 
        swap(l, r);
        long long row, col;
        //*this makes it so that l is pointing at the smaller one. 
        if (q[i]<=diagonals[l]+l){
            row = l+1;
            col = l+1 - (q[i] - diagonals[l]);
        }
        else{
            row = r+1 - (diagonals[r]-q[i]);
            col = r+1;
        }

        cout << row << " " << col << endl;
    }

}