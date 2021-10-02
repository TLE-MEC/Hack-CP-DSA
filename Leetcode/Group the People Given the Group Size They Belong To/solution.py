class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        dic = {}
        # First we add all people into dictionary where key will be the group size.
        for i in range(len(groupSizes)):
            if groupSizes[i] in dic:
                dic[groupSizes[i]].append(i)
            else:
                dic[groupSizes[i]] = [i]
        res = []
        print(dic)
        # Here we just separate the people into different groups according to the group sizes
        for k, v in dic.items():
            for i in range(0, len(v), k):
                res.append(v[i:i+k])
        return res
