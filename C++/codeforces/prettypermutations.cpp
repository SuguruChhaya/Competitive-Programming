#include <iostream>
#include <vector>
using namespace std;

int main(){
    //*If the number is even, the neightbors can just switch and it would be n moves because each moves once. 
    //*If odd, then we can just shift by one. 
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <long long> arr;
        for (long long j=1;j<=n;j++){
            arr.push_back(j);
        }
        if (n % 2==0){
            //*Swap. 
            long long temp1;
            for (long long j=0;j<n;j+=2){
                //*Move by each 2. 
                temp1 = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp1;
            }
        }
        else{
            long long temp, prev, curr;
            //*Actually the first element requires special treatement. 
            //!Odd works a little differently. 
            //*We can just rotate the last 2 elements.
            //!Upto that point, we can just do the neighbor swapping but after that we have to rotate the 3. 
            for (long long j=0;j<n-3;j+=2){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

            //!Just hardcode since we only have 3 elements left. 
            //!At this point array size will always be 3 or larger. 
            long long temp1, temp2, temp3;
            temp1 = arr[n-1];
            temp2 = arr[n-2];
            temp3 = arr[n-3];
            arr[n-1] = temp2;
            arr[n-2] = temp3;
            arr[n-3] = temp1;
            /*
            for (long long j=0;j<n;j++){
                curr = arr[j];
                if (j==0){
                    arr[j] = arr[n-1];
                }
                else{
                    arr[j] = prev;
                }
                prev = curr;
                //!Should work...
            }
            */
        }

        for (long long j=0;j<n;j++){
            cout << arr[j] << " ";
        }
        cout << "\n";
    }
}