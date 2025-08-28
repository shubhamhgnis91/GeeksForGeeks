class Solution:
    
    count = 0
    def  towerOfHanoi(self, n, fromm, to, aux):
        # code here
        
        def solve(n, f, t, h):
            self.count += 1
            if n == 1:
                return
            
            solve(n - 1, f, h, t)
            solve(n - 1, h, t, f)
            
        solve(n, fromm, to, aux)
        return self.count