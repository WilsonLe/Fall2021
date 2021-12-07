#include "graph.h"
#include <climits>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void testGraphConstructor() {
  cout << "Testing graph constructor" << endl;
  Graph graph1("sampleGraph(1).txt");
  string graphString1 = "0: 1 2 \n1: 0 2 3 \n2: 0 1 4 \n3: 1 4 \n4"
                        ": 2 3 \n";
  assert(graph1.toString() == graphString1);
  cout << "\tTest 1 Passed" << endl;

  Graph graph2("sampleGraph(2).txt");
  string graphString2 = "0: 1 \n1: 0 \n2: 3 \n3: 2 \n";
  assert(graph2.toString() == graphString2);
  cout << "\tTest 2 Passed" << endl;
}

int main() {
  testGraphConstructor();
  Graph graph1("sampleGraph(1).txt");
  graph1.prim(0);
  // expected
  // 0 1 1
  // 1 2 1
  // 1 3 1
  // 3 4 1
  cout << "dfs output: " << endl;
  graph1.dfs();
  // expected
  // 0 1 2 4 3

  cout << "cycle output:" << endl;
  // expected 1
  cout << graph1.cycle() << endl;

  Graph graph2("sampleGraph(2).txt");
  graph2.prim(0);
  // expected
  // The graph is disconnected. Therefore, prim operation is not possible.

  cout << "dfs output: " << endl;
  graph2.dfs();
  // expected
  // 0 1
  // 2 3

  cout << "cycle output:" << endl;
  // expected 1
  cout << graph2.cycle() << endl;

  Graph graph3("sampleGraph(3).txt");
  graph3.prim(0);
  // expected
  // The graph is disconnected. Therefore, prim operation is not possible.

  cout << "dfs output: " << endl;
  graph3.dfs();
  // expected
  // 0 1
  // 2 3

  cout << "cycle output:" << endl;
  // expected 0
  cout << graph3.cycle() << endl;

  Graph graph4("sampleGraph(4).txt");
  graph4.prim(0);
  // expected
  // The graph is disconnected. Therefore, prim operation is not possible.

  cout << "dfs output: " << endl;
  graph4.dfs();
  // expected
  // 0 1
  // 2 3

  cout << "cycle output:" << endl;
  // expected 0
  cout << graph4.cycle() << endl;
}