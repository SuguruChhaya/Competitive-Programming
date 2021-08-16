#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//*Some weird whitespace issue. 
int main(){
    //*I feel like the algo is gonna go down to O(n**2)
    //*Quick time-saving tricks: first precalculate the sum so I only have to calculate for one side. 
    //*O(n) is guaranteed because we have to choose l for every place. 
    //*I feel like we might use a prefix sum array to store the sum from the point. 
    //*Just use the prefix table and total sum. 

    long long n;
    long long s;
    vector <long long> arr;
    //*In fact, the total sum is the last element in the prefix sum. 
    vector <long long> prefix_sum;
    cin >> n;
    //long long total_sum=0;
    for (long long i=0;i<n;i++){
        cin >> s;
        
        arr.push_back(s);
        if (i==0){
            prefix_sum.push_back(s);
        }
        else{
            prefix_sum.push_back(s+prefix_sum[i-1]);
        }
    }
    long long curr_min;
    long long curr_split;
    long long team_a;
    //!Maybe I can create a double length array and prefix. 
    
    for (long long i=0;i<n;i++){
        arr.push_back(arr[i]);
        prefix_sum.push_back(arr[arr.size()-1]+prefix_sum[prefix_sum.size()-1]);
    }
    for (int i=0;i<n;i++){
        curr_min = INT_MAX;
        //*Do every check. 
        //!Outer loop is relatively easy to understand. 
        //*But inner loop should go back to the beginning too. 
        curr_split = i;
        for (int j=0;j<n;j++){
            //*In this context, j just keeps track of how many operations. Have a separate value that updates.
            //*Though checking unnecessary, looping through is OK.
            team_a = prefix_sum[curr_split] - prefix_sum[i] + arr[i]; //!I see, the prefix sum doesn't necessarily work well when starting elements go to the end. 
            curr_min = min(curr_min, abs(team_a - (prefix_sum[n-1]-team_a)));
            curr_split++;
        }
        cout << curr_min;
        /*
        if (i!=n-1){
            cout << " ";
        }
        */
    }
}