class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        stack = []
        max_area = 0
        n = len(heights)

        for i in range(n):
            while stack and heights[stack[-1]] > heights[i]:
                elem = stack.pop()
                nse = i
                pse = stack[-1] if stack else -1
                max_area = max(max_area, heights[elem] * (nse - pse - 1))
            stack.append(i)

        while stack:
            nse = n  # Set nse to the rightmost index (n)
            elem = stack.pop()
            pse = stack[-1] if stack else -1
            max_area = max(max_area, (nse - pse - 1) * heights[elem])

        return max_area
