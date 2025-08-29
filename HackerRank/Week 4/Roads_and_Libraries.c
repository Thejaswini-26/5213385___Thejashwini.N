long roadsAndLibraries(int n, int c_lib, int c_road, int cities_rows, int cities_columns, int** cities) {
   
    if (c_lib <= c_road) {
        return (long)c_lib * n;
    }

    int** adj = calloc(n + 1, sizeof(int*));
    int* adj_size = calloc(n + 1, sizeof(int));
    int* adj_capacity = calloc(n + 1, sizeof(int));

    for (int i = 0; i < cities_rows; i++) {
        int u = cities[i][0];
        int v = cities[i][1];

        if (adj_capacity[u] == 0) {
            adj_capacity[u] = 2;
            adj[u] = malloc(adj_capacity[u] * sizeof(int));
        } else if (adj_size[u] == adj_capacity[u]) {
            adj_capacity[u] *= 2;
            adj[u] = realloc(adj[u], adj_capacity[u] * sizeof(int));
        }
        adj[u][adj_size[u]++] = v;

        if (adj_capacity[v] == 0) {
            adj_capacity[v] = 2;
            adj[v] = malloc(adj_capacity[v] * sizeof(int));
        } else if (adj_size[v] == adj_capacity[v]) {
            adj_capacity[v] *= 2;
            adj[v] = realloc(adj[v], adj_capacity[v] * sizeof(int));
        }
        adj[v][adj_size[v]++] = u;
    }


    int* visited = calloc(n + 1, sizeof(int));
    long total_cost = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int* stack = malloc(n * sizeof(int));
            int top = 0;
            stack[top++] = i;
            visited[i] = 1;
            int component_size = 1;

            while (top > 0) {
                int node = stack[--top];
                for (int j = 0; j < adj_size[node]; j++) {
                    int neighbor = adj[node][j];
                    if (!visited[neighbor]) {
                        visited[neighbor] = 1;
                        stack[top++] = neighbor;
                        component_size++;
                    }
                }
            }

            free(stack);
            total_cost += c_lib + (component_size - 1) * c_road;
        }
    }

    for (int i = 0; i <= n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adj_size);
    free(adj_capacity);
    free(visited);

    return total_cost;
}