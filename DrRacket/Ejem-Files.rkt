#lang racket
(define p1 (open-output-file "salidarkt3.txt"))
  (display "HOLA CRAYOLA" p1)
  (newline p1)
  (display "ADIOS" p1)
  (close-output-port p1)