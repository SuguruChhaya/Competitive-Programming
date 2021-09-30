    #include <bits/stdc++.h>

    using namespace std;

    int main(){
        long long t;
        cin >> t;
        for (long long i=0;i<t;i++){
            long long W, H, x1, y1, x2, y2, w, h;
            cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
            long long a, b, c, d;
            a = x1; b=W-x2,c=y1, d=H-y2;
            long long result = -1;
            long long zero = 0;
            if (a+b >= w){
                result = min(max(zero, w-a), max(zero, w-b));
            } 
            if (c+d>=h){
                if (result==-1){
                    //!Now I get how it could become a negative. 
                    result = min(max(zero, h-c), max(zero, h-d));
                }
                else{
                    result = min(result, min(max(zero, h-c), max(zero, h-d)));
                }
            }
            cout << result << endl;
        }
        
        
    }