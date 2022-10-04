#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void randomVector(int vector[], int size)
{
    for (int i = 0; i < size; i++)
    {
        //Store 0-99 random numbers into the vector
        vector[i] = rand() % 100;
    }
}


int main(){

    unsigned long size = 100000000;

    srand(time(0));

    int *v1, *v2, *v3;

    //Store the Start time of the Vector Addition
    auto start = high_resolution_clock::now();

    //Store the blocks of memory into each vector
    v1 = (int *) malloc(size * sizeof(int *));
    v2 = (int *) malloc(size * sizeof(int *));
    v3 = (int *) malloc(size * sizeof(int *));


    randomVector(v1, size);

    randomVector(v2, size);


    //Loop each Vectors and add them together
    for (int i = 0; i < size; i++)
    {
        v3[i] = v1[i] + v2[i];
    }

    auto stop = high_resolution_clock::now();

    // Store the total time taken for adding the vectors
    auto duration = duration_cast<microseconds>(stop - start);


    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}



/*





#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <pthread.h>
#include <thread>//
using namespace std::chrono;
using namespace std;

#define NUM_THREADS 16 //



// Function to initialise and add vectors
void addVector(int v1[], int v2[], int v3[], unsigned long startIndex, unsigned long endIndex, short seed)
{
    // Initialize vector 1 with random values
    randomVector(v1, startIndex, endIndex, seed);

    // Update seed value
    seed++;

    // Initialize vector 2 with random values
    randomVector(v2, startIndex, endIndex, seed);

    // Add the two vectors
    for (int i = startIndex; i <= endIndex; i++)
    {
         v3[i] = v1[i] + v2[i];
    }
       
    
}

void randomVector (int vector[], int size)
{
    for (int i = 0; i < size; i++)
    {
        //Store 0-99 random numbers into the vector
        vector[i] = rand() % 100;
    }
}




int main(){

    unsigned long size = 100000000;

   //  srand(time(0));

    int *v1, *v2, *v3;
    int i; // 

    //Store the Start time of the Vector Addition
    auto start = high_resolution_clock::now();

    //Store the blocks of memory into each vector
    v1 = (int *) malloc(size * sizeof(int *));
    v2 = (int *) malloc(size * sizeof(int *));
    v3 = (int *) malloc(size * sizeof(int *));


    // randomVector(v1, size);

    // randomVector(v2, size);


    // //Loop each Vectors and add them together
    // for (int i = 0; i < size; i++)
    // {
    //     v3[i] = v1[i] + v2[i];
    // }

  // Create thread objects
    thread threads[NUM_THREADS];
    cout<<"\nNumber of Threads = "<< NUM_THREADS;
    // Seed factor is used to make sure the srand gets a unique seed when initializing vectors
    short seed = 0;
    
    unsigned long startIndex = 0;
    unsigned long endIndex;
    unsigned long partitionSize = size / NUM_THREADS;
    
    // Start threads to initialize and add vectors 
    for (i = 0; i < NUM_THREADS; i++)
    {
        // Calculate start and end index based on partition size
        endIndex = startIndex + partitionSize;
        if (endIndex >= size)
            endIndex = size - 1;

        // Start thread
        threads[i] = thread(addVector, v1, v2, v3, startIndex, endIndex, ref(seed));

        // Update seed value
        seed++;

        // Calculate start and end index based on partition size
        startIndex = endIndex + 1;
    }

    // Wait for all threads to finish executing
    for (i = 0; i < NUM_THREADS; i++)
    {
       threads[i].join();
    }
j



    auto stop = high_resolution_clock::now();

    // Store the total time taken for adding the vectors
    auto duration = duration_cast<microseconds>(stop - start);


    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}







*/
