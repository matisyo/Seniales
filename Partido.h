//
// Created by matiascarballo on 23/10/17.
//

#ifndef JUSTSIGNALS_PARTIDO_H
#define JUSTSIGNALS_PARTIDO_H
#include <iostream>

class Partido {
    private:

    public:
        int i;
        int j;
        pid_t pid;
        int id;
        Partido();
        ~Partido();
        void play();
};


#endif //JUSTSIGNALS_PARTIDO_H
