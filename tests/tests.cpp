#include <iostream>
#include <assert.h>
#include "../list.h"
using namespace std;

class ListTests {
    // Testing class
    protected:
        void test_instantiate() {
            // Tests the instantion of List
            List defaut_list_length = List();
            assert(defaut_list_length.capacity == 2);
            assert(defaut_list_length.ln == 0);

            int large_list_size = 20;
            List large_list = List(large_list_size);
            assert(large_list.capacity == large_list_size);
            assert(large_list.ln == 0);
            cout << "Test passed: Instantiate" << endl;
        };
    public:
        ListTests() {
            cout << "---------------------" << endl;
            cout << "Running tests" << endl;
            cout << "---------------------" << endl;
            test_instantiate();
        };
};

int main() {
    // Create a Testing Class with an empty list
    // The constructor runs the tests
    ListTests testing_class = ListTests();
    return 0;
}
