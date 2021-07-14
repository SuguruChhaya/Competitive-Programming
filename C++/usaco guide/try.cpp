#include <bits/stdc++.h>

using namespace std;

struct Car{
    long long a=0;
};

int main(){
    //!There is some kind of issue with booleans. 
    //!Now I get it!!
    //*Unlike Python, I cannot do a < b < c Instead, I have to do it explicitly separately. 
    vector <Car> arr;
    for (long long i=0;i<2;i++){
        Car temp;
        arr.push_back(temp);
    }

    arr[0].a = 5;

    for (long long i=0;i<2;i++){
        cout << arr[i].a << endl;
    }

    //!The object creation is working properly. 
    bool a = "abc"=="abc";
    cout <<  a << endl;

    set <long long> h;
    h.insert(5);
    h.insert(3);
    h.insert(6);

    for (auto e:h){
        cout << e << endl;
    }


}
