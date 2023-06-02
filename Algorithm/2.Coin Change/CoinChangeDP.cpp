#include <iostream>
using namespace std;

int coinChange(int coin[], int Num_coin, int amount){

    if (amount < 1)
        return 0;

    int minCoinDP[amount + 1];
    minCoinDP[0] = 0;
    for (int i = 1; i <= amount; i++){
        minCoinDP[i] = INT_MAX;
        for (int j = 0; j < Num_coin; j++){
            if (coin[j] <= i){
                int x = minCoinDP[i - coin[j]];
                //printf("i=%d j=%d: x:%d\n",i,j,minCoinDP[i - coin[j]]);
                if (x != INT_MAX && x + 1 < minCoinDP[i]){
                    minCoinDP[i] = 1 + x;
                    //printf("DP: %d\n\n",minCoinDP[i]);
                }
            }
        }
    }
    if (minCoinDP[amount] == INT_MAX)
        return -1;
    return minCoinDP[amount];
}

int main()
{
    int coin[] = {1, 5};
    int Num_coin = sizeof(coin) / sizeof(coin[0]);
    int amount = 7;

    int minCoin = coinChange(coin, Num_coin, amount);
    printf("\nTotal number of coins: %d", minCoin);
}