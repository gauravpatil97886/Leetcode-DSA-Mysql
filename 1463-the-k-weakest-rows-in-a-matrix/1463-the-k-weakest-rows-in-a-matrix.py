class Solution:
    def kWeakestRows(self, mat, k):
        rows = [(sum(row), i) for i, row in enumerate(mat)]
        rows.sort(key=lambda x: (x[0], x[1]))
        weakest_rows = [row[1] for row in rows[:k]]
        return weakest_rows
