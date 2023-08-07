class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x , y;
        x = (tomatoSlices/2)-cheeseSlices;
        y = (2*cheeseSlices) - (tomatoSlices/2);
        
        if(tomatoSlices % 2 == 0 && cheeseSlices <= tomatoSlices/2 && tomatoSlices <= cheeseSlices *4)
            return {x,y};
        return {};
    }
};