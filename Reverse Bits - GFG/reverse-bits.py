#User function Template for python3
class Solution:
    def reversedBits(self, X):
        binary = bin(X)[2:].zfill(32)

        reversed_binary = binary[::-1]

        result = int(reversed_binary, 2)
        return result



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        X=int(input())
        
        ob = Solution()
        print(ob.reversedBits(X))
# } Driver Code Ends