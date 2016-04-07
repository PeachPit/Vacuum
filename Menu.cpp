//Included libraries and such //
//Using SDL and standard IO
#include <SDL.h>
#include <SDL_main.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Start sup SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Global variables will remove soon
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHellowWorld = Null;

bool init(){
//Initialization flag
bool success = true;

//Initialize SDL
if(SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    success = false;
}
else{
    //Create window
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(gWindow == Null)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else{
        //Get window surface
        gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
}
return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP( "C:\Users\Kam Blackweb\Downloads\Peach_Pit_Logo.bmp" );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "Peach_Pit_Logo.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}



int main( int argc, char* args[] )
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
     else
    {
        //Create window
        window = SDL_CreateWindow( "Menu Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
           else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 4000 );
        }
    }
    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}

