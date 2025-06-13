def postfix(expr):
    stack=[]
    split_expr = expr.split()
    for token in split_expr:
        if (token.isdigit()):
            stack.append(float(token))
        else:
            op1=stack.pop()
            op2=stack.pop()
            if token== '+':
                result = op2 +op1
            elif token== '-':
                result= op2 -op1
            elif token== '/':
                result= op2 /op1
            elif token== '*':
                result= op2 *op1
            else:
                result= op2**op1
            stack.append(result)
    return stack.pop()

inp_expr = input("Enter postfix expression: ")
answer = postfix(inp_expr)
print(f"Result of {inp_expr} is: {answer}")