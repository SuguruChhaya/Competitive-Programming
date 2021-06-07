#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    //!Kind of like finding the equation...
    //*Does say that the answer can be unique.. 
    
    //!Having the values, I think it is actually pretty easy. 
    //*After sorting, the 2 smallest values are a and b and the largest value is a+b+c. 
    //Just subtract and find the answer. 

    //*Would be definitely easier if I can receives files like standard input. 
    //freopen("promote.in", "r", stdin);

    //!Honestly, reading from standard input is so much easier. 
    /*
    int x;
    int y;
    vector <int> arr1;

    while (cin >> x){
        arr1.push_back(x);
    }

    for (int i=0;i<2;i++){
        cout << arr1[i] << endl;

    }
    */


    //int arr [7];
    //int largest;
    //int smallest;
    //int second;
    /*
    for (int i=0;i<7;i++){
        //Direction matters.
        //!If separated by space I can just get and add it into array. 
        cin >> arr[i];
        if 
    }*/

    //?Do sorting. Need to include algorithm. 
    sort(arr, arr+7);

    int a = arr[0];
    int b = arr[1];
    int c = arr[6] - a - b;

    cout << a << " " << b << " " << c;

    /*
    char temp [100];
    cin.getline(temp, 100);
    vector <char> arr;
    int i = 0;
    //!I think the casing to int is costing the problem. 
    //!Also, 
    while (i < 100){
        //*I am gonna try adding if not a space. 
        if (temp[i] != ' '){
            arr.push_back(temp[i]);
        }
        //cout << temp[i] << endl;
        i++;
    }
    //!Still really not adding the correct values. 
    //*So much random stuff is pushed back. 
    for (int i=0; i<7;i++){
        cout << arr[i] << endl;
    }
    */

    
}