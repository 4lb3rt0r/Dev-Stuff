#|
  File: regexp5.rkt
  Description: Another useful regex functions
  Author: lqnub <lqnub@pm.me>
  Last Modified: 7 Mar 2022
|#

#lang racket
(regexp-match-positions #rx"x." "12x4x6") ; '((2 . 4))
(regexp-replace #rx"mi" "mi casa" "su") ; "su casa"
