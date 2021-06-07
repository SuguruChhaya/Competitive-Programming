#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    //?I don't know how to declare array with the size given. Says not constant. 
    vector <string> arr;
    string a;
    while (cin >> a){
        arr.push_back(a);
    }
    //!Added into the vector correctly. 
    /*
    for (int i=0;i<arr.size();i++){
        cout << arr[i] << endl;
    }
    */
    //!Another while loop to check through length. 
    int currLength = 0;
    int i =0;
    //*Loop through the entire length. 
    //!Just never print correctly!!
    while (i<n){
        //!Instead of checking then adding, I need to first think of what will happen if I added first. 

        if (currLength +  arr[i].size() > k){
            cout << endl;
            currLength = 0;
        } 
        else{
            if (currLength != 0){
                cout << " ";
            }
            cout << arr[i];
            //!Is the problem with the size??
            currLength += arr[i].size();
            i++;

        
        }
        
    }

}