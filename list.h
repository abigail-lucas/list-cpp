class List {
    protected:
        int* arr;
        int ln, capacity;
        void resize(int c);
    public:
        List();
        List(int l);
        ~List();
        int get(int i);
        int length();
        void append(int n);
        void extend(int n[], int l);
        void pop();
        void pop(int i);
        void pop(int s, int e);
    friend class ListTests;
};
