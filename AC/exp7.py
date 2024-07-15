import math


def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        gcd, x, y = extended_gcd(b % a, a)
        return gcd, y - (b // a) * x, x

p = int(input("Enter the value of p: "))
q = int(input("Enter the value of q: "))


n = p * q
phi = (p - 1) * (q - 1)


e = 2
while e < phi:
    if math.gcd(e, phi) == 1:
        break
    else:
        e += 1

gcd, x, y = extended_gcd(e, phi)
d = x % phi  


m = int(input("Enter the value of m: "))

ct = pow(m, e) %n
print("Cipher text:", ct)

dt = pow(ct, d) %n
print("Decrypted text:", dt)

print("\nPublic Key (e, n):", (e, n))
print("Private Key (d, n):", (d, n))