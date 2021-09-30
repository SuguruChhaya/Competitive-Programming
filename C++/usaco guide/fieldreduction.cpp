#include <bits/stdc++.h>
using namespace std;

int main(){
    //!Really close but some errors...
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    long long n;
    cin >> n;
    vector <vector <long long>> x_sort(n, vector <long long> (2)), y_sort(n, vector <long long> (2));
    for (long long i=0;i<n;i++){
        cin >> x_sort[i][0] >> x_sort[i][1];
        y_sort[i][0] = x_sort[i][1];
        y_sort[i][1] = x_sort[i][0];
    }

    sort(x_sort.begin(), x_sort.end());
    sort(y_sort.begin(), y_sort.end());

    long long result = 9999999999999999;

    set <vector <long long>> s = {x_sort[0], x_sort[n-1], {y_sort[0][1], y_sort[0][0]}, {y_sort[n-1][1], y_sort[n-1][0]}};
    //*My method was the lazy way but I could have kept track of the second smallest and all that. 
    for (auto v:s){
        vector <long long> edges = {99999, 99999, 0, 0};
        for (auto e:x_sort){
            if (v!=e){
                edges[0] = min(edges[0], e[0]);
                edges[1] = min(edges[1], e[1]);
                edges[2] = max(edges[2], e[0]);
                edges[3] = max(edges[3], e[1]);
            }
        }
        result = min(result, (edges[2]-edges[0]) * (edges[3]-edges[1]));
    }
    cout << result << endl;
}