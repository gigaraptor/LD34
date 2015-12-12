#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <jansson/jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <winsock2.h>


const static int SUCCESS = 1;
const static int FAIL = 2;
const static int GAME_WON = 3;
const static char *OPTIONS_FILE = "options.json";
const static int MAXIMUM_UNITS = 1000;
const static int SENDING_BRACKET = 10;
const static int NO_SIDES = 4;
const static int SIZE_WELCOME = 100;
const static char *WELCOME_COMMAND = "meep";
typedef struct
{
	int SCREEN_WIDTH, SCREEN_HEIGHT, PORT_ADDRESS;
	const char *TITLE, *RED_FILEPATH, *BLUE_FILEPATH, *NODE_FILEPATH, *IP_ADDRESS_SERVER;
}options;

typedef struct
{
	short x,y;
	char alive,dest, inCombat, xVel,yVel,side;

}unitData;
typedef struct
{
	char code, holder;
	short x,y,sideOneNumber,sideTwoNumber;

}node;

//init functions
char *loadJsonFile(const char *filename, int *success);
options initOptions(const char *jsonFile, int *success);
SDL_Window *initSDL(options *opt, int *success);
int getFileSize(FILE *sizeToGet, int *success);
SDL_Renderer *createRenderer(SDL_Window *screen, int *success);
WSADATA startWinsock(int *success);
SOCKET initSocket(int *success);
struct sockaddr_in getServerDetails(options *opt, int *success);
void deinit();
int connectToServer(int *isSuccess, struct sockaddr_in details, SOCKET soc);