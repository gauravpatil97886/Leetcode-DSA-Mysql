class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groups = {}  # Dictionary to store groups
        
        for i, size in enumerate(groupSizes):
            if size not in groups:
                groups[size] = []  # Initialize a new group if it doesn't exist
            
            groups[size].append(i)  # Add person i to the corresponding group
        
        result = []  
        
        for size, members in groups.items():
            subgroups = [members[i:i+size] for i in range(0, len(members), size)]
            result.extend(subgroups)
        
        return result
