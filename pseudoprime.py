from math import sqrt

primes = [2, 3]
def calc_prime(n: int):
    i = primes[-1]
    while primes[-1] < n:
        i += 2
        is_prime = True
        for p in primes:
            if p > sqrt(n):
                break
            if i % p == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(i)

def is_prime(n: int) -> bool:
    if primes[-1] < n:
        calc_prime(n)
    return n in primes

def get_remainder(p: int, a: int):
    #return (a**p) % p
    for i in range(p - 1):
        a = a*a % p
    return a

def is_pseudoprime(p: int, a: int) -> bool:
    if is_prime(p):
        return False
    return get_remainder(p, a) == a

def main():
    a, b = [int(i) for i in input().split()]
    while not (a == 0 and b == 0):
        print("yes" if is_pseudoprime(a, b) else "no")
        a, b = [int(i) for i in input().split()]

if __name__ == "__main__":
    main()
