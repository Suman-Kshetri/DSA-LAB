def postfix(exp):
    stack=[]
    operators=['+', '-', '*', '/', '^']
    tokens=exp.split()
    for token in tokens:
        if token not in operators:
            stack.append(float(token))
        else:
                op1=stack.pop()
                op2=stack.pop()
                if token=='+':result=op2+op1
                elif token=='-':result=op2-op1
                elif token=='*':result=op2*op1
                elif token=='/':result=op2/op1
                elif token=='^':result=pow(op2,op1)
                stack.append(result)
    return stack[0]
exp=input("Enter the string: ")
answer=postfix(exp)
print(f"The evaluated postfix expression is {answer}")