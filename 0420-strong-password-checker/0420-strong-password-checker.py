class Solution:
    def strongPasswordChecker(self, s: str) -> int:
        n = len(s)
        missing = self.getMissing(s)
        replaces = 0
        oneSeq = 0
        twoSeq = 0

        i = 2
        while i < n:
            if s[i] == s[i - 1] and s[i - 1] == s[i - 2]:
                length = 2
                while i < n and s[i] == s[i - 1]:
                    length += 1
                    i += 1
                replaces += length // 3
                if length % 3 == 0:
                    oneSeq += 1
                if length % 3 == 1:
                    twoSeq += 1
            else:
                i += 1

        if n < 6:
            return max(6 - n, missing)
        if n <= 20:
            return max(replaces, missing)

        deletes = n - 20
        replaces -= min(oneSeq, deletes)
        replaces -= min(max(deletes - oneSeq, 0), twoSeq * 2) // 2
        replaces -= max(deletes - oneSeq - twoSeq * 2, 0) // 3
        return deletes + max(replaces, missing)

    def getMissing(self, s: str) -> int:
        missing = 3
        if any(c.isupper() for c in s):
            missing -= 1
        if any(c.islower() for c in s):
            missing -= 1
        if any(c.isdigit() for c in s):
            missing -= 1
        return missing
