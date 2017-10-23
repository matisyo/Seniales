#ifndef SIGINT_HANDLER_H_
#define SIGINT_HANDLER_H_

#include <signal.h>
#include <assert.h>

#include "EventHandler.h"

class SIGINT_Handler : public EventHandler {

private:
    sig_atomic_t gracefulQuit;

public:
    pid_t *vec_id;
    int *altos;
    int n;
    SIGINT_Handler () : gracefulQuit(0) {
    }

    ~SIGINT_Handler () {
    }

    virtual int handleSignal ( int signum ) {
        assert ( signum == SIGINT );
        this->gracefulQuit = this->gracefulQuit+1;
        for(int i = 0;i<n;i++){
            if(altos[i]<this->gracefulQuit){
                std::cout << "Pid " << vec_id[i] <<std::endl;
                kill(vec_id[i],SIGINT);
            }

        }
        return 0;
    }

    sig_atomic_t getGracefulQuit () const {
        return this->gracefulQuit;
    }

};

#endif /* SIGINT_HANDLER_H_ */
