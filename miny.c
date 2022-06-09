#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h>

int const SIZEX = 10; 
int const SIZEY = 5; 
int const MINES = 5; 

//first input is row and second is collums

void spread(int x, int y, int pole[SIZEX][SIZEY], int mask[SIZEX][SIZEY])
{
    if(pole[x][y] == 0)
    mask[x][y] = 0;
    { 
        int cga = x!=0?-1:0; 
        int cgb = x!=SIZEX-1?1:0; 

        int cha = y!=0?-1:0; 
        int chb = y!=SIZEY-1?1:0; 

        for(int g = cga; g <= cgb; g++) 
        { 
            for(int h = cha; h <= chb; h++) 
            { 
                spread(g, h, pole, mask);
            } 
        } 
    } 
}

int uncover(int pole[SIZEX][SIZEY], int mask[SIZEX][SIZEY])
{
    int ix = 0;
    int iy = 0;
    scanf(" %d %d", &ix, &iy);
    ix--;
    iy--;
    if(pole[ix][iy] != 9)
    {
    mask[ix][iy] = pole[ix][iy];
    spread(ix++, iy++, pole, mask);
    return 1;
    }else
    {
        for(int y = 0; y < SIZEY; y ++){ 
            for(int x = 0; x < SIZEX; x++) 
            { 
                mask[x][y] = pole[x][y];
            } 
        } 
    }
    return 0;
}





int main() { 

    srand(time(NULL)); 

    int toPlaceMines = MINES; 
    int pole[SIZEX][SIZEY]; 
    
    int mask[SIZEX][SIZEY];

    //inicialise 
    for(int y = 0; y < SIZEY; y ++){ 
        for(int x = 0; x < SIZEX; x++) 
        { 
            pole[x][y] = 0;
            mask[x][y] = 10;
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
    
    //preprint mask 
        for(int y = 0; y < SIZEY; y ++){ 
            for(int x = 0; x < SIZEX; x++) 
            { 
                if(mask[x][y] == 9){ 
                    printf("*");
                }else if(mask[x][y] == 10){
                    printf("X");
                }else{ 
                    printf("%d", mask[x][y]); 
                } 
            } 
        printf("\n"); 
        } 
    
    
    
    
    
    
    
    
    //interact
    int loop = 1;
    
    while(loop)
    {
        loop = uncover(pole, mask);

        
        
        //print mask 
        for(int y = 0; y < SIZEY; y ++){ 
            for(int x = 0; x < SIZEX; x++) 
            { 
                if(mask[x][y] == 9){ 
                    printf("*"); 
                }else if(mask[x][y] == 10){
                    printf("X");
                }else{ 
                    printf("%d", mask[x][y]); 
                }
            } 
        printf("\n"); 
        } 
    }
    
    return 0; 
} 
