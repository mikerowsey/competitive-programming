# CSES Problems Index

This index tracks solved problems, their primary technique, and local test mode.

| Problem               | Pattern / Technique                  | Test Kind | Perf Smoke |
| --------------------- | ------------------------------------ | --------- | ---------- |
| apple_division        | Exhaustive search / subset recursion | exact     | no         |
| bit_strings           | Modular exponentiation               | exact     | no         |
| chessboard_and_queens | Backtracking with constraints        | exact     | no         |
| coin_piles            | Math invariants                      | exact     | no         |
| creating_strings      | Backtracking with duplicate handling | exact     | no         |
| gray_code_bit         | Bit construction                     | exact     | no         |
| increasing_array      | Greedy accumulation                  | exact     | yes        |
| missing_number        | Arithmetic sum / xor-style invariant | exact     | no         |
| number_spiral         | Math pattern mapping                 | exact     | yes        |
| palindrome_reorder    | Frequency counting                   | exact     | no         |
| permutations          | Constructive ordering                | exact     | no         |
| raab_game_i           | Constructive permutations            | semantic  | no         |
| repetitions           | Linear scan                          | exact     | no         |
| tower_of_hanoi        | Recursive generation                 | exact     | no         |
| trailing_zeros        | Factor counting                      | exact     | no         |
| two_knights           | Formula derivation                   | exact     | no         |
| two_sets              | Greedy partition                     | exact     | no         |
| weird_algorithm       | Simulation                           | exact     | no         |

## Notes

- `exact` tests compare normalized output against fixtures.
- `semantic` tests validate correctness properties for multi-answer tasks.
- Perf smoke tests run only when `CP_ENABLE_PERF_TESTS=ON` (e.g. `cmake --preset perf`).
