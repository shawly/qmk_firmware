#pragma once

/*
 * |-----------------------------------------------------------------------|
 * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17|
 * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
 * |-----------------------------------------------------------------------|
 */
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_ORANGE},
    {14, 2, HSV_PURPLE},
    {16, 1, HSV_ORANGE}
);
/*
 * |-----------------------------------------------------------------------|
 * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17|
 * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
 * |-----------------------------------------------------------------------|
 */
const rgblight_segment_t PROGMEM function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE},
    {12, 2, HSV_TEAL},
    {14, 3, HSV_PURPLE}
);
/*
 * |-----------------------------------------------------------------------|
 * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17|
 * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
 * |-----------------------------------------------------------------------|
 */
const rgblight_segment_t PROGMEM macro_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_TEAL},
    {14, 2, HSV_ORANGE},
    {16, 1, HSV_TEAL}
);
/*
 * |-----------------------------------------------------------------------|
 * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17|
 * | * | * | * | * |   |   |   |   |   |   |   |   |   |   | * | * | * | * |
 * |-----------------------------------------------------------------------|
 */
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, HSV_RED}
);
/*
 * |-----------------------------------------------------------------------|
 * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17|
 * |   |   |   |   |   |   | * | * | * | * | * | * |   |   |   |   |   |   |
 * |-----------------------------------------------------------------------|
 */
const rgblight_segment_t PROGMEM scrolllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 6, HSV_GREEN}
);
/*
 * |-----------------------------------------------------------------------|
 * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17|
 * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
 * |-----------------------------------------------------------------------|
 */
const rgblight_segment_t PROGMEM bootloader_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 17, HSV_BLUE}
);


const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    function_layer,
    macro_layer,
    capslock_layer,
    scrolllock_layer,
    bootloader_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(3, led_state.caps_lock);
    rgblight_set_layer_state(4, led_state.scroll_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BL));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _FL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _ML));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case QK_BOOT:
                rgblight_disable_noeeprom();
                return true;
        }
    }
    return true;
}