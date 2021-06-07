#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'canBeEqualized' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY firstStrings
 *  2. STRING_ARRAY secondStrings
 */
/*
vector<string> canBeEqualized(vector<string> firstStrings, vector<string> secondStrings) {
    //*Pretty obvious that I can only have one string differece. 
    //*Basically, if I hit a string difference, I can just map that I changed this to this. Then I can continue traversing and if there is an mismatchm, I can just return NO. 
    vector <string> result;
    //*Equal length. 
    map <char, char> hashmap_1, hashmap_2;
    string temp_1;
    bool add_1, add_2;
    set <char> hashset_1, hashset_2;
    for (int i=0;i<firstStrings.size();i++){
        //
        
        //*Not sure if this case exists but take care of unequal length. 
        if (firstStrings[i].size() != secondStrings[i].size()){
            result.push_back("NO");
        }
        else{
            //!I have to notice that merely looping from the other side will give me the same results. 
            hashmap_1 = {};
            hashset_1 = {};
            //!We are checking individually so I could break from for loop but I need a bool to check whether should be added. 
            add_1 = true;
        
            //*Honestly, the easiest solution I can think of is to iterate from both sides. 
            for (int j=0;j<firstStrings[i].size();j++){
                if (firstStrings[i][j] != secondStrings[i][j]){
                    if (hashmap_1.count(firstStrings[i][j]) == 0){
                        //*If there already is a value, there cannot be 2 mappings. 
                        if (hashmap_1.size()==1){
                            add_1 = false;
                            break;
                        }
                        else if (hashset_1.count(firstStrings[i][j]) == 0){
                            hashmap_1[firstStrings[i][j]] = secondStrings[i][j];
                        }
                        else{
                            add_1 = false;
                            break;
                        }
                    }
                    
                    //*Kind of inefficient writing this again and again. 
                    else{
                        if (hashmap_1[firstStrings[i][j]]!=secondStrings[i][j]){
                            add_1 = false;
                            break;
                        }
                    }
                    
                }
                else{
                    //*Regardless of whether they are equal or not, if they are in the mapping already, I need to check. 
                    hashset_1.insert(firstStrings[i][j]);
                    if (hashmap_1.count(firstStrings[i][j]) ==1 && hashmap_1[firstStrings[i][j]] != secondStrings[i][j]){
                        add_1 = false;
                        break;
                    }
                }
            }

            //*I see, we might go over matching and then go through mismatch so I can select that in a set. 

            hashmap_2 = {};
            hashset_2 = {};
            add_2 = true;
            //!Could check intermediately but I could do that if I run out of time. 
            for (int j=0;j<secondStrings[i].size();j++){
                if (firstStrings[i][j] != secondStrings[i][j]){
                    if (hashmap_2.count(secondStrings[i][j])==0){
                        if (hashmap_2.size()==1){
                            add_2 = false;
                            break;
                        }
                        else if (hashset_2.count(secondStrings[i][j])==0){
                            hashmap_2[secondStrings[i][j]] = firstStrings[i][j];
                        }
                        else{
                            add_2 = false;
                            break;
                        }
                    }
                    else{
                        if (hashmap_2[secondStrings[i][j]]!=secondStrings[i][j]){
                            add_2 = false;
                            break;
                        }
                    }
                }
                else{
                    hashset_2.insert(secondStrings[i][j]);
                    if (hashmap_2.count(secondStrings[i][j])==1 && hashmap_2[secondStrings[i][j]] != firstStrings[i][j]){
                        add_2 = false;
                        break;

                }
            }
        }

        if (add_1 == false && add_2 == false){
            result.push_back("NO");
        }
        else{
            result.push_back("YES");
        }
    }
    //!I guess I have to look at the strings from both angles. 
    

        
    }
    return result;
}
*/
/*
vector<string> canBeEqualized(vector<string> firstStrings, vector<string> secondStrings) {
    vector <string> result;
    map <char, char> hashmap_1, hashmap_2;
    bool add_1, add_2;
    //!Now I am not addressing the basic needs.     
    for (int i=0;i<firstStrings.size();i++){
        if (firstStrings[i].size() != secondStrings[i].size()){
            result.push_back("NO");
        }
        else{
            //!Instead of taking down the whole loop, I can just add counters. 
            hashmap_1 = {};
            hashmap_2 = {};

            add_1 = true;
            add_2 = true;
            for (int j=0;j<firstStrings[i].size();j++){
                //*First check if exists in the map. 
                if (hashmap_1.count(firstStrings[i][j])==0){
                    hashmap_1[firstStrings[i][j]] = secondStrings[i][j];
                }
                else{
                    if (secondStrings[i][j] != hashmap_1[firstStrings[i][j]]){
                        add_1 = false;
                        break;
                    }
                }
            }

            for (int j=0; j<secondStrings[i].size();j++){
                if (hashmap_2.count(secondStrings[i][j]) == 0){
                    hashmap_2[secondStrings[i][j]] = firstStrings[i][j];
                }
                else{
                    if (firstStrings[i][j] != hashmap_2[secondStrings[i][j]]){
                        add_2 = false;
                        break;
                    }
                }
            }

            if (add_1 || add_2){
                result.push_back("YES");
            }
            else{
                result.push_back("NO");
            }
        }
    }
    return result;
}
*/
//!Then there is the issue of doing it twice. 
//!Literally F this problem.    
vector<string> canBeEqualized(vector<string> firstStrings, vector<string> secondStrings) {
    char from;
    char to;
    string s;
    int j=0;
    vector <string> result;
    int i;
    for (i=0;i<firstStrings.size();i++){
        if (firstStrings[i].size() != secondStrings[i].size()){
            result.push_back("NO");
        }
        from = '1';
        to = '1';
        s = "";
        //*Once I do find a mismatch, why don't I revert back. 
        j = 0;
        while (j<firstStrings[i].size())
            if (from=='1' && to=='1' && firstStrings[i][j] != secondStrings[i][j]){
                from = firstStrings[i][j];
                to = secondStrings[i][j];
                s="";
                j = 0;
            }

            else{
                if (firstStrings[i][j]==from){
                    s+= to;
                }
                else{
                    s+=firstStrings[i][j];
                }
                j++;
            }
        }
        if (s==secondStrings[i]){
            result.push_back("YES");
        }
        else{
            result.push_back("NO");
        }
    return result;
}
    


int main(){
    vector<string> result = canBeEqualized({"aaabbb"}, {"abbbbb"});
    for (int i=0;i<result.size();i++){
        cout << result[i] << endl;
    }
}
/*
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string firstStrings_count_temp;
    getline(cin, firstStrings_count_temp);

    int firstStrings_count = stoi(ltrim(rtrim(firstStrings_count_temp)));

    vector<string> firstStrings(firstStrings_count);

    for (int i = 0; i < firstStrings_count; i++) {
        string firstStrings_item;
        getline(cin, firstStrings_item);

        firstStrings[i] = firstStrings_item;
    }

    string secondStrings_count_temp;
    getline(cin, secondStrings_count_temp);

    int secondStrings_count = stoi(ltrim(rtrim(secondStrings_count_temp)));

    vector<string> secondStrings(secondStrings_count);

    for (int i = 0; i < secondStrings_count; i++) {
        string secondStrings_item;
        getline(cin, secondStrings_item);

        secondStrings[i] = secondStrings_item;
    }

    vector<string> result = canBeEqualized(firstStrings, secondStrings);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
*/
