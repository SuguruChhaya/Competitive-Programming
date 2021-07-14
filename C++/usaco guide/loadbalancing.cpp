#include <bits/stdc++.h>

using namespace std;

int main(){
    //*Pretty much divide the number of cows as evenly as possible. 
    //*Could just run a brute force loop.

    //!I see how I could store so that I don't have to check previous ones to save time. 
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    //*Doesn't matter where in the big field I place. Only makes a difference for a few amount when cow is right next to line. 

    /*
    There are a lot of possible fence combinations to consider - if we simply consider every possible even x-coordinate and every possible event y-coordinate, there would be 5000002 different combinations which is far too many.

Let us take an extreme example where there are two cows, one at (1,1) and the other at (999999,999999). Note that every even x-coordinate between 2 and 999998 yields exactly the same division of cows into quadrants, no matter which y-coordinate we pick. By the same logic, every even y-coordinate between 2 and 999998 yields exactly the same division of cows into quadrants.

Therefore, we can make the following observation - if we set the vertical fence at x=a but no cow is placed with an x-coordinate of a−1, we can move the vertical fence to x=a−2 and still preserve the same division of cows into quadrants. Similarly, if we set the horizontal fence at y=b but no cow is placed with a y-coordinate at y=b−1, we can move the horizontal fence to y=b−2.

This means that we only need to place vertical fences where x=a and there is a cow with x-coordinate a−1, and we only need to place vertical fences where y=b and there is a cow with y-coordinate b−1.

This gives us at most ten thousand pairs to try, which is small enough.
    */

    long long n, b;
    cin >> n >> b;

    //*I could sort the points based on x and y...
    //!Could I use something like binary sort?
    //*Number of points isn't a big concern since it is under 100 so I could check all. 

    //*WA for some and TLE for others. 
    //!IDK if I can prove that half middle is the best for all cases. 

    //!So I can store the x+1 coord in vector. 
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


    for (auto x:x_coords){
        for (auto y:y_coords){
            long long top_left, bottom_left, top_right, bottom_right;
            top_left = 0;
            bottom_left = 0;
            top_right=0;
            bottom_right=0;
            for (auto point: points){

                if (point[0] < x){
                    if (point[1] < y){
                        bottom_left++;
                    }   
                    else{
                        top_left++;
                    }
                }
                else{
                    if (point[1] < y){
                        bottom_right++;
                    }
                    else{
                        top_right++;
                    }
                }
            


            }
        long long max1 = max(top_left, top_right);
        long long max2 = max(bottom_left, bottom_right);
        long long final_max = max(max1, max2);
        result = min(result, final_max);
        }
    }

    cout << result << endl;

    /*
    //*Odd integer of at most b. Does that mean b is odd or even? 
    //*Positive odd numbers. 
    //!Since atmost, I should make it <=b
    
    //!OK to start at 0 since points are even. 
    for (long long x=0;x<=b;x+=2){
        for (long long y=0;y<=b;y+=2){
            long long top_left, bottom_left, top_right, bottom_right;
            top_left = 0;
            bottom_left = 0;
            top_right=0;
            bottom_right=0;
            for (auto point:points){
                if (point[0] < x){
                    if (point[1] < y){
                        bottom_left++;
                    }   
                    else{
                        top_left++;
                    }
                }
                else{
                    if (point[1] < y){
                        bottom_right++;
                    }
                    else{
                        top_right++;
                    }
                }
            }

            vector <long long> temp= {top_left, bottom_left, top_right, bottom_right};
            sort(temp.begin(), temp.end());
            result = min(result, temp[3]);

        }
    }
    */
    /*
    long long result = 9999999999999999;
    //!Gonna assume that half point works the best. 
    //*What if the number of points is odd though...
    //long long half = points.size() / 2;
    long long curr_x_division = 99999999999;
    long long x_divide;
    for (long long x=0;x<=b;x+=2){
        //*Since it would be rouded off, we could just try to exceed the half point...
        long long left, right;
        left = 0;
        right =0;
        for (auto point: points){
            if (point[0]<x){
                left++;
            }
            else{
                right++;
            }
        }
        //*Need to keep making progress but I could stay at same value.
        if (abs(left-right) <= curr_x_division){
            curr_x_division = abs(left-right);
            x_divide = x;
        }
        else{
            //*Since we already reached. 
            break;
        }
    }
    //cout << x_divide << endl;
    for (long long y=0;y<=b;y+=2){
        long long top_left, bottom_left, top_right, bottom_right;
        top_left = 0;
        bottom_left = 0;
        top_right=0;
        bottom_right=0;
        for (auto point:points){
            if (point[0] < x_divide){
                if (point[1] < y){
                    bottom_left++;
                }   
                else{
                    top_left++;
                }
            }
            else{
                if (point[1] < y){
                    bottom_right++;
                }
                else{
                    top_right++;
                }
            }
        }

        vector <long long> temp= {top_left, bottom_left, top_right, bottom_right};
        sort(temp.begin(), temp.end());
        result = min(result, temp[3]);
    }
    
    cout << result << endl;
    */
}