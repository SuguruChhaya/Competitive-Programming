#include <iostream>
#include <vector>

using namespace std;

int main(){

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    long long n;
    cin >> n;
    long long temp;
    //*I literally just have to construct an alternative version. 
    vector <long long> original_order, id, reverse_order, temp_id;
    //*First push back one element so no confusion. 
    original_order.push_back(0);
    reverse_order.push_back(0);
    id.push_back(0);
    //!Now I don't have to worry about indexing. 
    for (long long i=0;i<n;i++){
        cin >> temp;
        original_order.push_back(temp);
        reverse_order.push_back(0);
    }

    for (long long i=0;i<n;i++){
        cin >> temp;
        id.push_back(temp);
    }
    
    for (long long i=1;i<=n;i++){
        reverse_order[original_order[i]] = i;
    }   
    //*Create a temp vector so I don't lose. 
    for (int i=0;i<3;i++){
        temp_id = id;
        //*Editing the curr values. 
        //!I think we are actually gonna iterate over the reverse one. 
        //*I have to add an extra 0 to the ID for it to work too. 
        for (int j=0;j<reverse_order.size();j++){
            id[reverse_order[j]] = temp_id[j];
        }
    }

    for (int i=1;i<id.size();i++){
        cout << id[i] << endl;
    }
    
}