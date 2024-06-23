from collections import deque

input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0
    # 입력 힌트

    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0
    print("곰의 초기 위치 x : {0}, y : {1}".format(bear_x, bear_y))

    # 상하좌우 방향
    direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # BFS를 위한 deque 초기화
    queue = deque([(bear_x, bear_y)])
    visited = [[False] * N for _ in range(N)]
    visited[bear_x][bear_y] = True
    
    while queue:
        x, y = queue.popleft()
        time += 1
        
        for dx, dy in direction:
            nx, ny = x + dx, y + dy
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                visited[nx][ny] = True
                if forest[nx][ny] == 0 or forest[nx][ny] <= bear_size:
                    if forest[nx][ny] == bear_size:
                        honeycomb_count += 1
                        bear_size += 1
                        forest[nx][ny] = 0
                    queue.append((nx, ny))
    
    return time

result = problem3(input)

assert result == 14
print("정답입니다.")
