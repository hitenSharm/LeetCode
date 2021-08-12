#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
  public:
    string genAns(string num1, string num2) {
      string ans = "";
      int carry = 0;
      int bigger = num1.length() - 1, smaller = num2.length() - 1;
      while (bigger >= 0 and smaller >= 0) {
        char t1 = num1[bigger];
        char t2 = num2[smaller];
        int t3 = (t1 - '0') + (t2 - '0') + carry;
        if (t3 < 10) {
          char c = '0' + t3;
          carry = 0;
          ans.push_back(c);
        } else {
          char c = '0' + t3 % 10;
          t3 = t3 / 10;
          carry = t3;
          ans.push_back(c);
        }
        bigger--;
        smaller--;
      }
      while (bigger>=0) {          
        int t3 = num1[bigger] - '0';
          t3+=carry;          
        if (t3 < 10) {
          char c = '0' + t3;
          carry = 0;
          ans.push_back(c);
        } else {
          char c = '0' + t3 % 10;
          t3 = t3 / 10;
          carry = t3;
          ans.push_back(c);
        }
        bigger--;
      }
      if(carry>0)ans.push_back(carry+'0');
      reverse(ans.begin(), ans.end());
      return ans;
    }

  string addStrings(string num1, string num2) {
    if (num1.length() >= num2.length()) {
      return genAns(num1, num2);
    }
    return genAns(num2, num1);
  }
};