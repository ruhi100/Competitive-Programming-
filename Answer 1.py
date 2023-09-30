
for _ in range(int(input())):
    n, H = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    l = 0
    h = max(a)
    def isvalid(enemy_strengths, initial_strength, resistance):
        for strength in enemy_strengths:
            if strength > resistance:
                if initial_strength <= strength:
                    return False
                else:
                    initial_strength -= strength
        return True
    while l<h:
        mid = (l+h)//2
        
        if isvalid(a,H,mid):
            h = mid
        else:
            l = mid+1
    print(l)
