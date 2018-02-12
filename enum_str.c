#define ENUM_ELEM(X)                X
#define ENUM_STR(X)                 [X] = #X
#define ENUM_ENUM_DEF(ELEMS, NAME)  typedef enum { ELEMS(ENUM_ELEM) } NAME
#define ENUM_STR_DEF(ELEMS, NAME)   __attribute__((unused)) static const char* NAME##_str[] = { ELEMS(ENUM_STR) }
#define ENUM_DEF(ELEMS, NAME)       ENUM_ENUM_DEF(ELEMS, NAME); ENUM_STR_DEF(ELEMS, NAME)


#define ABZ_STATES(_)       _(STOPPED),         \
                            _(RAMP),            \
                            _(RUNNING),         \
                            _(GO_TO),           \
                            _(CARAC_SPEED),     \
                            _(CARAC_POS)

ENUM_DEF(ABZ_STATES, ABZ_State);

