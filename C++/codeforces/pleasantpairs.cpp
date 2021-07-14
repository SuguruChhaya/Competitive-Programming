#include <iostream>
#include <vector>
using namespace std;

int main(){
    //*The fact that all integers are distinct must be doing something. 
    //*Has to be done in linear time otherwise TLE. 

    //*a_i and a_j must be distinct. That I know. 
    //*Could create big array for existence/index location but how could that help? 

    //!I can kind of guess certain strategies to speed things up by limiting checking numbers...
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;

    for (long long i=0;i<t;i++){
        //!Create an index vector so I can loop through all the possible values. 
        //*Index: number -1, value: index it appeared in (1-indexed). 
        //*Doing this because i+j severely restricts the number I could multiply to get. 
        long long n, temp;
        long long result = 0;
        cin >> n;
        //*Store in vector for each. 
        vector <long long> arr;
        //*Initialize upto 2*n elements. 
        //!There may be some index error so might add 1 element to the front. 
        arr.push_back(-1);
        for (long long j=0;j<2*n;j++){
            arr.push_back(-1);
        }
        //!1-indexed. 
        for (long long j=1;j<=n;j++){
            cin >> temp;
            //!The max number a_i and a_j can be. 
            long long limit = 2 *j / temp;

            for (long long number=1;number<=limit;number++){
                //*arr[number] cannot be negative though. 
                if (arr[number] != -1 && number * temp == j+arr[number]){
                    result++;
                }
            }
            //*Check before pushing back. 
            /*
            for (long long k=1;k<=arr.size();k++){
                if (j+k==temp*arr[k-1]){
                    result++;
                }
            }
            */
            arr[temp] = j;
        }
        cout << result << "\n";
    }
    
}