class Solution:
    def reconstructQueue(self, p: List[List[int]]) -> List[List[int]]:
        p=sorted(p, key=lambda x: (-x[0], x[1]))
        # print(p)
        o = []
        for i in p:
            o.insert(i[1], i)
            # print(o)
        return o