#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int const SIZEX = 20; 
int const SIZEY = 7; 
int const MINES = 15; 

int main() { 

    srand(time(NULL)); 

    int toPlaceMines = MINES; 
    int pole[SIZEX][SIZEY]; 

    //inicialise 
    for(int y = 0; y < SIZEY; y ++){ 
        for(int x = 0; x < SIZEX; x++) 
        { 
            pole[x][y] = 0; 
        } 
    } 

     

    //place mines 
        do 
        { 
            int randx = rand() % SIZEX; 
            int randy = rand() % SIZEY; 
            if(pole[randx][randy] == 0) 
            { 
                pole[randx][randy] = 9; 
                toPlaceMines -= 1; 
            } 
        }while(toPlaceMines > 0); 

     

    //add numbers 
    for(int y = 0; y < SIZEY; y ++){ 
        for(int x = 0; x < SIZEX; x++) 
        { 
            if(pole[x][y] == 9) 
            { 
                int cga = x!=0?-1:0; 
                int cgb = x!=SIZEX-1?1:0; 

                int cha = y!=0?-1:0; 
                int chb = y!=SIZEY-1?1:0; 

                for(int g = cga; g <= cgb; g++) 
                { 
                    for(int h = cha; h <= chb; h++) 
                    { 
                        if(pole[x + g][y + h] != 9) 
                        { 
                            pole[x + g][y + h] += 1; 
                        } 
                    } 
                } 
            } 
        } 
    } 

    //print pole 
    for(int y = 0; y < SIZEY; y ++){ 
        for(int x = 0; x < SIZEX; x++) 
        { 
            if(pole[x][y] == 9){ 
                printf("*"); 
            }else{ 
              printf("%d", pole[x][y]); 
            } 
        } 
        printf("\n"); 
    } 
    return 0; 
} 