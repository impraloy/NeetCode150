/*
Test case 1:
Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 10
Output: true

Test case 2:
Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 15
Output: false
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = rows * cols - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int row = mid/cols, col = mid % cols;

            if(target > matrix[row][col]){
                low = mid + 1;
            }else if(target < matrix[row][col]){
                high = mid - 1;
            }else{
                return true;
            }
        }
        return false;
        
    }
};
