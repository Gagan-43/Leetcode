class Solution {
public:
    void merge(vector<int>& a, int n, vector<int>& b, int m) {
        int i = n - 1;      // a ke last valid element ka pointer
        int j = m - 1;      // b ke last element ka pointer
        int k = n + m - 1;  // final position (end of a)

        // Jab tak dono arrays mein elements bache hain
        while(i >= 0 && j >= 0) {
            if(a[i] > b[j]) {
                a[k] = a[i]; // bada element a[i] hai
                i--;
            } else {
                a[k] = b[j]; // bada element b[j] hai
                j--;
            }
            k--;
        }

        // Agar b ke elements bache hain toh unko daal do
        while(j >= 0) {
            a[k] = b[j];
            j--;
            k--;
        }
        // Agar a ke elements bache hain toh wo already sahi jagah pe hain
    }
};
