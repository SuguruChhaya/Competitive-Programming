#include <bits/stdc++.h>
using namespace std;

/*
My code for solving this problem is below (in C++, but if you speak Java or Python it should hopefully still be easy to follow). I first wrote a helper function target(i) that computes to whom cow i passes the ball. Using this, I count for each cow i the number of cows passing to her. If this number is zero, the cow is a "source" -- she passes the ball away but never gets a ball back. Such cows all need their own starting ball from Farmer John.

The only other special case where Farmer John needs to distribute a ball initially is to a pair of adjacent cows that both pass to each-other, and where neither receives a pass from anyone else, so this pair is isolated from the rest of the game.
*/

int main(){

    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    long long n;
    cin >> n;
    vector <long long> arr;
    vector <long long> send_arr; //!Stores who receives from who. Max size of inner vector is 2. 
    vector <vector <long long>> received;

    //*Really, I could receive from different places. 
    //*Just received or not doesn't help us determine. 
    //*Need more specific info to check whether isolated trap or not. 

    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        //bool_arr.push_back(0);
        send_arr.push_back(-1);
        //initially push back an empty array. 
        received.push_back({});
    }
    sort(arr.begin(), arr.end());

    //*Get rid of the case of only 1 cow since otherwise segmentatione rror. 
    if (arr.size()==1){
        cout << 1 << endl;
    }
    else{
        //!Probably easier doing sending.

        //*Mark which vectors received with bool arr. 
        for (long long i=0;i<n;i++){
            if (i==0){
                //*Better to use index. 
                send_arr[i] = i+1;
                received[i+1].push_back(i);
            }
            else if (i==n-1){
                send_arr[i] = i-1;
                received[i-1].push_back(i);
            }
            else{
                if (abs(arr[i]-arr[i-1]) <= abs(arr[i]-arr[i+1])){
                    //*Going left. 
                    send_arr[i] = i-1;
                    received[i-1].push_back(i);
                }
                else{
                    send_arr[i] = i+1;
                    received[i+1].push_back(i);
                }
            }
        }
        
        //*Check received arr. 
        /*
        for (auto elem:received){
            cout << elem << endl;
        }
        */
        

        //*Actually, we are only sending to one person so no need vector. 
        long long result = 0;
        for (long long i=0;i<n;i++){
            if (received[i].size()==0){
                result++;
            }
            else{
                //*Check whether the current index and the next index are stuck. 
                //*Cannot be at i==n-1
                if (i != n-1){
                    //*We have to check their receiving. 
                    //*If they are sending out to each other
                    /*
                    if (i == send_arr[send_arr[i+1]]){
                        result++;
                    }*/
                    if (received[i].size()==1 && received[i+1].size()==1 && received[i][0]==i+1 && received[i+1][0]==i){
                        result++;
                    }
                }
            }
        }
        cout << result << endl;
    }


}