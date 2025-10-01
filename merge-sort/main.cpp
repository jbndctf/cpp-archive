#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &left_vector, vector<int> &right_vector) {
  vector<int> sorted_vector;

  while (!left_vector.empty() && !right_vector.empty()) {
    if (left_vector[0] > right_vector[0]) {
      sorted_vector.push_back(right_vector[0]);
      right_vector.erase(right_vector.begin());
    } else {
      sorted_vector.push_back(left_vector[0]);
      left_vector.erase(left_vector.begin());
    }
  }

  while (!left_vector.empty()) {
    sorted_vector.push_back(left_vector[0]);
    left_vector.erase(left_vector.begin());
  }

  while (!right_vector.empty()) {
    sorted_vector.push_back(right_vector[0]);
    right_vector.erase(right_vector.begin());
  }

  return sorted_vector;
}

vector<int> merge_sort(vector<int> &unsorted_vector) {
  if (unsorted_vector.size() == 1) {
    return unsorted_vector;
  }

  vector<int> left_vector, right_vector;

  for (int i = 0; i < unsorted_vector.size(); i++) {
    if (i < unsorted_vector.size() / 2) {
      left_vector.push_back(unsorted_vector[i]);
    } else {
      right_vector.push_back(unsorted_vector[i]);
    }
  }

  left_vector = merge_sort(left_vector);
  right_vector = merge_sort(right_vector);

  return merge(left_vector, right_vector);
}

int main() {
  vector<int> unsorted_vector;
  unsorted_vector.push_back(10);
  unsorted_vector.push_back(4);
  unsorted_vector.push_back(2);
  unsorted_vector.push_back(7);
  unsorted_vector.push_back(7);
  unsorted_vector.push_back(5);

  cout << "Unsorted: ";
  for (int i = 0; i < unsorted_vector.size(); i++) {
    cout << unsorted_vector[i] << " ";
  }
  cout << endl;

  vector<int> sorted_vector = merge_sort(unsorted_vector);
 
  cout << "Sorted: ";
  for (int i = 0; i < sorted_vector.size(); i++) {
    cout << sorted_vector[i] << " ";
  }
  cout << endl;
}
