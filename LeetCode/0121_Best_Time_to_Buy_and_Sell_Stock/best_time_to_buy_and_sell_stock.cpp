class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // return bruteForce(prices);
        return onePass(prices);
    }

    // track of the largest element in an array
    int bruteForce(vector<int>& prices){
        if(prices.empty() || prices.size() < 2) return 0;
        int maxiProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i + 1; j < prices.size(); j++){
                int profit = prices[j] - prices[i];
                if(profit > maxiProfit) maxiProfit = profit;
            }
        }
        return maxiProfit;
    }

    // track the maxiProfit so far
    int onePass(vector<int>& prices){
        if(prices.empty() || prices.size() < 2) return 0;
        int miniPrice = prices[0];
        int maxiProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            // minimum price so far from day 0 to day i
            miniPrice = std::min(miniPrice, prices[i]);
            // maximum profit so far from day 0 to day i
            maxiProfit = std::max(maxiProfit, prices[i] - miniPrice);
        }
        return maxiProfit;
    }
};
