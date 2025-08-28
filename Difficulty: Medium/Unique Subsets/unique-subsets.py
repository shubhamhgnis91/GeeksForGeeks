class Solution:
    def AllSubsets(self, arr, n):
        self.res = []
        self.mp = {}

        def solve(ip, op):
            if len(ip) == 0:
                key = tuple(sorted(op))  # Sort to ensure uniqueness
                if key not in self.mp:
                    self.res.append(sorted(op))  # Sort each subset
                    self.mp[key] = True
                return

            op1 = op.copy()
            op2 = op.copy()
            op2.append(ip[0])

            solve(ip[1:], op1)
            solve(ip[1:], op2)

        arr.sort()  # Sort input to help with lexicographical order
        solve(arr, [])
        return sorted(self.res)
