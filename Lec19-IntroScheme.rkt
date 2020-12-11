#|

Programming Paradimgs
1. Imperative/procedural - C
2. Object-oriented - C++
3. Functional

C
vector v
VectorNew(&v, ...);
VectorInsert(&v, ...);
VectorSort(&v, ...);

C++
vector<int> v;
v.push_back(4);
v.erase(v.begin());

Math
f(x, y) = x^3 + y^2 + 7
g(x) = f(x, x + 1) + 8
h(x, y, z) = f(x, z) * g(x + y)
           = x^3 + z^2 + 7 * (f(x+y, x+y+1) + 8)

|#

; Scheme
(define celsius->fahrenheit (temp)
    (+ 32 (* 1.8 temp)))

> (celsius->fahrenheit 100)
212
> 4
4
> "hello"
hello
> #f
#f
> #t
#t
> 11.752
11.752
> 11/5
11/5
> 22/4
11/2
> (+ 1 2 3)
6
> (* (+ 4 4) (+ 5 5))
80
> (> 4 2)
#t
> (< 10 5)
#f
> (and (< 4 2) (< 10 5))
#f

car ; return head of list
cdr ; return other than head
cons ; concatenate two lists
quote (short hand ')  treat behind as raw data, not evaluate it

> (car '(1 2 3 4 5))
1
> (cdr '(1 2 3 4 5))
(2 3 4 5)
> (car (cdr (cdr '(1 2 3 4 5))))
3
> (cons 1 '(2 3 4 5))
(1 2 3 4 5)
> (cons '(1 2 3) '(4 5))
((1 2 3) 4 5)
> (append '(1 2 3) '(4 5))
(1 2 3 4 5)
> (append '(1 2) '(3) '(4 5) '(6 7 8))
(1 2 3 4 5 6 7 8)
> (append '(2 3) (list 1) '(4 5)) ; add list so that 1 can be append
> (cdr '(4))
()
> (cdr '())
error


> (define (add x y) (+ x y)) ; equates add with (x y) arguments and (+ x y) expression
ADD
> (add 10 7)
17
> (sum-of '(1 2 3 4))




