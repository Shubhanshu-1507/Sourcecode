def fibonacci(n):
    # Base cases: Fibonacci(0) = 0, Fibonacci(1) = 1
    if n == 0:
        return 0
    elif n == 1:
        return 1

    # Create a list to store Fibonacci numbers
    fib = [0] * (n + 1)
    fib[0], fib[1] = 0, 1

    # Fill the array by calculating each Fibonacci number from the previous two
    for i in range(2, n + 1):
        fib[i] = fib[i - 1] + fib[i - 2]

    return fib[n]

# Example usage
n = 10
print(f"The {n}th Fibonacci number is: {fibonacci(n)}")
