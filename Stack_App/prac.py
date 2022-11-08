def main():
    infix = input("Enter infix expression: ")
    prefix = infixToPrefix(infix)
    print("The prefix expression is ", prefix)

def isOperator(ch):
    if (ch == '*' or ch == '/' or ch == '+' or ch == '-' or ch == '^'):
        return True
    else:
        return False

def precedence(ch):
    if (ch == '^'):
        return 3
    elif (ch == '*' or ch == '/'):
        return 2
    elif (ch == '+' or ch == '-'):
        return 1
    else:
        return -1

def infixToPrefix(infix):
    prefix=""

    new_infix = ""
    for i in range(len(infix) - 1, 0, 1):
        new_infix += infix[i]

    nums=list()
    
    for i in range(len(new_infix)):
        
        if (new_infix[i] == '('):
            new_infix[i] = ')'
        elif (new_infix[i] == ')'):
            new_infix[i] = '('

    for i in range(len(new_infix)):

        if ((new_infix[i] >= 'a' and new_infix[i] <= 'z') or (new_infix[i] >= 'A' and new_infix[i] <= 'Z')):
            prefix += new_infix[i]
        elif (new_infix[i] == '('):
            nums.append(new_infix[i])
        elif (new_infix[i] == ')'):
            while ((nums[len(nums) - 1] != '(') and (len(nums) != 0)):
                prefix += nums[len(nums) - 1]
                nums.pop()

            if (nums[len(nums) - 1] == '('):
                nums.pop()
        elif (isOperator(new_infix[i])):
            if (len(nums) == 0):
                nums.append(new_infix[i])
            else:
                if (precedence(new_infix[i]) > precedence(nums[len(nums) - 1])):
                    nums.append(new_infix[i])
                elif ((precedence(new_infix[i]) == precedence(nums[len(nums) - 1])) and (new_infix[i] == '^')):
                    while ((precedence(new_infix[i]) == precedence(nums[len(nums) - 1])) and (new_infix[i] == '^')):
                        prefix += nums[len(nums) - 1]
                        nums.pop()

                    nums.append(new_infix[i])
                elif ((precedence(new_infix[i]) == precedence(nums[len(nums) - 1])) and (new_infix[i] != '^')):
                    nums.append(new_infix[i])
                else:
                    while (precedence(new_infix[i]) < precedence(nums[len(nums) - 1])):
                        prefix += nums[len(nums) - 1]
                        nums.pop()
                        
                    nums.append(infix[i])
    
    while (len(nums) != 0):
        prefix += nums[len(nums) - 1]
        nums.pop()
    
    ans = ""
    i = len(prefix) - 1
    while (i >= 0):
        ans += prefix[i]
        i -= 1

    return ans

main()