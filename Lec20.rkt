; Lecture 20
(define sum-list (numlist)
    (if (null? numlist) 0)  ; if numlist is null return 0
        (+ (car numlist)  ; else execute here
            (sum-list (cdr numlist))))


> (sum-list '(1 2 3 4 5))
15
> (sum-list '())
0
> (sum-list '("hello" 1 2 3 4 5))
error


(define fib (n)
    (if (zero? n) 0
        (if (= n 1) 1
            (+ (fib (- n 1))
                (fib (- n 2))))))

(define fib (n)
    (if (or (= n 0)
        (= n 1)) n
    (+ (fib (- n 1))
        (fib (- n 2)))))

> (if (zero? 0) 4
    (+ "hello" 4.5 '(8 2))) ; though error, program didn't care
4
> (flatten '(1 2 3 4))
(1 2 3 4)
> (flatten '(1 (2 3) 4 ((5))))
(1 2 3 4 5)
> (flatten '(1 (2 "3") "4" ((5))))
(1 2 "3" "4" 5)

In Scheme, programmer doesn't deal with memory management

> (flatten '(1 2 () 3 4)) ; assume empty list edge case doesn't exist

(define flatten(sequence)
    (cond (((null? sequence) '()) ; if sequence null?
        ((list? (car sequence)) ; if this is a list?
            (append (flatten (car sequence))
                (flatten (cdr sequence)))))
            (else (cons (car sequence)
                (flatten (cdr sequence))))))


(define sorted? (num-list)
    (or (< (length numlist) 2)
        (and (<= (car numlist)
            (cadr numlist))
            (sorted? (cdr numlist)))))


; cdddr, cadadr, only 4 between c and r
> (sorted? '(1 2 2 4 7))
#t
> (sorted? '(1 0 4 7 10))
#f
> (< 1 2)
#t
> (<= 1 2 3 4 5 6 6)
#t


> (sorted? '(1 3 5 7) <=) ; pass in operator to guide comparison
#t
> (sorted? '("a", "b", "d", "c") 
    string<?)
#f

(define sorted? (seq comp)  ; comp guide how to operate on (car seq) and (cadr seq)
    (or (< (length seq) 2)
        (and (comp (car seq)
                (cadr seq))
            sorted? (cdr seq) comp)))









