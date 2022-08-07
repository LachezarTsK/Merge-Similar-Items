
#include <vector>
using namespace std;

class Solution {
    
    inline static constexpr array<int, 2> ITEM_VALUES_RANGE {1, 1000};
    
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& firstItems, vector<vector<int>>& secondItems) {
        array<int, ITEM_VALUES_RANGE[1] + 1 > sumWeightPerValue{};
        for (const auto& item : firstItems) {
            sumWeightPerValue[item[0]] += item[1];
        }
        for (const auto& item : secondItems) {
            sumWeightPerValue[item[0]] += item[1];
        }

        vector<vector<int>> mergedSimilarItems;
        for (int i = 0; i < sumWeightPerValue.size(); ++i) {
            if (sumWeightPerValue[i] > 0) {
                mergedSimilarItems.push_back(vector<int>{i, sumWeightPerValue[i]});
            }
        }
        return mergedSimilarItems;
    }
};
