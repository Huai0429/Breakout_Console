#include "stdio.h"
#include "stdlib.h"
#include "ili9488.h"



#define Ball_Size 3
#define edge_width 5
extern uint16_t LCD_cur_width;
extern uint16_t LCD_cur_height;
typedef enum direction {
    North = 0b00000001,
    North_East = 0b00000010, 
    East = 0b00000100,
    South_East = 0b00001000,
    South = 0b00010000,
    South_West = 0b00100000,
    West = 0b01000000,
    North_West = 0b10000000
}direction;
typedef struct Ball_status
{
    uint16_t xPos;
    uint16_t yPos;
    uint16_t init_xPos;
    uint16_t init_yPos;
    int  xSpeed;
    int  ySpeed;
    direction  dir;
    // void* move_pfn;
}s_Ball_stat;
// s_Ball_stat Ball;

typedef struct GameBoard_status
{
    int TL[2];
    int TR[2];
    int BR[2];
    int BL[2];
    int width;
}s_GameBoard_stat;

typedef struct Stick_status
{
    int x;
    int y;
    int width;
    int height;
}s_Stick_stat;

void Game_Board(void); 
void Game_Initial(void);
void Draw_Ball(uint16_t,uint16_t,uint16_t);
void *Ball_Move();
void Game_rotation(int,int);
void Ball_Speed_adjust(int,int);
void Ball_Dir_adjust(direction);
int edge_check(int);
void stick_create(void);