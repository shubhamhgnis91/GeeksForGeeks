#User function Template for python3

class Solution:
    
    def subsets(self, arr):
        # code here
        self.res = []
        def solve(ip, op):
            if len(ip) == 0:
                self.res.append(op)
                return
            
            op1 = op.copy()
            op2 = op.copy()
            op2.append(ip[0])
        
            
            solve(ip[1:], op1)
            solve(ip[1:], op2)

        
        solve(arr, [])
        return sorted(self.res)