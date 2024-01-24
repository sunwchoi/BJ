a, b = map(int, input().split())

def getGCD(a, b):
    r = a%b
    if r == 0 :
        return b
    return getGCD(b,r)

def getLCM(a, b, gcd):
    return a*b / gcd


gcd = getGCD(a, b)
lcm = int(getLCM(a, b, gcd))
print(gcd)
print(lcm)