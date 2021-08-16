#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <long long> arr;
        map <long long, long long> d;
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            arr.push_back(temp);
            if (d.count(temp)==1){
                d[temp]++;
            }
            else{
                d.insert({temp, 1});
            }
        }

        //*If the numbers are all distinct, I can just choose one x value and all the other y-values are going to be different. 
        //*I think the problem is when multiple same values. 
        //*Integer x can be split in x-1 different ways. 
        //*So if there are more than x-1 (meaning starting from x) numbers of x, we will not be able to place the exceeding part. 

        //*Try with dict but if too slow, use a frequency array. 
        long long result = 0;
        for (auto p:d){
            result += min(p.first-1,p.second);
        }
        cout << result << endl;
    }
}