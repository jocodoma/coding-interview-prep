class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return sortMerge(intervals);
    }

    // time complexity: O(nlogn) due to sorting algorithm
    // space complexity: O(1)
    vector<vector<int>> sortMerge(vector<vector<int>& intervals>){
        if(intervals.empty()) return {};

        int len = intervals.size();
        std::vector<std::vector<int>> result;
        std::sort(intervals.begin(), intervals.end(), 
            [](std::vector<int>& l, std::vector<int>& r){return l[0] < r[0];});  // lambda expression

        int i = 0;
        while(i < len - 1){
            if(intervals[i][1] < intervals[i+1][0]){
                result.push_back(intervals[i]);
            }
            else if(intervals[i][1] >= intervals[i+1][0] && intervals[i][1] <= intervals[i+1][1]){
                intervals[i+1][0] = intervals[i][0];
            }
            else{
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = intervals[i][1];
            }
            i++;
        }
        result.push_back(intervals[i]);
        return result;
    }
};
