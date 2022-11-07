#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define HYPER OSM(MOD_LSFT | MOD_LALT | MOD_LGUI | MOD_LCTL )
enum layers {
    _QWERTY = 0,
    _SYM,
    _NAV,
    _NUM,
    _ADJUST,
};

// Tap Dance declarations
enum {
    DANCE_0,
    DANCE_1,
    DANCE_2,
    DANCE_3,
};

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    DOUBLE_COLON,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define ADJUST   MO(_ADJUST)

#define B_BACK    LGUI(KC_LEFT)
#define B_FORWARD RGUI(KC_RIGHT)
#define TAB_LEFT  LALT(LGUI(KC_LEFT))
#define TAB_RIGHT LALT(LGUI(KC_RIGHT))
#define S_GUI_A   LSFT(LGUI(KC_A))

