//
//  main.cpp
//  minNumberOfCoins
//
//  Created by adeeb mohammed on 25/02/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>

// time complexity is o(d*n) d->denomination
// space complexity is o(n)

int minNumberOfCoinsForChange(int n, std::vector<int> denoms) {
    std::vector<int> numOfCoins(n + 1,INT_MAX);
    numOfCoins.at(0) = 0;
    int toCompare = 0;
    for(auto denom : denoms ){
        for(int amount = 0; amount < n+1; amount++){
            if(denom <= amount){
                if(numOfCoins[amount - denom] == INT_MAX){
                    toCompare = numOfCoins[amount - denom];
                }else{
                    toCompare = numOfCoins[amount - denom]+1;
                }
                numOfCoins[amount] = std::min(toCompare,numOfCoins[amount]);
            }
        }
    }
    return numOfCoins.at(n) != INT_MAX?numOfCoins.at(n):-1;
}

int main(int argc, const char * argv[]) {
    std::cout << "Min No of coins to make Sum" << minNumberOfCoinsForChange(5, {1,2,3,20})<< std::endl;
    return 0;
}
