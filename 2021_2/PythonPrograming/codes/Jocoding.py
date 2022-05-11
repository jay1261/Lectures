# Youtube Jocoding Python 

# 변수에는 주소를 넣어주는거다
a = [1, 2, 3]
b = a # 주소만 넣어 주는것
a[1] = 4
print(b)
print(a is b) # a와 b가 같은가
b = a[:] # 슬라이싱을 하면 깊은복사로 해서 새로 만들어 주는 거다.
print(a is b)
from copy import copy
b = copy(a) #이것도 깊은 복사
print(a is b)

# 변수를 만드는 여러 방법
a = 1
a , b = ("python", 1) # 튜플을 이용하서 넣어주면 각각 들어간다
[a,b] = ["python", 1]
a = b = "hello"
a = 3; b = 5
a,b = b,a # swap이 이렇게 쉽게 가능
print(a,b)

# --------------- 3장 -------------------------
# 3-1. 조건문
money = True
if money:
    print("택시 타고 가라")
else:
    print("걸어 가라")

if 1 not in [1,2,3]:
    print("택시")
else:
    print("걸어가")

#조건부 표현식
score = 70
if score >= 60:
    message = "success"
else:
    message = "failure"
#위 코드와 아래 한줄 코드가 같음
message = "success" if score>=60 else "failure" # 3항 연산자 느낌 else가 꼭 필요함
print(message)

# 3-2 --- 반복분 ---
#while문
treeHit = 0
while treeHit < 10:
    treeHit = treeHit + 1 
    print("나무를 %d번 찍었다" % treeHit)
    if treeHit == 10:
        print("나무 쓰러졌다")

#for 문
test = ["one", "two", "three"]
for i in test:
    print(i)

a = [(1,2), (3,4),(5,6)]
for (first,last) in a:
    print(first+last)

marks = [90, 25, 67, 45, 80]
number = 0
for mark in marks:
    number += 1
    if mark >= 60 :
        print("%d번 학생은 합격입니다." % number)
    else:
        print("%d번 학생은 불합격입니다." % number)

sum = 0
for i in range(1,11):
    print(i)
    sum += i
print(sum)

i=0
while i<6:
    print("*"*i)
    i += 1

i=0;j=0
while i<6:
    #i += 1
    while i<6:
        print("*",end="")
    i += 1

#리스트 내포 comprehension
a = [1,2,3]
result = [num *3 for num in a]
print(result)

result = [num *3 for num in a if num%2 ==0]
print(result)

result = [x*y for x in range(2,10) for y in range(1,10)]
print(result)

#아래 코드를 리스트 컴프리헨션으로
numbers = [1, 2, 3, 4, 5]
result = []
for n in numbers:
    if n % 2 == 1:
        result.append(n*2)
print(result)
#정답
result = [n*2 for n in numbers if n %2 == 1]
print(result)


# ================ 4장 ====================
#함수

def sum(a,b):
    result = a + b
    return result
print(sum(3,5))

def say():
    return "Hi"
print(say())

def sum(a,b):
    print("%d, %d의 합은 %d" % (a,b,a+b))
sum(1,2)

def sum_many(*args):
    sum = 0 
    for i in args:
        sum = sum + i
    return sum
print(sum_many(1,2,3))

def print_kwargs(**kwargs):
    for k in kwargs.keys():
        if(k == "name"):
            print("당신의 이름은 :" + k)
print(print_kwargs(name = "조수",b="2"))

#lambda 함수

add = lambda a,b : a+b
print(add(1,2))

mylist = [lambda a,b:a+b, lambda a,b : a-b]
print(mylist[0](1,2))
print(mylist[1](1,2))

#---------------- 사용자 입력 출력 ------------------
#input
a = input("숫자 입력")
print(a)

print('life','is','too','short',end = " ")
#-------------------파일 읽고쓰기-----------------------------

f = open('새파일.txt', "w", encoding='UTF-8')
for i in range(1,11):
    data = "%d번째 줄 입니다.\n" % i
    f.write(data)
f.close()

f2 = open('새파일.txt', "r", encoding='UTF-8')
lines = f2.readlines()
for line in lines:
    print(line,end="")
f2.close()

with open("새파일.txt","r")as f:
    lines = f.readlines()
    for line in lines:
        print(line,end="")



