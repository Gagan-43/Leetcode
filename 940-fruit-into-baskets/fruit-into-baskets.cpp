class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int low=0;      
       int res=0;
        unordered_map<int,int> mp1;
        for(int high=0;high<fruits.size();high++){
            mp1[fruits[high]]++;
            while(mp1.size()>2){
               mp1[fruits[low]]--;
            if(mp1[fruits[low]]==0){
                mp1.erase(fruits[low]);}
                  low++;
               
            }
                 
         res=max(res,high-low+1);
          }
            return res;
    }
};