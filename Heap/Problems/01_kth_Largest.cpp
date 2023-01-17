//bruforce TC:O(n log n)  SC:O(1)
int findKthLargest(vector<int>& nums, int k) {
         sort(nums.begin(),nums.end(),greater<int>());
         return nums[k-1];
}

//optimised using min-heap TC:O(n log k)  SC:O(k)
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> mn;

        for(auto i:nums){
            mn.push(i);
            if(mn.size()>k){
                mn.pop();
            }
        }
    return mn.top();
}

//optimised using max-heap TC:O(n log n)  SC:O(n)
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> mx;
        for(auto i:nums){
            mx.push(i);
        }
        while(--k){
            mx.pop();
        }
     return mx.top();
}

//more optimised is quick select technique
