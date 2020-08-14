/*
    Author  : <<your name>>
    Email   : <<your email>>
    Date    : 2020-08-14 20:59:45
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

    int t, i, j, ans;
    string s;
    vector<int> ones;

    cin >> t;
    while (t--) {
        cin >> s;
        ones.clear();
        for (i = 0; i < s.size(); ) {
            if (s[i] == '1') {
                for (j = i + 1; j < s.size(); j++) {
                    if (s[j] == '0') {
                        break;
                    }
                }

                ones.push_back(j - i);
                i = j;
            }
            else {
                i++;
            }
        }
        ans = 0;
        sort(ones.begin(), ones.end(), greater<int>());
        for (i = 0; i < ones.size(); i += 2) {
            ans += ones[i];
        }
        cout << ans << endl;
    }

    return 0;
}
