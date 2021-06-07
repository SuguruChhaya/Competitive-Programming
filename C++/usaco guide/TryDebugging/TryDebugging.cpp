#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
//https://stackoverflow.com/a/45114212/13398982 need configuration. 

using namespace std;

void showVector(vector<vector <char>> arr) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            //!Somehow I am getting segmentation fault error. 
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void showCharArr(char arr[10]) {
    for (int i = 0; i < 10; i++) {
        cout << arr[i];
        //!The value is correct but equality isn't shown. 
        if (arr[i] == 'B') {
            //cout << "found" << endl;
            //!Really can be found in this!!
        }
    }
    cout << endl;
}

void showTempVector(vector<char> arr) {
    for (int i = 0; i < 10; i++) {
        //!Somehow I am getting segmentation fault error. 
        cout << arr[i];
    }
    cout << endl;
}


int main() {
    //*Classisc BFS problem but I think it can also be done without BFS since it is problem 1. 
    //*I don't understand that the variable might be unsafe crap. 
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    //*Run a 10 loop and 
    //*Need to define a 10 by 10 2D char array. 
    vector <vector <char>> arr;


    int i = 0;
    int j = 0;

    vector <int> start;
    vector <int> end;

    //!Would be really helpful if I could just directly input in vector and push_back. 
    //*Apparatnly there is a problem with modifying arr
    for (int i = 0; i < 10; i++) {
        //!I honestly think this tempArr might be error since it is receiving multiple times. 
        char tempArr[10];
        //!Does this getline() statement really work? I need to test it..
        //*But now it isn't an issue of how many characters... Data just isn't read correctly. 
        //!The character array can always be length 10 but getline must be longer. 
        //!If there are no spaces, I am better off just using cin
        cin >> tempArr;
        //showCharArr(tempArr);
        //!Copy into a vector so that I can push_back
        //vector <char> tempVector(begin(tempArr), begin(tempArr) + 10);
        vector <char> tempVector;
        //*Maybe the size just isn't big enough...
        //?In the first place, why are there so many spaces?
        //*I think this is like a problem with scope...
        for (int j = 0; j < 10; j++) {
            tempVector.push_back(tempArr[j]);
            if (tempArr[j] == 'B') {
                //!No problem with finding the temp vector...
                start = { i, j };
            }
            else if (tempArr[j] == 'L') {
                end = { i, j };
            }
        }
        //!I need to reset j value!
        //showTempVector(tempVector);
        arr.push_back(tempVector);
    }
    //showVector(arr);
    //!The issue is that curr[0] has for some reason become -1!!
    //*Using the debug console suffices for the visual studio. 
    vector <vector <int>> queue;
    //The start value isn't really initialized. 
    queue.push_back(start);
    vector <int> curr;
    //*I need to store where it came from. 
    //*Good opportunity to use hashmap. 
    //!Actually, I just need to know the minimum steps. I just need to include the current steps in the map. 
    set <vector <int>> visited;
    vector <int> curr_row_col;
    while (queue.size() > 0) {
        //*Standard BFS here. 
        //!Scope is not the real issue. 
        //!How can curr be length 0 tho? 
        curr = queue[0];
        queue.erase(queue.begin());
        curr_row_col = { curr[0], curr[1] };

        if (curr[0] == end[0] && curr[1] == end[1]) {
            //!I have this crazy number generated why?
            cout << curr[2];
            break;
        }
        //*I think it could possibly be an out of bounds thing. 
        //!I guess the values just aren't inputted correctly?
        //!Could it be that in C++, it checks all the and statements so error carries on?
        //!No, https://docs.microsoft.com/en-us/cpp/cpp/logical-and-operator-amp-amp?view=msvc-160 says it only evaluates one tho...
        //!Does not make any sense. curr[0] is -1 but why is it passing?

        //*Create the vector pair and try to find it. 

        else if ((0 <= curr[0] && curr[0] < 10) && (0 <= curr[0] && curr[0] < 10) && (arr[curr[0]][curr[1]] != 'R') && (visited.count(curr_row_col) == 0)) {
            visited.insert(curr_row_col);
            vector <int> up = { curr[0] - 1,curr[1], curr[2] + 1 };
            vector <int> down = { curr[0] + 1,curr[1], curr[2] + 1 };
            vector <int> left = { curr[0],curr[1] - 1, curr[2] + 1 };
            vector <int> right = { curr[0],curr[1] + 1, curr[2] + 1 };
            queue.push_back(up);
            queue.push_back(down);
            queue.push_back(left);
            queue.push_back(right);
        }

    }
}

/*
//!Yeah, somehow the char line isn't cleanly going into the letter.
 char tempChar;
 int x, y;
 //int i=0;
 while (i<2){
     char temp [1];
     //!Actually, the end argument of getline should be larger than the actual number of characters!!
     cin.getline(temp, 3);
     //cout << temp[0] << endl;
     if (i==0){
         temp[0] >> x;
     }
     else if (i==1){
         temp[0] >> y;
     }
     i++;
 }
 cout << x << " " << y;
 */
 //!The problem is that I just cannot see where the problem is! VS Code debugging sucks!
 //!There is this weird question mark where the value doesn't seem to be assigned. 
 //cout << arr[1][0];
 //!The vector doesn't really show clearly...
 //showVector(arr);
 //!Since it is just 10x10, I don't think big deal to keep visited hashset. 
 //*The queue will contain a vector: {row, col}







