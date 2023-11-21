#include <bits/stdc++.h>
using namespace std;
int main()
{
    float a[100][100], x[100], r;

    int i,j,k,n;

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<n-1;i++){
        if(a[i][i] == 0.0){
            cout << "Error\n";
            return 0;
        }

        for(int j = i+1;j<n;j++){
            r = a[j][i]/a[i][i];
            for(int k = 0; k<=n;k++){
                a[j][k] = a[j][k] - r*a[i][k];
            }
        }
    }

    x[n-1] = a[n-1][n]/a[n-1][n-1];

    for(int i=n-2; i>=0; i--){
        x[i] = a[i][n];

        for(int j= i+1; j<n;j++){
            x[i] = x[i] - a[i][j]*x[j];
        }

        x[i] = x[i]/a[i][i];
    }

    for(int i=0;i<n;i++){
        cout << "x "<< i+1 << ": " << x[i] << endl;
    }
}
