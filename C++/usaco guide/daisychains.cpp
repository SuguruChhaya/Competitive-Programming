#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <long long> arr;
    long long n, temp;
    cin >>n;
    long long curr_sum=0;
    vector <long long> prefix_sum;
    for (long long i=0;i<n;i++){
        cin >> temp;
        arr.push_back(temp);
        curr_sum+=temp;
        prefix_sum.push_back(curr_sum);

    }

    //*Naive is O(n^3) but can easily be be improved to O(n^2)?
    //*Don't think because it has to include it.
    long long result = 0; 
    double average; //!Double works. 
    for (long long i=0;i<n;i++){
        for (long long j=i;j<n;j++){
            average = (prefix_sum[j]-prefix_sum[i]+arr[i]) / ((j-i+1) * 1.0);
            for (long long k=i;k<=j;k++){
                if (arr[k]==average){
                    result++;
                    break;
                }
            }
        }
    }
    cout << result << endl;     

}