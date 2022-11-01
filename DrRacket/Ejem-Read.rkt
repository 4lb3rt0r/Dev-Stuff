#lang racket

(define (despliega p1 p2 c)
  (if (equal? #\" (peek-char p1))
      (begin
        (display #\" p2)
        (display (read p1) p2)
        (display #\" p2))
      (despliega p1 p2 (peek-char p1))))

(define (des2 p1 p2 c)
  (if (regexp-match #rx"#\"[a-zA-Z][a-zA-Z0-9]*#\"" (symbol->string(read p1)))
      (begin
        (display #\" p2)
        (display (read p1) p2)
        (display #\" p2))
      (des2 p1 p2 (read p1))))

(define (main)
  (define p1 (open-input-file "Prueba_Read2.txt"))
  (define p2 (open-output-file "NO.html" #:exists 'replace))

  (define c (peek-char p1))

  (des2 p1 p2 c)
  
  (close-output-port p2))

(define (xd c)
  (display c))

(define (comillas c)
  (if (equal? #\" c)
      (display c)
      (display "CHINGASTE A TU PUTA MADRE")))

(define (c2 c)
  (if (string? c)
      (begin
        (display #\")
        (display c)
        (display #\"))
      (display "CHINGASTE A TU PUTA MADRE")))

(define (acum n)
  (+ 0 n))

;(define ch (peek-char p1))
;(display ch)
;(newline)
;(define ch2 (read p1))
;(display ch2)
;(newline)
;(define ch3 (read-char p1))
;(display ch3)
;(newline)
;(define ch4 (read p1))
;(display ch4)
;(newline)
;(define ch5 (read-char p1))
;(display ch5)
;(newline)
;(define ch6 (peek-char p1))
;(display ch6)
;(newline)
;(define ch7 (peek-char p1))
;(display ch7)
;(newline)
