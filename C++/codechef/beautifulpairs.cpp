
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <double> arr;
        for (long long j=0;j<n;j++){
            double temp;
            cin >> temp;
            arr.push_back(temp);
        }
        long long result = 0;
        for (long long a=0;a<n;a++){
            for (long long b=a+1;b<n;b++){

                    if (((arr[a]-arr[b]) / arr[a]) < ((arr[a]-arr[b]) / arr[b])){
                        result++;
                    }
                
            }
        }
        cout << result*2 << "\n";
    }
}