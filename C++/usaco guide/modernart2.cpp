    /*
Intuitively, the larger our rectangles are, the more likely they are to overlap other rectangles. Since we want to maximize the number of rectangles that can have been drawn first, we want as few overlaps as possible, since knowing that two rectangles overlap means that one of them cannot possibly have been drawn first. This means it is always to our advantage to assume, when we can, that an overlap doesn't occur, and so we will try to assume that each rectangle is as small as it can possibly be. In particular, for each rectangle of a certain color, we will always assume that the leftmost grid square of that color is its left border, the topmost grid square of that color is its top border, etc.

Now that we know the bounds of our rectangles, it is very straightforward to determine whether two rectangles overlap. But when two rectangles overlap, how do we know which one can be on top? Can either of them be on top? Consider the area formed when two rectangles of colors C and D overlap. Clearly it cannot contain squares of both colors C and D. If it contains either C or D, then the corresponding rectangle of that color must have been painted later. (Otherwise, the later rectangle would have painted over the color that shows up.) If it contains neither, then we can assume either rectangle was painted first, as we have no way to tell the difference.

This means that a rectangle R could have been painted first if, and only if, there is no other rectangle S such that there's a grid square of color R within the area of S.

Since N is very small (at most 10), we can compute for each pair of rectangles R and S whether S is on top of R using brute-force. Whenever we find a rectangle that does not have to have any other rectangle on top of it, we can add it to our overall count.
    */

#include <bits/stdc++.h>
using namespace std;
long long n;
vector <vector <long long>> arr;

bool appears(long long color){
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            if (arr[i][j]==color){
                return true;
            }
        }
    }
    return false;
}

bool on_top_of(long long c1, long long c2){
    //*If c1 (passed as the first color) is on top of c2, then c1 cannot be the original color. 
    long long top=n, bottom=0,left=n,right=0;
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            if (arr[i][j]==c2){
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }

    for (long long i=top;i<=bottom;i++){
        for (long long j=left;j<=right;j++){
            if (arr[i][j]==c1){
                return true;
            }
        }
    }
    return false;
}

int main(){

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    cin >> n;
    //*2D array that stores the colors. 
    

    //!So basically we say no colors were beneath. 
    //*Weird problem worded confusingly. 
    for (long long i=0;i<n;i++){
        string s;
        cin >> s;
        vector <long long> temp_vector;
        for (long long j=0;j<n;j++){
            //*I could convert using stoi but a relatively simpler way is to use the ascii values of char. 
            //*But for originality, I will keep using the conversion method. 
            string temp;
            temp.push_back(s[j]);
            long long color = stoi(temp);
            temp_vector.push_back(color);
        }
        arr.push_back(temp_vector);
    }

    long long answer =0;
    
    for (long long i=1;i<=9;i++){
        if (appears(i)){
            bool could_be_first = true;
            for (long long j=1;j<=9;j++){
                if (j!=i && appears(j) && on_top_of(i, j)){
                    could_be_first = false;
                }
            }
            if (could_be_first){
                answer++;
            }
        }
    }

    cout << answer << endl;
}