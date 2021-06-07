#include <iostream>
#include <vector>
using namespace std;

int main(){
    //*I think I can use similar logic as the O(1) algo in previous problem. 

    //*Honestly for this problem, I think it would just be easier to use vector and calculate the longest continuous one. 
    //*Can be seen: 1
    //*Cannot be seen (obstructed): 0.
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int lx1, ly1, lx2, ly2, cx1, cy1, cx2, cy2;

    cin >> lx1 >> ly1 >> lx2 >> ly2 >> cx1 >> cy1 >> cx2 >> cy2;

    vector <vector <int>> arr;
    vector <int> temp;
    //*Since they are in coordinate form, there are 2000 max. 
    for (int i=0;i<2000;i++){
        temp = {};
        for (int j=0;j<2000;j++){
            //*Since all of them initially irrerlevant, I should do a 0
            temp.push_back(0);
        }
        arr.push_back(temp);
    }

    //*Show where we can see. 
    for (int i=lx1;i<lx2;i++){
        for (int j=ly1;j<ly2;j++){
            //*Can be seen so 1. 
            arr[1000+i][1000+j] = 1;
        }
    }

    //*Cover where we cannot see. 
    for (int i=cx1;i<cx2;i++){
        for (int j=cy1;j<cy2;j++){
            arr[1000+i][1000+j] = 0;
        }
    }

    //*Now check what the largest continuing row and col is. 
    //*Easier to do in separate loop. 
    int longest_x = 0;
    int longest_y = 0;
    int x;
    int y;
    int curr_x;
    int curr_y;
    //*I am doing things the opposite way. 
    //!Stupid ad hoc. First try easy way and if it doesn't work try mathy way. 
    //array <vector <int>, 5> a; -> array class is more flexible but why use it?
    for (int x=0;x<arr.size();x++){
        y = 0;
        curr_y = 0;
        while (y < arr[x].size()){
            if (arr[x][y]==1){
                curr_y++;
            }
            else{
                longest_y = max(longest_y, curr_y);
                curr_y = 0;
            }
            y++;
        }
        //*Check at the last end. 
        longest_y = max(longest_y, curr_y);


        //*I have to consider the case where we start at the end. 
    }

    for (int y=0;y<2000;y++){
        x = 0;
        curr_x = 0;
        while (x < arr.size()){
            if (arr[x][y]==1){
                curr_x++;
            }
            else{
                longest_x = max(longest_x, curr_x);
                curr_x = 0;
            }
            x++;
        }
        //*Check at the last end. 
        longest_x = max(longest_x, curr_x);
    }

    cout << (longest_x * longest_y);
    




}