/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 menu.cpp
 ************************************************************/

#include <iostream>
#include <string>
#include "graph.h"
#include "dirGraph.h"

using namespace std;

int main(void) {
    char graphType;
    
    string fileName;
    string vertexToGetDegree;
    string tempStr1, tempStr2;
    
    int menuSelection = 0;
    int inDeg, outDeg, deg;
    
    double weight;
    
    // get graph type and text file name from user
    cout << "Enter graph type [d: directed; u: undirected]: ";
    cin >> graphType;
    cout << "Enter name of text file: ";
    cin.ignore();
    getline(cin, fileName);
    
    // menu for undirected graph
    if (graphType == 'u') {
        Graph myGraph(fileName);
        while(menuSelection != 11){
            cout << "Select a menu option: \n"
            << "1: Empty?\n"
            << "2: Degree (v)\n"
            << "3: Edge count\n"
            << "4: Connected?\n"
            << "5: Adjacent (u, v) \n"
            << "6: DFS (v)\n"
            << "7: BFS (v)\n"
            << "8: Print MST (v)\n"
            << "9: Clear\n"
            << "10: Insert (u, v, w)\n"
            << "11: Exit\n"
            << endl;
            cin >> menuSelection;
            
            switch(menuSelection) {
                case 1:
                    myGraph.empty() ?
                    cout << "Graph is empty" << endl :
                    cout << "Graph is not empty" << endl;
                    break;
                    
                case 2:
                    cout << "Enter vertex name to get degree of:";
                    cin.ignore();
                    getline(cin, vertexToGetDegree);
                    try
                    {
                        deg = myGraph.degree(vertexToGetDegree);
                        cout << "Degree of vertex " << vertexToGetDegree << " is "
                        << deg << endl;
                    }
                    catch (invalid_argument &e)
                    {
                        cerr << endl;
                    }
                    
                    break;
                    
                case 3:
                    cout << "The graph has " << myGraph.edgeCount() << " edges" << endl;
                    break;
                    
                case 4:
                    myGraph.isConnected() ?
                    cout << "The graph is connected" << endl :
                    cout << "The graph is not connected" << endl;
                    break;
                    
                case 5:
                    cout << "Enter name of first vertex: ";
                    cin.ignore();
                    getline(cin, tempStr1);
                    cout << "Enter name of second vertex: ";
                    getline(cin, tempStr2);
                    try {
                        weight = myGraph.adjacent(tempStr1, tempStr2);
                    } catch (invalid_argument &e) {
                        cerr << e.what() << endl;
                    }
                             
                    cout << "The weight of the edge connecting " << tempStr1
                    << " with " << tempStr2 << " is "
                    << weight << endl;
                    break;
                    
                case 6:
                    cout << "Enter vertex to start DFS search at: ";
                    cin.ignore();
                    getline(cin, tempStr1);
                    myGraph.DFS(tempStr1);
					cout << endl;
                    myGraph.reset();
                    break;
                    
                case 7:
                    cout << "Enter vertex to start BFS search at: ";
                    cin.ignore();
                    getline(cin, tempStr1);
                    myGraph.BFS(tempStr1);
                    myGraph.reset();
                    break;
                    
                case 8:
                    cout << "Enter vertex to get minimum spanning tree of: ";
                    cin.ignore();
                    getline(cin, tempStr1);
					myGraph.reset();
                    myGraph.MST(tempStr1);
                    break;
                    
                case 9:
                    myGraph.clear();
					cout << "Graph cleared" << endl;
                    break;
                    
                case 10:
                    cout << "Enter first vertex: ";
					cin.ignore();
					getline(cin, tempStr1);
					cout << "Enter second vertex: ";
					getline(cin, tempStr2);
					cout << "Enter weight: ";
					cin >> weight;
                    try {
                        myGraph.insert(tempStr1, tempStr2, weight);
                    } catch (invalid_argument &e) {
                        cerr << e.what();
                    }					
                    break;
                case 11:
                    return 0;
                    break;
                    
                default:
                    cout << "Invalid entry. Selection an option [1-11]: ";
                    cin >> menuSelection;
                    cout << endl;
                    break;
            } // end switch
        } // end while
        // end if, begin else
        // menu for directed graph

    } else if (graphType == 'd'){
        DirGraph myGraph(fileName);
        while(menuSelection != 11){
            cout << "Select a menu option: \n"
            << "1: Empty?\n"
            << "2: InDegree (v)\n"
            << "3: OutDegree\n"
            << "4: Edge Count?\n"
            << "5: Adjacent (u, v) \n"
            << "6: DFS (v)\n"
            << "7: BFS (v)\n"
            << "8: Print shortest path (v)\n"
            << "9: Clear\n"
            << "10: Insert (u, v, w)\n"
            << "11: Exit\n"
            << endl;
            cin >> menuSelection;
            
            switch(menuSelection) {
                case 1:
                    myGraph.empty() ?
                    cout << "Graph is empty" << endl :
                    cout << "Graph is not empty" << endl;
                    break;
                    
                case 2:
                    cout << "Enter vertex name to get inDegree of:";
                    cin.ignore();
                    getline(cin, vertexToGetDegree);
                    try {
                        inDeg = myGraph.inDegree(vertexToGetDegree);
                        cout << "InDegree of vertex " << vertexToGetDegree << " is "
                        << inDeg << endl;
                    } catch (invalid_argument &e) {
                        cerr << e.what() << endl;
                    }
                    
                    break;
                    
                case 3:
                    cout << "Enter vertex name to get outDegree of:";
                    cin.ignore();
                    getline(cin, vertexToGetDegree);
                    try {
                        outDeg = myGraph.outDegree(vertexToGetDegree);
                        cout << "OutDegree of vertex " << vertexToGetDegree << " is "
                        << outDeg << endl;
                    } catch (invalid_argument &e) {
                        cerr << e.what() << endl;
                    }
                    
                    break;
                    
                case 4:
                    cout << "The graph has " << myGraph.edgeCount() << " edges" << endl;
                    break;
                    
                case 5:
                    cout << "Enter name of first vertex: ";
                    cin.ignore();
                    getline(cin, tempStr1);
                    cout << "Enter name of second vertex: ";
                    getline(cin, tempStr2);
                    cout << "The weight of the edge connecting " << tempStr1
                    << " with " << tempStr2 << " is "
                    << myGraph.adjacent(tempStr1, tempStr2) << endl;
                    break;
                    
                case 6:
                    cout << "Enter vertex to start DFS search at: ";
                    cin.ignore();
                    getline(cin, tempStr1);
					myGraph.reset();
                    myGraph.DFS(tempStr1);
					cout << endl;
                    myGraph.reset();
                    break;
                    
                case 7:
                    cout << "Enter vertex to start BFS search at: ";
                    cin.ignore();
                    getline(cin, tempStr1);
                    myGraph.BFS(tempStr1);
                    myGraph.reset();
                    break;
                    
                case 8:
                    cout << "Enter the vertex name to begin shortest path: ";
                    cin.ignore();
                    getline(cin, tempStr1);
                    cout << "The shortest path between " << tempStr1 <<
							" and each vertex: " << endl;
                    try {
                        myGraph.shortPath(tempStr1);
                    } catch (invalid_argument &e) {
                        cerr << e.what() << endl;
                    }
                    
                    break;
                    
                case 9:
                    myGraph.clearGraph();
                    if (myGraph.empty())
                        cout << "Graph cleared" << endl;
                    break;
                    
                case 10:
                    cout << "Enter name of first vertex: ";
                    cin.ignore();
                    
                    getline(cin, tempStr1);
                    cout << "Enter name of second vertex: ";
                    getline(cin, tempStr2);
                    
                    cout << "Enter a weight: ";
                    cin >> weight;
                    cout << endl;
                    try {
                        myGraph.insert(tempStr1, tempStr2, weight);
                    } catch (invalid_argument &e) {
                        cerr << e.what() << endl;
                    }
                    break;
                case 11:
                    return 0;
                    break;
                    
                default: 
                    cout << "Invalid entry. Selection an option [1-11]: ";
                    cin >> menuSelection;
                    cout << endl;
                    break;
            } // end switch
        } // end while
        // end if, begin else
    } else {
        cout << "Invalid graph type" << endl;
    } 
    return 0;
}
