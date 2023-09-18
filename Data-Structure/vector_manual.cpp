#include <vector>

int main(int argc, char* argv[]) {
    // declaration
    vector<int> A;                  // declare with the form of "vector<data_type> variable_name"

    // insert operation
    A.push_back(1);                 // insert 1 after the last element
    A.insert(A.begin(), 7);         // insert 1 before the first element
    A.insert(A.begin() + 2, 10);    // insert 10 to the location of the index 2

    // value change
    A[4] = -5;                      // change the value of the index 4 into -5

    // delete operation
    A.pop_back();                   // delete the last element
    A.erase(A.begin() + 3);         // delete the element of the index 3
    A.clear();                      // delete all elements

    // get information
    A.size();                       // the number of element
    A.front();                      // the first element
    A.back();                       // the last element
    A[3];                           // the value of the index 3
    A.at(5);                        // the value of the index 5
    A.begin();                      // the location of the first element
    A.end();                        // the next location of the last element
}