# 1541 parentheses equation
expr = input().strip()

parts = expr.split('-')

sums = []
for part in parts:
    nums = map(int, part.split('+'))
    sums.append(sum(nums))

result = sums[0] - sum(sums[1:])

print(result)
