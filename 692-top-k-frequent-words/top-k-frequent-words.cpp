class Solution {
public:
    struct emp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, emp> pq;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }

        for (auto i : mp) {
            pair<string, int> curr = i;
            if (pq.size() < k) {
                pq.push({curr.second, curr.first});
                continue;
            }
            pq.push({curr.second, curr.first});
            pq.pop();
        }
        vector<string> res;
        while (!pq.empty()) {
            pair<int, string> curr = pq.top();
            pq.pop();
            res.push_back(curr.second);
        }
        reverse(res.begin(),res.end());
        return res;
    }
}; 

// class Solution {
// public:
//     struct emp {
//         bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
//             if (a.first != b.first) {
//                 return a.first > b.first;
//             }
//             return a.second < b.second;
//         }
//     };

//     vector<string> topKFrequent(vector<string>& words, int k) {
//         int n = words.size();

//         unordered_map<string, int> mp;

//         for (int i = 0; i < n; i++) {
//             mp[words[i]]++;
//         }

//         priority_queue<pair<int, string>,
//         vector<pair<int, string>>, emp> pq;

//         for (auto i : mp) {
//             if (pq.size() < k) {
//                 pq.push({i.second, i.first});
//                 continue;
//             }

//             pq.push({i.second, i.first});
//             pq.pop();
//         }

//         vector<string> res;

//         while (!pq.empty()) {
//             pair<int, string> curr = pq.top();
//             pq.pop();

//             res.push_back(curr.second);
//         }

//         reverse(res.begin(), res.end());

//         return res;
//     }
// };
