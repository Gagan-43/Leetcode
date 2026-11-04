class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        while(pq.size()>1){
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            int res=abs(top1-top2);
            if(res!=0){
                pq.push(res);
            }
        }

if(pq.size()==0)return 0;
return pq.top();
    }
};