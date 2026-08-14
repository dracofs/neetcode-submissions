class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        buckets = dict()
        for string in strs:

            # normalize string
            # do a char count, format str like a1b0c2..z0
            count = [0] * 26
            res = ""
            for char in string:
                count[ord(char) - ord('a')] += 1
            
            for i in range(len(count)):
                res += str(i + ord('a')) + str(count[i])

            if res not in buckets:
                buckets[res] = [string]
            else:
                buckets[res].append(string)
        
        ret = []
        for key, value in buckets.items():
            ret.append(value)
        return ret
