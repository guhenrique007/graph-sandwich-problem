# graph-sandwich-problem

## Implementação de algoritmos de resolução do problema grafo sanduíche para as classes Split e Cordal

### Problema Sanduíche
Os problemas-sanduíche surgem como uma
generalização relaxada dos problemas de reconhecimento. O problema de reconhecimento
se preocupava em descobrir se um grafo G pertence ou não a uma
determinada classe de grafos, isto é, se possui ou não determinada
propriedade. Os problemas-sanduíche por sua vez, tem o objetivo de responder se existe alguma instância de grafo-sanduíche para os grafos de entrada G1 e G2, e que além disso, 
pertença à classe proposta. O problema grafo-sanduíche pode ser resolvido em tempo polinomial para algumas classes como: grafos split, grafos de limiar, grafos bipartidos e cografos.
E é NP-completo quando o problema possui a propriedade de ser um grafo cordal, grafo de comparabilidade , grafo de permutação, grafo bipartido cordal , ou grafo cadeia.
Para esta implementação foi escolhido as classes grafo split e cordal.


### SP-Split
Um  grafo-(<i>k,l</i>) ́e  um  grafo  G  que  admite  uma  (<i>k,l</i>)-partição,  quando  seu  conjunto  de vértices  pode  ser  particionado  em  <i>k</i>  conjuntos  independentes  e  <i>l</i>  cliques.



### SP-Cordal
Implementação à partir do algoritmo de reconhecimento de grafos Cordais, baseado no teorema que afirma <i>"Seja G(V,E) um grafo cordal. Se G é completo. qualquer um de seus
vértices é simplicial. Se G não é completo, ele contém um par de vértices
simpliciais não adjacentes.
"</i>.  


### Referências
# M. C. Golumbic, Haim Kaplan, R. S. (1993).Algorithms and Complexity of SandwichProblems in Graphs. 790 edition
# Jayme Luiz Szwarcfiter (2018) -	Teoria Computacional De Grafos

