# graph-sandwich-problem

## Implementação de algoritmos de resolução do problema grafo sanduíche para as classes Split e Cordal
Os problemas-sanduíche surgem como uma
generalização relaxada dos problemas de reconhecimento. O problema de reconhecimento
se preocupava em descobrir se um grafo G pertence ou não a uma
determinada classe de grafos, isto é, se possui ou não determinada
propriedade. Os problemas-sanduíche por sua vez, tem o objetivo de responder se existe alguma instância de grafo-sanduíche para os grafos de entrada G1 e G2, e que além disso, 
pertença à classe proposta. O problema grafo-sanduíche pode ser resolvido em tempo polinomial para algumas classes como: grafos split, grafos de limiar, grafos bipartidos e cografos.
E é NP-completo quando o problema possui a propriedade de ser um grafo cordal, grafo de comparabilidade , grafo de permutação, grafo bipartido cordal , ou grafo cadeia.
Para esta implementação foi escolhido as classes grafo split e cordal.


### SP-Split
Um  grafo-(k,l) ́e  um  grafo  G  que  admite  uma  (k,l)-partic ̧ ̃ao,  quando  seu  conjunto  dev ́ertices  pode  ser  particionado  em  k  conjuntos  independentes  e  <i>l</i>  cliques.



### SP-Cordal
Implementação à partir do algoritmo de reconhecimento de grafos Cordais, baseado no teorema que afirma "Qualquer  grafo  cordal  não-completo  possui  ao  menos  dois  vertices  simpliciais não-adjacentes; e todos os vértices de um grafo cordal completo devem ser simpliciais".  


### Referências
M. C. Golumbic, Haim Kaplan, R. S. (1993).Algorithms and Complexity of SandwichProblems in Graphs. 790 edition

