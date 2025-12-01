class Solution {
public:
    int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
    int gcdOfOddEvenSums(int n) {
        int al = 2*n;
        int e_sum =0;
        int o_sum =0;
        for(int x=1;x< al;x++){
            if(x %2 == 0) e_sum+=x;
            else o_sum+=x;
        }
        return gcd(e_sum,o_sum);
        
    }
};