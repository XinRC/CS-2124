/*
  rec01_start.cpp
  fall 2024
*/

// For Xin Rui Chen (xc2926)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//
// main
//
int main() { // Yes, it has to have an int for the return type
    //
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"
  std::cout<<"hello"<<std::endl; 

    // Task 2  Printing hello ...  Using "using namespace"
  cout<<"hello"<<endl; 


    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable
  int x;
  cout<<x<<endl; //displaying variable "x"
    

    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.
  int y = 17;
  int z = 2000000017;
  double pie = 3.14159;

  cout<<"size of y: "<<sizeof(y)<<endl;
  cout<<"size of z: "<<sizeof(z)<<endl;
  cout<<"size of pie: "<<sizeof(pie)<<endl;
    
    // Task 5  Attempt to assign the wrong type of thing to a variable

    //
    // Conditions
    //

    // Task 6  Testing for a range

  if (y>=10 && y<=20){
    cout<<y<<" is between 10 and 20, inclusive."<<endl;
  } else if (y>20){
    cout<<y<<" is greater than 20."<<endl;
  } else {
    cout<<y<<" is smaller than 10."<<endl;
  }


    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive

    // First with a for loop
  cout<<"task7"<<endl;
  int i = 10;
  for (; i <= 20; ++i){
    cout<<i<<" ";
  }

  cout<<endl;

    // Then with a while loop
  i = 10;
  while (i<= 20){
    cout<<i<<" ";
    ++i;
  }
  cout<<endl;

    // Finally with a do-while loop

  i=10;
  do{
    cout<<i<<" ";
    ++i;
  } while(i<=20);

  cout<<endl;

    // Task 8  Looping to successfully open a file, asking user for the name

  cout<<"task8"<<endl;
  string file_txt;

  cout<<"File Name: ";
  cin>>file_txt;
  ifstream file_name(file_txt);

  if (!file_name){
    cout<<"Error:" <<endl;
    
    while(!file_name){
      cout<<"File Name: ";
      cin>>file_txt;
      file_name.open(file_txt);
    }

  }


  cout<<endl;
  cout<<file_txt;

    // Task 9  Looping, reading file word by "word".
  cout<<"task9"<<endl;
  string words;
  while (file_name >> words){
      cout<<words<<endl;
  }

  file_name.close();
  cout<<endl;


    // Task 10 Open a file of integers, read it in, and display the sum.
  cout<<"task10"<<endl;
  int iterating_num;
  int sum = 0;
  ifstream integer_file("integers.txt");

  if (!integer_file){
    cerr<<"An error has occured with the file. Unable to read it";
    exit(1);
  }

  while (integer_file >> iterating_num){
    sum += iterating_num;
  }

  cout<<sum;
  integer_file.close();

  cout<<endl; 

    // Task 11 Open and read a file of integers and words. Display the sum.
  // should work
  cout<<"task11"<<endl;
  int task_11_iterating_num;
  int task_11_sum;
  ifstream task_11_integer_file("mixed.txt");

  if (!task_11_integer_file){
    cerr<<"An error has occured with the file. Unable to read it";
    exit(1);
  }

  while (task_11_integer_file >> task_11_iterating_num){
    task_11_sum += task_11_iterating_num;
  }
  cout<<task_11_sum;
  task_11_integer_file.close();

    //
    // Vectors
    //

    // Task 12 Filling a vector of ints

  cout<<endl;
  cout<<"task12"<<endl;
  vector<int>even_ints;

  for (int i = 10; i <= 100; i+=2){
    even_ints.push_back(i);
  }
    
    // Task 13 Displaying the vector THREE times
    //         a) using the indices,
  cout<<"task13a"<<endl;
  for (size_t i = 0; i < even_ints.size(); ++i){
    cout<<even_ints[i]<<" ";
  }
  cout<<endl;
    //         b) using a "ranged for"
  cout<<"task13b"<<endl;
  for (int values : even_ints){
    cout<<values<<" ";
  }
  cout<<endl;

    //         c) using indices again but backwards
  cout<<"task13c"<<endl;
  for (size_t i = even_ints.size(); i > 0; --i){
    cout<<even_ints[i-1]<< " ";
  }

    // Task 14. Initialize a vector with the primes less than 20. 

  //manually?

  cout<<endl;
  cout<<"task 14"<<endl;
  vector <int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

  for (int values : primes){
    cout<<values<<" ";
  }

    
} // main

