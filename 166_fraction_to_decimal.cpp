class Solution{
public:
	 string fractionToDecimal(int64_t num, int64_t den) {
		 if (num == 0) {
			 return "0";
		 }
		 string res;
		 if (num<0 ^ den<0) {
			 res += "-";
			 num = abs(num);
			 den = abs(den);
		 }
		 res += to_string(num/den);
		 if (num%den == 0) {
			 return res;
		 }
		 res += ".";
		 unordered_map<int,int> map;
		 for (int64_t r = num%den; r; r %= den) {
    
			 if (map.count(r)>0) {
				 res.insert(map[r], 1, '(');
				 res += ")";
				 break;
			 }
			 map[r] = res.size();
			 r *= 10;
			 res += to_string(r/den);
		 }
		 return res;
	}
};