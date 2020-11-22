class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int k = digits.size();
        int n_len = 0;
        int res = 0;
        bool digits_exist[10] = {false};
        int acc_digits[10] = {0};
        vector<int> n_digits;
        
        for (string s:digits) {
            int d = stoi(s);
            
            digits_exist[d] = true;
            for (int i = d + 1; i < 10; i++) {
                acc_digits[i]++;
            }
        }
        
        /*
        for (int i = 0; i < 10; i++) {
            cout << i << " " << digits_exist[i] << " " << acc_digits[i] << endl;
        }
        */
        
        for (int i = n; i > 0; i /= 10) {
            n_len++;
            n_digits.push_back(i % 10);
        }
        //cout << n << " n_len = " << n_len << endl;
        
        for (int i = 0; i < (n_len - 1); i++) {
            res += pow(k, (i + 1));
        }
        //cout << "first step " << res << endl;
        
        for (int i = n_digits.size() - 1; i >= 0; i--) {
            int d = n_digits[i];
            
            res += acc_digits[d] * pow(k, i);
            
            //cout << "second " << i << " " << d << " " << res << " " << acc_digits[d] << endl;
            if (!digits_exist[d]) {
                break;
            }
            
            if (i == 0) {
                res += 1;
            }
        }
        
        return res;
    }
};