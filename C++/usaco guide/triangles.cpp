#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);


    long long n;
    cin >> n;
    vector <vector <long long>> arr;
    for (long long i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }
    long long result = 0;
    for (long long p1=0;p1<n;p1++){
        for (long long p2=0;p2<n;p2++){
            for (long long p3=0;p3<n;p3++){
                //*Before calculating area, we must check for the parallel condition.
                //*6 types of orientations to consider. 
                long long area;
                if (arr[p1][0]==arr[p2][0] && arr[p2][1]==arr[p3][1]){
                    area = (abs(arr[p2][0]-arr[p3][0]) * abs(arr[p1][1]-arr[p2][1])); 
                }
                //*Literally I just have to hardcode all these. 
                //!I am not challenging myself. 
                //*Another approach for hardcoding is to pick one point and check whether it matches -> pretty much the same. 
                //*Anyways need to hardcode 6 possibilities. 
                else if (arr[p1][0]==arr[p3][0] && arr[p3][1]==arr[p2][1]){
                    area = (abs(arr[p3][0]-arr[p2][0]) * abs(arr[p1][1]-arr[p3][1]));
                }
                else if (arr[p2][0]==arr[p3][0] && arr[p1][1]==arr[p3][1]){
                    area = (abs(arr[p3][0]-arr[p1][0]) * abs(arr[p2][1]-arr[p1][1]));
                }
                else if (arr[p2][0]==arr[p3][0] && arr[p1][1]==arr[p3][1]){
                    area = (abs(arr[p1][0]-arr[p3][0]) * abs(arr[p2][1]-arr[p3][1]));
                }
                else if (arr[p3][0]==arr[p2][0] && arr[p2][1]==arr[p1][1]){
                    area = (abs(arr[p2][0]-arr[p1][0]) * abs(arr[p3][1]-arr[p2][1]));
                }
                else if (arr[p3][0]==arr[p1][0] && arr[p2][1]==arr[p1][1]){
                    area = (abs(arr[p2][0]-arr[p1][0]) * abs(arr[p3][1]-arr[p1][1]));
                }

                //!Pretty sure only one triangle can be made using all that. 
                //!Since I didn't divide by 2 in process, I don't multiply
                result = max(result, area);
            }
        }
    }
    cout << result << endl;
}