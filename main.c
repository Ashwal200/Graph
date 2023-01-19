#include <stdio.h>
#include "graph.h"



#define END_OF_PROGRAM 0


int main(){

    char user_decision = ' ';
    int answer =0;
    pNode last_graph = NULL;
    while ( !feof(stdin) )
    {
        user_decision = getchar();
//        printf("the last user input after new loop is: %c\n", user_decision);//***********
        switch (user_decision)
        {
            case 'A':
//                printf("\nget into A \n");
                if (last_graph != NULL)
                {
                    deleteGraph_cmd(&last_graph);
                }
                build_graph_cmd(&last_graph);
//                user_decision = getchar();
                break;

            case 'B':
//                printf("\nget into B \n");
                insert_node_cmd(&last_graph);
//                user_decision = getchar();
                break;

            case 'D':// Delete the next input node.
//                printf("\nget into D \n");
                delete_node_cmd(&last_graph);
                break;

            case 'S':
                answer = shortsPath_cmd(last_graph);
                printf("Dijsktra shortest path: %d \n", answer);
                break;

            case 'T':
                answer= TSP_cmd(last_graph);
                printf("TSP shortest path: %d \n", answer);
//                user_decision = getchar();
                break;
        }
    }

    if (last_graph != NULL)
    {
        deleteGraph_cmd(&last_graph);
    }

    return END_OF_PROGRAM;
}