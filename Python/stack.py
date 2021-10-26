stack=[]                                #stack implementation using List
def insert_ele():
    if(len(stack)==n):
        print("Stack is full")
    else:
        ele=input("Enter element:")        
        stack.append(ele)              #push operation is performed
        print(stack)
        
def rem_ele():
    if(len(stack)==0):
        print("Stack is empty")
    else:
        e=stack.pop()                      #pop operation is formed
        print("Remove element is:",e)
        print("Stack after removing is:",stack)
        
n=int(input("Enter the size of stack"))
while 1:
    print("Enter ur choice 1.insert_ele,2.rem_ele,3.Quit")
    choice=int(input())
    if(choice==1):
        insert_ele()
    elif(choice==2):
        rem_ele()
    elif(choice==3):
        break
    else:
        print("Please enter correct choice")
