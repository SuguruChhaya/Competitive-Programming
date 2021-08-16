#include <bits/stdc++.h>
using namespace std;

int main(){
    //*I can just try all of the colors and see if their pattern matches. 
    //*Because all the other colors could be paited in some random way. 
    //*I just need to detect which colors 
    //*The special case is when the color isn't appearing. 
    //*If not appearning, we want to make it as easy so we can scan and place a 1x1 block where the original didn't occupy.

    //!What info do I need to store?
    //*Colors are 0-indexed. 
    //*Min_x, max_x, min_y, max_y
    
    //freopen("art.in", "r", stdin);
    //freopen("art.out", "w", stdout);

    vector <vector <long long>> arr;

    //*10 colors (including blank. )
    //*Start off my -1 because both min and max exist. 
    for (long long i=0;i<10;i++){
        arr.push_back({-1, -1, -1, -1});
    }

    long long n;
    cin >> n;

    //!New info: each rectangle must be touching the edge. 
    //*But where did 2 and all the other colors go???
    //!Really weird and boring question. I guess I didn't understand the question well enough???

    //!Each side doesn't have to TOUCH the edge but it has to be parallel. 


    vector <vector <long long>> final_painting;
    for (long long i=0;i<n;i++){
        string s;
        cin >> s;
        vector <long long> temp_vector;
        for (long long j=0;j<n;j++){
            //*Need to convert to int if I wanna place into vector. 
            string temp;
            temp.push_back(s[j]);
            long long color = stoi(temp);
            
            //*Min row. 
            if (arr[color][0]==-1){
                arr[color][0] = i;
            }
            if (arr[color][1]==-1){
                arr[color][1] = j;
            }
            if (arr[color][2]==-1){
                arr[color][2] = i;
            }
            if (arr[color][3]==-1){
                arr[color][3] = j;
            }
            //!Min_x, min_y, max_x, max_y
            //*Now just do the min max. 
            arr[color][0] = min(arr[color][0], i);
            arr[color][1] = min(arr[color][1], j);
            arr[color][2] = max(arr[color][2], i);
            arr[color][3] = max(arr[color][3], j);

            temp_vector.push_back(color);
        }
        final_painting.push_back(temp_vector);
    }
    /*
    for (auto color_vector:arr){
        for (auto info:color_vector){
            cout << info << " ";
        }
        cout << endl;
    }
    */
    
    //!The array isn't even initialized correctly. 
    //*Pick from the colors.   
    long long result = 0;

    //*Create the original vector. 
    vector <vector <long long>> original;
    for (long long i=0;i<n;i++){
        vector <long long> temp;
        for (long long j=0;j<n;j++){
            temp.push_back(0);
        }
        original.push_back(temp);
    }

    //!There is a possibility that all of them end up being 0s.

    //!Honestly more convenient to store everything in int. 
    for (long long first_color = 1;first_color<=9;first_color++){
        /*
        if (first_color==2){
            cout << "";
        }
        */
        bool ok = true;
        auto curr = original;

        //!Must be visible!! That changes the entire game!!
        //*But all colors are still at least drawn once. 
        if (arr[first_color][0] ==-1){
            ok = false;
        }
        else{
            //*I need to first paint the color. 
            for (long long row=arr[first_color][0];row<=arr[first_color][2];row++){
                for (long long col=arr[first_color][1];col<=arr[first_color][3];col++){
                    curr[row][col] = first_color;
                }
            }

            for (long long color = 1;color<=9;color++){
                //!make sure that it is different from the first color. 
                if (first_color!=color){
                    if (arr[color][0]=-1){
                        //*If one of the indices is -1, I know it didn't appear on the array.
                        //!If so check whether there is a spot to fit. 
                        //*Doesn't show so just check whether it can take up SOME spot. 
                        //!If the final thing contains at least one spot that is neither the first color nor uncolored, that would count. 
                        
                        //!If the color is not shown, I don't think we even consider it to be hindering the chances. 
                        /*
                        pair <long long, long long> open_coord;
                        bool open = false;
                        for (long long row=0;row<n;row++){
                            for (long long col=0;col<n;col++){
                                if (final_painting[row][col] != first_color && final_painting[row][col] != 0){
                                    open_coord.first = row;
                                    open_coord.second = col;
                                    open = true;
                                    break;
                                }
                            }
                        }

                        if (open){
                            curr[open_coord.first][open_coord.second] = color;
                        }
                        else{
                            //*Since there is no placement for not shown colors. 
                            ok = false;
                            break;
                        }
                        */
                    }
                    //!The color is shown. 
                    else{
                        for (long long row=arr[color][0];row<=arr[color][2];row++){
                            for (long long col=arr[color][1];col<=arr[color][3];col++){
                                curr[row][col] = color;
                            }
                        }
                    }
                }
            }
        }

        //!Finally we need to do a check. Check whether things are ok so far.
        if (ok){
            for (long long row=0;row<n;row++){
                for (long long col=0;col<n;col++){
                    //*Order will change so other spots could change. 
                    //!But wherever showing up will still show up. 
                    /*
                    string temp;
                    temp.push_back(final_painting[row][col]);
                    long long color = stoi(temp);
                    */
                    //!Check if it is the original color. And check whether curr[row][col] (char) is equal to final_painting[row][col] (char). 
                    if (final_painting[row][col]==first_color && curr[row][col] != final_painting[row][col]){
                        ok = false;
                        break;
                    }
                }
            }
        }

        if (ok){
            result++;
        }
    }   
    cout << result << endl;
}