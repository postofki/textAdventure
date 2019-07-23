#include<iostream>

struct state;
struct transition;

struct transition
{
    char const *text;
    struct state *next_state;
};

struct state
{
    char const *text;
    struct transition transitions[8];
};

extern struct state start;
extern struct transition start_transitions[];
extern struct state octopus;
extern struct transition octopus_transitions[];
extern struct state asleep;
extern struct transition asleep_transitions[];
extern struct state miracle;
extern struct transition miracle_transitions[];

struct state start = {
    "\nWake up!! A giant space octopus attacked our Spaceship!\n"
    "Grab your lasergun and follow me to the main gate!\n"
        "What are you going to do?\n",
    {
        {" Follow your crew member.\n", &octopus},
        {" Fell asleep again.\n", &asleep},
        {NULL}
    }
};

struct state octopus = {
    "\nYou move immediately to the bridge of spaceship as you observe the fallen\n"
    "guards and you encounter gigantic tentacles waving inside the room\n"
        "What the fuck will you do?\n",
    {
        {" Attempt to attack one of the Tentacles with your lasergun.\n", NULL},
        {" Wait for a miracle to happen...\n", &miracle},
        {" RUN TO THE DROP PODS!\n", NULL},
        {NULL}
    }
};

struct state asleep = {
    "\n(-_-)\n"
    "Seriously ??\n",
    {
        {" Second change pleaaaase.\n", &start},
        {" Game Over. \n", NULL},
        {NULL}
    }
};

struct state miracle = {
    "\nWOW...Is it kinda soon to go for that? Aaanyway...\n"
    "You hear the noise of big laser canon shots and the space octopus\n"
    "exploded in thousand pieces coloring your spaceship in purple blood.\n"
        "What will you do?\n",
    {
        {" Search for the source of these canon shots.\n", NULL},
        {" Run to the communication section in bridge.\n", NULL},
        {NULL}
    }
};

int main(void)
{
    state *cur = &start;
    while (cur) {
        std::cout << cur->text << std::endl;

        unsigned trans = 0;
        while (cur->transitions[trans].text){
            std::cout << trans << "." << cur->transitions[trans].text;
            trans += 1;
        }

        unsigned choice;
        std::cin >> choice;
        std::cin.ignore();

        if(choice < trans){
            cur = cur->transitions[choice].next_state;
        }
    }
    return 0;
}



