
import java.util.ArrayList;
import java.util.List;

public class Solution {

    private static final int[] ITEM_VALUES_RANGE = {1, 1000};

    public List<List<Integer>> mergeSimilarItems(int[][] firstItems, int[][] secondItems) {
        int[] sumWeightPerValue = new int[ITEM_VALUES_RANGE[1] + 1];
        for (int[] item : firstItems) {
            sumWeightPerValue[item[0]] += item[1];
        }
        for (int[] item : secondItems) {
            sumWeightPerValue[item[0]] += item[1];
        }

        List<List<Integer>> mergedSimilarItems = new ArrayList<>();
        for (int i = 0; i < sumWeightPerValue.length; ++i) {
            if (sumWeightPerValue[i] > 0) {
                mergedSimilarItems.add(List.of(i, sumWeightPerValue[i]));
            }
        }
        return mergedSimilarItems;
    }
}
