#include <iostream>
#include <vector>
using namespace std;

int main(){
    //*How am I gonna store the info...? 
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    //!I guess I kind of wanna optimize this thing a little tho...
    //*I could store in map so I know location for each session immediately I guess. 
    long long k, n, temp;
    cin >> k >> n;
    vector <vector <long long>> arr;
    vector <long long> temp_vector;

    for (long long i=0;i<k;i++){
        temp_vector = {};
        for (long long j=0;j<n;j++){
            cin >> temp;
            temp_vector.push_back(temp);
        }
        arr.push_back(temp_vector);
    }
    long long first_rank, second_rank;
    //*After receiving data, have to match. 
    bool win_overall;
    long long result = 0;
    //!Goes both ways!!
    for (long long i=1;i<=n;i++){
        //*Must be different cow matching. 
        for (long long j=1;j<=n;j++){
            //*Just hardcore bruteforce through everything and check the vector every time. 
            win_overall = true;
            for (long long session=0;session<k;session++){
                for (long long cow=0;cow<n;cow++){
                    if (arr[session][cow]==i){
                        first_rank = cow;
                    }
                    //!Since same values might be passed, it cannot be an else if. 
                    //*Because we want second_rank to be the same as first rank since I have that covered. 
                    //*If not it will just carry on previous value. 
                    if (arr[session][cow]==j){
                        second_rank = cow;
                    }
                }
                //*Now check whether greater or not. 
                if (first_rank>=second_rank){
                    win_overall = false;
                    break;
                }
            }
            if (win_overall==true){
                result++; //?Why is 4, 4 recognized here? 
            }
        }
    }
    cout << result << endl; 
}