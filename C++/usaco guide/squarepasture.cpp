#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //*More simple to think of constant solution. 
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x11, y11, x12, y12, x21, y21, x22, y22;

    cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;

    //*Minimum x must be either x11 or x21. 
    int min_x = min(x11, x21);
    //*Maximum x. 
    int max_x = max(x12, x22);
    //*Minimum y.
    int min_y = min(y11, y21);
    //*Maximum y. 
    int max_y = max(y12, y22);
    //*Has to be a square pasture. 
    //*Then square the maximum of the 2 sides. 
    cout << pow(max((max_x-min_x), (max_y-min_y)), 2); 
}