import networkx as nx
from networkx.drawing.nx_agraph import write_dot, graphviz_layout
import matplotlib.pyplot as plt


##
G = nx.Graph()
for i in range(5):
	G.add_node("%i" % i)

G.add_edge("0", "1")
G.add_edge("0", "2")

G.add_edge("1", "3")
G.add_edge("1", "4")

G.add_edge("2", "5")
G.add_edge("5", "6")

# write dot file to use with graphviz
# run "dot -Tpng test.dot >test.png"
write_dot(G,'test.dot')

# same layout using matplotlib with no labels
plt.title('draw_networkx')
pos = graphviz_layout(G, prog='dot')
nx.draw_networkx_nodes(G, pos, node_size=1600, node_color='r', alpha=0.4, node_shape='o')
nx.draw_networkx_labels(G, pos, font_size=20, font_family='sans-serif')
nx.draw_networkx_edges(G, pos)

#nx.draw(G, pos, with_labels=True, arrows=True)
plt.savefig('nx_test.png')

plt.show()
