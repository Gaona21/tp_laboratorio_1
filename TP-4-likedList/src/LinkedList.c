#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL){
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodeaux = NULL;
	int len = ll_len(this);

	if(this!=NULL && nodeIndex>-1 && nodeIndex<len){
		nodeaux = this->pFirstNode;//igualo al primer nodo de this

		if(nodeaux != NULL){
			for(int i=0; i<nodeIndex; i++){
					nodeaux = nodeaux->pNextNode;
			}
		}
	}
    return nodeaux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    Node* pNodo = NULL;
    Node* auxNode = NULL;

    if(this!=NULL && nodeIndex>-1 && nodeIndex<=len){
    	pNodo = (Node*)malloc(sizeof(Node));

    	if(nodeIndex == 0){

    		if(this->pFirstNode == NULL){
    			pNodo->pNextNode = NULL;
    		}else{
    			pNodo->pNextNode = this->pFirstNode;
    		}
    		this->pFirstNode = pNodo;

    	}else{
    		auxNode = getNode(this, nodeIndex -1);

    		if(auxNode != NULL){
    			pNodo->pNextNode = auxNode->pNextNode;
    			auxNode->pNextNode = pNodo;
    		}
    	}

    	pNodo->pElement = pElement;
    	this->size++;
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    int respuesta;

    if(this!=NULL){
    	len = ll_len(this);

    	respuesta = addNode(this, len, pElement);
    	if(respuesta == 0){
    		returnAux = 0;
    	}

    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);

    Node* pNodo = NULL;

    if(this!=NULL && index>-1 && index<=len){
    	pNodo = getNode(this, index);

    	if(pNodo!=NULL){
    		returnAux = pNodo->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    Node* pNodo = NULL;

    if(this!=NULL && index>-1 && index<=len){
    	pNodo = getNode(this, index);

    	if(pNodo!=NULL){
    		pNodo->pElement = pElement;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* pNodo = NULL;
    Node* auxNodo = NULL;

    if(this!=NULL && index>-1 && index<len){
    	pNodo = getNode(this, index);

    	if(index == 0){
    		this->pFirstNode = pNodo->pNextNode;
    	}else{
        	if(pNodo!=NULL){
        		auxNodo = getNode(this, index-1);

        		if(auxNodo!=NULL){
        			auxNodo->pNextNode = pNodo->pNextNode;
        		}
        	}
    	}
		free(pNodo);
		this->size--;
		returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;

    if(this!=NULL){
    	len = ll_len(this);

    	for(int i=0; i<len; i++){
    		ll_remove(this, i);
    	}
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    Node* pNodo = NULL;

    if(this!=NULL){
    	len = ll_len(this);

    	for(int i=0; i<len; i++){
    		pNodo = getNode(this, i);

    		if(pNodo->pElement == pElement){
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;

    if(this!=NULL){
    	len = ll_len(this);
    	if(len>0){
    		returnAux = 0;
    	}else{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    int respuesta;

    if(this!=NULL && index>-1 && index <= len){
    	respuesta = addNode(this, index, pElement);

    	if(respuesta == 0){
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);

    Node* pNodo = NULL;

    if(this!=NULL && index>-1 && index<=len){
    	pNodo = getNode(this, index);

    	if(pNodo!=NULL){
        	returnAux = pNodo->pElement;
        	free(pNodo);
        	this->size--;
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indicePelement;

    if(this!=NULL){
    	indicePelement = ll_indexOf(this, pElement);

    	if(indicePelement!=-1){
    		returnAux = 1;
    	}else{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len = ll_len(this);
    int len2 = ll_len(this2);
    int respuesta;

    void* pelement = NULL;

    if(this!=NULL && this2!=NULL){
    	returnAux = 1;
    	for(int i=0; i<len; i++){
    		pelement = ll_get(this2, i);

    		if(pelement!=NULL){
    			respuesta = ll_contains(this, pelement);

    			if(respuesta == 0){
    				returnAux = 0;
    				break;
    			}
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    int auxFrom;

    void* pElement = NULL;

    if(this!=NULL && from>-1 && from<=len && to>-1 && to<=len){
    	cloneArray = ll_newLinkedList();
    	auxFrom = from;

    	while(auxFrom < to){ //no habia que icluir el to
    		pElement = ll_get(this, auxFrom);

        	ll_add(cloneArray,pElement);
        	auxFrom++;
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int len;

    if(this!=NULL){
    	len = ll_len(this);

    	cloneArray = ll_subList(this, 0, len);

    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int len;
    int respuesta;

    void* pElementI = NULL;
    void* pElementJ = NULL;
    void* pAuxElement = NULL;

    if(this!=NULL && pFunc!=NULL && order>-1 && order>=1){
    	len = ll_len(this);

    	for(int i=0; i<len-1; i++){
    		pElementI = ll_get(this, i);
    		for(int j=i+1; j<len; j++){
    			pElementJ = ll_get(this, j);

    			respuesta = pFunc(pElementI,pElementJ);

				if(order == 1 && respuesta == 1){
					pAuxElement = pElementI;
					pElementI = pElementJ;
					pElementJ = pAuxElement;
				}else{
					if(order == 0 && respuesta == -1){
						pAuxElement = pElementJ;
						pElementJ = pElementI;
						pElementI = pAuxElement;
					}
				}

				ll_set(this, i, pElementI);
				ll_set(this, j, pElementJ);
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;

}

