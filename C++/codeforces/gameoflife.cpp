#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long numTests;
    cin >> numTests;
    long long n, m;
    string s;
    vector <char> arr;
    vector <char> temp;
    bool can_make;
    //!Not reading in the input correctly somehow. 
    //*Kind of did expect time limit exceed. 
    //!I can detect when further iterations will be useless since we checked everything. 
    for (long long i=0;i<numTests;i++){
        cin >> n >> m >> s;
        arr = {};
        for (auto x:s){
            arr.push_back(x);
        }

        //*Naive way is to just simulate but at some point we might reach a point where no more iterations are really helpful. 
        for (long long j=0;j<m;j++){
            //*To only simulate that one round, copy the vector. 
            temp = arr;
            //!Check whether there are any meaningful moves to make. 
            can_make = false;
            for (long long k=0;k<n;k++){
                //*Iterate through all and change. 
                if (arr[k]=='0'){
                    //!The elements on the edge are special cases. 
                    if (k==0 && arr[1]=='1'){
                        temp[0] = '1';
                        can_make = true;
                    }
                    else if (k==n-1 && arr[n-2]=='1'){
                        temp[k] = '1';
                        can_make = true;
                    }
                    else if (arr[k-1]=='1' && arr[k+1]=='0'){
                        temp[k] = '1';
                        can_make = true;
                    }
                    else if (arr[k-1]=='0' && arr[k+1]=='1'){
                        temp[k] = '1';
                        can_make = true;
                    }
                }
            }
            if (can_make==false){
                break;
            }
            arr = temp;
        }
        for (auto x:arr){
            cout << x;
        }
        cout << "\n";
    }
}