#lang racket
(define seq '(1 2 3))

(car seq)
(cdr seq)
(cons '(1 2 3) '(4 5 6)); car field points to '(1 2 3), cdr points to 4 5 6

(cons '(1 2) '(1 2))
((lambda (x) (cons x x)) '(1 2)); equivalent resuilt to above

(map car '((1 2) (3 4) (5 6 7))); (1 3 5)
(map + '(1 2) '(10 20) '(100 400)); (111 422)

(map * '(1) '(2) '(3) '(4) '(5)); 120

(define (unary-map fn seq)
  (if (null? seq) '()
      (cons (fn (car seq))
            (unary-map fn
                       (cdr seq)))))

(define (bar a b c . d)
  (list a b c d))

; not working
(define (map fn first-list . other-lists)
  (if (null? first-list) '()
      (cons (apply fn
                   (cons (car first-list)
                         (unary-map car other-lists))))))

(apply map
       (cons fn)
       (cons (cdr first-list)
             (unary-map cdr other-lists))

;(map list (1 10 100) (2 20 200) (3 30 300)) 

(define x '(1 2 3)); x bind to (1 2 3)
(define y (cdr x)); y pointer to (2 3)
(define x '(4 5)); x points to (4 5)

; under the hood, car is the first field, cdr is the second field
; implemeted in linked list type data structure

