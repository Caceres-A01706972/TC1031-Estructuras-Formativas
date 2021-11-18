/*
	Ricardo Andres Caceres Villibord 
	A01706972

	Archivo .h para la Actividad Formativa 4.1 (Grafos)
*/

#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;


class Graph {
private:
	int edgesList;
	int edgesMat;
	int nodes;
	vector<int> *adjList;
	int *adjMatrix;
	//vector<Type> *vect = new vector<Type>

public:
	Graph(int);
	Graph();

	void loadGraphMat(string, int, int);
	void addEdgeAdjMatrix(int, int);
	string printAdjMat();
	string printAdjMat_clean();

	void loadGraphList(string, int, int);
	void addEdgeAdjList(int, int);
	string printAdjList();
	
	string DFS(int, int);
	void dfsHelper(int, int, stack<int>&, list<int>&, vector<vector<int>>&, stringstream&);
	string BFS(int, int);
	void bfsHelper(int, int, queue<int>&, list<int>&, vector<vector<int>>&, stringstream&);
	void printPath(vector<vector <int>>&, int, int, stringstream&);
	void printVisited(list<int>, stringstream&);
	

	bool contains(list<int>, int);
	void sortAdjList();
};

Graph::Graph() {
	edgesList = edgesMat = 0;
}

Graph::Graph(int n) {
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for (int i = 0; i < nodes*nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;
}


void Graph::loadGraphMat(string name, int a, int b){
	adjMatrix = new int [a*b];
	nodes = a;
	for (int i = 0; i < a*b; i++)
		adjMatrix[i] = 0;
		string line;
		ifstream archivo (name);
		int u, v;
		if (archivo.is_open()){
			while (getline(archivo, line)){
				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjMatrix(u,v);
			}
			archivo.close(); // Closes the file
		} else {
			cout << "Unable to open file";
		}
}

void Graph::loadGraphList(string nom_archivo, int a, int b){
	nodes = a;
	adjList = new vector<int>[nodes];

	string line;
	ifstream archivo (nom_archivo);
	int u, v;
	if (archivo.is_open()){
		while (getline(archivo, line)){
			u = stoi(line.substr(1,1));
			v = stoi(line.substr(4,1));
			addEdgeAdjList(u,v);
		}
		archivo.close();
	} else {
		cout<<"Unable to open file";
	}
}

void Graph::addEdgeAdjList(int u, int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
	edgesList++;
}


void Graph::addEdgeAdjMatrix(int u, int v){
	adjMatrix[u*nodes+v] = 1;
	adjMatrix[v*nodes+u] = 1;
	edgesMat++;
}

string Graph::printAdjList(){
	sortAdjList();
	stringstream aux;
	for (int i = 0; i < nodes; i++){
		aux << "vertex "
				<< i << " :";
		for (int j = 0; j < adjList[i].size(); j ++){
							aux << " " << adjList[i][j];
				}
		aux << " ";
}
	return aux.str();

}

string Graph::printAdjMat(){
	stringstream aux;
	for (int i = 0; i < nodes; i++){
	   for (int j = 0; j < nodes; j++){
			 aux << adjMatrix[i*nodes+j] << " ";
		 }
  }
	return aux.str();
}

string Graph::printAdjMat_clean(){
	stringstream aux;
	aux << "\n nodes \t|";
	for (int i = 0; i < nodes; i++){
			aux << "\t" << i ;
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
			aux << "__________";
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
		 aux << i << "\t|";
	   for (int j = 0; j < nodes; j++){
			 aux << "\t" << adjMatrix[i*nodes+j];
		 }
	   aux << "\n";
  }
	return aux.str();
}

string Graph::DFS(int inicio, int objetivo){
	stringstream aux;

	stack<int>my_stack;
	list<int> visited;
	vector<vector<int>> paths(nodes, vector<int>(1,-1));
	my_stack.push(inicio);

	dfsHelper(inicio, objetivo, my_stack, visited, paths, aux);
    printPath(paths, inicio, objetivo, aux);
    
    return aux.str();
}

void Graph::dfsHelper(int current, int objetivo, stack<int> &my_stack, list<int> &visited, vector<vector<int>> &paths, stringstream &aux) {
    
    if (current == objetivo) {
        printVisited(visited, aux);
    } else if (my_stack.empty()) {
        aux << "node not found";
    } else {
        current = my_stack.top(); //guardo el nodo en que me encuentro (el que esta de primero en el stack)
        my_stack.pop(); //queda vacio el stack
        visited.push_back(current); //meto el current en lista de visited
        for (int  i = 0; i < adjList[current].size(); i++) {
            if (!contains(visited, adjList[current][i])) {
                my_stack.push(adjList[current][i]);
                paths[ adjList[current][i] ] [0] = current;
            }
        }
        dfsHelper(current, objetivo, my_stack, visited, paths, aux);
    }
}


string Graph::BFS(int inicio, int objetivo) {
    stringstream aux;
    
    queue<int> my_queue;
    list<int> visited;
    vector<vector<int>> paths(nodes, vector<int>(0));
    my_queue.push(inicio);
    
    bfsHelper(inicio, objetivo, my_queue, visited, paths, aux);
    printPath(paths, inicio, objetivo, aux);
    
    return aux.str();
}

void Graph::bfsHelper(int current, int objetivo, queue<int> &my_queue, list<int> &visited, vector<vector<int>> &paths, stringstream &aux) {
    
    if (current == objetivo) {
        printVisited(visited, aux);
    } else if (my_queue.empty()) {
        aux << "";
    } else {
        current = my_queue.front();
        my_queue.pop();
        visited.push_back(current);
        for (int  i = 0; i < adjList[current].size(); i++) {
            if (!contains(visited, adjList[current][i])) {
                my_queue.push(adjList[current][i]);
                paths[adjList[current][i]].push_back(current);
            }
        }
        bfsHelper(current, objetivo, my_queue, visited, paths, aux);
    }
}

void Graph::printVisited(list<int>visited, stringstream &aux) {
    aux << "visited: ";
    while (!visited.empty()){
        aux << visited.front() << " ";
        visited.pop_front();
    }
}

void Graph::printPath(vector<vector <int>> &path, int inicio, int objetivo, stringstream &aux) {
    aux << "path: ";
    int node = path[objetivo][0];
    
    stack<int> reverse; //stack auxiliar
    reverse.push(objetivo);
    
    while (node != inicio) {
        reverse.push(node);
        node = path[node][0];
    }
    
    reverse.push(inicio);
    while (!reverse.empty()) {
        aux << reverse.top();
        reverse.pop();
        if (!reverse.empty())
            aux << " ";
    }
}

void Graph::sortAdjList() {
    for (int i = 0; i < nodes; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }
}

bool Graph::contains(list<int> lista, int node) {
    list<int>::iterator it;
    it = find(lista.begin(), lista.end(), node);
    
    if (it != lista.end()){
		return true;
	} else {
		return false;
	}
}

#endif /* Graph_H_ */
