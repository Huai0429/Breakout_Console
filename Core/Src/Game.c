#include "Game.h"
s_Ball_stat Ball={
  .xPos = 10,
  .yPos = 10,
  .init_xPos = 10,
  .init_yPos = 10,
  .xSpeed = 5,
  .ySpeed = 5,
  .dir = South_East,
  // .move_pfn = Ball_Move
};
s_GameBoard_stat Board = {
  .TL = {0,0}, //5,5
  .TR = {0,0}, //475,5
  .BL = {0,0}, //5,315
  .BR = {0,0}, //475,315
  .width = edge_width
};
s_Stick_stat Stick = {
  .x = 10,
  .y = 160,
  .width = 20,
  .height = 3, 
};
void stick_create(void)
{
  fillRect(Stick.x - (Stick.height/2),Stick.y - (Stick.width/2),Stick.height,Stick.width,ILI9488_RED);
}
void Game_Board(void)
{
  fillScreen(ILI9488_BLACK);
  fillRect(0,0,LCD_cur_width,Board.width,ILI9488_WHITE);// Top Board.TL[0],Board.TL[1]
  fillRect(0,Board.TL[1],Board.width,LCD_cur_height,ILI9488_WHITE);// Left Board.TL[0],Board.TL[1]
  fillRect(Board.TR[0],0,Board.width,LCD_cur_height,ILI9488_WHITE);// Right Board.TR[0],Board.TR[1]
  fillRect(0,Board.BL[1],LCD_cur_width,Board.width,ILI9488_WHITE);//Bottom  Board.BL[0],Board.BL[1]
}
void Game_Initial(void)
{
  Game_Board();
  stick_create();
  Draw_Ball(Ball.init_xPos,Ball.init_yPos,ILI9488_WHITE);
}

void Draw_Ball(uint16_t x, uint16_t y, uint16_t color)
{
  // printf("Draw Ball start\n");
  fillRect(x,y,Ball_Size,Ball_Size,color);
  // printf("Finished !! \n");
}

void *Ball_Move()
{
  Draw_Ball(Ball.xPos,Ball.yPos,ILI9488_BLACK);
  // printf("1. X:%d Y:%d Dir:%d\n",Ball.xPos,Ball.yPos,Ball.dir);
  // const int new_xpos = (Ball.xPos + Ball.xSpeed);
  // const int new_ypos = (Ball.yPos + Ball.ySpeed);
  const int new_xpos = edge_check(0);
  const int new_ypos = edge_check(1);
  // printf("2. X:%d Y:%d Dir:%d\n",new_xpos,new_ypos,Ball.dir);
  // Game_Board();
  Draw_Ball(new_xpos,new_ypos,ILI9488_WHITE);
  Ball.xPos = new_xpos;
  Ball.yPos = new_ypos;
  return (void*)1;
}
int edge_check(int XorY)
{
  if(!XorY){
    int target_Pos = Ball.xPos + Ball.xSpeed;
    // printf("XXX = %d TR[0] %d TL[0] %d\n",target_Pos,Board.TR[0],Board.TL[0]);
    if(target_Pos>=Board.TR[0]){
      if(Ball.dir == North_East)
        Ball_Dir_adjust(North_West);
      else 
        Ball_Dir_adjust(South_West);
      return Board.TR[0]-Ball_Size;
    }else if(target_Pos<=Board.TL[0]){
      if(Ball.dir == North_West)
        Ball_Dir_adjust(North_East);
      else 
        Ball_Dir_adjust(South_East);
      return edge_width + Ball_Size + 2 ;
    }
    return target_Pos;  
  }else{
    int target_Pos = Ball.yPos + Ball.ySpeed;
    // printf("YYY = %d TR[1] %d BR[1] %d \n",target_Pos,Board.TR[1],Board.BR[1]);
    if(target_Pos<=Board.TR[1]){
      if(Ball.dir == North_West)
        Ball_Dir_adjust(South_West);
      else
        Ball_Dir_adjust(South_East);
      return edge_width + Ball_Size + 2;
    }else if(target_Pos>=Board.BR[1]){
      if(Ball.dir == South_West)
        Ball_Dir_adjust(North_West);
      else
        Ball_Dir_adjust(North_East);
      return Board.BR[1] - Ball_Size;
    }
    return target_Pos;
  }
}
void Game_rotation(int h,int w)
{
  Board.TL[0] = edge_width;
  Board.TL[1] = edge_width;
  Board.TR[0] = w - edge_width;
  Board.TR[1] = edge_width;
  Board.BL[0] = edge_width;
  Board.BL[1] = h - edge_width;
  Board.BR[0] = w - edge_width;
  Board.BR[1] = h - edge_width;
  // printf("Top Right corner %d %d\n",Board.TR[0],Board.TR[1]);
  // printf("Top Left  corner %d %d\n",Board.TL[0],Board.TL[1]);
  // printf("Bot Left  corner %d %d\n",Board.BL[0],Board.BL[1]);
  // printf("Bot Right corner %d %d\n",Board.BR[0],Board.BR[1]);

}
void Ball_Speed_adjust(int xSpeed ,int ySpeed)
{
  Ball.xSpeed = xSpeed;
  Ball.ySpeed = ySpeed;
}
void Ball_Dir_adjust(direction dir)                              
{
  switch(dir){
    case North:
      Ball.xSpeed = 0;
      Ball.ySpeed = Ball.ySpeed<0?Ball.ySpeed:(Ball.ySpeed*-1); //-
      Ball.dir = North;
      break;
    case North_East:
      Ball.xSpeed = Ball.xSpeed<0?(Ball.xSpeed*-1):Ball.xSpeed;//+
      Ball.ySpeed = Ball.ySpeed<0?Ball.ySpeed:(Ball.ySpeed*-1);//-
      Ball.dir = North_East;
      break;
    case East:
      Ball.xSpeed = Ball.xSpeed<0?(Ball.xSpeed*-1):Ball.xSpeed;//+
      Ball.ySpeed = 0;
      Ball.dir = East;
      break;
    case South_East:
      Ball.xSpeed = Ball.xSpeed<0?(Ball.xSpeed*-1):Ball.xSpeed;//+
      Ball.ySpeed = Ball.ySpeed<0?(Ball.ySpeed*-1):Ball.ySpeed;//+
      Ball.dir = South_East;
      break;
    case South:
      Ball.xSpeed = 0;
      Ball.ySpeed = Ball.ySpeed<0?(Ball.ySpeed*-1):Ball.ySpeed;//+
      Ball.dir = South;
      break;
    case South_West:
      Ball.xSpeed = Ball.xSpeed<0?Ball.xSpeed:(Ball.xSpeed*-1);//-
      Ball.ySpeed = Ball.ySpeed<0?(Ball.ySpeed*-1):Ball.ySpeed;//+
      Ball.dir = South_West;
      break;
    case West:
      Ball.xSpeed = Ball.xSpeed<0?Ball.xSpeed:(Ball.xSpeed*-1);//-
      Ball.ySpeed = 0;//
      Ball.dir = West;
      break;
    case North_West:
      Ball.xSpeed = Ball.xSpeed<0?Ball.xSpeed:(Ball.xSpeed*-1);//-
      Ball.ySpeed = Ball.ySpeed<0?Ball.ySpeed:(Ball.ySpeed*-1);//-
      Ball.dir = North_West;
      break;
  }

}