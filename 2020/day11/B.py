if __name__ == "__main__":
    n = int(input())
    mp = {}
    for i in range(n):
        s = input()
        mp[s] = mp.setdefault(s, 0) + 1

    ret = ["AC", "WA", "TLE", "RE"]
    for word in ret:
        print(f"{word} x {mp.setdefault(word, 0)}")
