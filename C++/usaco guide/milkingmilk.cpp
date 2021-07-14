    #include <iostream>

    using namespace std;

    int main(){
        //*OK the cycles could repeat but I don't care because it is only just 100 cycles. 

        freopen("mixmilk.in", "r", stdin);
        freopen("mixmilk.out", "w", stdout);

        long long a_capacity, a, b_capacity, b, c_capacity, c;

        cin >> a_capacity >> a >> b_capacity >> b >> c_capacity >> c;

        for (int i=0;i<100;i++){
            //*We can tell who is pouring into who by the mod. 
            if (i % 3==0){
                //*Pour from 1st to 2nd.
                if (a <= b_capacity-b){
                    //*Can empty first and add the remaining to the second. 
                    b += a;
                    a = 0;
                    
                }
                else{
                    //*Stuff remains in a but also fill into b. 
                    a -= (b_capacity - b);
                    b = b_capacity;
                }
            }
            else if (i % 3==1){
                //*Pour from 2nd to 3rd. 
                if (b <= c_capacity-c){
                    c += b;
                    b = 0;
                }
                else{
                    b -= (c_capacity-c);
                    c = c_capacity;
                }
            }
            else if (i % 3==2){
                //*Pour from 3rd to 1st. 
                if (c <= a_capacity-a){
                    a += c;
                    c = 0;
                }
                else{
                    c -= (a_capacity-a);
                    a = a_capacity;
                }
            }
        }

        cout << a << "\n" << b << "\n" << c << "\n";
    }