class list {
    private:
        int* arr;
        int ln, capacity;
    public:
        list();
        list(int l);
        ~list();
        int get(int i);
        int length();
        void append(int n);
};
