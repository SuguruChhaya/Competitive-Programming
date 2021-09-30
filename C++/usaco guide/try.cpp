#include <bits/stdc++.h>

using namespace std;

struct Car{
    long long a=0;
};

int main(){
    //!There is some kind of issue with booleans. 
    //!Now I get it!!
    //*Unlike Python, I cannot do a < b < c Instead, I have to do it explicitly separately. 
    vector <long long> arr = {1};
    arr.resize(2, 0);
    //!It just fills it up. 

    arr.insert(arr.begin()+2, 2);
    for (auto e:arr){
        cout << e << endl;
    }
}
