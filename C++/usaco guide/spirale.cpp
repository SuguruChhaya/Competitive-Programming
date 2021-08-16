#include <bits/stdc++.h>
using namespace std;

bool is_completed(vector <vector <long long>> arr){
    for (long long i=0;i<arr.size();i++){
        for (long long j=0;j<arr[i].size();j++){
            if (arr[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    vector <vector <long long>> spirals;
    for (long long i=0;i<k;i++){
        long long x, y, t;
        cin >> x >> y >> t;
        //*Store all the spiral locations. 
        
        //*These will be starting numbers. 
        //!Keep track of next direction. 
        //*If counter-clockwise, the direction is up. 
        //*0: up, 1:down, 2:left, 3:right. 
        //!Actually, they both move up initially. 
        spirals.push_back({x, y, t, 0});
        

    }

    //*Create the vector initialized with 0s. 
    vector <vector <long long>> arr;
    for (long long i=0;i<n;i++){
        vector <long long> temp;
        for (long long j=0;j<m;j++){
            temp.push_back(0);
        }
        arr.push_back(0);
    }

    //!Too painful of an implementation problem. 

    long long number = 1;
    while (!is_completed(arr)){
        //!To make modifications, I need to loop by index. 
        for (long long s=0;s<k;s++){
            if (spirals[s][0] >=0 && spirals[s][0] < n && spirals[s][1] >=0 && spirals[s][1]<m && arr[spirals[s][0]][spirals[s][1]]==0){
                arr[spirals[s][0]][spirals[s][1]]=number;
            }
            if (spirals[s][3]==0){
                spirals[s][0]--;
            }
            else if (spirals[s][3]==1){
                spirals[s][0]++;
            }
            else if (spirals[s][3]==2){
                spirals[s][1]--;
            }
            else if (spirals[s][3]==3){
                spirals[s][1]++;
            }
            
            //*Now adjust. 
            //!It really just follows a pattern right?

            /*
            if (spirals[spiral[0] >=0 && spiral[0]<n && spiral[1] >= 0 && spiral[1] <m && arr[spiral[0]][spiral[1]]==0){
                arr[spiral[0]][spiral[1]]=number;
            }
            //!We are going to follow the instructions from the previous but change the instructions after moving. 
            if (spiral[3]==0){
                //*Going north. 
                spiral[0]--;
            }
            else if (spiral[3]==1){
                //*Going south. 
                spiral[0]++;
            }
            else if (spiral[3]==2){
                //*Going left. 
                spiral[1]--;
            }
            else if (spiral[3]==3){
                spiral[1]++;
            }
            */
        }
    }

    //*In each step, the counter moves once anyways. 
    
    //!Totally get the square thingy. 
    //!The generic spiral technique could work IF the first step (0) is ignored. 
    //*Wouldn't it just be easier to just simulate for each of the 
    /*
    while (!is_completed(arr)){
        for (auto spiral:spirals){
            //*First check whether in bounds and that there is no number in that spot. 
            if (spiral[0] >=0 && spiral[0]<n && spiral[1] >= 0 && spiral[1] <m && arr[spiral[0]][spiral[1]]==0){
                arr[spiral[0]][spiral[1]]=number;
            }
            //*Move to the next location. 
            //!This is done regardless of whether it is in range or not. 
            //*Several help articles for when it is an inward going martrix but not so much if it starts in the middle. 
            if (spiral[2]==0){
                //*Moving clockwise
                //*If there is nothing around, move up. 
                if (arr[spiral])
            }
        }
    }
    */
    //!Tough that the memory limit is 64MB. Might not be good to create so many 2D arrays. 
    //*Instead just simulate the entire process I guess. 
    /*
    for (auto spiral:spirals){
        //*I guess I could 
    }
    */
}