import networkx as nx
import matplotlib.pyplot as plt
from sys import stdin
# Crear un grafo no dirigido
G = nx.Graph()

# Agregar nodos y aristas con peso

case = [int(x) for x in stdin.readline().split()]
while case != [-1, -1, -1]:
    G.add_edge(case[0] ,case[1], weight = case[2])
    case = [int(x) for x in stdin.readline().split()]

# Mostrar los nodos y las aristas con su peso
print("Nodos:", G.nodes())
print("Aristas:", G.edges(data=True))  # Muestra las aristas con sus atributos

# Dibujar el grafo
pos = nx.spring_layout(G, k=1.5)  # Aumenta k para que los nodos se separen más (ajusta según sea necesario)
nx.draw(G, pos, with_labels=True, node_size=500, node_color="lightblue", font_size=15)

# Dibujar los pesos de las aristas
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

plt.show()
