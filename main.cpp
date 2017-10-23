#include <iostream>
#include <unistd.h>
#include <csignal>

#include "SIGINT_Handler.h"
#include "SignalHandler.h"
#include "Partido.h"
#include "SIGUSR2_Handler.h"

#define f(A,B) for(int A = 0 ; A < B ; A++)

using namespace std;

int main () {
    bool flag = true;

    int alto = 2;
    int ancho= 2;
    int n = alto*ancho;
    pid_t vec[n];
    pid_t altos[n];
    f(i,n){
        pid_t p = fork();
        if(p==0){
            //cout << "Soy el proceso hijo " << getpid() << endl;
            //cout << "alto: " << i%ancho << endl;
            //cout << "ancho: " << i/ancho << endl;
            Partido partido;
            partido.i=i%ancho;
            partido.j=i/ancho;
            partido.id=i;
            partido.pid=p;
            partido.play();

            flag = false;
            break;
        }else{
            vec[i]=p;
            altos[i]=i/ancho;
        }
    };
    if(flag){
        // event handler para la senial SIGINT (-2)
        SIGINT_Handler sigint_handler;
        sigint_handler.vec_id = vec;
        sigint_handler.altos = altos;
        sigint_handler.n=n;

        SIGUSR2_Handler sigusr2_handler;
        sigusr2_handler.sig = &sigint_handler.gracefulQuit;
        // se registra el event handler declarado antes
        SignalHandler :: getInstance()->registrarHandler ( SIGINT,&sigint_handler );
        SignalHandler :: getInstance()->registrarHandler ( SIGUSR2,&sigusr2_handler );

        cout << "Soy el proceso " << getpid() << endl;
        // mientras no se reciba la senial SIGINT, el proceso realiza su trabajo
        while ( sigint_handler.getGracefulQuit() < 3 ) {
            cout << "Soy el sigint_handler " << sigint_handler.getGracefulQuit() << endl;
            sleep ( 2 );
        }
        // se recibio la senial SIGINT, el proceso termina
        SignalHandler :: destruir ();
        cout << "Termino el proceso" << endl;
    }
    return 0;
}
