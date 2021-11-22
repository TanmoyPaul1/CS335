// Homework 4
// Testing Sorting Algorithms
// Tanmoy Paul

#include "Sort.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Computes duration given a start time and a stop time in nano seconds.
// Keep it in.
long long ComputeDuration(chrono::high_resolution_clock::time_point start_time, 
			  chrono::high_resolution_clock::time_point end_time) {
  return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
}

// Test function that shows how you can time a piece of code.
// Just times a simple loop. Remove for final submission.

void TestTiming() {
  cout << "Test Timing" << endl;
  const auto begin_time = chrono::high_resolution_clock::now();
  // Time this piece of code.
  int sum = 0;
  for (int i = 1; i < 10000; ++i) sum ++;
  // End of piece of code to time.
  const auto end_time = chrono::high_resolution_clock::now();    
  cout << ComputeDuration(begin_time, end_time) << "ns" << endl;
}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  // Use rand() to generate random integer
  vector<int> v(size_of_vector);
  for (size_t i = 0; i < size_of_vector; ++i)
  {
    v[i] = rand() % 100;
  }
  return v; 
}

// Generates and returns sorted vector of size @size_of_vector.
// If @smaller_to_larger is true, returns vector sorted from small to large.
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) {
  vector<int> v = GenerateRandomVector(size_of_vector);
  if (smaller_to_larger)
    sort(v.begin(), v.end());
  else
    sort(v.begin(), v.end(), greater<int>());
  return v;
}

// Verifies that a vector is sorted given a comparator.
// I.e. it applies less_than() for consecutive pair of elements and returns true
// iff less_than() is true for all pairs.
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {
  for(size_t i = 1; i < input.size(); ++i)
  {
    if (input[i - 1] != input[i] && !less_than(input[i - 1], input[i]))  return false;
  }
  return true; 
}

template <typename Comparable>
void print(const vector<Comparable> &input) {
  for(size_t i = 0; i < input.size(); ++i)
  {
    cout << input[i] << " ";
  }
  cout << endl;
}

// Wrapper function to test different sorting algorithms. See homework's PDF for details.
void testSortingWrapper(int argc, char **argv) {
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);
  if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small") {
    cout << "Invalid input type" << endl;
    return;
  }
  if (input_size <= 0) {
    cout << "Invalid size" << endl;
    return;
  }
  if (comparison_type != "less" && comparison_type != "greater") {
    cout << "Invalid comparison type" << endl;
    return;
  }

  // This block of code to be removed for your final submission.
  // TestTiming();

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  srand((unsigned) time(0));
  vector<int> heap_vector;
  vector<int> merge_vector;
  vector<int> quick_vector;
  vector<int> quick_vector2;
  vector<int> quick_vector3;
  if (input_type == "random") {
    // Generate random vector.
    heap_vector = GenerateRandomVector(input_size); 
    merge_vector = GenerateRandomVector(input_size); 
    quick_vector = GenerateRandomVector(input_size); 
    quick_vector2 = GenerateRandomVector(input_size); 
    quick_vector3 = GenerateRandomVector(input_size); 
  } else {
    // Generate sorted vector.
    bool smaller_to_larger = (input_type == "sorted_small_to_large" ? true : false);
    heap_vector = GenerateSortedVector(input_size, smaller_to_larger);
    merge_vector = GenerateSortedVector(input_size, smaller_to_larger);
    quick_vector = GenerateSortedVector(input_size, smaller_to_larger);
    quick_vector2 = GenerateSortedVector(input_size, smaller_to_larger);
    quick_vector3 = GenerateSortedVector(input_size, smaller_to_larger);
  }

  // cout << "Original vectors" << endl;
  // print(heap_vector);
  // print(merge_vector);
  // print(quick_vector);
  // print(quick_vector2);
  // print(quick_vector3);

  // Call HeapSort / MergeSort / QuickSort  using appropriate input.
  // ^^SAME for HeapSort & QuickSort
  // Call quicksort with median of three as pivot / middle as pivot / first as pivot using appropriate input.
  // ^^SAME for QuickSort2 & QuickSort3

  function<bool(int, int)> compare;
  if (comparison_type == "less") 
    compare = less<int>{};
  else
    compare = greater<int>{};
  
  // HeapSort(heap_vector, compare);
  // MergeSort(merge_vector, compare);
  // QuickSort(quick_vector, compare);
  // QuickSort2(quick_vector2, compare);
  // QuickSort3(quick_vector3, compare);

  // cout << "\nSorted vectors" << endl;
  // print(heap_vector);
  // print(merge_vector);
  // print(quick_vector);
  // print(quick_vector2);
  // print(quick_vector3);

  const auto heap_begin_time = chrono::high_resolution_clock::now();
  HeapSort(heap_vector, compare);
  const auto heap_end_time = chrono::high_resolution_clock::now();
  cout << "\nHeapsort\n\n" << "Runtime: " << ComputeDuration(heap_begin_time, heap_end_time) << " ns\n";
  cout << "Verified: " << VerifyOrder(heap_vector, compare) << endl;

  const auto merge_begin_time = chrono::high_resolution_clock::now();
  MergeSort(merge_vector, compare);
  const auto merge_end_time = chrono::high_resolution_clock::now();
  cout << "\nMergeSort\n\n" << "Runtime: " << ComputeDuration(merge_begin_time, merge_end_time) << " ns\n";
  cout << "Verified: " << VerifyOrder(merge_vector, compare) << endl;

  const auto quick_begin_time = chrono::high_resolution_clock::now();
  QuickSort(quick_vector, compare);
  const auto quick_end_time = chrono::high_resolution_clock::now();
  cout << "\nQuickSort\n\n" << "Runtime: " << ComputeDuration(quick_begin_time, quick_end_time) << " ns\n";
  cout << "Verified: " << VerifyOrder(quick_vector, compare) << endl;

  cout << "\nTesting Quicksort Pivot Implementations" << endl;

  const auto quick1_begin_time = chrono::high_resolution_clock::now();
  QuickSort(quick_vector, compare);
  const auto quick1_end_time = chrono::high_resolution_clock::now();
  cout << "\nMedian of Three\n\n" << "Runtime: " << ComputeDuration(quick1_begin_time, quick1_end_time) << " ns\n";
  cout << "Verified: " << VerifyOrder(quick_vector, compare) << endl;

  const auto quick2_begin_time = chrono::high_resolution_clock::now();
  QuickSort2(quick_vector2, compare);
  const auto quick2_end_time = chrono::high_resolution_clock::now();
  cout << "\nMiddle\n\n" << "Runtime: " << ComputeDuration(quick2_begin_time, quick2_end_time) << " ns\n";
  cout << "Verified: " << VerifyOrder(quick_vector2, compare) << endl;

  const auto quick3_begin_time = chrono::high_resolution_clock::now();
  QuickSort3(quick_vector3, compare);
  const auto quick3_end_time = chrono::high_resolution_clock::now();
  cout << "\nFirst\n\n" << "Runtime: " << ComputeDuration(quick3_begin_time, quick3_end_time) << " ns\n";
  cout << "Verified: " << VerifyOrder(quick_vector3, compare) << endl;
}

int main(int argc, char **argv) {
  // DO NOT CHANGE or ADD ANY CODE in this function.
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
  
  testSortingWrapper(argc, argv);

  return 0;
}
