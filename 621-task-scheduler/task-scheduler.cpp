class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //2420906 Gagandeep Singh
        
        vector<int> freq(26, 0);

        // Count frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        //2420906 Gagandeep Singh
        // Find maximum frequency
        int maxFreq = 0;

        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }
        //2420906 Gagandeep Singh
        // Count how many tasks have maximum frequency
        int countMax = 0;

        for (int f : freq) {
            if (f == maxFreq) {
                countMax++;
            }
        }
        //2420906 Gagandeep Singh
        // Calculate minimum intervals
        int ans = (maxFreq - 1) * (n + 1) + countMax;

        // We cannot have fewer intervals than total tasks
        return max((int)tasks.size(), ans);
    }
};