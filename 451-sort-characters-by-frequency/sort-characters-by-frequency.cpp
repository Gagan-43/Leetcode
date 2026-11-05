class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        } 
        priority_queue<pair<int,char>>pq;
        for(auto i:mp){
            pq.push({i.second,i.first});

        }
        string res="";
        while(!pq.empty()){
            pair<int,char>curr=pq.top();
            pq.pop();
            while(curr.first--){
                res.push_back(curr.second);
            }
        
        }
        return res;
    }
};