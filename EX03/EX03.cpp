#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX; // Constante que representa o valor "infinito"

// Estrutura para representar uma aresta (nó de destino e peso da aresta)
typedef pair<int, int> Edge;

// Função que implementa o algoritmo de Dijkstra para encontrar as distâncias mínimas de um nó de início
vector<int> dijkstra(int n, int start, vector<vector<Edge>>& adj) {
    vector<int> dist(n, INF); // Vetor que armazena as distâncias mínimas de 'start' até cada nó
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Fila de prioridade min-heap para processar os nós
    
    dist[start] = 0; // A distância até o nó de início é sempre zero
    pq.push({0, start}); // Inserindo o nó de início na fila de prioridade

    // Enquanto houver nós a serem processados na fila de prioridade
    while (!pq.empty()) {
        int d = pq.top().first; // Distância mínima até o nó atual
        int u = pq.top().second; // Identificador do nó atual
        pq.pop();
        
        // Se a distância retirada da fila for maior do que a armazenada, ignoramos
        if (d > dist[u]) continue;
        
        // Para cada aresta do nó 'u', verificamos se encontramos um caminho mais curto
        for (auto& edge : adj[u]) {
            int v = edge.first; // Nó destino da aresta
            int weight = edge.second; // Peso da aresta
            
            // Se a distância até 'v' através de 'u' for menor, atualizamos
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Inserimos a nova distância e nó na fila de prioridade
            }
        }
    }
    
    return dist; // Retornamos o vetor com as distâncias mínimas
}

// Função para calcular a menor distância máxima entre o nó inicial e cada nó usando Dijkstra
vector<int> dijkstra_min_max(int n, int start, vector<vector<Edge>>& adj) {
    vector<int> dist(n, INF); // Inicializamos as distâncias com "infinito"
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Fila de prioridade min-heap

    dist[start] = 0;
    pq.push({0, start});

    // Processamos a fila de prioridade
    while (!pq.empty()) {
        int max_weight = pq.top().first; // Maior peso no caminho até o nó atual
        int u = pq.top().second; // Identificador do nó atual
        pq.pop();

        if (max_weight > dist[u]) continue;

        // Para cada aresta do nó 'u', calculamos o novo máximo e verificamos se é melhor
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            int new_max = max(dist[u], weight);
            if (new_max < dist[v]) {
                dist[v] = new_max;
                pq.push({new_max, v});
            }
        }
    }

    return dist; // Retornamos as menores distâncias máximas
}

// Função para calcular a maior distância mínima entre o nó inicial e cada nó usando Dijkstra
vector<int> dijkstra_max_min(int n, int start, vector<vector<Edge>>& adj) {
    vector<int> dist(n, 0); // Inicializamos as distâncias com zero (o menor valor possível)
    priority_queue<Edge> pq; // Fila de prioridade max-heap

    dist[start] = INF; // A maior distância mínima até o nó inicial é "infinito"
    pq.push({INF, start});

    while (!pq.empty()) {
        int min_weight = pq.top().first; // Menor peso no caminho até o nó atual
        int u = pq.top().second;
        pq.pop();

        if (min_weight < dist[u]) continue;

        // Para cada aresta do nó 'u', calculamos o novo mínimo e verificamos se é melhor
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            int new_min = min(dist[u], weight);
            if (new_min > dist[v]) {
                dist[v] = new_min;
                pq.push({new_min, v});
            }
        }
    }

    return dist; // Retornamos as maiores distâncias mínimas
}

int main() {
    int n = 5; // Número de nós no grafo
    vector<vector<Edge>> adj(n); // Lista de adjacência para representar o grafo
    
    // Adicionando arestas ao grafo (nó origem, nó destino, peso)
    adj[0].push_back({1, 10});
    adj[0].push_back({3, 5});
    adj[1].push_back({2, 1});
    adj[3].push_back({1, 2});
    adj[3].push_back({2, 9});
    adj[3].push_back({4, 2});
    adj[4].push_back({0, 7});
    adj[4].push_back({2, 6});
    
    // Executando o algoritmo de Dijkstra a partir do nó 0
    vector<int> dist = dijkstra(n, 0, adj);
    
    // Exibindo as distâncias mínimas do nó 0 até os outros nós
    for (int i = 0; i < n; ++i) {
        cout << "Distância até " << i << ": " << dist[i] << endl;
    }
    
    return 0;
}
