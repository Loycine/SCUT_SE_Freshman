import sys

if __name__ == "__main__":
    n = int(input())
    
    line = sys.stdin.read()
    a = list(map(int, line.split()))
    a = sorted(a)

    maxn = a[-1] + 1
    cnt = [False for i in range(maxn)]
    prev = -1
    for i in a:
        cnt[i] = True
    for i in a:
        if i==prev:
            cnt[i] = False
        prev = i
        for j in range(i+i, maxn, i):
            cnt[j] = False
    
    ans = 0
    for i in a:
        if(cnt[i]):
            ans = ans + 1
    
    print(ans)
