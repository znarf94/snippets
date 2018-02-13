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
static EventHandler bar;
static EventHandler baz;

EventHandler* table[nb_States][nb_Events] = {
    [A][X] = foo,
    [B][Y] = bar,
    [C][Z] = baz,
};

int main() {
    State s = A;
    Event e = X;
    EventHandler* eh;

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

static State bar() {
    return C;
}

static State baz() {
    return A;
}
