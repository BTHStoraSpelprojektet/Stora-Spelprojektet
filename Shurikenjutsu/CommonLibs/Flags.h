#ifndef FLAGS
#define FLAGS

// Flags for debug build
#ifdef _DEBUG 
#define FLAG_DEBUG 1
#define FLAG_RUN_TESTS 0
#define FLAG_FPS 1

// Flags for release build
#else
#define FLAG_DEBUG 0
#define FLAG_RUN_TESTS 0
#define FLAG_FPS 1
#endif

#endif