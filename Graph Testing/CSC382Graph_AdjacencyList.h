#pragma once

// This class works based on an adjecency list representation. Nodes are stored as elements in the adjecency list. Connections are represented by lists connecting the nodes together. The class is templated to use generic data types.

template <typename T> // Templated class for a graph represented by an adjency list
class CSC382Graph_AdjacencyList
{


public: // Public members
	
	CSC382Graph_AdjacencyList() // Default adjency list constructor
	{
		graph_adjacencylist = new vector<list<T>*>();
	}


	~CSC382Graph_AdjacencyList() // Default adjency list deconstructor
	{

		for (list<T>* iter : *graph_adjacencylist) 	// For loop that clears out the memory that stored the graph
		{
			if (iter != nullptr)
			{

				delete iter; // Delete any entries that store data
			}
		}

		delete graph_adjacencylist; // Deletes the graph
	}

	list<T>* AddVertex(T data) // Function that adds a vertex to the graph, parameters: data of type T, return type: list pointer of type T
	{

		if (IsVertex(data)) // Attempt to find
		{
			cout << "Vertex is already in the graph. Duplicate NOT added." << endl;
			return nullptr; // If the data already excists in the graph, return from the function
		}
		else // Otherwise add the data to the graph
		{

			list<T>* new_vertex = new list<T>();		// Create new list to house the vertex and its edges
			new_vertex->push_back(data);				// Data is added as the first element in the list
			graph_adjacencylist->push_back(new_vertex);	// list pointer is added to the graph
			return new_vertex;
		}
	}

	bool AddEdge(list<T>* vertex, T data) // Function that adds an edge to the graph, parameters: data of type T and list pointer of data type T vertex, return type: bool
	{
		if(!IsVertex(vertex)) // If the vertex does not exist, return false
		{
			cout << "Vertex specified does not exist. Cannot add edge to a non-existant vertex." << endl;
			return false;
		}
		if (IsVertex(data)) // Data must be an existing vertex or it will need to be created.
		{
			vertex->push_back(data); // If the data of the second vertex does not exist, add it to the graph with an edge between vertex and itself
			return true; 
		}
		else // Otherwise create an edge between the data and the vertex
		{
			list<T>* new_vertex = AddVertex(data);
			vertex->push_back(data);
			return true;
		}
	}

	bool AddEdge(list<T>* starting_vertex, list<T>* ending_vertex) // Function that adds an edge to the graph, parameters: list pointer of data type T for starting vertex and the endging vertex, return type: bool
	{
		if(!IsVertex(starting_vertex) || !IsVertex(ending_vertex)) // If neither one or the other vertices exist in the graph, return false
		{
			cout << "Cannot AddEdge because one of the specified vertices does not exist in the graph." << endl;
			return false;
		}
		if (!IsEdge(starting_vertex, ending_vertex->front())) // Prevent adding duplicate edges
		{
			starting_vertex->push_back(ending_vertex->front());  // Otherwise, add the edge between the two nodes
			return true;
		}
		return false;
	}

	bool IsVertex(T data) // Function that checks if data exists as a vertex, parameters: data of type T, return type: bool
	{
		for (list<T>* iter : *graph_adjacencylist) // Loops through the adjency list
		{
			if (iter->front() == data) // Check the first value in the list which is the primary vertex
			{
				return true; // Data exists in the graph
			}
		}
		return false; // Otherwise if data doesn't exist in the graph, return false
	}

	bool IsVertex(list<T>* vertex_to_find) // Function that checks if data exists as a vertex, parameters: list pointer of data type T vertex to find, return type: bool
	{
		for (list<T>* iter : *graph_adjacencylist) // Loops through the adjency list
		{
			if (iter == vertex_to_find) // Check if the current pointer is our vertex
			{
				return true; // If so, return true
			}
		}
		return false; // Otherwise, return false
	}

	bool IsEdge(T edge_to_find) // Function that checks if an edge exists in the graph, parameters: data of type T edge to find, return type: bool
	{
		for (list<T>* iter : *graph_adjacencylist) // Loops through the adjency list
		{
			if (IsEdge(iter, edge_to_find)) // Checks if an edge exists between our current node and the data of the vertex we are looking for
			{
				return true; // If so, return true
			}
		}
		return false; // Otherwise, return false
	}

	bool IsEdge(list<T>* vertex, T edge_to_find) // Function that checks if an edge exists between two nodes, parameters: list pointer of data type T vertex and data of type T edge to find, return type: bool
	{
		for (T i : *vertex) // Looping through connected verticies of our vertex
		{
			if (vertex->front() == i) // skip checking the primary vertex and only check edges
			{
				continue; 
			}
			if (i == edge_to_find) // If our data matches the data we are looking for....
			{
				return true; // The edge exists, return true
			}
		}
		return false; // Otherwise, return false
	}

	list<T>* FindVertex(T data)  // Funtion that finds if a vertex exists in a adjency list, paraemeters: data of type T, return type: List pointer of data type T
	{
		for (list<T>* iter : *graph_adjacencylist) // Loops through the adjency list
		{
			if (iter->front() == data) // If current node is the data we are looking for
			{
				return iter; // Return the current node
			}
		}
		return nullptr; // Otherwise, return null pointer
	}

	void PrintAdjacencyList() // Function that prints out the adjency list, return type: void
	{
		for (list<T>* iter : *graph_adjacencylist) // Loops through the adjency list
		{
			for (T i : *iter) // Loops through the connections of the current vertex
			{
				// skip checking the primary vertex and only check edges
				if (iter->front() == i)		// Prints the Vertex 
				{
					cout << "Vertex = " << i << "   Edges = ";
				}
				else	// Prints the Edges
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
	}

	int NumberOfEdges(T vertex_data) // Function that gets the number of edges connected to a given vertex, parameters: data of type T vertex data, return type: int
	{
		list<T>* vertex = FindVertex(vertex_data); // Find the vertex containing our data

		if(vertex != nullptr) // If the vertex does exists...
		{
			return NumberOfEdges(vertex); //Return the number of edges connected to the vertex
		}
		return -1; // Otherwise, return error message
	}

	int NumberOfEdges(list<T>* vertex) // Function that gets the number of edge connected to a given vertex, parameters: pointer of list of data type T vertex, return type: int
	{
		return vertex->size(); // Return the size of the list that is the vertex
	}

	int GraphSize() // Function that gets the size of the graph
	{
		return graph_adjacencylist->size(); // Return the size of the graph
	}

private: // Private data members
	vector<list<T>*>* graph_adjacencylist; // Adjency list is stored as a vector of list pointers of data type T
};