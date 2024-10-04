

def fibonacci(n):
    fib_numbers = [0, 1]
    for i in range(2, n):
        fib_numbers.append(fib_numbers[i-1] + fib_numbers[i-2])
    return fib_numbers[:n]
def cube(x):
    return x ** 3
if __name__ == '__main__':
    n = int(input())
    print(list(map(cube, fibonacci(n))))