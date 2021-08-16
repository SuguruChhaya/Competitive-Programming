#include <bits/stdc++.h>
//!Still really hard for me to understand this. Skip for now. 

using namespace std;
int main(){
    //*Cannot generate all subarrays because 10^5. 
    //*Need a linear solution. 
    long long t;
    cin >> t;

    for (long long i=0;i<t;i++){
        vector <long long> arr;
        vector <long long> prefix_sum;
        long long n;
        cin>>n;
        string s;
        cin >> s;
        
        //*Quadratic might work. 
        for (long long j=0;j<n;j++){
            string temp_string;
            temp_string.push_back(s[j]);
            long long temp = stoi(temp_string);
            arr.push_back(temp);

            if (j==0){
                prefix_sum.push_back(temp);
            }
            else{
                prefix_sum.push_back(prefix_sum[prefix_sum.size()-1]+temp);
            }
        }
        /*
        for (auto e:prefix_sum){
            cout << e << endl;
        }*/


        //!When doing prefix sums, I always have to consider that I have to add the number itself after the subtraction. 
        //!Just need to be real careful with the indexes. 



        //*Create a new arr. 
        map <long long, long long> d;
        //vector <long long> better;
        for (long long j=0;j<n;j++){
            //better.push_back(prefix_sum[j]-j);
            if (d.count(prefix_sum[j]-j)==1){
                d[prefix_sum[j]-j]++;
            }
            else{
                d.insert({prefix_sum[j]-j, 1});
            }
        }

        long long result = 0;
        for (auto p:d){
            //cout << p.first << " " << p.second << endl;
            result += (p.second * (p.second - 1)) / 2;
        }
        cout << result << endl;



    }
}