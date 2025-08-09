G = [
    [0, 10, 0, 5, 0],
    [0, 0, 1, 2, 0],
    [0, 0, 1, 2, 0],
    [0, 0, 0, 0, 2],
    [0, 3, 9, 0, 2],
    [7, 0, 6, 0, 0],
]

def FloydWarshall(W):
    n = len(W)
    D = dict()
    D[0] = W
    for k in range(1, n+1):
        D[k] = D[k-1]
        for i in range(1, n+1):
            for j in range(1, n+1):
                if D[k-1][i][j] > D[k-1][i][j] + D[k-1][k][j]:
                    D[k][i][j] = D[k-1][i][j]
    print(k)
    return D[k]

ans = FloydWarshall(G)
print(ans)
