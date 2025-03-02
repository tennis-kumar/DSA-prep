class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """


        # approach 1 using hashmap/dictionary
        # result = []
        # hash_map = {}

        # for number in nums:
        #     hash_map[number] = hash_map.get(number,0)+1

        # # hash_map.items() converts dict to a list of tuples eg: [(key,value),(key,value)]
        # # we use index 1 for accessing the value, index 0 for accessing the key

        # # here item[1] is the value, item[0] is the key
        # sorted_hash_map = sorted(hash_map.items(),key=lambda item:item[1],reverse=True)
        # result = [item[0] for item in sorted_hash_map[:k]]
        # # time complexity O(nlogn)

        # return result



        # approach 2 using bucket sort
        count = {}
        freq = [[] for i in range(len(nums)+1)]

        for n in nums:
            count[n] = count.get(n,0)+1
        
        # n -> number
        # c -> count/frequency of number
        for n,c in count.items():
            freq[c].append(n)

        res = []

        for i in range(len(freq) - 1,0,-1):
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res
