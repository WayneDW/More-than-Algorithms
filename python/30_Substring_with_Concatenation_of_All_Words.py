#!/usr/bin/python
import sys
import os

'''
For example, given:
"barfoothefoobarman"  ["foo", "bar"] return the indices: [0,9].
"barfoo-foo bar the-foobarman"  ["bar","foo","the"]   [6,9,12]
"wordgoodgoodgoodbestword", ["word","good","best","good"] [8]
'''

'''
Bad question, ambiguous target, too different kinds of return values
'''


class Solution(object):
    def findSubstring(self, s, words):
    	if len(words) == 0:
    		return None
    	n = len(s)
    	p = len(words)
    	m = len(words[0])
    	word = {}
    	for i, element in enumerate(words):
    		word[element] = word.setdefault(element, 0) + 1

    	res, order, last = [], "", 0
    	for i in range(n - m + 1):
    		for j, element in enumerate(word): # enumerate foo, bar...
    			#print i, element
    			cnt = 0
    			for k in range(m): # f - o - o
    				if s[i + k] != element[k]:
    					break
    				cnt += 1
    			if cnt == m and ((i != 0 and i - last >= m) or i == 0):
    				#print i, last, i - last, "m = ", m, last
    				res.append(i)
    				order += str(j)
    				last = i

    	q = len(res)
    	#print "q = ", q
    	if q < p:
    		return None
    	cmp = ""
    	for i, element in enumerate(word):
    		for j in range(word[element]):
    			cmp += str(i)
    	#print cmp, p, order[0:2]
    	for i in range(q - p + 1):
			cat = "".join(sorted(order[i:(p + i)]))
			if cat == cmp:
				out = []
				for k in range(p):
					out.append(res[i + k])
				return out		
    	return None        


def main():
    s = Solution()
    print s.findSubstring("barfoothefoobarman", ["bar", "foo"])
    print s.findSubstring("barfoofoobarthefoobarman", ["bar","foo","the"])
    print s.findSubstring("wordgoodgoodgoodbestword", ["word","good","best","good"])
    print s.findSubstring("aaa", ["aa","aa"])
    print s.findSubstring("aaaaaa", ["aaa","aaa"])

if __name__ == "__main__":
    main()
