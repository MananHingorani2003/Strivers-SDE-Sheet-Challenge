#include <bits/stdc++.h> 

int findMinimumCoins(int amount) 
{
    vector<int>coins{1,2,5,10,20,50,100,500,1000};
    int total=0;
    for(int i=coins.size()-1;i>=0;i--){
        if(coins[i]<=amount){
            int noOfCoins=amount/coins[i];
            total+=noOfCoins;
            amount=amount-(coins[i]*noOfCoins);
        }
        if(amount<=0){
            break;
        }
    }
    return total;
    
}
