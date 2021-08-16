#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);


    //!Or, we could keep flipping the uneven part every single time (even though that would be less efficient because ^2 time. )
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    long long result = 0;
    //*Have to loop through and see how many efficient swaps I can do. 
    long long index = 0;
    while (index < n){
        //*First check that they are not equal. 
        if (a[index]==b[index]){
            index++;
        }
        else{
            //!It doesn't have to remain in the same letters but they just have to be different. 
            while (index < n && a[index]!=b[index]){
                index++;
            }
            result++;
        }
    }

    cout << result << endl;
}