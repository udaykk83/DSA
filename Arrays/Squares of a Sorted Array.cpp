/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

*/
 
 vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int left=0;int right=n-1;
        while(left<=right){
            if(left==right){
                ans.push_back(nums[left]*nums[left]);
                break;
            }
            if(abs(nums[left])<abs(nums[right])){
                ans.push_back(nums[right]*nums[right]);
                right--;
            }
            else{
                ans.push_back(nums[left]*nums[left]);
                left++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;        
    }