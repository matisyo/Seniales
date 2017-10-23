#ifndef SIGUSR2_HANDLER_H_
#define SIGUSR2_HANDLER_H_

#include <signal.h>
#include <assert.h>
#include <iostream>

#include "EventHandler.h"

class SIGUSR2_Handler : public EventHandler {

private:
public:
    sig_atomic_t *sig;

    SIGUSR2_Handler ()  {
    }

    ~SIGUSR2_Handler () {
    }

    virtual int handleSignal ( int signum ) {
        assert ( signum == SIGUSR2 );
        *sig = *sig-1;
        if(*sig<0){
            *sig=0;
        }
        return 0;
    }

};

#endif /* SIGUSR2_HANDLER_H_ */
