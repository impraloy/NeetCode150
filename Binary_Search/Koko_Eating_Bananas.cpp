class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int results = high;

        while(low <= high){
            int k = (low + high) / 2;

            int totalTime = 0;

            for(int &p : piles){
                totalTime += ceil(static_cast<double>(p)/k);
            }

            if(totalTime <= h){
                results = k;
                high = k - 1;
            }else{
                low = k +1;
            }
        }
        return results;
        
    }
};
