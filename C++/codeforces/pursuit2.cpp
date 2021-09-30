#include <bits/stdc++.h>
using namespace std;

bool you_win(long long n, long long k, vector <long long> a, vector <long long> b){
    a[100] += k;
    b[0] += k;
    //*Not pointers so doesn't directly change. 
    //long long numChoose = b.size() - floor(b.size() / 4);
    //!Need to keep track of how many elements are in arr. 
    long long numChoose = (n+k) - floor((n+k) /4);
    long long a_sum = 0, b_sum = 0, a_processed = 0, b_processed = 0, a_index=100, b_index=100;
    while (a_processed <numChoose){
        //cout << "a" << endl;
        long long num_add = min(numChoose-a_processed, a[a_index]);
        a_sum += a_index * num_add;
        a_processed += num_add;
        a_index--;
    }

    while (b_processed <numChoose){
        if (b_index==0){
            cout << "";
        }
        long long num_add = min(numChoose-b_processed, b[b_index]);
        b_sum += b_index * num_add;
        b_processed += num_add;
        b_index--;
    }

    return a_sum >= b_sum;
    
}

void solve(){
    long long n;
    cin >> n;
    vector <long long> a (101, 0), b(101, 0);
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        a[temp]++;
    }
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        b[temp]++;
    }

    long long l=0, r=n, last_k=0;
    while (l<=r){
        long long mid=(l+r)/2;
        if (you_win(n, mid, a, b)){
            last_k = mid;
            r = mid-1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << last_k << endl;
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}