#include <iostream>
#include <vector>

using namespace std;

int main(){

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int m, n, k;
    cin >> m >> n >> k;
    vector <vector <char>> arr, result;
    string temp;
    vector <char> temp_vector;
    for (int row=0;row<m;row++){
        cin >> temp;
        temp_vector = {};
        for (int col=0;col<n;col++){
            temp_vector.push_back(temp[col]);
        }
        arr.push_back(temp_vector);
    }

    //*Just create the answer vector right way. 
    for (int row=0;row<m*k;row++){
        temp_vector = {};
        for (int col=0;col<n*k;col++){
            temp_vector.push_back('.');
        }
        result.push_back(temp_vector);
    }

    //*Now start iterating and change the value. 

    //*Should know the index based on current iteration. 
    //!Cannot do it in constant way because k can be 3 etc. 
    int row_limit, col_limit;
    for (int row=1;row<=m;row++){
        for (int col=1;col<=n;col++){
            //*We can decrement by 3. 
            //!Have to adjust to the 0-indexing. 
            //*We have to set a number at first for proper. 
            
            for (int i=row*k;i>row*k-k;i--){
                for (int j=col*k;j>col*k-k;j--){
                    result[i-1][j-1] = arr[row-1][col-1];
                }
            }
        }
    }

    for (int i=0;i<m*k;i++){
        for (int j=0;j<n*k;j++){
            cout << result[i][j];
        }
        cout << "\n";
    }
}