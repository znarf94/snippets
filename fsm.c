#include <stdlib.h>

typedef enum {
    A,
    B,
    C,
    nb_States
} State;

typedef enum {
    X,
    Y,
    Z,
    nb_Events
} Event;

typedef State (EventHandler)(void) ;

static EventHandler foo;

EventHandler* table[nb_States][nb_Events];

int main() {
    State s = A;
    Event e = X;
    EventHandler* eh;

    table[A][X] = foo;

    for (;;) {
        e = X;
        eh = table[s][e];
        
        if (eh != NULL) {
            s = eh();
        }
    }
    return 0;
}


static State foo() {
    return B;
}
