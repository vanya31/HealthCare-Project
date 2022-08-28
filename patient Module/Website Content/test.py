def _sum(arr):
    sum = 0
    for i in arr:
        sum = sum + i
 
    return(sum)
 
arr = []
n = int(input())
for i in range(0, n):
    ele = int(input())
  
    arr.append(ele) 
n = len(arr)
 
ans = _sum(arr) 
print(ans)