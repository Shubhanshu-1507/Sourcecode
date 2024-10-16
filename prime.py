# Function to check if a number is prime
def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

# Function to print prime numbers in a given range
def print_prime_numbers(start, end):
    prime_numbers = [num for num in range(start, end + 1) if is_prime(num)]
    print("Prime numbers between", start, "and", end, ":", prime_numbers)
