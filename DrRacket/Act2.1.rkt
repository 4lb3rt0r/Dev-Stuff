#lang racket

#|Implementación de Métodos Computacionales
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 02/Mar/2022
Actividad: Act 2.1|#

(define (farenheit-to-celsius f) ;Convierte las unidades de medición de temperatura de Farenheit a Celcius
  (/(* 5 (- f 32))9))

(define (operation weight height) ;Función adicional para calcular el índice de masa corporal o BMI 
  (/ weight (* height height)))

(define (bmi weight height) ;Clasifica el BMI calculado en base a la altura y peso
  (if (< (operation weight height) 20)
      (display "underweight")
      (if (and (>= (operation weight height) 20)(< (operation weight height) 25))
          (display "normal")
          (if (and (>= (operation weight height) 25)(< (operation weight height) 30))
              (display "obese1")
              (if (and (>= (operation weight height) 30)(< (operation weight height) 40))
                  (display "obese2")
                  (if (>= (operation weight height) 40)
                      (display "obese3")
                      0))))))

(define (positives lst) ;Filtra una lista y elimina los números negativos para dejar solamente los positivos
  (if (null? lst)
      '()
      (if (< (car lst) 0)
          (positives (cdr lst))
          (cons (car lst) (positives (cdr lst))))))

(define (swapper a b lst) ;Recibe 3 parámetros, una lista y 2 elementos "a" y "b", donde "a" será reemplazada por "b" y viceversa de encontrase dentro de dicha lista 
  (if (and (null? lst) (list? lst))
      '()
      (if (equal? (car lst) a)
          (cons b (swapper a b (cdr lst)))
          (if (equal? (car lst) b)
              (cons a (swapper a b (cdr lst)))
              (cons (car lst) (swapper a b (cdr lst)))))))