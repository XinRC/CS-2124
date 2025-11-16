<div align = "center"> 

# Lecture 14
## Seperate Compilation

</div>

#### Seperate Compilation

Seperate Compilation is used to make programs look cleaner. Instead of having class definitions inside the `main.cpp` file, two new files can be created that will house the 1. declaration of the class, 2. definition of the class - a `.h` and a `.cpp` file. 

For the .h file, to ensure that there will be no loop of recreating of the header file, `.h`, use the following. If this is not done, then it is possible that with another seperate compilation file calls the .h file, which calls another .h file, which calls the old .h file, creating an infinite loop. 

```C++
#ifndefine HEADERNAME
#define HEADERNAME

// class declarations... 

#endif

```

Do note for the header file, `.h`, it is best to not use `using namespace std;` as it is much safer to just type out whatever needed of the std file - an example being `std::cout` or `std::vector`. 

#### To Run Files

To run the seperated compilation program, you must put the files in **one** folder and run a terminal command:
`g++ *.cpp -o [.exe file name]` for Windows 
`g++ -std=c++17 *.cpp -o bin && ./bin ` for MacOS

