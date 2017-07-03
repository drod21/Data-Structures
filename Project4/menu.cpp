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
    int menuSelection = 0;
	string vertexToGetDegree;
	string tempStr1, tempStr2;
    
    // get graph type and text file name from user
    cout << "Enter graph type [d: directed; u: undirected]: ";
    cin >> graphType;
    cout << "Enter name of text file: ";
    cin.ignore();
    getline(cin, fileName);
    
    // menu for undirected graph
    if (graphType == 'u') {
		Graph myGraph;
        while(menuSelection != 11){
            cout << "Selection a menu option: \n"
            << "1: Empty?\n"
            << "2: Degree (v)\n"
            << "3: Edge count\n"
            << "4: Connected?\n"
            << "5: Adjacent (u, v)? \n"
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
					if(myGraph.empty() == true)
						cout << "Graph is empty" << endl;
					else
						cout << "Graph is not empty" << endl;
                    break;
                    
                case 2:
					cout << "Enter vertex name to get degree of:";
					cin.ignore();
					getline(cin, vertexToGetDegree);
					cout << "Degree of vertex " << vertexToGetDegree << " is "
						 << myGraph.degree(vertexToGetDegree) << endl;
                    break;
                    
                case 3:
                    cout << "The graph has " << myGraph.edgeCount() << " edges" << endl;
                    break;
                    
                case 4:
                    if(myGraph.isConnected() == true)
						cout << "The graph is connected" << endl;
					else
						cout << "The graph is not connected" << endl;
                    break;
                    
                case 5:
                    cout << "Enter name of first vertex: ";
					cin.ignore();
					getline(cin, tempStr1);
					cout << "Enter name of second vertex: ";
					cin.ignore();
					getline(cin, tempStr2);
					cout << "The weight of the edge connecting " << tempStr1
						 << " with " << tempStr2 << " is "
						 << myGraph.adjacent(tempStr1, tempStr2); 
                    break;
                    
                case 6:
                    cout << "Enter vertex to start DFS search at: ";
					cin.ignore();
					getline(cin, tempStr1);
					myGraph.DFS(tempStr1);
                    break;
                    
                case 7:
                    cout << "Enter vertex to start BFS search at: ";
					cin.ignore();
					getline(cin, tempStr1);
					myGraph.BFS(tempStr1);                    
                    break;
                    
                case 8:
                    cout << "Enter vertex to get minimum spanning tree of: ";
					cin.ignore();
					getline(cin, tempStr1);
					myGraph.MST(tempStr1);
                    break;
                    
                case 9:
                    
                    break;
                    
                case 10:
                    
                    break;
                case 11:
                    
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
		DirGraph myGraph;
        while(menuSelection != 11){
            cout << "Selection a menu option: \n"
            << "1: Empty?\n"
            << "2: InDegree (v)\n"
            << "3: OutDegree\n" 
            << "4: Edge Count?\n"
            << "5: Adjacent (u, v)? \n"
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
                    if(myGraph.empty() == true) 
						cout << "Graph is empty" << endl;
					else
						cout << "Graph is not empty" << endl;
                    break;
                    
                case 2:
					cout << "Enter vertex name to get inDegree of:";
					cin.ignore();
					getline(cin, vertexToGetDegree);
					cout << "InDegree of vertex " << vertexToGetDegree << " is "
						 << myGraph.inDegree(vertexToGetDegree) << endl;
                    break;
                    
                case 3:
					cout << "Enter vertex name to get outDegree of:";
					cin.ignore();
					getline(cin, vertexToGetDegree);
					cout << "OutDegree of vertex " << vertexToGetDegree << " is "
						 << myGraph.outDegree(vertexToGetDegree) << endl;
                    break;
                    
                case 4:
                    cout << "The graph has " << myGraph.edgeCount() << " edges" << endl;
                    break;
                    
                case 5:
                    cout << "Enter name of first vertex: ";
					cin.ignore();
					getline(cin, tempStr1);
					cout << "Enter name of second vertex: ";
					cin.ignore();
					getline(cin, tempStr2);
					cout << "The weight of the edge connecting " << tempStr1
						 << " with " << tempStr2 << " is "
						 << myGraph.adjacent(tempStr1, tempStr2);                    
                    break;
                    
                case 6:
                    cout << "Enter vertex to start DFS search at: ";
					cin.ignore();
					getline(cin, tempStr1);
					myGraph.DFS(tempStr1);                    
                    break;
                    
                case 7:
                    cout << "Enter vertex to start BFS search at: ";
					cin.ignore();
					getline(cin, tempStr1);
					myGraph.BFS(tempStr1);                    
                    break;
                    
                case 8:
                    cout << "Enter name of first vertex";
					cin.ignore();
					getline(cin, tempStr1);
					cout << "Enter name of second vertex: ";
					cin.ignore();
					cout << "The shortest path between " << tempStr1 << " and "
						 << tempStr2 << " is: \n";
					myGraph.shortPath(tempStr1, tempStr2);
                    break;
                    
                case 9:
                    
                    break;
                    
                case 10:
                    
                    break;
                case 11:
                    
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
