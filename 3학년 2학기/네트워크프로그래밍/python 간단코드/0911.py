a=[1,2,3,4]

result=[num*3 for num in a]
print(result)

result = [num*3 for num in a if num%2==0]
print(result)

result = [i*2 if i%2==0 else i**2 for i in range(10)]
print(result)