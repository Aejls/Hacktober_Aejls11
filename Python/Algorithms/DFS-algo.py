# a program to implement depth first search algorithm

ad_max= [
    #0 1 2 3 4 5 6 7 8 9 10 11 
    [0,1,0,0,0,0,1,1,0,0,0,0],#0
    [1,0,1,0,0,1,0,0,0,0,0,0],#1
    [0,1,0,1,1,0,0,0,0,0,0,0],#2
    [0,0,1,0,0,0,0,0,0,0,0,0],#3
    [0,0,1,0,0,0,0,0,0,0,0,0],#4
    [0,1,0,0,0,0,0,0,0,0,0,0],#5
    [1,0,0,0,0,0,0,0,0,0,0,0],#6
    [1,0,0,0,0,0,0,0,1,0,0,1],#7
    [0,0,0,0,0,0,0,1,0,1,1,0],#8
    [0,0,0,0,0,0,0,0,1,0,0,0],#9
    [0,0,0,0,0,0,0,0,1,0,0,0],#10
    [0,0,0,0,0,0,0,1,0,0,0,0],#11
]

visited = [0,0,0,0,0,0,0,0,0,0,0,0]
ans=[]
stack=[]

def stack_display():
    for val in stack:
        print(val,end=" ")
    print()

def dfa(n) :
    if visited[n]!=0 :
        return 
    else:
        visited[n] = 1
        stack.append(n)
        stack_display()
        num=0


        for relation in ad_max[n] :
            if relation !=0:
                dfa(num)
            num = num+1
        #print(n)
        ans.append(n)
        stack.pop()
        stack_display()

src_node = int(input("Enter  node number: "))
dfa(src_node)


# output of the program
# Enter  node number: 2
# 2 
# 2 1 
# 2 1 0 
# 2 1 0 6 
# 2 1 0 
# 2 1 0 7 
# 2 1 0 7 8 
# 2 1 0 7 8 9 
# 2 1 0 7 8 
# 2 1 0 7 8 10 
# 2 1 0 7 8 
# 2 1 0 7 
# 2 1 0 7 11 
# 2 1 0 7 
# 2 1 0 
# 2 1 
# 2 1 5 
# 2 1 
# 2 
# 2 3 
# 2 
# 2 4 
# 2 
