// Modified by Justin Kahn. Adapted from the Pascal Getreuer Caps Word library. See licence below.
// This version does not activate caps word by hitting the left and right shift keys. Instead,
// it relies on the user to create a rule (usually a combo) that activates caps word in keymap.c


// Copyright 2021-2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//
// Caps Word, activated by pressing both shift keys at the same time.
//
// This library implements "Caps Word", which is like conventional Caps Lock,
// but automatically disables itself at the end of the word. This is useful for
// typing all-caps identifiers like `MOD_MASK_ALT`.
//
// For full documentation, see
// https://getreuer.info/posts/keyboards/caps-word

#pragma once

#include QMK_KEYBOARD_H

// Call this function from `process_record_user()` to implement Caps Word.
bool process_caps_word(uint16_t keycode, keyrecord_t* record);

// Activates or deactivates Caps Word. For instance activate Caps Word with a
// combo by defining a `COMBO_ACTION` that calls `caps_word_set(true)`:
//
// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case CAPS_COMBO:
//       if (pressed) {
//         caps_word_set(true);  // Activate Caps Word.
//       }
//       break;
//
//     // Other combos...
//   }
// }
void caps_word_set(bool active);

// Returns whether Caps Word is currently active.
bool caps_word_get(void);

// An optional callback that gets called when Caps Word turns on or off. This is
// useful to represent the current Caps Word state, e.g. by setting an LED or
// playing a sound. In your keymap, define
//
//   void caps_word_set_user(bool active) {
//     if (active) {
//       // Do something when Caps Word activates.
//     } else {
//       // Do something when Caps Word deactivates.
//     }
//   }
void caps_word_set_user(bool active);
