#include <iostream>
#include <assert.h>
#include <string.h>
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
        void test_get() {
            // Tests the get function of List
            List testing_list = List(); // Creates our List at length 2
            testing_list.append(1);
            testing_list.append(3);

            assert(testing_list.get(0) == 1);
            assert(testing_list.get(1) == 3);

            bool error_happened = false;
            try {
                // Try getting an element that shouldn't exist
                testing_list.get(2);
            }
            catch (exception& e) {
                // We expect the error to happen
                error_happened = true;
            }
            assert(error_happened == true);

            cout << "Test passed: Get" << endl;
        };
        void test_length() {
            // Test the length function of List
            List testing_list = List(); // Creates our List at length 2
            testing_list.append(1);
            testing_list.append(3);

            assert(testing_list.length() == 2);

            cout << "Test passed: Length" << endl;
        };
        void test_append() {
            // Tests the append function of List
            List testing_list = List(); // Creates our List at length 2
            testing_list.append(1);

            assert(testing_list.arr[0] == 1);
            assert(testing_list.ln == 1);

            testing_list.append(2);

            assert(testing_list.arr[1] == 2);
            assert(testing_list.ln == 2);

            // Here the array size would have been too small
            // The resize functionality got triggered
            testing_list.append(3);

            assert(testing_list.arr[2] == 3);
            assert(testing_list.ln == 3);

            cout << "Test passed: Append" << endl;
        };
        void test_pop() {
            // Test the pop function of List
            List testing_list = List(); // Creates our List at length 2
            testing_list.append(1);
            testing_list.append(3);
            testing_list.append(5);

            // First we confirm the length of our list
            assert(testing_list.length() == 3);

            testing_list.pop(1);
    
            // Assert that the middle element got removed
            // And the remaining elements got moved up
            assert(testing_list.get(0) == 1);
            assert(testing_list.get(1) == 5);
            // The length should have shrunk by 1
            assert(testing_list.length() == 2);

            testing_list.append(7);

            // First we assert that the last element available is 7
            assert(testing_list.get(testing_list.length() - 1) == 7);
            assert(testing_list.ln == 3);

            testing_list.pop();

            // Now we assert that the last element available is 5
            assert(testing_list.get(testing_list.length() - 1) == 5);
            assert(testing_list.ln == 2);

            cout << "Test passed: Pop" << endl;
        };
    public:
        ListTests() {
            cout << "---------------------" << endl;
            cout << "Running tests" << endl;
            cout << "---------------------" << endl;
            test_instantiate();
            test_get();
            test_length();
            test_append();
            test_pop();
            cout << "---------------------" << endl;
            cout << "All tests passed" << endl;
        };
};

int main() {
    // Create a Testing Class with an empty list
    // The constructor runs the tests
    ListTests testing_class = ListTests();
    return 0;
}
