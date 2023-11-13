#include <iostream>
#include <algorithm>

class Solution {
public:
    string sortVowels(string s) {
        string vowels, consonants;
        for (char c : s) {
            if (isVowel(c)) {
                vowels += c;
            } else {
                consonants += c;
            }
        }

        sort(vowels.begin(), vowels.end());

        string result;
        int vowelIndex = 0, consonantIndex = 0;
        for (char c : s) {
            if (isVowel(c)) {
                result += vowels[vowelIndex++];
            } else {
                result += consonants[consonantIndex++];
            }
        }

        return result;
    }

private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};
