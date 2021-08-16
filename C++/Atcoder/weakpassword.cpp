#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Basically defines what "follows" means. 
    /*
    long long x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;
    */
    //!Just take it in an array. 
    string s;
    cin >> s;
    
    vector <long long> arr;
    for (long long i=0;i<4;i++){
        string temp;
        temp.push_back(s[i]);
        long long t = stoi(temp);
        arr.push_back(t);
    }

    bool weak = true;
    for (long long i=1;i<4;i++){
        if (arr[i]!=arr[i-1]){
            weak = false;
        }
    }
    if (weak==true){
        cout << "Weak" << "\n";
    }
    else{
        weak = true;
        for (long long i=0;i<3;i++){
            if (arr[i]==9){
                if (arr[i+1]==0){

                }
                else{
                    weak = false;
                }
            }
            else{
                if (arr[i+1]==arr[i]+1){
                    
                }
                else{
                    weak = false;
                }
            }
        }
        if (weak==true){
            cout << "Weak" << "\n";
        }
        else{
            cout << "Strong" << "\n";
        }

    }
}