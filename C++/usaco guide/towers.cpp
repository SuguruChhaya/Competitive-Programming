#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    //*Pretty obvious greedy. 
    //!If larger, create new tower. 
    //*If smaller, place in a the smallest possible place I can place it in so I don't "waste" good towers. 
    vector <long long> on_top;
    
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        //*Just because it is larger than the prev doesn't mean that it cannot be placed. 
        //*Either loop through all the towers or store in var. 
        if (i==0){
            on_top.push_back(temp);
        }
        else{
            /*
            long long curr=0;
            while (curr<on_top.size() && on_top[curr]<=temp){
                curr++;
            }
            if (curr<on_top.size()){
                on_top[curr]=temp;
            }
            else{
                on_top.push_back(temp);
            }
            */
            long long l=0, r=on_top.size()-1, last_valid=-1;
            while (l<=r){
                long long mid = (l+r) / 2;
                if (on_top[mid]<=temp){
                    l=mid+1;
                }
                else{
                    last_valid = mid;
                    r = mid-1;
                }
            }
            //The last mid value will be the valid 
            //!No, it's the last valid place I visit
            if (last_valid==-1){
                //*No valid # so I need to append
                on_top.push_back(temp);
            }
            else{
                on_top[last_valid]=temp;
            }
        }
    }
    cout << on_top.size() << endl;
}