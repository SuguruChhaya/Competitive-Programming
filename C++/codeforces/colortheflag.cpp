#include <iostream>
#include <vector>

using namespace std;

int main(){
    //*Really, there are only 2 types of grids. One that starts with white and another with red. 
    //*Create the 2 arrays and check whether either fits in. 
    
    vector <vector <char>> arr1;
    vector <vector <char>> arr2;
    vector <char> temp;
    string temp_string;
    int numTests, n, m;
    cin >> numTests;

    for (int i=0;i<numTests;i++){
        cin >> n >> m;
        vector <vector <char>> inp;
        for (int row=0;row<n;row++){
            temp = {};
            cin >> temp_string;
            for (int col=0;col<m;col++){
                temp.push_back(temp_string[col]);
            }
            inp.push_back(temp);
        }
        for (int row=0;row<n;row++){
            temp = {};
            for (int col=0;col<m;col++){
                if (row==0 && col==0){
                    temp.push_back('W');
                }
                else if (col-1>=0){
                    if (temp[col-1]=='W'){
                        temp.push_back('R');
                    }
                    else{
                        temp.push_back('W');
                    }
                }
                else if (row-1>=0){
                    if (arr1[row-1][col]=='W'){
                        temp.push_back('R');
                    }
                    else{
                        temp.push_back('W');
                    }
                }
            }
            arr1.push_back(temp);
        }

        for (int row=0;row<n;row++){
            temp = {};
            for (int col=0;col<m;col++){
                if (row==0 && col==0){
                    temp.push_back('R');
                }
                else if (col-1>=0){
                    if (temp[col-1]=='W'){
                        temp.push_back('R');
                    }
                    else{
                        temp.push_back('W');
                    }
                }
                else if (row-1>=0){
                    if (arr2[row-1][col]=='W'){
                        temp.push_back('R');
                    }
                    else{
                        temp.push_back('W');
                    }
                }
            }
            arr2.push_back(temp);
        }
        bool yes = true;
        for (int row=0;row<n;row++){
            for (int col=0;col<m;col++){
                if (arr1[row][col] == inp[row][col] || inp[row][col]=='.'){

                }
                else{
                    yes = false;
                    break;
                }
            }
        }
        //!Some weird printing issue. 
        if (yes==true){
            //*Print and return right away. 
            cout << "YES" << endl;

            for (int row=0;row<n;row++){
                for (int col=0;col<m;col++){
                    cout << arr1[row][col];
                }
                cout << endl;
            }
        }
        else{
            yes = true;
            for (int row=0;row<n;row++){
                for (int col=0;col<m;col++){
                    if (arr2[row][col] == inp[row][col] || inp[row][col]=='.'){

                    }
                    else{
                        yes = false;
                        break;
                    }
                }
            }
            if (yes==true){
                //*Print and return right away. 
                cout << "YES" << endl;

                for (int row=0;row<n;row++){
                    for (int col=0;col<m;col++){
                        cout << arr2[row][col];
                    }
                    cout << endl;
                }
            }
            else{
                cout << "NO" << endl;
            }
            
        }
        

    }

    



}