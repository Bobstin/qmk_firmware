#include "tap_dances.h"

// SQL Layer Tap Dances ---------------------------------------------------------------------------------------
void sql_d_dance(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("d");
            break;
        case 2:
            SEND_STRING("DROP TABLE IF EXISTS ");
            break;
    }
    reset_tap_dance(state);
}

void sql_i_dance(qk_tap_dance_state_t *state, void *user_data) {
        switch (state->count) {
        case 1:
            SEND_STRING("i");
            break;
        case 2:
            SEND_STRING("INSERT INTO ");
            break;
    }
    reset_tap_dance(state);
}

void sql_s_dance(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("s");
            break;
        case 2:
            SEND_STRING("SELECT");
            break;
        case 3:
            SEND_STRING("SELECT * FROM ");
            break;
        case 4:
            SEND_STRING("SELECT TOP 100 * FROM ");
            break;
        case 5:
            SEND_STRING("SELECT DISTINCT ");
            break;
    }
    reset_tap_dance(state);
}

void sql_g_dance(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("g");
            break;
        case 2:
            SEND_STRING("GROUP BY ");
            break;
    }
    reset_tap_dance(state);
}

void sql_o_dance(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("o");
            break;
        case 2:
            SEND_STRING("ORDER BY ");
            break;
    }
    reset_tap_dance(state);
}

void sql_w_dance(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("w");
            break;
        case 2:
            SEND_STRING("WHERE ");
            break;
    }
    reset_tap_dance(state);
}

void sql_l_dance(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("l");
            break;
        case 2:
            SEND_STRING("LEFT JOIN ");
            break;
    }
    reset_tap_dance(state);
}

void sql_f_dance(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("f");
            break;
        case 2:
            SEND_STRING("FROM ");
            break;
    }
    reset_tap_dance(state);
}