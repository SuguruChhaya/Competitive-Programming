#include <bits/stdc++.h>
using namespace std;

bool covered(long long x, long long y, vector <long long> arr){
    return x>=arr[0] && x<=arr[2] && y>=arr[1] && y<=arr[3];
}
bool intersects(vector <long long> a, vector <long long> b){
    for (long long x=0;x<4;x+=2){
        for (long long y=1;y<4;y+=2){
            if (covered(a[x], a[y], b)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=759
    //freopen("billboard.in", "r", stdin);
    //freopen("billboard.out", "w", stdout);
    vector <long long> a(4), g(4), s(4);
    for (long long i=0;i<12;i++){
        if (i<4){
            cin >> a[i];
        }
        else if (i<8){
            cin >> g[i-4];
        }
        else{
            cin >> s[i-8];
        }
    }
    //!Maybe I didn't consider negative coordinates? 
    //!This doesn't work if it doesn't intersect in the first place. 
    //*So first check whether the rectangles intersect. If so, make a subtraction. 
    long long result = 0;
    long long a_area = (a[2]-a[0]) * (a[3]-a[1]);
    result += a_area;
    if (intersects(a, s)){
        long long xL = max(a[0], s[0]), xR = min(a[2], s[2]);
        long long yL = max(a[1], s[1]), yR = min(a[3], s[3]);
        long long a_intersect = (xR-xL) * (yR-yL);
        result -= a_intersect;
    }


    long long g_area = (g[2]-g[0]) * (g[3]-g[1]);
    result += g_area;
    //!Since we are only looking at corner points, we don't accurately know whether points are intersecting...
    
    if (intersects(g, s)){
        long long xL = max(g[0], s[0]), xR = min(g[2], s[2]);
        long long yL = max(g[1], s[1]), yR = min(g[3], s[3]);
        long long g_intersect = (xR-xL) * (yR-yL);
        result -= g_intersect;
    }


    cout << result << endl;
    
}