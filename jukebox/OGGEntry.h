#ifndef __OGG_ENTRY_H__
#define __OGG_ENTRY_H__

#include "audioentry.h"
using namespace std;

class OGGEntry: public AudioEntry {

	public:

    OGGEntry(string s);
    virtual ~OGGEntry();

    virtual void play();
        
};

#endif