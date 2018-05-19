#ifndef WORLD
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WIDTH 480
#define HEIGHT 270
#define SIZE 3
#define GRAID_SIZE 16
#define GENERATION 1
#define ADD_LIFE 1
#define ADD_CNT 1
#endif


void buildWorld(int (&world)[HEIGHT][WIDTH]);
void generate(int (&world)[HEIGHT][WIDTH], int times);
int calcOne(int (&world)[HEIGHT][WIDTH],int x, int y);
int surive(int num, int type);
void printWorld(int (&world)[HEIGHT][WIDTH]);
void addLife(int (&world)[HEIGHT][WIDTH]);