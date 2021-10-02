class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        dic = {}
        for i in range(len(groupSizes)):
            if groupSizes[i] in dic:
                dic[groupSizes[i]].append(i)
            else:
                dic[groupSizes[i]] = [i]
        res = []
        print(dic)
        for k, v in dic.items():
            for i in range(0, len(v), k):
                res.append(v[i:i+k])
        return res
