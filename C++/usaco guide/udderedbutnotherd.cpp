#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    //*Just create a vector of 1000 a's. 
    vector <string> arr (1000, a);
    
    long long checkLetter = 0, i = 0, j=0;

    while (checkLetter<b.size()){
        if (arr[i][j]==b[checkLetter]){
            checkLetter++;
        }
        j++;
        if (j>=a.size()){
            i++;
            j = 0;
        }
    }
    //*I think the exception is when the last letter is 'z' so it just ended and i just incremented.
    //Then we have to subtract. 
    if (j==0){
        i--;
    }
    cout << i+1;
}