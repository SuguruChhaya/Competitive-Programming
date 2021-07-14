#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <long long> a, b;
        long long sum_a, sum_b;
        sum_a = sum_b = 0;
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            a.push_back(temp);
            sum_a+=temp;
        }

        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            b.push_back(temp);
            sum_b += temp;
        }

        //*If the sum of all the elements are different then no way but otherwise it is always possible. 
        if (sum_a!=sum_b){
            cout << -1 << endl;
        }
        else{
            vector <long long> differences;
            vector <vector <long long>> result;
            for (long long j=0;j<n;j++){
                differences.push_back(a[j]-b[j]);
            }
            //!INCREASE the j-th element by 1. 

            for (long long curr_i=0;curr_i<n;curr_i++){
                long long curr_j = 0;
                while (differences[curr_i] > 0){
                    if (differences[curr_j] < 0){
                        long long numTransfer = min(differences[curr_i], abs(differences[curr_j]));
                        for (long long transfer=0;transfer<numTransfer;transfer++){
                            result.push_back({curr_i+1, curr_j+1});
                            differences[curr_i]--;
                            differences[curr_j]++;
                        }
                    }
                    curr_j++;
                }
            }

            cout << result.size() << endl;
            for (auto e:result){
                cout << e[0] << " " << e[1] << endl;
            }

            /*
            for (long long curr_i=0;curr_i<n;curr_i++){
                if (a[curr_i] > 0){
                    //*Only pick up i when it is smaller. 
                    //!More appropriate to put it in a while loop since if forloop it will go on forever and a[curr_i] may decrease so much but keep going. 

                    for (long long curr_j=0;curr_j<n;curr_j++){
                        if (differences[curr_j] <0){
                            long long numTransfer = min(a[curr_i], abs(a[curr_j]));
                            for (long long transfer=0;transfer<numTransfer;transfer++){
                                result.push_back({curr_i+1, curr_j+1}); //!1-index.
                            }

                            //*Decrease the actual values. 

                        }
                    }
                }
            }

            //*I guess it is always possible to move it. 
            long long curr_i = 0;
            long long curr_j = 1;
            //!We have to consider the case that it is bigger too. 
            //*I think it might be better if I stored how much it is larger/smaller in array and process that. 
            while (curr_i< n){
                //*We will process curr_i until it reaches the end. 
                while (a[curr_i] != b[curr_i]){
                    //*Wanna take from the next value since everything to the left has been adjusted.
                    curr_j=curr_i+1;
                    while (curr_j < n && curr_j )
                }
            }
            */
        }
    }
}