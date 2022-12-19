// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//        for(int i=0;i<=n;i++) //// my approach
//        {    
//            long double ans=pow(3,i);
//            if(ans==n)
//            {
//                return true;
//            }
//        }
//         return false;
//     }
// };



class Solution {
public:
    bool isPowerOfThree(int n) {
         // Base Cases
        if(n==0) return false;
        if(n==1) return true;
        
        return (n % 3 == 0) && (isPowerOfThree(n/3));
        
    }
};