class Solution:
    def firstMissingPositive(self, nums: list) -> int:
        N = len(nums)

        # A sorted, uninterrupted list of N numbers would only contain numbers in range 0 to N-1
        # 0 is not considered positive, as shown in the examples, so our effective range is 1 to N
        # Mark all numbers outside of range 1 to N with a positve number larger than N
        for i in range(N):
            if nums[i] <= 0 or nums[i] > N:
                nums[i] = N + 1

        # If current number has already been marked or is outside of range 1 to N, continue
        # If current number is within range 1 to N and has not been marked, mark it
        # We mark current number's would-be index if it were in a sorted list starting from 1
        for i in range(N):
            v = abs(nums[i])
            if v - 1 < N and nums[v - 1] > 0:
                nums[v - 1] = -nums[v - 1]

        # After the transformations, any positive number in array indicates a missing number in range 1 to N
        for i in range(N):
            if nums[i] > 0:
                return i + 1

        return N + 1
