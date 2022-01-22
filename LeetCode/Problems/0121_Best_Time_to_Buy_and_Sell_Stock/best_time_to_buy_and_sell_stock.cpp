#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // return bruteForce(prices);
        return twoPointers(prices);
        // return onePass(prices);
    }

private:
    // time complexity: O(n**2), space complexity: O(1)
    int bruteForce(vector<int>& prices){
        if(prices.empty())
            return 0;

        int maxProfitSoFar = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i + 1; j < prices.size(); j++){
                int profit = prices[j] - prices[i];
                if(profit > maxProfitSoFar)
                    maxProfitSoFar = profit;
            }
        }

        return maxProfitSoFar;
    }

    // time complexity: O(n), space complexity: O(1)
    int twoPointers(vector<int>& prices){
        int maxProfitSoFar = 0;
        int buy = 0;
        int sell = 1;
        while(sell < prices.size()){
            int profit = prices[sell] - prices[buy];
            if(profit > 0){
                if(profit > maxProfitSoFar)
                    maxProfitSoFar = profit;
                sell++;
            }
            else{
                buy = sell;
                sell++;
            }
        }

        return maxProfitSoFar;
    }

    // keep track both minimum price and maximum profit
    // time complexity: O(n), space complexity: O(1)
    int onePass(vector<int>& prices){
        if(prices.empty())
            return 0;

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

// nums is passed by constant reference and cannot be changed by this function
string printVector(const vector<int>& nums, int len){
    string str;

    str.append("[");
    for(int i = 0; i < len; i++){
        if(i != 0)
            str.append(", ");
        str.append(std::to_string(nums[i]));
    }
    str.append("]");

    return str;
}

int main(){
    vector<int> prices1({7,1,5,3,6,4});
    int output = Solution().maxProfit(prices1);
    cout << "Input:  " << printVector(prices1, prices1.size()) << "\n";
    cout << "Output: " << output << "\n\n";

    vector<int> prices2({7,6,4,3,1});
    output = Solution().maxProfit(prices2);
    cout << "Input:  " << printVector(prices2, prices2.size()) << "\n";
    cout << "Output: " << output << "\n\n";

    return 0;
}
