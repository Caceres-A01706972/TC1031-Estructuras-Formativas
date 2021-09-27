<h1>Analisis de Complejidad</h1>

<li>insertion()</li>
El Analisis de Complejidad de este algoritmo seria de O(n) porque dependiendo de que tan grande sea la lista va a recorrer por cada nodo hasta llegar al nodo final para poder agregar el siguiente nodo. Sin embargo, si el elemento es el primero en agregarse, es decir, se usa el insertionFirst() ese seria de complejidad O(1).
<br></br>

<li>search()</li>
Para este algoritmo, el analisis de complejidad es de O(n) ya que no sabemos en que index esta el valor que buscamos en la lista, asi que se tendria que recorrer por cada elemento de la lista checando si el p->value es igual al valor que se busca. 


<li>update()</li>
Este algoritmo tiene un Analisis de Complejidad de O(n) ya que recorre los elementos de la lista hasta que llegue al index especificado para cambiar el valor de ese elemento.



<li>deleteAt()</li>
El Analisis de Complejidad de este algoritmo es de O(n) ya que se recorre los elementos de la lista hasta llegar al index especificado y ahi hacer el delete. 
