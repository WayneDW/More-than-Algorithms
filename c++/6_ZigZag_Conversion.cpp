class Solution {
public:
	string convert(string s, int nRows) {
		if ((s.size() <= nRows) or (nRows < 2))
			return s;
		string sub;
		for (int i = 0; i < nRows; i++) {
			int tmp = 0;
			while (tmp + i < s.size()) {
				if ((i > 0) and (i < nRows - 1) and (tmp > i))
					sub.push_back(s[tmp - i]);
				sub.push_back(s[tmp + i]);
				tmp += 2 * (nRows - 1);
			}
			if ((tmp + i >= s.size()) and (tmp - i < s.size()) and (i < nRows - 1)) 
				sub.push_back(s[tmp - i]);
		}
		return sub;	
	}
};