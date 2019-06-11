class Vertex {
    char symbol;
    public:
        Vertex(char);
        char getChar() const;
        void setChar(char);

        Vertex& operator=(const Vertex&);
        bool operator==(const Vertex&);
};

Vertex::Vertex(char _c='X'){
    symbol = _c;
}

char Vertex::getChar() const {
    return symbol;
}

void Vertex::setChar(char _c) {
    symbol = _c;
}

Vertex& Vertex::operator=(const Vertex& other){
    if(this != &other){
        this->setChar(other.getChar());
    }

    return *this;
}

bool Vertex::operator==(const Vertex& other){
    return this->getChar() == other.getChar();
}

class Graph {
    Vertex** vertices;
    int* sizes;
    int cap, current;

    void resize(){
        Vertex** temp = new Vertex*[cap];
        for(int i = 0; i < current; i++){
            temp[i] = new Vertex[sizes[i]];
            for(int j = 0; j < sizes[i]; j++){
                temp[i][j] = vertices[i][j];
            }
        }

        for(int i = 0; i < current; i++){
            delete[] vertices[i];
        }
        delete[] vertices;

        cap *= 2;
        copyVertices(temp, current);
        
        for(int i = 0; i < current; i++){
            delete[] temp[i];
        }
        delete[] temp;
    }

    void copyVertices(Vertex** vertices, int n){
        this->vertices = new Vertex*[cap];
        while(current != n - 1){
            this->vertices[current] = new Vertex[sizes[current]];
            for(int i = 0; i < sizes[current]; i++){
                this->vertices[current][i] = vertices[current][i];
            }
            current++;
        }
    }

    public:
        Graph();
        Graph(Vertex**, int*, int);
        void add(Vertex, Vertex*, int);
        bool remove(Vertex);
        int find(Vertex);
};

Graph::Graph(){
    cap = 10;
    current = 0;
    vertices = new Vertex*[cap];
}

Graph::Graph(Vertex** vertices, int* sizes, int n){
    cap = n;
    current = 0;
    copyVertices(vertices, n);
    this->sizes = new int[n];
    for(int i = 0; i < n; i++){
        this->sizes[i] = sizes[i];
    }
}

void Graph::add(Vertex v, Vertex* adj, int n){
    if(current == cap){
        resize();
    }
    vertices[current] = new Vertex[n];
    for(int i = 0; i < n; i++){
        vertices[current][i] = adj[i];
    }
    current++;
}

int Graph::find(Vertex v){
    for(int i = 0; i < current; i++){
        if(vertices[i][0] == v){
            return i;
        }
    }
    return -1;
}
