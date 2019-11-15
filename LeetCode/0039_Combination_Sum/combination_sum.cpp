class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return backtracking(candidates, target);
    }

private:
    vector<vector<int>> backtracking(vector<int>& candidates, int target){
        if(candidates.empty()) return {{}};
        std::sort(candidates.begin(), candidates.end());
        findCombinations(candidates, target, 0);
        return result;
    }

    void findCombinations(vector<int>& candidates, int target, int pos){
        if(!target){
            result.push_back(potentialComb);
            return;
        }

        for(int i = pos; i < candidates.size(); i++){
            if(candidates[i] > target) return;  // no need to check if candidates[i] is already larger than target
            potentialComb.push_back(candidates[i]);
            int newTarget = target - candidates[i];
            findCombinations(candidates, newTarget, i);
            potentialComb.pop_back();
        }
    }

    std::vector<std::vector<int>> result;
    std::vector<int> potentialComb;
};
