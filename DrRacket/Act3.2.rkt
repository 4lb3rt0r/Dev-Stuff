#lang racket
#|Implementación de Métodos Computacionales
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 20/Mar/2022
Actividad: Act 3.2|#

;Algoritmo de O(n)
(define (imprime lista p2) ;se encarga de imprimir dentro del archivo .txt los tokens de la forma "TOKEN - TIPO"
  (define (despliega lista p2)
    (display (first lista) p2)
    (display "           " p2)
    (display (second lista) p2)
    (newline p2)
    1)
  (if (empty? lista)
      0
      (+ (despliega (car lista) p2) (imprime (cdr lista) p2)))) ;recursividad para imprimir n cantidad de tokens con su respectivo tipo

;Algoritmo de O(1)
(define (convierte atomo) ;se encarga de otorgar a cada token un formato para facilitar la identificación de los mismos
      (if (equal? '= atomo)
          (list atomo "Asignación")
          (if (real? atomo)
              (if (integer? atomo)
                  (list atomo "Entero")
                  (list atomo "Real"))
              (if (equal? '* atomo)
                  (list atomo "Multiplicación")
                  (if (equal? '- atomo)
                      (list atomo "Resta")
                      (if (equal? '/ atomo)
                          (list atomo "División")
                          (if (equal? '+ atomo)
                              (list atomo "Suma")
                              (if (equal? '^ atomo)
                                  (list atomo "Potencia")
                                  (list atomo "Variable")))))))))

;Algoritmo de O(n)
(define (recorre-2 p1) ;se encarga de recopilar n tokens dentro del archivo .txt dentro de una lista (que al final termina siendo una matriz)
  (if (eof-object? (peek-char p1))
  '()
  (append (list (convierte (read p1))) (recorre-2 p1))));recursividad para almacenar todos los tokens y a su vez llama a convierte para otorgar un formato

;Algoritmo de O(1)
(define (recorre file1 file2);se encarga de abrir el archivo de origen, crear el archivo final, llamar a recorre-2,
  (define p1 (open-input-file file1)); colocar los encabezados de la tabla, llamar a imprime y desplegar la cantidad de tokens
  (define p2 (open-output-file file2))
  (define lista (recorre-2 p1))
  (display "TOKEN" p2)
  (display "      " p2)
  (display "TIPO" p2)
  (newline p2)
  (define cantidad (imprime lista p2))
  (display "Cantidad de Tokens: " p2)
  (display cantidad p2)
  (close-output-port p2)
  (close-input-port p1))
