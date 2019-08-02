#pragma once

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>

// This header file stores a node based representation of the graph. Vertecies are represented by node class, which stores a data element and the connected vertitices to it. The graph is represented by a list that stores all the verticies.

using namespace std; // Using namespace for std

template <typename T>
class CSC382Graph_Vertex // Templated class for the vertex using data type T
{
private: // Private members
	T data; // Data type T storing vertex data
	list<CSC382Graph_Vertex<T>*>* connected_vertices; // List of connected vertices
public: // Public members
	CSC382Graph_Vertex() // Vertex default constructor
	{
		connected_vertices = new list<CSC382Graph_Vertex<T>*>(); // Initialize the list of connected vertices
		data = NULL; // Set data to NULL
	}

	CSC382Graph_Vertex(T node_data) // Vertex custom constructor, using data type T for node data
	{
		connected_vertices = new list<CSC382Graph_Vertex<T>*>(); // Initialize the list of connected vertices
		data = node_data; // Set data to node data
	}

	~CSC382Graph_Vertex() // Default vertex deconstroctur
	{
		delete connected_vertices; // Delete the list of conneted vertices
	}


	void AddEdge(CSC382Graph_Vertex<T>* vertex_connection) // Function to add edge, parameters: Vertex pointer of data type T for the connected vertices, return type: void
	{
		if (vertex_connection != this) // If the vertex we are adding is not the vertex we are in...
		{
			connected_vertices->push_back(vertex_connection); // Add the edge to the connected vertices
		}
	}


	bool VertexConnected(CSC382Graph_Vertex<T>* vertex_to_find) // Function to find our connected vertex, parameters: Vertex pointer of data type T for finding the vertex, return type: bool
	{
		for(CSC382Graph_Vertex<T>* i : *connected_vertices) // Looping through list of connected vertices
		{
			if(i == vertex_to_find) // If the current vertex we are on is looking for the vertex we are looking for...
			{
				return true; // return true
			}
		}
		return false; // If the vertex we are looking for is not found, return false
	}


	void RemoveEdge(CSC382Graph_Vertex<T>* edge_to_remove) // Function to remove the edge, parameters: Vertex pointer of data type T for removing the edge, return type: void
	{
		if (edge_to_remove != nullptr) // If the edge to remove is not a nullptr...
		{
			connected_vertices->remove(edge_to_remove); //Remove from the list of vertices
		}
	}


	T GetData() //Function to get data, parameters: empty, return type: data type T
	{
		return data; // Return the stored data
	}


	void SetData(T data_param) // Function to set the data, parameters: data type T for data to set, return tyoe: void
	{
		data = data_param; // Set data to data to set
	}

};


template <typename T>
class CSC382Graph_NodeBased // Templated class for nodebased graph using data type T
{
private: // private members
	list<CSC382Graph_Vertex<T>*>* graph; // List of vertices in a graph 

public: // public members
	CSC382Graph_NodeBased() // Node based graph default constructor
	{
		graph = new list<CSC382Graph_Vertex<T>*>; // Initialize the graph
	}


	CSC382Graph_NodeBased(CSC382Graph_Vertex<T>* initial_vertex) // Node based graph custom constructor
	{
		graph = new list<CSC382Graph_Vertex<T>*>; // Initialize the graph
		Insert(initial_vertex); // Insert the very first node
	}


	~CSC382Graph_NodeBased() // Node based graph default deconstructor
	{
		for (CSC382Graph_Vertex<T>* iter : *graph) // Looping through the list of vertices
		{
			if (iter != nullptr && iter != NULL) // If the node exists in the graph...
			{
				delete iter; // Delete it
			}
		}
		delete graph; //Then delete the whole graph
	}


	CSC382Graph_Vertex<T>* Insert(CSC382Graph_Vertex<T>* vertex) // Function to insert a vertex, parameters: vertex pointer using data type T for the vertex to insert, return type: vertex pointer using data type T
	{
		graph->push_back(vertex); // Add the vertex to the graph
		return vertex; // Return the vertex
	}


	CSC382Graph_Vertex<T>* Insert(T data) // Function to insert node based on data, parameters: data type T data to insert, return type: vertex pointer of data type T 
	{
		CSC382Graph_Vertex<T>* new_node = new CSC382Graph_Vertex<T>(data); // Create a new vertex based on the data
		return Insert(new_node); // Insert the new vertex
	}


	void RemoveVertex(T data) // Function to remove the vertex based on data, parameters: data type T data to remove, return type: void
	{
		CSC382Graph_Vertex<T>* vertex_to_remove = FindVertex(data); // Find the vertex
		RemoveVertex(vertex_to_remove); // Remove the vertex from the graph
	}


	void RemoveVertex(CSC382Graph_Vertex<T>* vertex_to_remove) // Function to remove vertex from the graph, parameters: vertex pointer of data type T for vertex to remove, return type: void
	{
		graph->remove(vertex_to_remove); // Remove the vertex from the list
	}


	void AddEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex) // Function to add an edge between two verticies, paramemters: two vertex pointers of data type for the starting vertex and ending vertex, return type: void
	{
		start_vertex->AddEdge(end_vertex); // Add an edge in the starting vertex and ending vertex
	}


	void RemoveEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex) // Function to remove an edge between two verticies, parameters:  two vertex pointers of data type for the starting vertex and ending vertex, return type: void
	{
		start_vertex->RemoveEdge(end_vertex); // Remove the edge between the two verticies
	}


	bool IsEdge(CSC382Graph_Vertex<T>* vertex_to_search_in, CSC382Graph_Vertex<T>* edge_to_check_for) // Function to check if an edge exists between two verticies, paramaters:  two vertex pointers of data type for the starting vertex and ending vertex, return type: bool
	{
		return vertex_to_search_in->VertexConnected(edge_to_check_for); // Check if there is an edge between the starting vertex and ending vertex
	}


	CSC382Graph_Vertex<T>* FindVertex(T data_to_find) // Function to find a vertex basedon data, paramaters: data type T data to find, return type: vertex pointer of data type T
	{
		for (CSC382Graph_Vertex<T>* iter : *graph) // Loop through the graph
		{
			if (iter->GetData() == data_to_find) // If the data matches the data we are looking for...
			{
				return iter; // Return the vertex
			}
		}
		return nullptr; // Otherwise, return nullptr
	}


	CSC382Graph_Vertex<T>* FindVertex(CSC382Graph_Vertex<T>* node_to_find) // Function to find a vertex, parameters: vertex pointer of data type T for node to find, return type: vertex pointer of data type T
	{
		for(CSC382Graph_Vertex<T>* iter : *graph) // Loop through the graph
		{
			if(iter == node_to_find) // If the node matches the node to find
			{
				return iter; // Return the vertex
			}
		}
		return nullptr; // Otherwise, return nullptr
	}


	int Size() // Function to get the size of the graph, parameters: empty, return type: int
	{
		return graph->size(); // Return the graph size
	}
};
