#include <iostream>
#include <string>
#include <bits/stdc++.h>
// #include <vector>
// #include <set>
// #include <map>
// #include <stack>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fo(i, a, b) for (int i = a; i < b; i++)
#define sqr(x) ((ll)(x) * (x))
#define p(a) cout << a << "\n"
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);



void solve(int t)
{
    int n;
    string Inputs, Outputs;
    cin >> n;
    char iArr[n], oArr[n];
    vector<int> noHuddle;
    vector<int> Huddle;
    // vector<int>
    cin >> Inputs;
    cin >> Outputs;
    fo(i, 0, n)
    {
        iArr[i] = Inputs[i];
        oArr[i] = Outputs[i];
        if (Inputs[i] == 'Y' && Outputs[i] == 'Y')
        {
            noHuddle.push_back(i);
        }
    }
    char matrix[n][n];
    // PrintArr(iArr, n);
    // PrintArr(oArr, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 'Y';
            if (i - j == 1 || i - j == -1)
            {
                if (Outputs[i] != 'Y' || Inputs[j] != 'Y')
                {
                    matrix[i][j] = 'N';
                }
            }

            else if (i > j)
            {
                for (int k = j + 1; k < i; k++)
                {
                    if (find(noHuddle.begin(), noHuddle.end(), k) == noHuddle.end() || Outputs[i] != 'Y' || Inputs[j] != 'Y')
                    {
                        matrix[i][j] = 'N';
                    }
                }
            }
            else if (i < j)
            {
                for (int k = i + 1; k < j; k++)
                {
                    if (find(noHuddle.begin(), noHuddle.end(), k) == noHuddle.end() || Outputs[i] != 'Y' || Inputs[j] != 'Y')
                    {
                        matrix[i][j] = 'N';
                    }
                }
            }
        }
    }
    cout << "Case #" << t << ":" << endl;
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{

    freopen("inputfbq1.txt", "r", stdin);
    freopen("OUTPUTFBQ11.txt", "w", stdout);
    int t;
    cin >> t;
    fo(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}
