#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    //!Passed 2 cases but not the others...
    //!Need to create a brute force in order to stress test this. 
    //*probably my approach is wrong in the first place. 
    long long n, k;
    cin >> n >> k;
    vector <vector <string>> pieces (k+1, vector <string> (n));
    vector <vector <vector <long long>>> coords (k+1, vector <vector <long long>>());
    for (long long i=0;i<=k;i++){
        for (long long j=0;j<n;j++){
            cin >> pieces[i][j];
            for (long long k=0;k<n;k++){
                if (pieces[i][j][k]=='#'){
                    coords[i].push_back({j, k});
                }
            }
        }
    }

    for (long long i=1;i<=k;i++){
        for (long long j=i+1;j<=k;j++){
            if (coords[i].size()+coords[j].size()==coords[0].size()){
                vector <vector <long long>> used (n, vector <long long> (n, -1));

                for (long long a=0;a<coords[0].size();a++){
                    for (long long b=0;b<coords[0].size();b++){
                        if (a!=b){
                            //!Update every time I change a and b
                            for (auto coord:coords[0]){
                                used[coord[0]][coord[1]]=0;
                            }
                            //!Correct solution occurs when i=1, j=3, a=3, b=0
                            /*
                            if (i==1 && j==3 && a==3 && b==0){
                                cout << "";
                            }
                            */
                            bool ok=true;
                            long long i_rowDiff = coords[0][a][0]-coords[i][0][0];
                            long long i_colDiff = coords[0][a][1]-coords[i][0][1];
                            long long j_rowDiff = coords[0][b][0]-coords[j][0][0];
                            long long j_colDiff = coords[0][b][1]-coords[j][0][1];

                            for (auto coord:coords[i]){
                                if (used[coord[0]+i_rowDiff][coord[1]+i_colDiff]==-1 || used[coord[0]+i_rowDiff][coord[1]+i_colDiff]==1){
                                    ok=false;
                                    break;
                                }
                                used[coord[0]+i_rowDiff][coord[1]+i_colDiff] = 1;
                            }
                            for (auto coord:coords[j]){
                                if (used[coord[0]+j_rowDiff][coord[1]+j_colDiff]==-1 || used[coord[0]+j_rowDiff][coord[1]+j_colDiff]==1){
                                    ok=false;
                                    break;
                                }
                                used[coord[0]+j_rowDiff][coord[1]+j_colDiff] = 1;
                            }

                            if (ok==true){
                                cout << i << " " << j << endl;
                                //return 0;
                                exit(EXIT_SUCCESS);
                                //return 0;
                                //!Why does this keep running even after printing. 
                            }
                        }
                    }
                }
            }
        }
    }
    //return 0;
}