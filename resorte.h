//TDA resorte:

//debo usar la lista que se da en clase
//cuando el usuario clickee sobre una masa creada se inicia la creacion de un resorte
 lista_t* resorte_i = lista_crear() //Se crea un resorte que por ahora no esta asociado a ninguna masa

//luego de crear el resorte, se le debe insertar el dato del nodo (masa) al que se este uniendo.
lista_insertar_primero(resorte_i, masa_t *masa);

//si resorte es mayor a LO_MAX se llama a 
lista_destruir(resorte_i);

//si se clickea sobre una una posicion sin masa se debe crear una masa y ademas agregarlo a la lista resorte:
m2 = *masa_crear();

lista_insertar_ultimo(resorte_i, m2); //Inserta en la ultima posicion de la lista la masa creada

//Con las posiciones de las masas previamente obtenidas con obtener_posicion hago la norma int n =||p2 -p1|| 
lista_insertar_ultimo(resorte_i, &n) //Se inserta en la ultima posicion del resorte su longitud.
//Si la longitud es mayor a LO_MAX no se estira mas el resorte.

lista_destruir(resorte_i, free); //Destruye el resorte 
//hola