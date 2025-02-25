import sys
import string
from solver import solve_2nd_degree, solve_1st_degree

# left part of the equation
decimal_eq1 = 0
x_eq1 = 0
x2_eq1 = 0

# right part of the equation
decimal_eq2 = 0
x_eq2 = 0
x2_eq2 = 0

# check if the user has entered an equation
if len(sys.argv) != 2:
    print("Wrong number of arguments")
    sys.exit(1)

# Detects wether the degree is higher
if ("X^3" in sys.argv[1] or "X^4" in sys.argv[1] or "X^5" in sys.argv[1] or "X^6" in sys.argv[1] or "X^7" in sys.argv[1] or "X^8" in sys.argv[1] or "X^9" in sys.argv[1]):
    print("The polynomial degree is stricly greater than 2, I can't solve.")
    sys.exit(1)

# Detects any invalid characters
if (any(c not in " .*+-=X^0123456789" for c in sys.argv[1])):
    print("Invalid characters", [c for c in sys.argv[1] if c not in " *+-=X^0123456789"])
    sys.exit(1)

# Splits the equation into two parts and then splits the parts into arguments
eq1 = sys.argv[1].split("=")[0]
eq2 = sys.argv[1].split("=")[1]
args1 = eq1.split(" ")
args2 = eq2.split(" ")

# Extracts the coefficients of the left side equation
for i, str in enumerate(args1):
    if (len(str) > 3 and "X^" in str):
        print("The polynomial degree is stricly greater than 2, I can't solve.")
        sys.exit(1)
    if ("X^2" in str):
        tmp = float(args1[i-2])
        if (i >= 3 and args1[i-3] == '-'):
            tmp *= -1
        x2_eq1 += tmp
    elif ("X^1" in str):
        tmp = float(args1[i-2])
        if (i >= 3 and args1[i-3] == '-'):
            tmp *= -1
        x_eq1 += tmp
    elif ("X^0" in str):
        tmp = float(args1[i-2])
        if (i >= 3 and args1[i-3] == '-'):
            tmp *= -1
        decimal_eq1 += tmp

# Extracts the coefficients of the right side equation
for i, str in enumerate(args2):
    if (len(str) > 3 and "X^" in str):
        print("The polynomial degree is stricly greater than 2, I can't solve.")
        sys.exit(1)
    if ("X^2" in str):
        tmp = float(args2[i-2])
        if (i >= 3 and args2[i-3] == '-'):
            tmp *= -1
        x2_eq2 += tmp
    elif ("X^1" in str):
        tmp = float(args2[i-2])
        if (i >= 3 and args2[i-3] == '-'):
            tmp *= -1
        x_eq2 += tmp
    elif ("X^0" in str):
        tmp = float(args2[i-2])
        if (i >= 3 and args2[i-3] == '-'):
            tmp *= -1
        decimal_eq2 += tmp

# Makes the polynomial = 0
a = x2_eq1 - x2_eq2
b = x_eq1 - x_eq2
c = decimal_eq1 - decimal_eq2

if (a == 0 and b == 0 and c == 0):
    print("Equation in its reduced form: 0 = 0")
    print("Polynomial degree: 0")
    print("All real numbers are solutions")
    sys.exit(0)
elif (a == 0 and b == 0):
    print(f"Equation in its reduced form: {c} = 0")
    print("Polynomial degree: 0")
    print("There are no solutions")
    sys.exit(0)

if (a != 0):
    print(f"Equation in its reduced form: {a} * X^2 {'+ ' if b >= 0 else '- '}{abs(b)} * X {'+ ' if c >= 0 else '- '}{abs(c)} = 0")
    print("Polynomial degree: 2")
    solve_2nd_degree(a, b, c)
elif (b != 0):
    print("Equation in its reduced form: ", b, "* X +", c, "= 0")
    print("Polynomial degree: 1")
    solve_1st_degree(b, c)
else:
    print("Equation in its reduced form: ", c, "= 0")
    print("Polynomial degree: 0")
    if (c == 0):
        print("All real numbers are solutions")
    else:
        print("There are no solutions")
