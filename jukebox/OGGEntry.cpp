#include <iostream>
#include "OGGEntry.h"
using namespace std;

OGGEntry::OGGEntry(string s) : AudioEntry(s)
{
#ifdef DEBUG
    cout << "OGGEntry Constructor" << endl;
#endif

    // We would scan the file to determine
    // the actual play length, the artist,
    // etc.

    // Here as a poor man's surrogate we put a random length:
    play_length = 120.0 + (rand() % 60); 

    // We're just going to assume that all of these are music,
    // not podcasts, for example
    setMusic(true);
}


OGGEntry::~OGGEntry()
{
#ifdef DEBUG
    cout << "Mp3Entry Destructor" << endl;
#endif
 
}

void OGGEntry::play()
{
#ifdef DEBUG
    cout << "OGGEntry play" << endl;
#endif
    cout << "In practice, we'd call an external application player for .ogg file..." << endl;

    // Fake some output to show the behavior
    if (isMusic())
        cout << "\t(" << get_name() << ")\ttra-la-la-lah! ..... " << get_play_length() << "s" << endl;
    else
        cout << "\t(" << get_name() << ")\tblah-blah-blah! ..... " << get_play_length() << "s" << endl;

}
