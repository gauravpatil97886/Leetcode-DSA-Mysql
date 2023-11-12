class Solution(object):
    def numBusesToDestination(self, routes, source, target):
        if source == target:
            return 0

        max_stop = max(max(route) for route in routes)
        if max_stop < target:
            return -1

        n = len(routes)
        mbtr = [float('inf')] * (max_stop + 1)
        mbtr[source] = 0

        while True:
            flag = False
            for r in routes:
                mini = float('inf')
                for s in r:
                    mini = min(mini, mbtr[s])
                mini += 1
                for s in r:
                    if mbtr[s] > mini:
                        mbtr[s] = mini
                        flag = True

            if not flag:
                break

        return mbtr[target] if mbtr[target] < float('inf') else -1
