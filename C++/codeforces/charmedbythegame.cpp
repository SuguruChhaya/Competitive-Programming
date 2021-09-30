#include <bits/stdc++.h>
using namespace std;

void solve(){
    double a,b;cin >> a >> b;
    double a_a = ceil((a+b)/2), a_b = floor((a+b)/2), b_a = floor((a+b)/2), b_b = ceil((a+b)/2);
    double a_min = abs(a_a-a), b_min = abs(b_a-a);
    double min_ans = min(a_min, b_min);
    double a_max = min(a_a, b) + min(a_b, a), b_max = min(b_a, b)+min(b_b, a);
    double max_ans = max(a_max, b_max);

    set <double> s;

    //*Means they will both cover either even or odd numbers. 
    //*This is pretty straightforward because there will be some overlap but covered by either one from min to max. 
    //? Or is it??
    //!I think running a loop from a_min to a_max might be a better idea and do it separately. 
    //*There might be a block between. 
    
    for (double i=a_min;i<=a_max;i+=2){
        s.insert(i);
    }
    for (double i=b_min;i<=b_max;i+=2){
        s.insert(i);
    }
    cout << s.size() << "\n";
    //!Insert in vector so no trailing spaces. 
    vector <double> v;
    for (auto e:s){
        v.push_back(e);
    }
    for (long long i=0;i<v.size();i++){
        if (i!=v.size()-1){
            cout << v[i] << " ";
        }
        else{
            cout << v[i] << endl;
        }
    }
}
int main(){
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
}