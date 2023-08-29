## Recursion and Backtracking
### Subset sum-II 
- [Problem link](https://leetcode.com/problems/subsets-ii/)
#### Intuition
- We need to sort the array first in order to eliminate the duplicate subsets created by duplicated elements. Whenever a value is encountered first time we add it to the all the existing subsets then we add its duplicates to subset created in previous step.
- In other words, we treat a group of duplicate elements as an array. Suppose we have an array [3, 3, 3]. The ways to add the elements from this array to the existing subsets are as follows:
  - Not add any element having value 3 in any subset.
  - Add one 3 in all the subsets.
  - Add two 3 in all the subsets.
  - Add three 3 in all the subsets.
 
#### Algorithm
- First sort the array
- We will then store empty array in final result array, after that we will traverse element one by one pushing each element to temp array(ds as in code) and if in a iteration you find two same element then we will avoid the duplicate after considering the first elemnt of its kind.
  - So if the array is [1,2,2], we will choose first 2 and avoid second 2 in first iteration
    >if(i != idx && nums[i] == nums[i+1]) continue;
  -After every subset of one element is complete we will remove the from the temp array recursively and start the iteration from next element.
    >In array [1,2,2] when every subset of one is complete then start making subset of first 2.

#### Code

public:

    void helperFun(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> ds){
        ans.push_back(ds);
        for(int i = idx; i < nums.size(); i++){
            //This line is necessary to check if the next iteration starts with the same element which is the not the index that is called from the previous stack function
            if(i != idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            helperFun(nums, i+1, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        helperFun(nums,0, ans, ds);
        return ans;
    }
