#include <iostream>
#include <fstream>
#include <bits/stdc++.h>/
//!Though I am getting underlines, I don't know if this will really become a problem.

using namespace std;
//*std stands for using standard things in C++. Nothing fancy. 
//!Apparantly the 2 lines (which I often saw with william lin) speed things up a lot. 
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
int main(){
    fstream myfile;
    //*Unlike Python this open statement doesn't create a text file if it doesn't exist. If it doesn't exist, it just skips. 
    myfile.open("a.txt");
    //*This kind of reading and writing often times 
    myfile << "1 2";
    myfile.close();
    string a = "abc";
    //cout << a[1];
    //return 0;

    //fstream fin("test.txt");
    
    //fin.close();
    //!Read the objects and store it in a character array. 
    char filename[50];
    
    ifstream fin;

    cin.getline(filename, 60);
    fin.open(filename);
    
    //!Why??? I am opening the file but it just doesn't work!!
    char word[80];
    fin >> word;
    //*Somehow the last 6 has just vanished. 
    
    //!I might need this good thing from now on too so...
    while (fin.good()){
        cout << word << "\n";
        fin >> word;
    }
    //!Should I really waste time on this stuff?
    //!I guess when I just do "word", the outputs the first letter. 
    /*
    cout << word;
    int length = sizeof(word);
    //!Have no idea why this prints 1PP. 
    for (int i; i < length; i++){
        cout << word[i];
    }
    */

    //cout << filename;
    //!Still have no idea about C++ syntax and really how to do things. 
    //?Probably should follow a tutorial just for syntax. 


}