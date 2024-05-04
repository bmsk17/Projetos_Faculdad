#include <iostream>
#include <cstring>

using namespace std;




INICIALIZA(G,s)         // Grafffo e origen
    para cada v E G.V   // Pega todos os vertice do grafo e
    v.d = ∞             // todos os verticec: ficam com distancia ininita
    v.π = NIL           // antecessor nuulo
    s.d = 0             // distancia doinicial 0


RELAXA(u,v,w)
    se v.d > u.d+w(u,v)         // se a distancia de v fffor maior que a de u mais disrancia total
        v.d = u.d+w(u,v)        // iguala os dois
        v.π = u                 // e bota o u com antecessor de v.


DIJKSTRA(G,w,s)
    INICIALIZA(G,s)
    S = vazio
    Q = G.V
    enquanto Q 6= ∅
        u = EXTRACT-MIN(Q)
        S = S∪{u}
        para cada v ∈ G.Adj[u]
            RELAXA(u,v,w)
