enum custom_keycodes {
    TOG_SYM = SAFE_RANGE,
    TOG_NAV,
    CTL_SFT,
    OPT_SFT,
    CMD_SFT,
    // ... your other custom keycodes

    SAFE_SHIFT,
};

bool custom_keys_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TOG_SYM:
            if (record->event.pressed) {
                layer_invert(_SYM);
            }
            return false;
        case TOG_NAV:
            if (record->event.pressed) {
                layer_invert(_NAV);
            }
            return false;

        case CTL_SFT: 
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            return false;
        case OPT_SFT: 
            if (record->event.pressed) {
                register_code(KC_LOPT);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LOPT);
                unregister_code(KC_LSFT);
            }
            return false;
        case CMD_SFT: 
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LCMD);
                unregister_code(KC_LSFT);
            }
            return false;
        case SAFE_SHIFT:
            if (record->event.pressed) {
                // When key is pressed, send shift only
                unregister_code(KC_LCMD); // Ensure CMD is not pressed
                register_code(KC_LSFT);
            } else {
                // When key is released, unregister shift
                unregister_code(KC_LSFT);
            }
            return false; // Skip all further processing of this key
    }
    return true;
}

