//Bull: Kind of a hard problem where I have to find shift the pieces in so many different ways to find the solution...
#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    long long n;
    cin >> n;

    set <long long> x_coords;
    set <long long> y_coords;
    long long result = 9999999999;
    vector <vector <long long>> points;
    for (long long i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        points.push_back({x, y});
        //!Maybe wanna use something other than a hashset? 
        x_coords.insert(x+1);
        y_coords.insert(y+1);
    }

    //*Sort the points array based on the x_axis.  
    sort(points.begin(), points.end());

    //*Since we can DP based on x_coords, I should set the y_values as constant. 
    for (auto y:y_coords){
        //*I think I have to count the number of points in each coord first. 
        //*Really, nothing will be in the left_side. Just divide into top_right and bottom_right. 
        long long top_left, bottom_left, top_right, bottom_right;

        top_right = bottom_right = top_left = bottom_left = 0;
        for (auto point: points){
            if (point[1] < y){
                bottom_right++;
            }
            else{
                top_right++;
            }
        }
        //Am I gonna do this based on x_index or points. 
        //*There could be points with same x_value but they must be dealt with at the same time. 
        //!The set iteration always happens in sorted order. So I can just iterate and move while the element at that index is smaller. 
        long long index = 0;
        for (auto x:x_coords){
            //*Check whether the point will fit into top_left or bottom_left. 
            
            //*Keep an index record so I 
            while (index < n && points[index][0] < x){
                if (points[index][1] < y){
                    bottom_left++;
                    //*And subtract. 
                    bottom_right--; 
                }
                else{
                    top_left++;
                    top_right--;
                }
                index++;
            }
            //*Everytime I move the x, we must check. 
            long long max1 = max(top_left, top_right);
            long long max2 = max(bottom_left, bottom_right);
            long long final_max = max(max1, max2);
            result = min(result, final_max);
        }


    }
    cout << result << endl;
}