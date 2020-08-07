/*
    Author  : debugster
    Email   : alive.dew@gmail.com
    Date    : 2020-08-05 21:05:34
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <string>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>    // PBDS
#include <ext/pb_ds/tree_policy.hpp>        // PBDS

using namespace std;
using namespace __gnu_pbds;                 // PBDS

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS_INT;               // PBDS for int
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> PBDS_LL;    // PBDS for long long

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define EPS 1e-9
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI

#define value_at_index(x) find_by_order(x)
#define index_of(x) order_of_key(x)

#define pq priority_queue

/* macro ends */

/* function starts */

/// calculates n-th (0-based) Gray Code
template<typename dataType>
dataType nthGrayCode(dataType n)
{
    return (n ^ (n >> 1));
}

/// generates all possible subsets for the given set
template<typename dataType>
void generateAllSubset(vector<dataType> &data)
{
    int i, j, n;
    n = data.size();

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << data[j] << " ";
            }
        }
        cout << "\n";
    }
}

/* function ends */

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    fastIO;

    int t, n, i, l, p;
    string str, temp;
    vector<int> ansPos;
    vector<string> all;
    queue<int> posZero, posOne;

    cin >> t;
    while (t--) {
        cin >> n >> str;
        ansPos.clear();
        all.clear();
        while (!posZero.empty()) {
            posZero.pop();
        }
        while (!posOne.empty()) {
            posOne.pop();
        }

        for (i = 0; i < n; i++) {
            if (str[i] == '0') {
                if (!posOne.empty()) {
                    p = posOne.front();
                    posOne.pop();
                    all[p] += "0";   
                }
                else {
                    p = all.size();
                    all.push_back(string("0"));
                }

                ansPos.push_back(p + 1);
                posZero.push(p);
            }
            else {
                if (!posZero.empty()) {
                    p = posZero.front();
                    posZero.pop();
                    all[p] += "1";   
                }
                else {
                    p = all.size();
                    all.push_back(string("1"));
                }

                ansPos.push_back(p + 1);
                posOne.push(p);
            }
        }

        cout << all.size() << endl;
        for (i = 0; i < n; i++) {
            cout << ansPos[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
