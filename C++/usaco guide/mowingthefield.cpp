#include <iostream>
#include <vector>
using namespace std;

int main(){

    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    //*I cannot easily construct a 2D vector because 

    //*Since s=10 and n=100, we can go at max 1000 in any direction during that time. 
    //*So I could store in a 2001x2001 vector. 
    //*At every step, I could store the minute that specific grass was cut. 

    //*Every time we re-encounter, we check with the current max re-appearation time. 

    vector <vector <long long>> arr;
    vector <long long> temp_vector;
    for (long long i=0;i<2001;i++){
        temp_vector = {};
        for (long long j=0;j<2001;j++){
            //*Insert a -1 for not visited. 
            temp_vector.push_back(-1);
        }
        arr.push_back(temp_vector);
    }

    long long curr_time = 0;
    long long curr_row = 1000;
    long long curr_col = 1000;
    arr[curr_row][curr_col] = curr_time;
    curr_time++;
    long long n;
    cin >>n;
    char direction;
    long long distance;
    long long x = 9999999999999;
    bool again = false;
    //!Maybe I can set the default max value to -1 instead of 
    for (long long i=0;i<n;i++){
        cin >> direction >> distance;
        //*I think it might be easier to run the loop distance+1 times and include the current time. 
        //!That won't work since at every iteration time will be incremented so I cannot visit same place twice. 

        for (long long j=0;j<distance;j++){
            if (direction=='N'){
                curr_row--;
            }
            else if (direction=='S'){
                curr_row++;
            }
            else if (direction=='E'){
                curr_col--;
            }
            else if (direction=='W'){
                curr_col++;
            }

            //!After movement we have to first check if we have visited. 
            if (arr[curr_row][curr_col] != -1){
                again = true;
                x = min(x, curr_time-arr[curr_row][curr_col]);
            }
            //*After movement settle.
            arr[curr_row][curr_col] = curr_time;
            curr_time++;
        }
        
    }

    if (again==true){
        cout << x << endl;
    }
    else{
        cout << -1 << endl;
    }
}