#lang racket

; power set
(define (ps set)
  (if (null? set) '(())
      (append (ps (cdr set))
              (map (lambda (subset)
                     (cons (car set) subset))
                   (ps (cdr set))))))

; > (ps '(1 2 3))
; '(() (3) (2) (2 3) (1) (1 3) (1 2) (1 2 3))

; list in Scheme is immutable. Program generates new list
; hence algorithm above is slow
; More efficient power set algorithm
(define (ps2 set)
  (if (null? set) '(())
      (let ((ps-rest (ps2 (cdr set))))
        (append ps-rest
                 (map (lambda (subset)
                        (cons (car set) subset))
                      ps-rest)))))

; think arguments are evaluated regardless of ordering
; local binding: let

(define (permute items)
  (if (null? items) '(())
      (apply append
         (map (lambda (elem)
                (map (lambda (permutation)
                       (cons elem permutation)
                     (permute (remove items elem))))
                items)))))

; remove first element, not build-in



; Draw triangle recursively
(require 2htdp/image)

(let sierpinski ([n 8])
  (if (zero? n)
      (triangle 2 'solid 'red)
      (let ([t (sierpinski (- n 1))])
            (freeze (above t (beside t t))))))