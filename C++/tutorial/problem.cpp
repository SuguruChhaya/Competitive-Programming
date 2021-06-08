#include <iostream>
#include <vector>
using namespace std;
//!Need to adjust the problems a little. n=width, m=height. 
/*
If n>=1 and m>=1, how many ways are there of tiling an n X m rectangle with 1 X n tiles?
*/
/*
int main(){
    //*First wanna implement the DP solution. 
    int n, m;
    n = 3;
    m = 7;
    vector <int> arr; 
    //*Until we reach height of m, we can only stack it up horizontally (1 way). 

    if (m<n){
        cout << 1;
    }
    else{
        //*We can fill in the vector until that point. When height is 0, there is exactly 1 way to fill that up so we need to include 0 too. 
        for (int height=0;height<n;height++){
            arr.push_back(1);
        }
        //*Accomodate for the 0. 
        for (int currHeight=n;currHeight<=m;currHeight++){
            arr.push_back(arr[currHeight-n]+arr[currHeight-1]);
        }
        cout << arr[arr.size()-1];
    }
}
*/
//!NVM this problem already exists in Geeksforgeeks lol. 
bool is_solved(vector <vector <int>> arr){
    for (int i=0;i<arr.size();i++){
        for (int j=0;j<arr[i].size();j++){
            if (arr[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

void showVector(vector <vector <int>> arr){
    for (int i=0;i<arr.size();i++){
        for (int j=0;j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
//*Now want to create a slower version which works but is more complicated. 
int main(){
    int n, m;
    n = 3; //width
    m = 7; //height
    //!I cannot confuse the width and height. 

    //*Store the current solution in a 2D array with markings. 
    vector <vector <vector <int>>> queue; //[n][m]
    vector <vector <int>> curr;
    vector <int> temp;
    for (int height=0;height<m;height++){
        temp = {};
        for (int width=0;width<n;width++){
            temp.push_back(0);
        }
        curr.push_back(temp);
    }
    queue.push_back(curr);
    int total = 0;
    bool can_stack_horizontally;
    bool can_stack_vertically;
    vector <vector <int>> horizontal;
    vector <vector <int>> vertical;
    while (queue.size() > 0){
        curr = queue[0];
        queue.erase(queue.begin());

        if (is_solved(curr)){
            total++;
        }
        else{
            for (int height=0; height<m;height++){
                for (int width=0;width<m;width++){
                    if (curr[height][width]==0){
                        can_stack_horizontally = true;
                        if (width != 0){
                            can_stack_horizontally = false;
                        }
                        else{
                            for (int curr_width=0;curr_width<n; curr_width++){
                                //*Check whether even exists in the grid and then check whether it has been covered or not. 
                                //!Checking whether in range is actually pretty simple to do. 
                                if (curr[height][curr_width]==1){
                                    can_stack_horizontally = false;
                                    break;
                                }
                            }
                        }
                        if (can_stack_horizontally==true){
                            horizontal = curr;
                            for (int curr_width = 0;curr_width<n;curr_width++){
                                horizontal[height][curr_width] = 1;
                            }
                            //*Create a showVector helper. 
                            showVector(horizontal);
                            queue.push_back(horizontal);
                        }

                        can_stack_vertically = true;
                        //*Need to be inclusive with the array. 
                        if (height+n>m){
                            can_stack_vertically = false;
                        }
                        else{
                            for (int curr_height=height;curr_height<height+n; curr_height++){
                                //*Check whether even exists in the grid and then check whether it has been covered or not. 
                                //!Checking whether in range is actually pretty simple to do. 
                                if (curr[curr_height][width]==1){
                                    can_stack_vertically = false;
                                    break;
                                }
                            }
                        }
                        if (can_stack_vertically){
                            vertical = curr;
                            for (int curr_height=height;curr_height<height+n; curr_height++){
                                vertical[curr_height][width] = 1;
                            }
                            showVector(vertical);
                            queue.push_back(vertical);
                        }

                        //*If we could stack wither way, we should exit. 
                        //*If we cannot stack, keep looking. If we cannot stack until the end, gets pruned out. 
                        if (can_stack_horizontally || can_stack_vertically){
                            //*When I say break, I must break from both the width checking and the height checking. 
                            break;
                        }

                    }   
                }
            }
        }
    }
    return total;
}
