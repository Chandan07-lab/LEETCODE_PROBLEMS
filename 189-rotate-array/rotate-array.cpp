class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
     if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;
  vector<int>temp(k);
 for (int i = 0; i < k; i++) {
            temp[i] = arr[n - k + i];
        }
        for (int i = n - k; i > 0; i--) {
            arr[i + k - 1] = arr[i - 1];
        }

       
        for (int i = 0; i < k; i++) {
            arr[i] = temp[i];
        }
        
    }
};