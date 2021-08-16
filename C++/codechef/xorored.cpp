#include <bits/stdc++.h>

using namespace std;

vector <long long> decToBinary(long long n){
    vector <long long> result;

    while (n > 0){
        result.push_back(n%2);
        n /= 2;
    }

    return result;
}

long long binToDecimal(vector <long long> arr){
    long long result = 0;
    for (long long i=0;i<arr.size();i++){
        result += arr[i] * (pow(2, i)); //*First part is 0 or 1. Second part is the exponent. 
    }
    return result;
}

void show2D(vector <vector <long long>> arr){
    for (long long i=0;i<arr.size();i++){
        for (long long j=0;j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <long long> decimal;
        vector <vector <long long>> binary;
        long long max_binary_size = 0;
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            decimal.push_back(temp);
            //*Kind of get it. 
            //*As usual, I need a decimal to binary converter. 

            //*I need the maximum size of the converted result. 
            auto v = decToBinary(temp);
            long long length = v.size();
            max_binary_size = max(max_binary_size, length);
            binary.push_back(v);
            
        }


        vector <long long> x;
        vector <long long> mini;
        //*Will contain the result in reverse binary form. 
        //*Index doesn't matter so just auto. 
        /*
        for (auto b:binary){
            for (long long j=0;j<max_binary_size;j++){
                long long curr;
                if (j>=b.size()){
                    curr = 0;
                }
                else{
                    curr = b[j];
                }

            }
        }
        */
        //show2D(binary);
        for (long long j=0;j<max_binary_size;j++){
            //*Check that index for all.
            bool zero=0, one=0;
            //*If both exists then no chance. 
            for (auto b:binary){
                long long curr;
                if (j>=b.size()){
                   curr = 0;
                }
                else{
                    curr = b[j];
                }

                if (curr==0){
                    zero = 1;
                }
                else if (curr==1){
                    one = 1;
                }
            }
            //*Check and insert into result. 
            if (zero && one){
                mini.push_back(1); //*Since there is mismatch so there will be a 1. 
                x.push_back(1); //*Doesn't really matter which one I push back.
            }
            else if (zero){
                mini.push_back(0);
                x.push_back(0);
            }
            else if (one){
                mini.push_back(0);
                x.push_back(1);
            }
        }
        //cout << x[0] << x[1] << x[2] << endl;
        //cout << mini[0] << mini[1] << mini[2] << endl;
        //*Now just convert them back to decimal. 
        long long x_dec = binToDecimal(x);
        long long mini_dec=binToDecimal(mini);
        cout << x_dec << " " << mini_dec << endl;
    }
}