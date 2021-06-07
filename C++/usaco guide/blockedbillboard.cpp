#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    vector <vector <int>> arr;
    vector <int> temp;
    //*Since they are in coordinate form, there are 2000 max. 
    for (int i=0;i<2000;i++){
        temp = {};
        for (int j=0;j<2000;j++){
            temp.push_back(0);
        }
        arr.push_back(temp);
    }

    int x11, y11, x12, y12, x21, y21, x22, y22, bx1, bx2, by1, by2;
    cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22 >> bx1 >> by1 >> bx2 >> by2;

    //*Oh I forgot the conversion. 
    for (int i=x11;i<x12;i++){
        for (int j=y11;j<y12;j++){
            arr[1000+i][1000+j]=1;
        }
    }

    //*I think I am getting my coordinate orders messed up. 
    //!Based on how I am stroing it based on row, col. 
    //*I mean I could store it so that 1st row is when x=1. 
    for (int i=x21;i<x22;i++){
        for (int j=y21;j<y22;j++){
            arr[1000+i][1000+j]=1;
        }
    }

    for (int i=bx1;i<bx2; i++){
        for (int j=by1; j<by2; j++){
            arr[1000+i][1000+j] = 0;
        }
    }
    long long result=0;
    for (int i=0;i<arr.size();i++){
        for (int j=0;j<arr[i].size();j++){
            if (arr[i][j]==1){
                result++;
            }
        }
    }

    cout << result;

    //*We could find the area just by simple area calculation too...
    
}