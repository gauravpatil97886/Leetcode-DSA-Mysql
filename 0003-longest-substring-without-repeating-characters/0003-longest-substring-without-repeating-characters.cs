public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int n = s.Length;
        if (n <= 1) {
            return n; // No repeating characters in a string of length 0 or 1.
        }

        int maxLength = 0;
        int left = 0;
        Dictionary<char, int> charIndexMap = new Dictionary<char, int>();

        for (int right = 0; right < n; right++) {
            if (charIndexMap.ContainsKey(s[right]) && charIndexMap[s[right]] >= left) {
                // If the character is already in the current substring, update the left pointer
                // to the position after the last occurrence of this character.
                left = charIndexMap[s[right]] + 1;
            }
            
            // Update the index of the current character.
            charIndexMap[s[right]] = right;

            // Calculate the length of the current substring and update maxLength if needed.
            maxLength = Math.Max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
