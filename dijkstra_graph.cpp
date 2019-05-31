#include <iostream>

using namespace std;

unsigned int currentWeights[5];
bool nodesVisited[5];

class Node {
   Node** nodes;
   int* weights;
   int current;
   int capacity;
   char name;

public: 
   Node(char _n){
      name = _n;
      nodes = new Node*[10];
      weights = new int[10];
      capacity = 10;
      current = 0;
   }

   void add(Node* node, int weight){
      nodes[current] = node;
      weights[current++] = weight;
   }

   Node* getNode(int i){
     return nodes[i];
   }

   int getWeight(int i){
     return weights[i];
   }

   int nodesConnected(){
      return current;
   }

  char getName(){return name;}
};

void find(Node* start){
  bool flag = false;
  for(int i = 0; i < 5; i++){
    if(nodesVisited[i] == false){flag = true;}
  }

  if(!flag){return;}

  if(start->nodesConnected() == 0){
    return;
  }

  int minWeight = 10000;
  int minWeightId = -1;
  for(int i = 0; i < start->nodesConnected(); i++){
    if(nodesVisited[start->getNode(i)->getName() - 'A'] == false && minWeight > start->getWeight(i)){
      minWeight = start->getWeight(i);
      minWeightId = i;
    }
  }

  if(minWeightId == -1){return;}

  nodesVisited[start->getNode(minWeightId)->getName() - 'A'] = true;
  cout << start->getName() << "->" << start->getNode(minWeightId)->getName() << endl;
  find(start->getNode(minWeightId));
  find(start);
}

int main(){
  for(int i = 0; i < 5; i++){
    currentWeights[i] = 4294967294;
  }

  Node n1('A');
  Node n2('B');
  Node n3('C');
  Node n4('D');
  Node n5('E');

  n1.add(&n2, 2);
  n1.add(&n3, 10);
  n1.add(&n4, 6);

  n2.add(&n4, 8);
  n2.add(&n5, 4);

  n3.add(&n4, 4);
  n3.add(&n5, 2);

  find(&n1);

  return 0;
}
