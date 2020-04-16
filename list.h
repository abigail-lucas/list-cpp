class List {
    protected:
        int* arr;
        int ln, capacity;
    public:
        List();
        List(int l);
        ~List();
        int get(int i);
        int length();
        void append(int n);
    friend class ListTests;
};
