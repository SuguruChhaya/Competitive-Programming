#include <iostream>
using namespace std;
int main(){
    int a;
    //!Constant will give me error if not declared right away. 
    //const int b;
    //char b;
    //*Actually, input and stuff isn't that hard. I will procrastinate on reading files for now. 
    //cin >> a;
    //!When declaring an array, the value must be a constant. 
    const int b = 5;
    int arr [b];
    /*
    for (int i=0; i < a; i++){
        cin >> arr[i];
    }
    */

    cout << "arr" << "\n";
    int j = sizeof(arr);
    //!I guess for every loop due to scope reasons I need to redefine variable. 
    //!For some reason there are some crazy values in the arr. 
    //!Don't really know why but when I explicitly state the number it works OK. 
    for (int i=0; i<b; i++){
        cout << arr[i] << "\n";
    }

    //!The number just x4ed. 
    //!Finding the size of array is a little complicated. 
    //https://iq.opengenus.org/length-of-array-in-c/

    //cout << sizeof(arr) / sizeof(int);

    /*
    char yo [50];
    cin >> yo;

    for (int i=0; i<50; i++){
        cout << yo[i] << "\n";
    }
    */
    //string s;
    char s [20];
    //!Interestingly, getline's second argument doesn't include 11 so <11. 
    cin.getline(s, 11);
    //!I could create delimiter where line ends. 
    for (int i=0; i<10;i++){
        cout << s[i] << "\n";
    }

    //!What I must be able to do is read standard input and put them into array based on space. 

    
}