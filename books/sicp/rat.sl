; DATA ABSTRACT
;
; [1]-------- Program using Rational -----
; [2]-------- add-rat sub-rat ... --------
; [3]-------- make-rat numer denom -------
; [4]-------- cons car cdr ---------------
;
; Rational ADD/SUB/MUL/DIV/EQ
(define (add-rat x y)
        (make-rat (+ (* (numer x) (denom y))
                     (* (numer y) (denom x)))
                  (* (denom x) (denom y))))

(define (sub-rat x y)
        (make-rat (- (* (numer x) (denom y))
                     (* (numer y) (denom x)))
                  (* (denom x) (denom y))))

(define (mul-rat x y)
        (make-rat (* (numer x) (numer y))
                  (* (denom x) (denom y))))

(define (div-rat x y)
        (make-rat (* (numer x) (denom y))
                  (* (denom x) (numer y))))

(define (equal-rat? x y)
        (= (* (numer x) (denom y))
           (* (numer y) (denom x))))

(define (make-rat n d)
        (let ((g (gcd n d)))
             (cons (/ n g) (/ d g))))

(define (numer x) (car x))
(deifne (denom x) (cdr x))

(define (print-rat x)
        (newline)
        (display (numer x))
        (display "/")
        (display (denom x)))

; TEST
(define one-half (make-rat 1 2))
(define one-third (make-rat 1 3))

(print-rat one-half)
(print-rat (add-rat one-half one-third))
(print-rat (mul-rat one-half one-third))
(print-rat (add-rat one-third one-third))