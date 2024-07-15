import random

def mod_exp(base, exp, mod):
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        exp = exp // 2
        base = (base * base) % mod
    return result

def diffie_hellman():
    
    a_public = mod_exp(g, a_private, p)
    b_public = mod_exp(g, b_private, p)

    USER1_shared_secret = mod_exp(b_public, a_private, p)
    USER2_shared_secret = mod_exp(a_public, b_private, p)

    return USER1_shared_secret, USER2_shared_secret

if __name__ == "__main__":
    p=int(input("Enter Prime No: "))
    g=int(input("Enter Primitive root "))
    a_private= int(input("Enter USER1 private key: "))
    b_private= int(input("Enter USER2 private key: "))
    USER1_secret, USER2_secret = diffie_hellman()

    print("USER1 shared secret:", USER1_secret)
    print("USER2 shared secret:", USER2_secret)