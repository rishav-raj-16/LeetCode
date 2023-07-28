class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        n = len(capacity)
        rocks_needed = [max(0, capacity[i] - rocks[i]) for i in range(n)]

        # Sort bags based on the number of rocks needed in ascending order
        sorted_bags = sorted(range(n), key=lambda i: rocks_needed[i])

        # Distribute additional rocks to bags
        full_capacity_bags = 0
        for i in sorted_bags:
            if additionalRocks == 0:
                break

            rocks_to_add = min(additionalRocks, capacity[i] - rocks[i])
            rocks[i] += rocks_to_add
            additionalRocks -= rocks_to_add

            if rocks[i] == capacity[i]:
                full_capacity_bags += 1

        return full_capacity_bags


        