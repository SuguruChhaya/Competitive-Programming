
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;
int main(){
    //!There is some kind of issue with booleans. 
    //!Now I get it!!
    //*Unlike Python, I cannot do a < b < c Instead, I have to do it explicitly separately. 
    bool is = 0 <= -1 < 10;
    if (is){
        cout << "yes";
    }

}
