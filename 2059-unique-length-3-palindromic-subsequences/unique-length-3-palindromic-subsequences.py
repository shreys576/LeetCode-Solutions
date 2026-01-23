class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        uniq = list(set(s))
        idx = {ch: i for i, ch in enumerate(uniq)}
        m = len(uniq)
        
        # suffix counts: how many of each char appear at or after current position
        suffix = [0] * m
        for ch in s:
            suffix[idx[ch]] += 1
        
        prefix = [0] * m  # counts of chars strictly before current position
        seen = set()      # set of distinct 3-letter palindromes (c + mid + c)
        
        for ch in s:
            # current char is considered as the middle character; remove it from suffix
            suffix[idx[ch]] -= 1
            
            # any character c that appears both before and after this middle forms c+ch+c
            for c_i, c in enumerate(uniq):
                if prefix[c_i] > 0 and suffix[c_i] > 0:
                    seen.add(c + ch + c)
            
            # now include current char into prefix for next iterations
            prefix[idx[ch]] += 1
        
        return len(seen)