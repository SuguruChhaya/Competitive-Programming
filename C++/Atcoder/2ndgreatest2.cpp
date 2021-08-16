#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    /*
    vector <vector <long long>> coords, x_coords, y_coords;
    vector <long long> small;
    //*Store index as well as smallest values. 
    //pair <long long, long long> s1, s2, l1, l2;
    for (long long i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        coords.push_back({x, y});
        //*If the smallest does not exist.
        //!If sorting, I need to do it for both x and y-coords. 
        x_coords.push_back({x, i});
        y_coords.push_back({y, i});
    }   
    sort(x_coords.begin(), x_coords.end());
    sort(y_coords.begin(), y_coords.end());

    //*If multiple houses can have the same coordinates, wouldn't it be better to 
    */

    vector <vector <long long>> arr;
    set <long long> ids;
    for (long long i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        arr.push_back({x, y, i});
    }

    for (long long k=0;k<2;k++){
        sort(arr.begin(), arr.end());
        for (long long i=0;i<2;i++){
            ids.emplace(arr[i][2]);
            ids.emplace(arr[n-1-i][2]);
           
        }
        //!So first sort based on x then sort based on y. 
        for (auto &v:arr){
           swap(v[0], v[1]);
        }
    }

    vector <pair <long long,long long>> b;
    for (auto v:arr){
        if (ids.count(v[2]) != 0){
            //*Meaning this exists in the original arr. 
            //*Adding all the ones that exist. 
            b.push_back({v[0], v[1]});
        }
    }
    vector <long long> d;
    for (long long i=0;i<b.size();i++){
        for (long long j=i+1;j<b.size();j++){
            d.emplace_back(max(abs(b[i].first - b[j].first), abs(b[i].second - b[j].second)));
        }
    }
    sort(d.begin(), d.end());
    cout << d[d.size()-2] << endl;
}