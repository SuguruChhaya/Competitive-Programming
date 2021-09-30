#include <bits/stdc++.h>
using namespace std;
//!Come back to this later. 
int main(){
    vector <long long> white(4), a(4), b(4);
    for (long long i=0;i<12;i++){
        if (i<4){
            cin >> white[i];
        }
        else if (i<8){
            cin >> a[i-4];
        }
        else{
            cin >> b[i-8];
        }
    }
    //!Could do double intersecting and intersecting area may be greater. 
    //!Then I should subtract the intersection area between a and b. 
    bool both = true;
    long long zero = 0;
    long long white_area = (white[2]-white[0]) * (white[3]-white[1]);
    long long a_xl = max(white[0], a[0]), a_xr = min(white[2], a[2]);
    long long a_yd = max(white[1], a[1]), a_yu=min(white[3], a[3]);
    //!If negative and negative multiply, not good. 
    long long intersecting = max(zero, max(zero, a_xr-a_xl) * max(zero, a_yu-a_yd));
    if (intersecting==zero){
        both = false;
    }

    long long b_xl = max(white[0], b[0]), b_xr = min(white[2], b[2]);
    long long b_yd = max(white[1], b[1]), b_yu=min(white[3], b[3]);
    auto prev = intersecting;
    intersecting += max(zero, max(zero, b_xr-b_xl) * max(zero, b_yu-b_yd));
    if (intersecting==prev){
        both = false;
    }
    //!Not just how much of a and b are overlapping but more like how much of a and b are overlapping on white (so how much overlap of all a, b, and white). 
    //!We have to check this only if both the rectangles are intersecting in some way. 
    if (both){
        long long xl = max(a_xl, b_xl), xr = min(a_xr, b_xr);
        long long yd = max(a_yd, b_yd), yu = min(a_yu, b_yu);
        intersecting -= max(zero, (xr-xl) * (yu-yd));
    }
    /*
    long long xl = max(a[0], b[0]), xr = min(a[2], b[2]);
    long long yd = max(a[1], b[1]), yu=min(a[3], b[3]);
    intersecting -= max(zero, (xr-xl) * (yu-yd));
    */

    if (intersecting<white_area){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout << endl;
}