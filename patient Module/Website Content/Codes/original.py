def partition(l, r, nums):
	pivot, ptr = nums[r], l
	for i in range(l, r):
		if nums[i] <= pivot:
			nums[i], nums[ptr] = nums[ptr], nums[i]
			ptr += 1
	nums[ptr], nums[r] = nums[r], nums[ptr]
	return ptr

def quicksort(l, r, nums):
	if len(nums) == 1: 
		return nums
	if l < r:
		pi = partition(l, r, nums)
		quicksort(l, pi-1, nums) 
		quicksort(pi+1, r, nums) 
	return nums

class Illness:
 def doctors(ele,a):
  example = { "Dr Brick Wall":"Back",
 "Dr Ether":"Back",
 "Dr Comfort":"Neck",
 "Dr Deadman":"Limbs",
 "Dr Hand":"Stomach",
 "Dr Luke":"Limbs",
 "Dr Finger":"Back",
 "Dr Neupane":"Back"
 }
  value = {i for i in example if example[i]==a}
  print(value)

class result(Illness):
 def ratings(value):
    stars={"Dr Brick Wall":5,
"Dr Ether":5,
"Dr Comfort":4,
"Dr Deadman":3,
"Dr Hand":5,
"Dr Luke":4,
"Dr Finger":2,
"Dr Neupane":3.5
}
    rate = {i for i in stars if stars[i]==value}
    print(rate)



Doctors=["Back","Neck","Limbs","Stomach","Limbs","Back","Back"]
print(Doctors)
a=input("Enter the illness area:")
print(a)
for x in Doctors:
 if x == a:
    ele=[]
    ele.append(x)
    Doctors(x,ele,a)

