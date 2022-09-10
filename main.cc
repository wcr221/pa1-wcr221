#include "Set.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <chrono>

using namespace std;
using namespace std::chrono;
extern char *optarg; // global variable for getopt()

void execute(Set &data, int iterations, int max_key, int ro_ratio);

int main(int argc, char **argv)
{
    int iterations, max_key, ro_ratio, opt;
    char ds[10];
    const char *options = "i:k:d:r:"; // possible options, : for option with associated value
    if (argc != 5)
    {
        cout << "Max number of arguements has not been reached" << endl;
        return 0;
    }
    // iterate through the command-line arguments
    while ((opt = getopt(argc, argv, options)) != -1)
    {
        switch (opt)
        { // return value of getopt
        case 'i':
            iterations = atoi(optarg); // optarg contains the value associated with the option i
            if (iterations < 0)
            {
                cout << "Invalid entry for number of iterations" << endl;
                return 0;
            }
            break;
        case 'k':
            max_key = atoi(optarg);
            if (max_key < 0)
            {
                cout << "Invalid entry for max key" << endl;
                return 0;
            }
            break;
        case 'd':
            strcpy(ds, optarg);
            break;
        case 'r':
            ro_ratio = atoi(optarg);
            if (ro_ratio < 0 || ro_ratio > 100)
            {
                cout << "Invalid entry for number of iterations" << endl;
                return 0;
            }
            break;
        default:
            cout << "Invalid option." << endl;
            ;
            cout << "Please try again" << endl;
            return 0;
        }
    }

    // print arguments
    cout << "Experiment: ITERATIONS = " << iterations << endl;
    cout << "Experiment: MAX KEY = " << max_key << endl;
    cout << "Experiment: DATA STRUCTURE = " << ds << endl;
    cout << "Experiment: RATIO = " << ro_ratio << endl;

    // Start the experiment
    if (strcmp(ds, "array"))
    {
        arraySet dataSet(max_key, max_key); // size is variable
        execute(dataSet, iterations, max_key, ro_ratio);
    }
    else if (strcmp(ds, "list"))
    {
        listSet dataSet(max_key, max_key);
        execute(dataSet, iterations, max_key, ro_ratio);
    }
    else if (strcmp(ds, "tree"))
    {
        treeSet dataSet(max_key, max_key);
        execute(dataSet, iterations, max_key, ro_ratio);
    }
    else if (strcmp(ds, "hash"))
    {
        treeSet dataSet(max_key, max_key);
        execute(dataSet, iterations, max_key, ro_ratio);
    }
    else
    {
        cout << "Invalid data structure entered.  Please enter valid data structure." << endl;
    }
    return 0;
}

void execute(Set &data, int iterations, int max_key, int ro_ratio)
{
    long duration_omega = 0;
    for (int run = 0; run < 5; run++)
    {
        int find_limit = (iterations * ro_ratio) / 100;
        int limit = (iterations - find_limit) / 2;
        int find_count = 0, insert_count = 0, remove_count = 0;

        // duration_average is the total amount of time it takes
        long duration_average = 0;
        for (int x = 1; x <= iterations; x++)
        {
            int random_op = rand() % 3;
            int random_key;
            auto start = high_resolution_clock::now();
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start); // dummy initialization
            switch (random_op)
            {

            case 0:
                if (find_count < find_limit)
                {
                    // find;
                    find_count++;
                    random_key = rand() % max_key;
                    start = high_resolution_clock::now();
                    data.find(random_key);
                    stop = high_resolution_clock::now();
                    duration = duration_cast<milliseconds>(stop - start);
                    duration_average = duration_average + duration.count();
                    // cout << duration_average << endl;
                    // record operation time
                }
                break;

            case 1:
                // insert;
                insert_count++;
                random_key = rand() % max_key - 1;
                start = high_resolution_clock::now();
                data.insert(random_key);
                stop = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop - start);
                duration_average = duration_average + duration.count();
                // cout << duration_average << endl;
                // record opertation time
                break;
            case 2:
                // remove:
                remove_count++;
                random_key = rand() % max_key - 1;
                start = high_resolution_clock::now();
                data.remove(random_key);
                stop = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop - start);
                duration_average = duration_average + duration.count();
                // cout << duration_average << endl;
                // record operation time
                break;
            }

            // cout << "duration_average durng iteration #" << iterations << " is " << duration_average << endl;
        }

        cout << "duration durng run #" << run + 1 << " is " << duration_average << endl;
        duration_omega = duration_omega + duration_average;
        cout << "duration_omega is " << duration_omega << endl;
    }

    duration_omega = duration_omega / 5;
    cout << "The average of 5 runs for the entire program is " << duration_omega << " milliseconds" << endl;
};
