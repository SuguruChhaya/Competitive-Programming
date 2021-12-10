#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}
vector<bool>visited;
vector<vector<long long>> connections;

void dfs(long long i){
    if (!visited[i]){
        visited[i] = 1;
        //cout << connections[i].size() << endl;
        for (auto e:connections[i]){
            //cout << "ran" << endl;
            dfs(e);
        }
    }
}
bool invalid(vector<vector<long long>>arr){
    if (arr.size()==0){
        return true;
    }
    //*Not size of arr but total # of elements. 
    //*Which should be arr.size()+1
    //So arr.size()+2
    visited = {};
    connections = {};
    visited.resize(arr.size()+2, 0);
    connections.resize(arr.size()+2);
    //*Need to read in from arr. 
    for (auto e:arr){
        connections[e[0]].push_back(e[1]);
        connections[e[1]].push_back(e[0]);
    }
    dfs(1);
    for (long long i=1;i<=arr.size()+1;i++){
        if (!visited[i]){
            return 1;
        }
    }
    return 0;
}

int main(int argc, char* argv[]){
    //*Also need to make sure they form a tree, which could be harder. 
    int seed = atoi(argv[1]);
    srand(seed);
    
    long long n = rnd(1, 10), m = rnd(1, 10);
    //long long n = 2, m = 8;
    cout << n << " " << m << endl;
    vector<char> arr = {'G', 'H'};
    for (long long i=0;i<n;i++){
        cout << arr[rnd(0, 1)];
    }
    
    cout << endl;
    set <vector<long long>> used;

    vector<vector<long long>> temp;
    while (invalid(temp)){
        //!Seems to never find a valid one. 

        temp = {};
        used = {};
        for (long long i=0;i<n-1;i++){
            long long x = rnd(1, n), y = rnd(1, n);
            while (x==y || used.count({x, y})){
                x = rnd(1, n), y= rnd(1, n);
            }
            //*Need to include in count
            used.insert({x, y});
            temp.push_back({x, y});
        }
    }

    for (auto v:temp){
        cout << v[0] << " " << v[1] << endl;
    }

    for (long long i=0;i<m;i++){
        long long a = rnd(1, n), b = rnd(1, n);
        char c = arr[rnd(0, 1)];
        cout << a << " " << b << " " << c << endl;
    }
}