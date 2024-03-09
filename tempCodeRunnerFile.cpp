recursion(n, 0, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << (cal[i][j]) ? '*' : ' ';
        }
        cout << endl;
    }