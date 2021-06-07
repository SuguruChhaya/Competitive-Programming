#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //*The trick is to calculate exactly in K steps. 
    //*I realized that there is manhattan distance but I can also keep adding 2 to that distance and get there. 
    long long a, b, c, d, k, numTests;
    cin >> numTests;
    long long manhattan_distance;
    //cout << -2 % 2;
    for (long long i=0;i<numTests;i++){
        cin >> a >> b>>c>>d>>k;
        //*I probably didn't anticipate the fact that he can go back to the same cell multiple times...
        //*They are not the same cell. 
        manhattan_distance = abs(a-c) + abs(b-d);
        //!Maybe I didn't consider the case where it goes to a negative number. 
        if ((k-manhattan_distance) >= 0 && (k-manhattan_distance) % 2 == 0){
            cout << "YES" << "\n";
        } 
        else{
            cout << "NO" << "\n";
        }
    }
}