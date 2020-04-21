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
        void test_extend() {
            List testing_list = List(3);
            int extending_arr[3] = {1,2,3};

            assert(testing_list.length() == 0);

            testing_list.extend(extending_arr, 3);

            assert(testing_list.length() == 3);
            assert(testing_list.get(0) == 1);
            assert(testing_list.get(1) == 2);
            assert(testing_list.get(2) == 3);

            testing_list.extend(extending_arr, 3);

            assert(testing_list.length() == 6);
            assert(testing_list.get(3) == 1);
            assert(testing_list.get(4) == 2);
            assert(testing_list.get(5) == 3);

            cout << "Test passed: Extend" << endl;
        };
        void test_pop_last() {
            List testing_list = List(3); // Creates our List at length 3
            testing_list.append(1);
            testing_list.append(3);
            testing_list.append(5);

            // First we assert that the last element available is 5
            assert(testing_list.get(testing_list.length() - 1) == 5);
            assert(testing_list.length() == 3);

            testing_list.pop();

            // Now we assert that the last element available is 3
            assert(testing_list.get(testing_list.length() - 1) == 3);
            assert(testing_list.length() == 2);

            cout << "Test passed: Pop last" << endl;
        };
        void test_pop_last_errors() {
            List testing_list = List();

            bool error_happened = false;
            try {
                testing_list.pop();
            }
            catch(exception& e) {
                // We expect the error to happen
                error_happened = true;
            }
            assert(error_happened == true);
            assert(testing_list.ln == 0);

            cout << "Test passed: Pop last error" << endl;
        };
        void test_pop_one() {
            // Test the pop function of List
            List testing_list = List(3); // Creates our List at length 3
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

            cout << "Test passed: Pop one" << endl;
        };
        void test_pop_one_errors() {
            List testing_list = List(3); // Creates our List at length 3

            bool error_happened = false;
            try {
                testing_list.pop(0);
            }
            catch(exception& e) {
                error_happened = true;
            }
            assert(error_happened == true);

            testing_list.append(1);

            error_happened = false;
            try
            {
                testing_list.pop(1);
            }
            catch(exception& e)
            {
                error_happened = true;
            }
            assert(error_happened == true);

            cout << "Test passed: Pop one errors" << endl;
        };
        void test_pop_many() {
            List testing_list = List(5); // List of 5 for many options

            testing_list.append(0);
            testing_list.append(1);
            testing_list.append(2);
            testing_list.append(3);
            testing_list.append(4);

            testing_list.pop(1, 3); // Here we pop places 1,2,3

            assert(testing_list.get(0) == 0);
            assert(testing_list.get(1) == 4);
            assert(testing_list.length() == 2);

            cout << "Test passed: Pop many" << endl;
        };
        void test_pop_many_errors() {
            List testing_list = List(5); // List of 5 for many options

            bool error_happened = false;
            try
            {
                testing_list.pop(0, 4);
            }
            catch(exception& e)
            {
                error_happened = true;
            }
            assert(error_happened == true);

            testing_list.append(0);
            testing_list.append(1);
            testing_list.append(2);
            testing_list.append(3);
            testing_list.append(4);

            error_happened = false;
            try
            {
                testing_list.pop(-1, 3);
            }
            catch(exception& e)
            {
                error_happened = true;
            }
            assert(error_happened == true);

            error_happened = false;
            try
            {
                testing_list.pop(0, 6);
            }
            catch(exception& e)
            {
                error_happened = true;
            }
            assert(error_happened == true);

            cout << "Test passed: Pop many errors" << endl;
        };
    public:
        ListTests() {
        };
        void run_tests() {
            cout << "---------------------" << endl;
            cout << "Running tests" << endl;
            cout << "---------------------" << endl;
            test_instantiate();
            test_get();
            test_length();
            test_append();
            test_pop_last();
            test_pop_last_errors();
            test_pop_one();
            test_pop_one_errors();
            test_pop_many();
            test_pop_many_errors();
            cout << "---------------------" << endl;
            cout << "All tests passed" << endl;
        };
};

int main() {
    // Create a Testing Class with an empty list
    // The constructor runs the tests
    ListTests testing_class = ListTests();
    testing_class.run_tests();
    return 0;
}
