<h1>Analisis de Complejidad</h1>

<li>insertion()</li>
El Analisis de Complejidad de este algoritmo seria de O(1) porque estamos insertando el nuevo nodo en la ultima posicion de la lista, es decir cambiamos cual es el tail y agregamos un newLink.
<br></br>

<li>search()</li>
Para este algoritmo, el analisis de complejidad es de O(n) ya que no sabemos en que index esta el valor que buscamos en la lista, asi que se tendria que recorrer por cada elemento de la lista checando si el p->value es igual al valor que se busca. 
<br></br>

<li>update()</li>
Este algoritmo tiene un Analisis de Complejidad de O(n) ya que recorre los elementos de la lista hasta que llegue al index especificado para cambiar el valor de ese elemento.
<br></br>

<li>deleteAt()</li>
El Analisis de Complejidad de este algoritmo es de O(n) ya que se recorre los elementos de la lista hasta llegar al index especificado y ahi hacer el delete. 

