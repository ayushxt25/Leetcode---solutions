class Solution {
public:
    int integerReplacement(int n) {
        long long x = n;
        int ans = 0;

        while(x != 1){
            if((x & 1) == 0){
                x >>= 1;
            } else if(x == 3 || ((x >> 1) & 1) == 0){
                x--;
            } else{
                x++;
            }
            ans++;
        }

        return ans;
    }
};