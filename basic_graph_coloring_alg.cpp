#include <iostream>
#include <vector>

using namespace std;

class Node {
   Node** nodes;
   int current;
   int capacity;
   char name;
   char color;

public:
   Node(char _n='0'){
      name = _n;
      color = '0';
      nodes = new Node*[10];
      capacity = 10;
      current = 0;
   }

   void add(Node* node){
      nodes[current++] = node;
   }

   Node* getNode(int i){
     return nodes[i];
   }

   int nodesConnected(){
      return current;
   }

  char getName() const {return name;}

  char getColor() const { return color; }
  char setColor(char _color) {color = _color; }
};

bool contains(vector<char> vec, char el){
  for(int i = 0; i < vec.size(); i++){
    if(vec[i] == el){ return true; }
  }
  return false;
}

void basicColoring(Node** nodes, int n){
    for(int i = 0; i < n; i++){
        Node* currentNode = nodes[i];
        vector<char> v;
        for(int j = 0; j < currentNode->nodesConnected(); j++){
            if(!contains(v, currentNode->getNode(j)->getColor())){
                v.push_back(currentNode->getNode(j)->getColor());
            }
        }
        char c = 'a';
        bool flag = true;
        while(flag){
           if(!contains(v, c)){
              currentNode->setColor(c);
              flag = false;
           } else { c++; }
        }
    }
}

int main(){
    Node n1('A');
    Node n2('B');
    Node n3('C');
    Node n4('D');
    Node n5('E');

    n1.add(&n2);
    n1.add(&n3);
    n1.add(&n4);

    n2.add(&n1);
    n3.add(&n1);
    n4.add(&n1);

    n2.add(&n4);
    n2.add(&n5);

    n4.add(&n2);
    n5.add(&n2);

    n3.add(&n4);
    n3.add(&n5);

    n4.add(&n3);
    n5.add(&n3);

    Node** nodes = new Node*[5];
    nodes[0] = &n1;
    nodes[1] = &n2;
    nodes[2] = &n3;
    nodes[3] = &n4;
    nodes[4] = &n5;

    basicColoring(nodes, 5);

    vector<char> v;
    for(int i = 0; i < 5; i++){
        if(!contains(v, nodes[i]->getColor())){
            v.push_back(nodes[i]->getColor());
        }
        cout << nodes[i]->getName() << ": Color%" << nodes[i]->getColor() << "%;\n";
    }

    cout << "ChromaticNumber: " << v.size() << endl;

    return 0;
}
