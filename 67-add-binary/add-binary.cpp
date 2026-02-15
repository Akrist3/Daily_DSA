class Solution {
public:
    string addBinary(string a, string b){
        string result;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int digit_a = (i >= 0) ? a[i--] - '0' : 0;
            int digit_b = (j >= 0) ? b[j--] - '0' : 0;
            
            int sum = digit_a + digit_b + carry;
            carry = sum / 2;
            result.push_back((sum % 2) + '0');
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};