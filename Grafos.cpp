#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>


// Realizado por Alan Alvarez Puma y Jose Miguel Valdivia

template<typename T>
class Node;

template<typename T>
class Edge {
public:
    int val_edge;
    std::vector<Node<T>*> nodos;
    Edge(int val, Node<T>* src, Node<T>* dst) {
        val_edge = val;
        nodos.push_back(src);
        nodos.push_back(dst);
    }
};

template<typename T>
class Node {
public:
    T val_nodo;
    std::list<Edge<T>> aristas;
    Node(T val) :val_nodo(val) {}
};
template<class T>
class cmp {
public:
    bool operator()(const Edge<T>& a, const Edge<T>& b) {
        return a.val_edge > b.val_edge;
    }
};
template<typename T>
class Graph {
public:
    std::map<T, Node<T>*> grafo;
    bool dir;
    bool weighted;

    Graph(bool dir_a, bool weighted_a) : dir(dir_a), weighted(weighted_a) {}
    void InsertNode(T val) {
        auto veri = grafo.find(val);
        if (veri == grafo.end()) {
            grafo[val] = new Node<T>(val);
        }
    }
    void InsertEdge(T Node_start, T Node_end, int weight) {
        auto veri = grafo.find(Node_start);
        auto veri2 = grafo.find(Node_end);
        if (veri != grafo.end() && veri2 != grafo.end()) {
            Node<T>* Nodo1 = grafo[Node_start];
            Node<T>* Nodo2 = grafo[Node_end];
            if (!weighted) {
                weight = 1;
            }
            Edge<T> arista{ weight,Nodo1,Nodo2 };
            Nodo1->aristas.push_back(arista);
            if (!dir) {
                Nodo2->aristas.push_back(arista);
            }
        }
    }
    void print() {
        for (auto p : grafo) {
            std::cout << "Nodo " << p.second->val_nodo;
            std::cout << std::endl;
            for (auto k : p.second->aristas) {
                if (k.nodos[0] == p.second) {
                    std::cout << " Conectado a " << k.nodos[1]->val_nodo << " Con valor de " << k.val_edge << std::endl;
                }
                else {
                    std::cout << " Conectado a " << k.nodos[0]->val_nodo << " Con valor de " << k.val_edge << std::endl;
                }
            }
            std::cout << std::endl;
        }
    }
    void Sum_AllEdges(T start_node, std::priority_queue <Edge<T>, std::vector<Edge<T>>, cmp<T>>& pq) {
        for (auto p : grafo[start_node]->aristas) {
            pq.push(p);
        }
    }

    void Prim(T start_node) {
        std::priority_queue <Edge<T>, std::vector<Edge<T>>, cmp<T>> pq;
        std::map<T, bool> visited;
        int sum = 0;

        Sum_AllEdges(start_node, pq);
        visited[start_node] = true;
        std::vector<Edge<T>> route;
        while (!pq.empty()) {
            Edge<T> tmp = pq.top();
            pq.pop();
            Node<T>* val2 = grafo[start_node];
            if (!visited[tmp.nodos[1]->val_nodo]) {
                val2 = tmp.nodos[1];
            }
            else if (!visited[tmp.nodos[0]->val_nodo]) {
                val2 = tmp.nodos[0];
            }
            else {
                continue;
            }
            visited[val2->val_nodo] = true;
            sum += tmp.val_edge;
            route.push_back(tmp);
            Sum_AllEdges(val2->val_nodo, pq);
        }
        std::cout << "Salio la ruta de " << sum << std::endl;
        for (auto p : route) {
            std::cout << " De " << p.nodos[0]->val_nodo << " -> " << p.nodos[1]->val_nodo << std::endl;
        }
    }
};

int main()
{
    Graph<char> grafito(false, true);
    grafito.InsertNode('A');
    grafito.InsertNode('B');
    grafito.InsertNode('C');
    grafito.InsertNode('D');
    grafito.InsertNode('E');
    grafito.InsertNode('F');
    grafito.InsertNode('G');

    grafito.InsertEdge('A', 'B', 2);
    grafito.InsertEdge('A', 'C', 3);
    grafito.InsertEdge('A', 'D', 3);
    grafito.InsertEdge('B', 'C', 4);
    grafito.InsertEdge('B', 'E', 3);
    grafito.InsertEdge('C', 'D', 5);
    grafito.InsertEdge('C', 'E', 1);
    grafito.InsertEdge('C', 'F', 6);
    grafito.InsertEdge('D', 'F', 7);
    grafito.InsertEdge('E', 'F', 8);
    grafito.InsertEdge('F', 'G', 9);


    grafito.print();

    grafito.Prim('A');
}

