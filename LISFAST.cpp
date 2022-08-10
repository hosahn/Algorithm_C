#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
const long long NEGINFA = numeric_limits<long long>::min();
int n;
vector<long long> vt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vt.push_back(NEGINFA);
    long long num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > vt.back()) {
            vt.push_back(num);
        }
        else {
            int index = lower_bound(vt.begin(), vt.end(), num) - vt.begin();
            vt[index] = num;
        }
    }
    cout << vt.size() -1 << endl;
    for(int i = 1; i < vt.size(); i++){
        cout << vt[i] << " ";
    }
    return 0;
}
