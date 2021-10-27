#include <bits/stdc++.h>
using namespace std;
vector <tuple <char, long long, long long>> arr;
long long n;
vector <bool> stopped;
vector <long long> ans;
vector <long long> whenIntersects(long long i, long long j){
    if (stopped[i]==0 && stopped[j]==0){
        if (get<0>(arr[i])=='N'){
            if (get<0>(arr[i])=='N'){
                long long x = get<1>(arr[i]), y=get<2>(arr[j]);
                if (get<1>(arr[j])>x || get<2>(arr[i])>y){
                    return {-1};
                }
                else{
                    if (x-get<1>(arr[j])==y-get<2>(arr[i])){
                        return {-1};
                    }
                    else if (x-get<1>(arr[j])<y-get<2>(arr[i])){
                        return {y-get<2>(arr[i]), i};
                    }
                    else{
                        return {x-get<1>(arr[j]), j};
                    }
                }
            }
            else{
                if (get<1>(arr[i])==get<1>(arr[j])){
                    if (get<2>(arr[i])<get<2>(arr[j])){
                        return {get<2>(arr[j])-get<2>(arr[i]), i};
                    }
                    else{
                        return {get<2>(arr[i])-get<2>(arr[j]), j};
                    }
                }
                else{
                    return {-1};
                }
            }
        }
        else{
            if (get<0>(arr[j])=='E'){
                if (get<2>(arr[i])==get<2>(arr[j])){
                    if (get<1>(arr[i])<get<1>(arr[j])){
                        return {get<1>(arr[j])-get<1>(arr[i]), i};
                    }
                    else{
                        return {get<1>(arr[i])-get<1>(arr[j]), j};
                    }
                }
                else{
                    return {-1};
                }
            }
            else{
                long long x = get<1>(arr[j]), y = get<2>(arr[i]);
                if (get<1>(arr[i])>x || get<2>(arr[j])>y){
                    return {-1};
                }
                else{
                    if (x-get<1>(arr[i])==y-get<2>(arr[j])){
                        return {-1};
                    }
                    else if (x-get<1>(arr[i])<y-get<2>(arr[j])){
                        return {y-get<2>(arr[j]), j};
                    }
                    else{
                        return {x-get<1>(arr[i]), i};
                    }
                }
            }
        }
    }
    return {-1};
}

int main(){
    cin >> n;
    arr.resize(n);
    stopped.resize(n, 0);
    ans.resize(n, -1);
    for (long long i=0;i<n;i++){
        cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
    }
    vector <long long> ans(n, -1);
    vector <vector <long long>> pairs;
    for (long long i=0;i<n;i++){
        for (long long j=i+1;j<n;j++){
            auto temp = whenIntersects(i, j);
            if (temp[0]!=-1){
                pairs.push_back({temp[0], i, j});
            }
        }
    }
    sort(pairs.begin(), pairs.end());
    for (auto e:pairs){
        //cout << e[0] << " " << e[1] << " " << e[2] << endl;
        auto temp = whenIntersects(e[1], e[2]);
        
        if (temp[0]!=-1){
            //cout << temp[0] << " " << temp[1] << endl;
            stopped[temp[1]]=1;
            ans[temp[1]] = temp[0];
        }
    }
    for (auto e:ans){
        if (e==-1){
            cout << "Infinity" << endl;
        }
        else{
            cout << e << endl;
        }
    }
}