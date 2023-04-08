import math

def min_lasers(n):
    # Calculate the minimum number of lasers required to accommodate n terrorists
    # Returns the number of lasers as an integer
    if n == 1:
        return 2  # special case for 1 terrorist
    lasers = 1
    safe_spaces = 6
    while safe_spaces < n:
        lasers += 1
        new_spaces = 3 * (lasers - 1)  # each new laser creates this many new safe spaces
        safe_spaces += new_spaces
    return lasers

# Read input
t = int(input())
for i in range(t):
    n = int(input())
    # Calculate and print output
    result = min_lasers(n)
    print(result)
