int minimumMoves(int grid_count, char** grid, int startX, int startY, int goalX, int goalY) {
    int visited[MAX][MAX] = {0};
    Point queue[MAX * MAX];
    int front = 0, rear = 0;

    queue[rear++] = (Point){startX, startY, 0};
    visited[startX][startY] = 1;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (front < rear) {
        Point curr = queue[front++];

        if (curr.x == goalX && curr.y == goalY) {
            return curr.moves;
        }

        for (int d = 0; d < 4; d++) {
            int nx = curr.x;
            int ny = curr.y;

            while (1) {
                nx += dx[d];
                ny += dy[d];

                if (nx < 0 || ny < 0 || nx >= grid_count || ny >= grid_count || grid[nx][ny] == 'X') {
                    break;
                }

                if (!visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    queue[rear++] = (Point){nx, ny, curr.moves + 1};
                }
            }
        }
    }

    return -1; 
}
