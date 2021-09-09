/*
Ricardo Andres Caceres Villibord
A01706972

Act 1.2 Algoritmos de Busqueda y Ordenamiento
*/

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>

template <class T>
class Sorts{
    private:
        void swap(std::vector<T>&, int, int);
		void copyArray(std::vector<T>&, std::vector<T>&, int, int);
		void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
		void splitMerge(std::vector<T>&, std::vector<T>&, int, int);
		int partition(std::vector<T>&, int, int);
		void quickHelper(std::vector<T>&, int, int);
		int auxBinaria(std::vector<T>&, int, int, int);
    public:
        std::vector<T> busqSecuencial(const std::vector<T>&, int);
        std::vector<T> busqBinaria(const std::vector<T>&, int, int);
        std::vector<T> ordenaBurbuja(const std::vector<T>&);
		std::vector<T> ordenaSeleccion(const std::vector<T>&);
		std::vector<T> insertionSort(const std::vector<T>&);
		std::vector<T> shellSort(const std::vector<T>&);
		std::vector<T> ordenaMerge(const std::vector<T>&);
		std::vector<T> quickSort(const std::vector<T> &source);
		std::vector<T> bucketSort(const std::vector<T>&);
		std::list<T>   mergeList(const std::list<T>&, const std::list<T>&);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
std::vector<T> Sorts<T>::ordenaSeleccion(const std::vector<T> &source){
    std::vector<T> v(source);
    /*
    for (int i = v.size() - 1; i > 0; i--){
		int pos = 0;
		for (int j = 1; j <= i; j++){
			if (v[j] > v[pos]){
				pos = j;
			}
		}

		if (pos != i) {
			swap(v, i, pos);
		}
	}
	return v;
}*/

    for(int i = 0; i < v.size(); i++){
        int min = i;
        for(int j = i+1; j< v.size(); j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        if(min != i){
            swap(v,i,min);
        }
    }
    return v;

}


template <class T>
std::vector<T> Sorts<T>::ordenaBurbuja(const std::vector<T> &source) {
    std::vector<T> v(source);

    for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}


template <class T>
std::vector<T> Sorts<T>::ordenaMerge(const std::vector<T> &source){
    std::vector<T> v(source);
    std::vector<T> tmp(v.size());

    splitMerge(v, tmp, 0, v.size()-1);

    return v;
}

template <class T>
void Sorts<T>::splitMerge(std::vector<T> &A, std::vector<T> &B, int low, int high) {

	if((high-low) < 1){
		return;
	}

	int mid = (high + low)/2;

	splitMerge(A, B, low, mid);
	splitMerge(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);

}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {

	int i = low;
	int j = mid + 1;
	int k = low;

	while (i <= mid &&j <= high){
		if(A[i] < A[j]){
			B[k] = A[i];
			i++;
		}else{
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if(i > mid){
		for(; j <= high; j++){
			B[k++] = A[j];
		}
	} else{
		for(; i <= mid; i++){
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for(int i = low; i <= high; i++){
		A[i] = B[i];
	}
}


template <class T>
std::vector<T> Sorts<T>::busqSecuencial(const std::vector<T> &source, int numero) {
    std::vector<T> v(source);
	
	int i = 0;
	bool flag = false;
	while(flag == false && i < v.size()-1){
		if(v[i] == numero){
			flag = true;
		}
		i++;
	}
	if(flag == true){
		return i;
	} else if(flag == false){
		return -1;
	}
}	


template <class T>
std::vector<T> auxBinaria(const std::vector<T>&source, int low, int high, int numero){
	int mid;

	if(low <= high){
		mid = (low + high)/2;
		if(numero == arr[mid]){
			return mid;
		} else if(numero < arr[mid]){
			return auxBinaria(arr, low, mid-1, numero);
		} else if(numero > arr[mid]){
			return auxBinaria(arr, mid+1, high, numero);
		}
	}

	if (arr[low] != val){
		return -1;
	} else{
		return low;
	}

}

template <class T>
std::vector<T> busqBinaria(const std::vector<T>&source, int numero){
	
}




#endif /* SORTS_H_ */