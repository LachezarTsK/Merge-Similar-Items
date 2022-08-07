
/**
 * @param {number[][]} firstItems
 * @param {number[][]} secondItems
 * @return {number[][]}
 */
var mergeSimilarItems = function (firstItems, secondItems) {
    const ITEM_VALUES_RANGE = [1, 1000];
    const sumWeightPerValue = new Array(ITEM_VALUES_RANGE[1] + 1).fill(0);
    for (let item of firstItems) {
        sumWeightPerValue[item[0]] += item[1];
    }
    for (let item of secondItems) {
        sumWeightPerValue[item[0]] += item[1];
    }

    const mergedSimilarItems = [];
    for (let i = 0; i < sumWeightPerValue.length; ++i) {
        if (sumWeightPerValue[i] > 0) {
            mergedSimilarItems.push([i, sumWeightPerValue[i]]);
        }
    }
    return mergedSimilarItems;
};
