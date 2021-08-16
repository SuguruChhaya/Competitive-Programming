#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Just greedy the whole thing. 
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long h, w;
        cin >> h >> w;
        //*Create the h x w vector. 
        vector <vector <bool>> arr;
        for (long long row=0;row<h;row++){
            vector <bool> temp_vector; 
            for (long long col=0;col<w;col++){
                temp_vector.push_back(0);
            }
            arr.push_back(temp_vector);
        }
        //long long result = 0;
        //cout << arr.size() << " " << arr[0].size() << endl;
        for (long long row=0;row<h;row++){
            for (long long col=0;col<w;col++){
                if (row==0 || col==0 || row==h-1 || col==w-1){
                    //*On an edge. 
                    /*
                    (i−1,j), (i,j−1), (i+1,j), (i,j+1), (i−1,j−1), (i−1,j+1), (i+1,j−1), (i+1,j+1).
                    */
                   //!Need to check whether such row, col even exists. 
                    if ((row-1 >= 0 && arr[row-1][col]) || (col-1>=0 && arr[row][col-1]) || (row+1 < h && arr[row+1][col]) || (col+1 < w && arr[row][col+1]) || (row-1 >= 0 && col-1 >= 0 && arr[row-1][col-1]) || (row-1 >= 0 && col+1 < w && arr[row-1][col+1]) || (row+1 < h && col-1 >= 0 && arr[row+1][col-1]) || (row+1 < h && col+1 < w && arr[row+1][col+1])){

                    }
                    else{
                        arr[row][col] = 1;
                    }
                }
            }
        }
        for (long long row=0;row<h;row++){
            for (long long col=0;col<w;col++){
                cout << arr[row][col];
            }
            cout << endl;
        }
    }
}