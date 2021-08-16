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

    cout << '1' - '0' << endl;

    cout << ('ab' < 'ac') << endl;

    pair <long long, long long> p1;
    p1.first = 0;
    p1.second = 1; 
    auto p2 = p1;
    p2.first = -1;
    p2.second = 3;

    vector <pair <long long, long long>> arr2;
    arr2.push_back(p1);
    arr2.push_back(p2);

    sort(arr2.begin(), arr2.end());
    cout << arr2[0].first << " " << arr2[0].second << endl;

    vector <vector <long long>> f;
    f.push_back({1, 2});
    //!Doesn't change when it is auto. 
    for (auto e:f){
        e[1]++;
    }
    cout << f[0][1] << endl;
}
