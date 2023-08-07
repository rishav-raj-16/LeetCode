class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices % 2 == 0 && cheeseSlices <= tomatoSlices/2 && tomatoSlices <= cheeseSlices *4)
            return {(tomatoSlices/2)-cheeseSlices,(2*cheeseSlices) - (tomatoSlices/2)};
        return {};
    }
};