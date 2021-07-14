#include <bits/stdc++.h>

using namespace std;


//!I guess the editorial is saying to only expand to the size of the maximum so I don't have to find all 1,000,000. 
//*Then I should consult the queries.
/*
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long n, q;
    cin >>n >> q;
    long long temp1, temp2, temp3;
    vector <vector <long long>> have, pixels;
    for (long long i=0;i<n;i++){
        
        cin >> temp1 >> temp2 >> temp3;
        have.push_back({temp1, temp2, temp3});
    }

    for (long long i=0;i<q;i++){
        cin >> temp1 >> temp2 >> temp3;
        pixels.push_back({temp1, temp2, temp3});
    }

    for (auto element: pixels){
        long long j;
        long long minValue = 9999999999999;
        //*Definitely might be able to do something with this inner loop...
        //!Quickly maybe I might use an implementation of binary search or something. 
        //!It isn't small tricks because 150,000 ^2 is over 10^10 so the easiest way I can think of is to make it nlogn time. 
        for (long long i=0;i<n;i++){
            if (abs(element[0]-have[i][0]) + abs(element[1]-have[i][1]) + abs(element[2]-have[i][2]) < minValue){
                j = i;
                minValue = abs(element[0]-have[i][0]) + abs(element[1]-have[i][1]) + abs(element[2]-have[i][2]);
            }
        }
        cout << j+1 << "\n";
        
        //!All paired together so hard to do loop through first 2 and then find last one in set type thing. 
        //*Can we ever break from the loop? 
    }


}
*/

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);



    //*The info to store: the index of that specific color in 1-indexed. 
    //*The r, g, b value. 
    //*Put the r,g,b value first and last is gonna be index. 
    deque <vector <long long>> queue;
    vector <long long> curr;


    long long n, q;
    cin >>n >> q;
    long long temp1, temp2, temp3;
    //vector <vector <long long>> pixels;
    long long max_value = 0;
    //!Make this 1-indexed for simplicity. 
    for (long long i=1;i<=n;i++){
        
        cin >> temp1 >> temp2 >> temp3;
        //arr[temp1][temp2][temp3] = 0;
        long long temp_max1 = max(temp1, temp2);
        long long temp_max2 = max(temp_max1, temp3);
        max_value = max(temp_max2, max_value);
        queue.push_back({temp1, temp2, temp3, i});
    }
    //*I think I could put either side in the queue but just because of printing order, I should put in the "have" colors in the queue. 

    vector <vector <long long>> queries;
    for (long long i=0;i<q;i++){
        cin >> temp1 >> temp2 >> temp3;
        //pixels.push_back({temp1, temp2, temp3});
        //cout << arr[temp1][temp2][temp3] << endl;
        //!Do not cout now but store in vector and cout later. 
        long long temp_max1 = max(temp1, temp2);
        long long temp_max2 = max(temp_max1, temp3);
        max_value = max(temp_max2, max_value);
        queries.push_back({temp1, temp2, temp3});
    }


    //!Only increase dimensions to the max. 
    vector <vector <vector <long long>>> arr;
    for (long long i=0;i<=max_value;i++){
        vector <vector <long long>> temp_2;
        for (long long j=0;j<=max_value;j++){
            vector <long long> temp_1;
            for (long long k=0;k<=max_value;k++){
                temp_1.push_back(-1);
            }
            temp_2.push_back(temp_1);
        }
        arr.push_back(temp_2);
    }

    while (!queue.empty()){
        curr = queue[0];
        queue.pop_front();
        //*Check whether visited. 
        //!Also check whether in range. 
        //!I don't use GCC so so confusing...
            if ((0<=curr[0] && curr[0]<=max_value) && (0<=curr[1] && curr[1]<=max_value) && (0<=curr[2] && curr[2]<=max_value) && arr[curr[0]][curr[1]][curr[2]]==-1){
                arr[curr[0]][curr[1]][curr[2]] = curr[3];
                queue.push_back({curr[0]+1, curr[1], curr[2], curr[3]});
                queue.push_back({curr[0], curr[1]+1, curr[2], curr[3]});
                queue.push_back({curr[0], curr[1], curr[2]+1, curr[3]});

                queue.push_back({curr[0]-1, curr[1], curr[2], curr[3]});
                queue.push_back({curr[0], curr[1]-1, curr[2], curr[3]});
                queue.push_back({curr[0], curr[1], curr[2]-1, curr[3]});
            }
        
    }

    //*Print out the entire array to see what is happening. 
    /*
    for (long long i=0;i<arr.size();i++){
        for (long long j=0;j<arr[i].size();j++){
            for (long long k=0;k<arr[i][j].size();k++){
                cout << i << " " << j << " " << k << ": " << arr[i][j][k] << endl;
            }
        }
    }
    */

    for (auto query:queries){
        cout << arr[query[0]][query[1]][query[2]] << "\n";
    }

    //!How can there be a segmentation fault??


    //!At the end, I could loop over all the pixels and index them and print out results. 


    //!WDYM try converting grid into graph??

    //!If I am marking stuff of a graph, I need it to be a 3D graph of length 101 (because 0 and 100 are included). 
    //*[red, green, blue]. 


}