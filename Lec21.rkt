#lang racket
(define (sorted? sequence cmp)
  (or (< (length sequence) 2)
      (and (cmp (car sequence) (cadr sequence))
                (sorted? (cdr sequence) cmp))))


> (sorted? '(1 2 3 4 5) <)
#t
> (sorted? '(1 3 2 4 3 5 2) >=)
#f

(define (double x) (* x 2))
(define (incr x) (+ x 1))

> (map double '(1 2 3 4))
(2 4 6 8)
> (map incr '(1 2 3 4))
(2 3 4 5)

> (map car '((1 2) (4 8 2) (11)))
(1 4 11)
> (map cdr ((1 2) (4 8 2) (11)))
((2) (8 2) ())
> (map cons '(1 2 8) '((4) () (2 5)))
((1 4) (2) (8 2 5))
> (map + '(1 2) '(3 4 1) '(6 10))
(10 16) // 1 in the second list is ignored

// Implement map
(define (my-unary-map fn seq)
  (if (null? seq) '()
      (cons (fn (car seq))
            (my-unary-map fn (cdr seq)))))


> '(+ 1 2 3)
'(+ 1 2 3)
// eval invoked in command prompt
> (eval '(+ 1 2 3))  
6
> (apply + '(1 2 3))
6

// apply collapses elements in list into one value
(define (average num-list)
  (/ (apply + num-list)
     (length num-list)))

// apply and map shown, terse recursion, not working
(define (flatten seq)
  (if (not (list? seq) (list seq)
           (apply append
                  (map flatten seq)))))

// lambda function
(define (translate points delta)
  (map (lambda (x) (+ x delta)) points))

> (translate '(1 2 3) 100)
'(101 102 103)


// inner function
(define (translate2 seq delta)
  (define (shift-by x)
    (+ x delta))
  (map shift-by seq))


(define (sum x y)
  (+ x y))

// equivalent to above
(define sum
  (lambda (x y) (+ x y)))

(define PI 3.14)





