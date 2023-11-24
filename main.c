#include <stdio.h>
#include <stdlib.h>
#include "headers/heap.h"
#include "headers/vector.h"
#include "headers/problem.h"
#include "headers/dijkstra.h"
#include "path.h"


void print_and_destroy_paths(Vector *paths)
{
    for (int i = 0; i < vector_size(paths); i++)
    {
        Path *path = vector_get(paths, i);
        path_print(path);
        path_destroy(path);
    }
    
    vector_destroy(paths);
}


int main()
{
    Problem *problem_data;
    Vector *paths;

    problem_data = problem_data_read("in.txt");
    paths = dijkstra_solve(problem_data);
    print_and_destroy_paths(paths);
    problem_data_destroy(problem_data);

    return 0;
}