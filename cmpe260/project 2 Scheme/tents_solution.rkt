#lang scheme
; 2017400048

;You can replace #f's with your function definitions and define more helper functions as you need to use this template.

; Custom Functions
;(define (abs x) (if (< x 0) (- x) x))
;(define (length lis) (cond ((null? lis) 0) (else (+ 1 (length (cdr lis))))))

; Solver function
;--------------
; PLAN:
; {
;  1: right (x,y) -> (x,y+1)
;  2: down  (x,y) -> (x+1,y)
;  3: left  (x,y) -> (x,y-1)
;  4: up    (x,y) -> (x-1,y)
; }
;
; 1: Get the amount of trees, set them as 1s (1 1 1 1)
; 2: check if the game is satisfied
; 3: if not, increment the list {(1 1 1 2) as example}
; 4: check once again
; 5: if one digit becomes 5, set it 0 and increase the left digit
; 6: check for all possibilities
; 7: if last digit becomes 5 return #f
;--------------
; Useful Stuff
; (sum (car input)) => amount of tents
; (car input)    => rows (----)
; (cadr input)   => columns(||||)
; (caddr input)  => tree list
;--------------
(define (tentCoordinates trees coordinates)(if (= (length trees) 0) '()
                                               ;else
                                               (cons (cond
                                                       ((= (car coordinates) 1) (list (car (car trees)) (+ (cadr (car trees)) 1)))
                                                       ((= (car coordinates) 2) (list (+ (car (car trees)) 1) (cadr (car trees))))
                                                       ((= (car coordinates) 3) (list (car (car trees)) (- (cadr (car trees)) 1)))
                                                       ((= (car coordinates) 4) (list (- (car (car trees)) 1) (cadr (car trees))))
                                                       (else (car trees))
                                                       )
                                                     (tentCoordinates (cdr trees) (cdr coordinates))
                                                     )
                                               )
  )
(define (noOverride treesNtents)(if (null? treesNtents)
                                    ;true
                                    #t
                                    ;false
                                     (and
                                      (not(member(car treesNtents) (cdr treesNtents)))
                                      (noOverride(cdr treesNtents))
                                      )
                                 )
  )
(define (noTentsNear tents) (if(null? tents)
                               ;true
                               #t
                               ;false
                             (and
                              (ADJACENT-WITH-LIST (car tents) (cdr tents))
                              (noTentsNear (cdr tents))
                              )
                             )
  )
(define (noTentsOutOfBorder rowLength columnLength tents)(if (null? tents)
                                                             ;true
                                                             #t
                                                             ;false
                                                             (and
                                                              (and 
                                                               (< (caar tents) (+ rowLength 1)) ; rowLength+1 because we need < or =
                                                               (< (cadar tents) (+ columnLength 1)); same applies here as well
                                                               )
                                                              (noTentsOutOfBorder rowLength columnLength (cdr tents))
                                                              )
                                                             )
  )
(define (rowFit rowNo goal counter tents)(if (null? tents)
                                       ;true
                                       (= goal counter)
                                       ;false
                                       (if (= (caar tents) rowNo)
                                        (rowFit rowNo goal (+ counter 1) (cdr tents))
                                        (rowFit rowNo goal counter (cdr tents))
                                        )
                                       )
  )
(define (rowsFit rowNo rows tents)(if (null? rows)
                                ;true
                                #t
                                ;false
                                (and
                                 (rowFit rowNo (car rows) 0 tents)
                                 (rowsFit (+ rowNo 1)(cdr rows) tents)
                                 )
                             )
  )
(define (columnFit columnNo goal counter tents)(if (null? tents)
                                       ;true
                                       (= goal counter)
                                       ;false
                                       (if (= (cadar tents) columnNo)
                                        (columnFit columnNo goal (+ counter 1) (cdr tents))
                                        (columnFit columnNo goal counter (cdr tents))
                                        )
                                       )
  )
(define (columnsFit columnNo columns tents)(if (null? columns)
                                      ;true
                                      #t
                                      ;false
                                      (and
                                       (columnFit columnNo (car columns) 0 tents)
                                       (columnsFit (+ columnNo 1)(cdr columns) tents)
                                       )
                                   )
  )

(define (WORKS input coordinates)(if; 5 conditions: noOverride noTentsNear noTentsOutOfBorder rowsFit columnsFit
                                  (and
                                   (and
                                    (noOverride (list (caddr input) (tentCoordinates (caddr input) coordinates)))
                                    (and
                                     (noTentsNear (tentCoordinates (caddr input) coordinates))
                                     (noTentsOutOfBorder (length (car input)) (length (cadr input)) (tentCoordinates (caddr input) coordinates))
                                     )
                                    (and
                                     (rowsFit 1 (car input) (tentCoordinates (caddr input) coordinates))
                                     (columnsFit 1 (cadr input) (tentCoordinates (caddr input) coordinates))
                                     )
                                    )
                                   )
                                  ;if true
                                  (tentCoordinates (caddr input) coordinates)
                                  ;if false
                                  #f
                                  )
  )

(define (sum list)
  (if (= (length list) 1)
      (car list)
      (+ (car list) (sum (cdr list)))
      )
  )
(define (initialize-coordinates n)(if (= n 1)
                                      (list 1)
                                      (cons 1 (initialize-coordinates (- n 1)))
                                      )
  )
(define (MY-INCREASE coordinates)(if (= (length coordinates) 1)
                                     (list (+ (car coordinates) 1))
                                     ;else
                                     (if (= (car (MY-INCREASE (cdr coordinates))) 5)
                                         (cons (+ (car coordinates) 1) (cons 1 (cdr (MY-INCREASE (cdr coordinates)))))
                                         (cons (car coordinates)(MY-INCREASE (cdr coordinates)))
                                         )
                                     )
  )
(define (TEST-COMBINATION input coordinates)(if (= (car coordinates) 5)
                                                #f
                                                (or (WORKS input coordinates)(TEST-COMBINATION input (MY-INCREASE coordinates)))
                                                )
  )
(define (TENTS-SOLUTION input)(if (null? (caddr input))'();if there are no trees
                                  ;else
                                  (TEST-COMBINATION input (initialize-coordinates (length (caddr input))))
                                  )
  )


; Helper functions
(define (RETURN-FIRST-NOT-FALSE func liste) (if (= (length liste) 0) #f
                                                ;else
                                                (if (func (car liste))
                                                    (func (car liste))
                                                    (RETURN-FIRST-NOT-FALSE func (cdr liste))
                                                    )
                                                )
  )

(define ADJACENT (lambda(elem1 elem2) (and
                                       (< (abs (- (car elem1) (car elem2))) 2)
                                       (< (abs (- (cadr elem1) (cadr elem2))) 2)
                                       )
                   )
  )

(define (ADJACENT-WITH-LIST node neighbors) (if (null? neighbors)
                                                #t
                                                (or (ADJACENT node (car neighbors)) (ADJACENT-WITH-LIST node (cdr neighbors)))
                                                )
  )

(define (NEIGHBOR-LIST node) (list
                              (list (car node) (+ (cadr node) 1))
                              (list (+ (car node) 1) (cadr node))
                              (list (car node) (- (cadr node) 1))
                              (list (- (car node) 1) (cadr node))
                              )
  )

(define (REPLACE-NTH list n new_num) (if (= n 1)
                                         (cons new_num (cdr list))
                                         (cons (car list) (REPLACE-NTH (cdr list) (- n 1) new_num))
                                         )
  )