#|
  File: regexp1.rkt
  Description: Definitions of <pce>
                              <pce> ::= <repeat>
                                    ::= <repeat>?
                                    ::= <atom>
  Author: lqnub <lqnub@pm.me>
  Last Modified: 4 Mar 2022
|#

#lang racket
; Compare the outputs of the following lines
(regexp-match #rx"ca*?[at]" "caaat") ; '("ca")
(regexp-match #rx"ca*?[bt]" "caaat") ; '("caaat")
(regexp-match #rx"ca*?[^a]" "caaam") ; '("caaam")
(regexp-match #rx"ca*?[^m]" "caaam") ; '("ca")
(regexp-match #rx"ca*?[^m]*?" "caaam") ; '("c")
(regexp-match #rx"ca*?[^a]*?" "caaam") ; '("c")

#|

  Explanaition:
  In general, given that the beginning of the regexes is #rx"ca*?" (you can go
ahead and try changing the regexes for that), this means that we're looking to
match the letter c, and the shortest possible version of a series of a's.
Without the end of the regex, this would always translate to an empty string,
BUT, because we're always adding something else, the behaviour is going to be
slightly different in every case

  On the first example, we're matching #rx"ca*?" with either an a or a t.
Because our string is "caaat", we're actually going to match a "c", an "empty
string", and then the letter "a". On contrast, with the second example, as we
can no longer match with an a (because we now have [bt]), instead of an "empty
string", we'll have to match with the "string of all a's" and then the "t"
itself

  Can you figure out the remaining two? Remember that [^<rng>] matches against
any character NOT in <rng>

|#
