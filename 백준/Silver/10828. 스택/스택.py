import sys
input = sys.stdin.readline

N = int(input())
stk = list()

for i in range(N):
    cmd = list(input().split())
    if (cmd[0] == "push"):
        stk.append(int(cmd[1]))
    elif cmd[0] == "pop":
        if len(stk):
            print(stk.pop())
        else:
            print(-1)
    elif cmd[0] == "size":
        print(len(stk))
    elif cmd[0] == "empty":
        if len(stk):
            print(0)
        else:
            print(1)
    elif cmd[0] == "top":
        l = len(stk)
        if l == 0:
            print(-1)
        else:
            print(stk[l - 1])
