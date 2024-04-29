def solve_2nd_degree(a, b, c):
    delta = b ** 2 - 4 * a * c
    print("Discriminant is:", delta)
    if delta > 0:
        print("Discriminant is strictly positive, the two solutions are:")
        x1 = (-b - delta ** 0.5) / (2 * a)
        x2 = (-b + delta ** 0.5) / (2 * a)
        print(x1)
        print(x2)
    elif delta == 0:
        print("Discriminant is zero, the solution is:")
        x = -b / (2 * a)
    else:
        print("Discriminant is strictly negative so there are no real solutions")

def solve_1st_degree(b, c):
    if c == 0:
        print("The solution is:")
        print(0)
    print("The solution is:")
    print(-c / b)
