#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    //*I see just brute force through all of them. 
    long long n, x, y;
    cin >> n;
    vector <vector<long long>> points;
    for (long long i=0;i<n;i++){
        cin >> x;
        points.push_back({x, 0});
    }
    for (long long i=0;i<n;i++){
        cin >> y;
        points[i][1] = y;
    }
    long long result =0;
    long long temp;
    for (long long p1=0;p1<n;p1++){
        for (long long p2=p1;p2<n;p2++){
            //*Euclidian distance so I have to use pythagorean theorem. 
            temp = pow(abs(points[p1][0]-points[p2][0]), 2) + pow(abs(points[p1][1]-points[p2][1]), 2);
            result = max(result, temp);
        }
    }

    cout << result << endl;
}