class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        int h = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int papers = n - mid; // number of papers with >= citations[mid]
            
            if (citations[mid] >= papers) {
                h = papers;        // possible h-index
                right = mid - 1;   // try to find smaller index
            } else {
                left = mid + 1;    // need more citations
            }
        }
        return h;
    }
};
