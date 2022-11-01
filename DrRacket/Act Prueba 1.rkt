#lang racket

(define lista1 (list 1 2 3 8 5 6 9 3 2 4))

(define(junta l1 l2)
       (append l1 l2))

(define (junta2 l1 l2)
  (cons l1 l2))

(define (oper f a b)
  (f a b))

(define (lee st)
  (display st)
  (display "\n")
  (define a (read))
  (display a)
  (display "\n")
  (write a))

(define (mayor a b)
  (if (> a b)
      (display a)
      (display b)))

(define (prom c1 c2 c3)
  (/ (+ c1 c2 c3) 3))

(define (calif c1 c2 c3)
  (if (< (prom c1 c2 c3) 70)
      (display "REPROBADO\n")
      (display "APROBADO\n")))

(define (fact n)
  (if (= n 0)
      1
      (* n (fact (- n 1)))))

(define (long lis)
  (if (null? lis)
  0
  (+ 1 (long (cdr lis)))))

(define (cuentaAtomos lis)
  (if (null? lis)
      0
      (if (list? (car lis))
          (+ (cuentaAtomos (car lis)) (cuentaAtomos (cdr lis)))
             (+ 1 (cuentaAtomos (cdr lis))))))