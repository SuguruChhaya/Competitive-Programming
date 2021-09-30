// Created by Jesse Choe - Bronze Template

#include <bits/stdc++.h>
using namespace std;

// Type aliases

using ll = long long;
using str = string; 
using vi = vector<int>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using si = set<int>;

// Vector Operations

#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define del(x, i) erase(begin(x)+i)
#define rem(x,i) erase(begin(x), begin(x)+i)

// Pairs

#define mp make_pair
#define sec second
#define fir first

// Sets and Maps

#define ins insert
#define ez erase
#define cnt count

// Math

#define MOD 1e9+7
#define MAX_INT 1e18*9

// Permutation

#define possibilities(x) while(next_permutation(all(x))

// Loops

#define Trav(a,x) for (auto& a: x)
#define For(i,a,b) for (int i = (a); i < (b); ++i)

// Input/Output - s is basically the file name without the ".in" and ".out"

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

vi x;

int numberOfBalesBetween(int a, int b){
	int bales = 0;
	For(i, 0, x.size()){
		if(x[i] >= a && x[i] <= b){
			bales++;
		}
	}
	return bales;
}

int lastElementBetween(int a, int b){
	for(int i=x.size()-1; i>=0; i--){
		if(x[i] <= b){
			return x[i];
		}
	}
	return x.size()-1;
} 

int firstElementBetween(int a, int b){
	For(i, 0, x.size()){
		if(x[i] >= a){
			return x[i];
		}
	}
	return 0;
}

int hayBales(int start){

	int upper = start;
	int lower = start;
	
	for(int i=1; i<=100; i++){
		if(numberOfBalesBetween(lower, upper) == numberOfBalesBetween(lower-i, upper+i)){
			break;
		} else {
			lower = firstElementBetween(lower-i, upper+i);
			upper = lastElementBetween(lower-i, upper+i);
		}
	}
	return numberOfBalesBetween(lower, upper);
}

int main(){

setIO("angry"); 

int N; cin >> N;

For(i, 0, N){
	int a; cin >> a; 
	x.pb(a);
}

sor(x);

int ans = 0;

For(i, 0, N){
	ans = max(ans, hayBales(x[i]));
}

cout << ans << endl;

}