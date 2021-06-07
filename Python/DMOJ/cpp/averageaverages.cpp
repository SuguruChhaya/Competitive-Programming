#include <iostream>
#include <string> 
#include <vector> 
#include <cstring> 
#include<sstream> 
#include <cstring>

using namespace std;
void tokenize(std::string const &str, const char* delim, 
            std::vector<std::string> &out) 
{ 
    char *token = strtok(const_cast<char*>(str.c_str()), delim); 
    while (token != nullptr) 
    { 
        out.push_back(std::string(token)); 
        token = strtok(nullptr, delim); 
    } 
} 


int main(){
    //!Really have to improve on my implementation skills. 
    string initial[100];
    //!Here, we are receiving the input into a bunch of strings. 
    //*Actually never mind. Just set it to some random byte number. 
    cin.getline(initial, 100);
    char* point;
    point = strtok(initial, " ");

    //?For some reason this thing only prints the first part. 
    //*The problem with this conversion is tha the character type is char. 
    int n = std::stoi(initial[0]);
    int q = initial[2];
    /*
    while (point != NULL){
        cout << point << endl;
        point  = strtok(NULL, " ");
    }
    */
   /*
    for (int i; i <= 3; i++){
        if (initial[i] != " "){
            if 
        }
    }
    */


    /*
    const char* delim = " "; 
    std::vector<std::string> out; 
    tokenize(initial, delim, out); 
    
    int n = std::stoi(out[0]);
    
    //!I am having some kind of problem converting out[1]
    cout << out[0];
    //!There seems like there is only 
    //int q = std::stoi(out[1]);
    */
    /*
    //cout << n;
    stringstream ss;
    ss << n;
    string s;
    ss >> s;
    cout << s;
    */

}