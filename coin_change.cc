#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <map>

using namespace std;

class CoinChange {
public:
    CoinChange(int *S, int m, int n) : coins(S), coinKinds(m), money(n) { 
        //sort(coins, coins + coinKinds);
        moneyMap.insert(make_pair(0, 1));
    }

    int cnt() {
        if (coins == NULL || coinKinds <= 0 || money <= 0) 
            return 0;
        else
            return count(money); 
    }
private:
    //去重
    int count() {

    }
    
    int count(int remainMoney, int beginIt = 0) {
        if (remainMoney < 0) return 0;
        if (remainMoney == 0) return 1;
        int retCnt = 0;
        for (int i = beginIt; i < coinKinds; ++i)
            retCnt += count(remainMoney-coins[i], i);
        return retCnt;
    }
    map<int, int> moneyMap;
    const int *coins;
    const int coinKinds;
    const int money;
};

int cnt(int S[], int m, int n, int beginIt = 0) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    int retCnt = 0;
    for (int i = beginIt; i < m; ++i)
        retCnt += cnt(S, m, n-S[i], i);
    return retCnt;
}

int count(int S[], int m, int n) {
    return cnt(S, m, n);
}

void testCnt() {
    int *s, m = 0, n = 0;
    cout << "please enter coin kinds: ";
    cin >> m;
    s = (int *)malloc(sizeof(int) * m);
    for (int i=0; i<m; ++i) {
        cout << "please enter the " << i << "th coin: ";
        cin >> s[i];
    }
    cout << "please enter money: ";
    cin >> n;

    cout << "count : " << count(s, m, n) << endl;
    free(s);
}

int main() {
    while (true)
        testCnt(); 
    return 0;
}
