// GraphTutorial.cpp : Creates a directed, unweighted graph.

#include "stdafx.h"
#include "CSC382Graph_NodeBased.h"
#include "CSC382Graph_AdjacencyList.h"

using namespace std;

bool Testing_NodeBased()
{
	bool passed = true;
	
	cout << "Graph Intro Project: Comments & Testing" << endl;
	cout << "\n--------------------------------------------------------------------" << endl;
	cout << "Node-Based testing results: " << endl;
	cout << "--------------------------------------------------------------------" << endl;

	// Test CSC382Graph_NodeBased Constructor(s)
	{
		CSC382Graph_NodeBased<int> nodebased_test = CSC382Graph_NodeBased<int>();

		if(nodebased_test.Size() == 0)
		{
			cout << "\nDefault constructor succesfully created" << endl;
		}
		else
		{
			cout << "\nDefault constructor failed to be created" << endl;
			passed = false;
		}
	}
	
	CSC382Graph_NodeBased<int> nodebased_test = CSC382Graph_NodeBased<int>(new CSC382Graph_Vertex<int>(1));

	if (nodebased_test.Size() == 1)
	{
		cout << "\nCustom constructor succesfully created" << endl;
	}
	else
	{
		cout << "\nCustom constructor failed to be created" << endl;
		passed = false;
	}

	if (nodebased_test.FindVertex(1) != nullptr)
	{
		cout << "\nInitial vertex succesfully inserted" << endl;
	}
	else
	{
		cout << "\nInitial vertex failed to be inserted" << endl;
		passed = false;

	}

	// Test functions of the CSC382Graph_NodeBased class and affiliated classes
	if (nodebased_test.Insert(2) != nullptr)
	{
		cout << "\nNew node inserted succesfully" << endl;
	}
	else
	{
		cout << "\nNew node failed to insert" << endl;
		passed = false;
	}

	if (nodebased_test.FindVertex(2) != nullptr)
	{
		cout << "\nNew node succesfully found" << endl;
	}
	else
	{
		cout << "\nNew node failed to be found" << endl;
		passed = false;
	}

	if (nodebased_test.Size() == 2)
	{
		cout << "\nGraph size succesfully increased" << endl;
	}
	else
	{
		cout << "\nGraph size failed to increase" << endl;
		passed = false;
	}

	CSC382Graph_Vertex<int>* new_node = new CSC382Graph_Vertex<int>(3);
	if (nodebased_test.Insert(new_node) != nullptr)
	{
		cout << "\nNode pointer succesfully inserted" << endl;
	}
	else
	{
		cout << "\nNode pointer failed to be inserted" << endl;
		passed = false;
	}

	if(nodebased_test.FindVertex(new_node) != nullptr)
	{
		cout << "\nNew node pointer succesfully found" << endl;
	}
	else
	{
		cout << "\nNew node pointer failed to be found" << endl;
		passed = false;
	}

	if (nodebased_test.Size() == 3)
	{
		cout << "\nGraph size succesfully increased" << endl;
	}
	else
	{
		cout << "\nGraph size failed to increase" << endl;
		passed = false;
	}

	nodebased_test.AddEdge(nodebased_test.FindVertex(1), new_node);

	if (nodebased_test.IsEdge(nodebased_test.FindVertex(1), new_node) == true)
	{
		cout << "\nEdge succesfully inserted and found" << endl;
	}
	else
	{
		cout << "\nEdge failed to be inserted or found" << endl;
		passed = false;
	}

	nodebased_test.RemoveEdge(nodebased_test.FindVertex(1), new_node);

	if (nodebased_test.IsEdge(nodebased_test.FindVertex(1), new_node) == false)
	{
		cout << "\nEdge was succesfully removed" << endl;
	}
	else
	{
		cout << "\nEdge failed to be removed" << endl;
		passed = false;
	}

	nodebased_test.RemoveVertex(new_node);

	if(nodebased_test.FindVertex(new_node) == nullptr)
	{
		cout << "\nVertex pointer succesfully removed" << endl;
	}
	else
	{
		cout << "\nVertex pointer failed to be removed" << endl;
		passed = false;
	}

	nodebased_test.RemoveVertex(2);

	if(nodebased_test.FindVertex(2) == nullptr)
	{
		cout << "\nVertex succesfully removed" << endl;
	}
	else 
	{
		cout << "\nVertex failed to be removed" << endl;
		passed = false;
	}

	// Test creating lots of nodes and edges
	for(int i = 2; i <= 21; i++)
	{
		nodebased_test.Insert(i);
		nodebased_test.AddEdge(nodebased_test.FindVertex(1), nodebased_test.FindVertex(i));
	}

	if(nodebased_test.FindVertex(2) != nullptr)
	{
		cout << "\nFirst of 20 nodes succesfully inserted" << endl;
	}
	else
	{
		cout << "\nFirst of 20 nodes failed to be inserted" << endl;
		passed = false;
	}

	if (nodebased_test.FindVertex(11) != nullptr)
	{
		cout << "\nMiddle of 20 nodes succesfully inserted" << endl;
	}
	else
	{
		cout << "\nMiddle of 20 nodes failed to be inserted" << endl;
		passed = false;
	}

	if (nodebased_test.FindVertex(21) != nullptr)
	{
		cout << "\nLast of 20 nodes succesfully inserted" << endl;
	}
	else
	{
		cout << "\nLast of 20 nodes failed to be inserted" << endl;
		passed = false;
	}

	if (nodebased_test.IsEdge(nodebased_test.FindVertex(1), nodebased_test.FindVertex(2)) == true)
	{
		cout << "\nFirst of 20 edges succesfully inserted" << endl;
	}
	else
	{
		cout << "\nFirst of 20 edges failed to be inserted" << endl;
		passed = false;
	}

	if (nodebased_test.IsEdge(nodebased_test.FindVertex(1), nodebased_test.FindVertex(11)) == true)
	{
		cout << "\nMiddle of 20 edges succesfully inserted" << endl;
	}
	else
	{
		cout << "\nMiddle of 20 edges failed to be inserted" << endl;
		passed = false;
	}

	if (nodebased_test.IsEdge(nodebased_test.FindVertex(1), nodebased_test.FindVertex(21)) == true)
	{
		cout << "\nLast of 20 edges succesfully inserted" << endl;
	}
	else
	{
		cout << "\nLast of 20 edges failed to be inserted" << endl;
		passed = false;
	}

	cout << "--------------------------------------------------------------------" << endl;
	return passed;
}

bool Testing_AdjacencyList()
{
	bool passed = true;
	cout << "\n--------------------------------------------------------------------" << endl;
	cout << "Adjacency List testing results: " << endl;
	cout << "--------------------------------------------------------------------" << endl;

	// Test CSC382Graph_AdjacencyList Constructor(s)
	CSC382Graph_AdjacencyList<int> adjacency_test = CSC382Graph_AdjacencyList<int>();

	if(adjacency_test.GraphSize() == 0)
	{
		cout << "\nAdjacency graph succesfully initialized" << endl;
	}
	else
	{
		cout << "\nAdjacency graph failed to be initialized" << endl;
		passed = false;
	}

	// Test functions of the CSC382Graph_AdjacencyList class

	if(adjacency_test.AddVertex(1) != nullptr)
	{
		cout << "\nFirst vertex succesfully added" << endl;
	}
	else
	{
		cout << "\nFirst vertex failed to be inserted" << endl;
		passed = false;
	}

	if(adjacency_test.FindVertex(1) != nullptr)
	{
		cout << "\nFirst vertex succesfully found" << endl;
	}
	else
	{
		cout << "\nFirst vertex failed to be found" << endl;
		passed = false;
	}

	if(adjacency_test.IsVertex(1) == true)
	{
		cout << "\nFirst vertex is succesfully set as the vertex" << endl;
	}
	else
	{
		cout << "\nFirst vertex failed to be set as the vertex" << endl;
		passed = false;
	}

	if(adjacency_test.GraphSize() == 1)
	{
		cout << "\nGraph size succesfully increased" << endl;
	}
	else
	{
		cout << "\nGraph size failed to be increased" << endl;
		passed = false;
	}

	list<int>* new_vertex = adjacency_test.AddVertex(2);

	if(adjacency_test.IsVertex(new_vertex) == true)
	{
		cout << "\nNew vertex pointer succesfully set as vertex" << endl;
	}
	else
	{
		cout << "\nNew vertex pointer failed to be set as vertex" << endl;
		passed = false;
	}

	if (adjacency_test.GraphSize() == 2)
	{
		cout << "\nGraph size succesfully increased" << endl;
	}
	else
	{
		cout << "\nGraph size failed to be increased" << endl;
		passed = false;
	}

	if(adjacency_test.AddEdge(adjacency_test.FindVertex(1),adjacency_test.FindVertex(2)) == true)
	{
		cout << "\nEdge for first and second node succesfully added" << endl;
	}
	else
	{
		cout << "\nEdge for first and second node failed to be added" << endl;
		passed = false;
	}

	if(adjacency_test.IsEdge(adjacency_test.FindVertex(1), 2) == true)
	{
		cout << "\nEdge succesfully found" << endl;
	}
	else
	{
		cout << "\nEdge failed to be found" << endl;
		passed = false;
	}

	if(adjacency_test.NumberOfEdges(1) == 2)
	{
		cout << "\nNumber of edges connected to node 1 succesfully increase" << endl;
	}
	else
	{
		cout << "\nNumber of edges connected to node 1 failed to increase" << endl;
		passed = false;
	}

	if (adjacency_test.AddEdge(adjacency_test.FindVertex(1), 3) == true)
	{
		cout << "\nEdge for first and second node succesfully added" << endl;
	}
	else
	{
		cout << "\nEdge for first and second node failed to be added" << endl;
		passed = false;
	}

	if (adjacency_test.IsEdge(3) == true)
	{
		cout << "\nEdge succesfully found" << endl;
	}
	else
	{
		cout << "\nEdge failed to be found" << endl;
		passed = false;
	}

	if (adjacency_test.NumberOfEdges(1) == 3)
	{
		cout << "\nNumber of edges connected to node 1 succesfully increase" << endl;
	}
	else
	{
		cout << "\nNumber of edges connected to node 1 failed to increase" << endl;
		passed = false;
	}

	if (adjacency_test.FindVertex(3) != nullptr)
	{
		cout << "\nThird vertex successfully added" << endl;
	}
	else
	{
		cout << "\nThird vertex failed to be added" << endl;
		passed = false;
	}

	cout << "\nThis is a manual test to see if the graph is displayed properly" << endl;

	adjacency_test.PrintAdjacencyList();

	// Test creating lots of nodes and edges

	for(int i = 4; i <= 17; i++)
	{
		adjacency_test.AddVertex(i);
		adjacency_test.AddEdge(adjacency_test.FindVertex(1), i);
	}

	if(adjacency_test.IsVertex(4))
	{
		cout << "\nFirst of 20 verticies succesfully inserted" << endl;
	}
	else
	{
		cout << "\nFirst of 20 verticies failed to be inserted" << endl;
		passed = false;
	}

	if (adjacency_test.IsVertex(11))
	{
		cout << "\nMiddle of 20 verticies succesfully inserted" << endl;
	}
	else
	{
		cout << "\nMiddle of 20 verticies failed to be inserted" << endl;
		passed = false;
	}

	if (adjacency_test.IsVertex(17))
	{
		cout << "\nLast of 20 verticies succesfully inserted" << endl;
	}
	else
	{
		cout << "\nLast of 20 verticies failed to be inserted" << endl;
		passed = false;
	}

	if (adjacency_test.IsEdge(4))
	{
		cout << "\nFirst of 20 edges succesfully inserted" << endl;
	}
	else
	{
		cout << "\nFirst of 20 edges failed to be inserted" << endl;
		passed = false;
	}

	if (adjacency_test.IsEdge(11))
	{
		cout << "\nMiddle of 20 edges succesfully inserted" << endl;
	}
	else
	{
		cout << "\nMiddle of 20 edges failed to be inserted" << endl;
		passed = false;
	}

	if (adjacency_test.IsEdge(17))
	{
		cout << "\nLast of 20 edges succesfully inserted" << endl;
	}
	else
	{
		cout << "\nLast of 20 edges failed to be inserted" << endl;
		passed = false;
	}
	
	cout << "--------------------------------------------------------------------" << endl;

	return passed;
}

int main()
{
	if (Testing_NodeBased())
		cout << "\nNode-Based Tests successfully passed\n";
	else
		cout << "\nNode-Based Tests failed\n";

	if (Testing_AdjacencyList())
		cout << "\nAdjacency List Tests successfully passed\n";
	else
		cout << "\nAdjacency List Tests failed\n";

	cout << "\n--------------------------------------------------------------------" << endl;
	cout << "\nTesting completed." << endl;
	cout << "\n--------------------------------------------------------------------" << endl;

	system("pause");

    return 0;
}

