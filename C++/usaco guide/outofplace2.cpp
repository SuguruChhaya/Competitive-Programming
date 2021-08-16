#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Interesting approach that if I remove one element the entire list will be in order. 
    //!Never thought of such an easy solution. 

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;    
        //*We don't know which one is the out of place one because could be increasing but still out of place. 
        arr.push_back(temp);
    }
    long long wrong_index = -1;
    for (long long i=0;i<n;i++){
        //*Index we are gonna skip. 
        auto copy = arr;
        copy.erase(copy.begin()+i);
        auto sorted_copy = copy;
        sort(sorted_copy.begin(), sorted_copy.end());
        if (copy==sorted_copy){
            //*That is the element out of place. 
            wrong_index = i;
        }
    }

    long long result =0;
    //!Could cause a segmentation error!
    while (!((wrong_index + 1 < n && arr[wrong_index] <= arr[wrong_index+1]) && (wrong_index-1 >= 0 && arr[wrong_index-1] <= arr[wrong_index]))){
        //*Consider smaller case too. 
        //*I can try going both ways and either will work. 
        //!Lesson is to never forget your brackets I guess cuz C++ doesn't do that for me. 
        if (!(arr[wrong_index-1] <= arr[wrong_index])){
            long long l = wrong_index-1, left_value = arr[wrong_index-1];
            while (l >= 0 && arr[l]==left_value){
                //*Small element got pushed to the right. 
                //!At least moves 1 to the right all the time. 
                l--;
            }
            l++;
            long long temp = arr[l];
            arr[l] = arr[wrong_index];
            arr[wrong_index] = temp;
            wrong_index = l;
            //cout << "stuck" << endl;
        }
        else{
            long long r = wrong_index+1, right_value = arr[wrong_index+1];
            while (r < n && arr[r]==right_value){
                r++;
            }
            r--;
            long long temp = arr[r];
            arr[r] = arr[wrong_index];
            arr[wrong_index] = temp;
            wrong_index = r;
            //cout << "stuck2" << endl;
        }
        result++;
        

    }
    cout << result << endl;
}