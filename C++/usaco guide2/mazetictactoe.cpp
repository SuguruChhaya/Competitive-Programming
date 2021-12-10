#include <bits/stdc++.h>
using namespace std;

bool found(vector <vector <char>> arr){
    
    vector <vector <vector <long long>>> move = 
    {
        {
            {1, 0},
            {-2, 0}
        },
        {
            {1, 0},
            {2, 0}
        },
        {
            {0, -1},
            {0, -2}
        },
        {
            {0, 1},
            {0, 2}
        },
        {
            {-1, -1},
            {-2, -2}
        },
        {
            {1, 1},
            {2, 2}
        }
    };
    for (long long i=0;i<3;i++){
        for (long long j=0;j<3;j++){
            if (arr[i][j]=='M'){
                //*There was a trick to make finding easier. 
                for (auto a:move){
                    bool ok = true;
                    for (auto b:a){
                        if (i+b[0]>=0 && i+b[0]<3 && j+b[1]>=0 && j+b[1]<3){
                            if (arr[i+b[0]][j+b[1]]=='O'){
                                continue;
                            }
                        }
                        ok = false;
                    }
                    if (ok){
                        return ok;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    
    long long n;
    cin >> n;
    vector <vector <vector <char>>> arr(n, vector <vector <char>>(n, vector <char>(3)));
    vector <long long> starting;
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j][0] >> arr[i][j][1] >> arr[i][j][2];
            if (arr[i][j][0]=='B'){
                starting = {i, j};
            }
        }
    }
    deque <tuple<vector<long long>, vector <vector <char>>, vector <vector <bool>>, vector <vector <bool>>>> q;
    set <vector <vector <char>>> ans;
    vector <vector <char>> temp1 (3, vector <char>(3, '.'));
    vector <vector <bool>> temp2(n, vector<bool>(n, 0)), temp3 (n, vector <bool>(n, 0));
    q.push_back({starting, temp1, temp2, temp3});

    while (!q.empty()){
        auto curr = q[0];
        cout << get<0>(curr)[0] << " " << get<0>(curr)[1] << endl;
        for (long long i=0;i<3;i++){
            for (long long j=0;j<3;j++){
                cout << get<1>(curr)[i][j];
            }
            cout << endl;
        }
        for (long long i=0;i<n;i++){
            for (long long j=0;j<n;j++){
                cout << get<2>(curr)[i][j];
            }
            cout << endl;
        }
        for (long long i=0;i<n;i++){
            for (long long j=0;j<n;j++){
                cout << get<2>(curr)[i][j];
            }
            cout << endl;
        }
        q.pop_front();
        long long row = get<0>(curr)[0], col = get<0>(curr)[1];
        if (found(get<1>(curr))){
            ans.insert({get<1>(curr)});
        }
        //!Since we process the starting element, we don't have to mark it initially. 
        //!Also need to check whether we are at a wall or not. 
        else if (get<2>(curr)[row][col]==0 && arr[row][col][0]!='#'){
            get<2>(curr)[row][col]=1;
            //!Basically checking whether we met a new PAPER, not necessarily cell. 
            if (arr[row][col][0]!='#' && get<3>(curr)[row][col]==0){
                //*Forgot to mark it. 
                //!Also it cannot be BBB or else seg error. 
                auto next1 = curr;
                if (arr[row][col][0]!='B' ){
                    long long markRow = arr[row][col][1] - '0', markCol = arr[row][row][2]-'0';
                    get<1>(next1)[markRow][markCol] = arr[row][col][0];
                }
                //!I set this markRow and markCol thing but never used it!!
                get<3>(next1)[row][col] = 1;
                get<2>(next1).clear();
                get<2>(next1).resize(n, vector<bool>(n, 0));
                q.push_back(next1);
            }
            else{
                //*Could be at empty or could be at 
                auto next1 = curr, next2=curr, next3=curr, next4=curr;
                get<0>(next1)[0]++;
                get<0>(next2)[0]--;
                get<0>(next3)[1]++;
                get<0>(next4)[1]--;
                q.push_back(next1);
                q.push_back(next2);
                q.push_back(next3);
                q.push_back(next4);
            }
        }
    }
    cout << ans.size() << endl;
}