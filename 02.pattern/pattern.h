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

typedef struct Cell {
    int data[3];
    int status[2];
} Cell;

extern Cell world[HEIGHT][WIDTH];

void buildCell(Cell(&C));
void buildWorld(Cell (&world)[HEIGHT][WIDTH]);
void addLife(Cell (&world)[HEIGHT][WIDTH]);
void generate(Cell (&world)[HEIGHT][WIDTH], int time);
void calcOne(Cell (&world)[HEIGHT][WIDTH], int x, int y);
void changeOne(Cell (&world)[HEIGHT][WIDTH], int pos[SIZE][SIZE][2]);
int surive(int num, int type);
void printCell(Cell(&C));
void printWorld(Cell (&world)[HEIGHT][WIDTH]);
