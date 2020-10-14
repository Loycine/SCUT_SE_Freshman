h = w = k = 0
mp = []
global_ans = 0
global_cnt = 0

def dfs(depth, state):
    global global_ans
    if(depth == h+w):
        return
    if depth == h+w-1:
        cnt = global_cnt
        rows = []
        columns = []
        for i in range(depth+1):
            cur = state[i]
            if(cur == 1):
                if(i < h):
                    rows.append(i)
                else:
                    columns.append(i-h)
        for i in rows:
            for j in columns:
                if mp[i][j] == "#":
                    cnt = cnt + 1
        for i in rows:
            for j in range(w):
                if mp[i][j] == "#":
                    cnt = cnt - 1
        for i in range(h):
            for j in columns:
                if mp[i][j] == "#":
                    cnt = cnt - 1

        if(cnt == k):
            global_ans = global_ans + 1

    new_state = state[:]

    new_state[depth] = 1
    dfs(depth+1, new_state[:])

    new_state[depth] = 0
    dfs(depth+1, new_state[:])
    

if __name__ == "__main__":
    h,w,k = map(int, input().split())

    mp = []
    for i in range(h):
        mp.append(input())
    
    global_cnt = 0
    for i in range(h):
        for j in range(w):
            if mp[i][j] == "#":
                global_cnt = global_cnt + 1

    state = [0 for i in range(h+w)]
    dfs(-1, state[:])
    print(global_ans)

