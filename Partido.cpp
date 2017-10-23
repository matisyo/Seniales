//
// Created by matiascarballo on 23/10/17.
//

#include <zconf.h>
#include <csignal>
#include "Partido.h"
#include "SignalHandler.h"
#include "SIGINT_Handler_Partidos.h"

Partido :: Partido () {
    i=0;
    j=0;
}
Partido ::~Partido(){

}
void Partido::play(){
    SIGINT_Handler_Partidos sigint_handler;
    SignalHandler :: getInstance()->registrarHandler ( SIGINT,&sigint_handler );

    sleep(15);
    if ( sigint_handler.getGracefulQuit() == 1 ){
        std::cout << "Mojado Pid " <<pid<< " i,j "<<i<<","<<j<< std::endl;
    } else{
        std::cout << "Seco Pid " <<pid<< " i,j "<<i<<","<<j<< std::endl;
    }

}
