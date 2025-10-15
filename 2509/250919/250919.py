# 2166 math
n = int(input())
ox, oy = map(int, input().split())
cx, cy = map(int, input().split())
sum = 0

for i in range(n-2):
    px, py = cx, cy
    cx, cy = map(int, input().split())
    sum += 0.5*((px-ox)*(cy-oy) - (py-oy)*(cx-ox))

print(round(abs(sum), 1))