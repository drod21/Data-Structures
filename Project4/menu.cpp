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
    
    // get graph type and text file name from user
    cout << "Enter graph type [d: directed; u: undirected]: ";
    cin >> graphType;
    cout << "Enter name of text file: ";
    cin.ignore();
    getline(cin, fileName);
    
    // menu for undirected graph
    if (graphType == 'u') {
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
                    
                    break;
                    
                case 2:
                    
                    break;
                    
                case 3:
                    
                    break;
                    
                case 4:
                    
                    break;
                    
                case 5:
                    
                    break;
                    
                case 6:
                    
                    break;
                    
                case 7:
                    
                    break;
                    
                case 8:
                    
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
                    
                    break;
                    
                case 2:
                    
                    break;
                    
                case 3:
                    
                    break;
                    
                case 4:
                    
                    break;
                    
                case 5:
                    
                    break;
                    
                case 6:
                    
                    break;
                    
                case 7:
                    
                    break;
                    
                case 8:
                    
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
