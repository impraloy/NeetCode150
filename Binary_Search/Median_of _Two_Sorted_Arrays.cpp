/*
Test Case 1:
Input: nums1 = [1,2], nums2 = [3]
Output: 2.0

Test Case 2:
Input: nums1 = [1,3], nums2 = [2,4]
Output: 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& m = nums1;
        vector<int>& n = nums2;


        int mSize = m.size();
        int nSize = n.size();
        
        if( nSize <  mSize){
            swap(m, n);
            swap(mSize, nSize);
        }

        int total = mSize + nSize;
        int half = (total + 1)/2;
        int low = 0;
        int high = mSize;

        while(low <= high){
            int midM = (low + high)/ 2;
            int midN = half - midM;

            int Mlow =  midM > 0 ? m[midM - 1] : INT_MIN;
            int Nlow = midN > 0 ? n[midN - 1] : INT_MIN;
            int Mhigh = midM < mSize ? m[midM] : INT_MAX;
            int Nhigh = midN < nSize ? n[midN] : INT_MAX;

            if(Mlow <= Nhigh && Nlow <= Mhigh){
                if(total % 2 != 0){
                return max(Mlow, Nlow);
                }
                return (max(Mlow, Nlow) + min(Mhigh, Nhigh)) / 2.0;
            }else if(Mlow > Nhigh){
                high = midM - 1;
            }else{
                low = midM + 1;
            }

        }
        return -1;

        
    }
};
