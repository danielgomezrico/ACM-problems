#include <cstdlib>
#include <iostream>

using namespace std;

//On2, s is an array
void selectionSort(int *s, int n){//S is the array to order, n the size of the array
	 int min;
	 int temp;//Contain the temporal value of the array to the swap
	 for(int i = 0; i < n; i++){
	 		 min = i;

			 for(int j = i+1; j < n; j++)
			 		 if(s[j] < s[min]) min = j; 

			 temp = s[i];
			 s[i] = s[min];
			 s[min] = temp;
	 }
}

//More faster than selectionSort, s is an array
void insertionSort(int *s, int n){
	 int i,j;
	 int temp;
	 for(i = 0; i < n; i++){
	 	j = i;
		while((j>0) && (s[j] < s[j-1]) ){ 
				temp = s[j];
				s[j] = s[j-1];
				s[j-1] = temp;
				j = j - 1;
		}	 
	 }
}

//Promedio nlog2n 
/*
    * Elegir un elemento de la lista de elementos a ordenar, al que llamaremos pivote.
    * Resituar los demás elementos de la lista a cada lado del pivote, de manera que a un lado queden todos los menores que 
	  él, y al otro los mayores. En este momento, el pivote ocupa exactamente el lugar que le corresponderá en la lista ordenada.
    * La lista queda separada en dos sublistas, una formada por los elementos a la izquierda del pivote, y otra por los elementos a su derecha.
    * Repetir este proceso de forma recursiva para cada sublista mientras éstas contengan más de un elemento. Una vez terminado este 
	  proceso todos los elementos estarán ordenados.

	  Como se puede suponer, la eficiencia del algoritmo depende de la posición en la que termine el pivote elegido.

    * En el mejor caso, el pivote termina en el centro de la lista, dividiéndola en dos sublistas de igual tamaño. En este caso, el orden de complejidad del algoritmo es O(n·log n).
    * En el peor caso, el pivote termina en un extremo de la lista. El orden de complejidad del algoritmo es entonces de O(n²). El peor caso dependerá de la implementación del algoritmo, aunque habitualmente ocurre en listas que se encuentran ordenadas, o casi ordenadas. Pero principalmente depende del pivote, si por ejemplo el algoritmo implementado toma como pivote siempre el primer elemento del array, y el array que le pasamos esta ordenado, siempre va a generar a su izquierda un array vacío, lo que es ineficiente.

http://es.wikipedia.org/wiki/Quicksort
*/
void quicksort(int *array, int inf, int sup){
//Inicializacion de variables
	 int pivote = lista[sup];
	 int i = inf;
	 int j = sup - 1;//Pues el sup es el pivote
	 int contenedor;
	 int cont = 1;

// Verificamos que no se crucen los límites
	 if(inf >= sup) return;

//  Clasificamos la sublista
	 while(cont){
			//i = sup-1;
			//j = sup+1;
			while( (lista[i] < pivote) && (i < j) ){ ++i;}
 			while( (lista[j] > pivote) && (j > i) ) { --j; } 
			
			if (lista[i] > lista[j]){//Swap
			   contenedor = lista[i];
			   lista[i] = lista[j];
			   lista[j] = contenedor;
			}
			else cont = 0;
	}

// Copiamos el pivote en su posición final
	if(lista[i] > lista[sup]){
				contenedor = lista[i];
				lista[i] = lista[sup];
				lista[sup] = contenedor;
	}

 // Aplicamos el procedimiento recursivamente a cada sublista
	quicksort(lista, inf, i - 1);
	quicksort(lista, i + 1, sup);
}




//---------------------------------

int main(int argc, char *argv[])
{
 	int arraySize = 10;
	int array [10] = {5,1,88,5,8,9,3,2,99,1};

	printf("\nUnordered:\n");	

	for(int i = 0; i < 10; i++)
			printf(" N: %d", array[i]);
	printf("\nOrdered:\n");

	//selectionSort(array, arraySize);
	//insertionSort(array, arraySize);
	quicksort(array, 0, arraySize - 1);


	for(int i = 0; i < 10; i++)
			printf(" N: %d", array[i]);
	printf("\n");

    system("PAUSE");
    return EXIT_SUCCESS;
}
