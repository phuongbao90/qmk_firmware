#pragma once

#define MASTER_LEFT
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// Press both shift to enable caplocks
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define PERMISSIVE_HOLD
#ifdef TAPPING_TERM          
    #undef TAPPING_TERM      
#endif                       
#define TAPPING_TERM 150
#define QUICK_TAP_TERM_PER_KEY

#define NO_AUTO_SHIFT_ALPHA
#define NO_ACTION_MACRO
#undef  ONESHOT_TAP_TOGGLE
