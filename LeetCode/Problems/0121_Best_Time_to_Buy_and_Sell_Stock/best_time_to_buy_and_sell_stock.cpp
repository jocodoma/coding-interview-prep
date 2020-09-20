class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // return bruteForce(prices);
        return onePass(prices);
    }

    // track of the largest element in an array
    int bruteForce(vector<int>& prices){
        if(prices.empty() || prices.size() < 2) return 0;
        int maxProfitSoFar = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i + 1; j < prices.size(); j++){
                int profit = prices[j] - prices[i];
                if(profit > maxProfitSoFar) maxProfitSoFar = profit;
            }
        }
        return maxProfitSoFar;
    }

    // track the max profit so far
    int onePass(vector<int>& prices){
        if(prices.empty() || prices.size() < 2) return 0;
        int minPriceSoFar = prices[0];
        int maxProfitSoFar = 0;
        for(int i = 1; i < prices.size(); i++){
            // minimum price so far from day 0 to day i
            minPriceSoFar = std::min(minPriceSoFar, prices[i]);
            // maximum profit so far from day 0 to day i
            maxProfitSoFar = std::max(maxProfitSoFar, prices[i] - minPriceSoFar);
        }
        return maxProfitSoFar;
    }
};
