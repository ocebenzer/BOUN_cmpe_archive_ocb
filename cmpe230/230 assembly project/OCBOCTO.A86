code segment

;octal multiplier by omer cihan benzer 2017400048

;input read starts here

  mov ah , 02
  mov cx , 22d
  mov bx , stringone
oneloop:
  mov dl , [bx]
  int 21h
  inc bx
  dec cx
  jnz oneloop

  call reader
  mov oneh , dx ; oneh is the numberOneHigh
  mov onel , bx ; onel is the numberOneLow

  mov ah , 02
  mov dl , 0A	; print '\n'
  int 21h

  mov ah , 02
  mov cx , 22d
  mov bx , stringtwo
twoloop:
  mov dl , [bx]
  int 21h
  inc bx
  dec cx
  jnz twoloop

  call reader
  mov twoh , dx ; twoh is the numberTwoHigh
  mov twol , bx ; twol is the numberTwoLow

  mov ah , 02
  mov dl , 0A	; print '\n'
  int 21h

;input read ends here

  ; just to help with debug

  push onel
  push oneh
  push twol
  push twoh
  pop ax
  pop ax
  pop ax
  pop ax


;multiplication starts here

  mov ax , onel
  mov bx , twol
  mul bx	; result is dx:ax
  mov out1h , dx
  mov out1l , ax

  mov ax , onel
  mov bx , twoh
  mul bx	;result is dx:ax
  mov out2h , dx
  mov out2l , ax

  mov ax , oneh
  mov bx , twol
  mul bx	; result is dx:ax
  mov out3h , dx
  mov out3l , ax

  mov ax , oneh
  mov bx , twoh
  mul bx	; result is dx:ax
  mov out4h , dx
  mov out4l , ax



	;now we add them together to create outd4:outd3:outd2:outd1

  mov ax , out1l
  mov outd1 , ax	;outd1 complete


  mov ax , 0
  mov cx , 0
  add ax , cx	;to reset cf
  mov temp w, 0
  mov ax , out1h
  mov bx , out2l
  add ax , bx
  jnc jump21
  inc temp w    ; if carry, we increase remainder to add to outd3
jump21:
  push ax
  mov ax , 0
  add ax , cx     	;to reset cf
  pop ax
  mov bx , out3l
  add ax , bx
  jnc jump22
  inc temp w       ; if carry, we increase remainder to add to outd3
jump22:
  mov outd2 , ax	 ; outd2 complete and we have temp as remainder


  mov ax , 0
  add ax , cx   	 ;to reset cf
  mov ax , temp
  mov temp , 0
  mov bx , out2h
  add ax , bx
  jnc jump31
    inc temp        ; if carry, we increase remainder to add to outd3
jump31:
  push ax
  mov ax , 0
  mov cx , 0
  add ax , cx	      ;to reset cf
  pop ax
  mov bx , out3h
  add ax , bx
  jnc jump32
  inc temp
jump32:
  push ax
  mov ax , 0
  add ax , cx     	;to reset cf
  pop ax
  mov bx , out4l
  add ax , bx
  jnc jump33
  inc temp
jump33:
  mov outd3 , ax	   ;outd3 complete and we have temp as remainder


  mov ax , temp
  mov bx , out4h
  add ax , bx
  mov outd4 , ax	;outd4 complete and our number is at outd4:outd3:outd2:outd1

;multiplication ends here

; just to help with debug

  push outd1
  push outd2
  push outd3
  push outd4

  pop ax
  pop ax
  pop ax
  pop ax

;output write starts here

  mov cx , 1		;cx is our counter
  mov bx , 0
  push bx
outputloop:
  call divider
  mov bx , 0
  cmp ax , bx		;ax is outd1
  jnz comparerfail
  mov ax , outd2
  cmp ax , bx
  jnz comparerfail
  mov ax , outd3
  cmp ax , bx
  jnz comparerfail
  mov ax , outd4
  cmp ax , bx
  jnz comparerfail
  jmp outputloopend     ; if all of outd1,2,3,4 are 0 jump to end
comparerfail:           ; else loop continues
  inc cx
  push dx
  jmp outputloop
outputloopend:
  push dx
  mov ah , 02
outputwriteloop:
  pop dx
  add dx , 30h
  int 21h
  dec cx
  mov bx , 0
  cmp cx , bx
  jnz outputwriteloop
outputwriteloopend:

;output write ends here

;print method for stringend
  mov ah , 02
  mov cx , 24d
  mov bx , stringend
  mov dl , 0A	; echo '\n'
  int 21h
endloop:
  mov dl , [bx]
  int 21h
  inc bx
  dec cx
  jnz endloop
endend:

  mov ah , 01
  int 21h

  int 20h

reader:
  mov ax , 0
  mov bx , 0
  mov cx , 0
  mov dx , 0
readerloop:		; dx:bx  inputHigh:inputLow
  mov ah , 01
  int 21h
  cmp al , 0D		; 0D equals to return or '\n'
  je readerend
  mov ah , 0
  sub al , 30h		; 30h for '0'
  mov readerd , ax
  mov ax , dx
  mov cx , 8d
  mul cx
  mov readera , ax
  mov ax , bx
  mul cx
  mov readerb , dx
  mov readerc , ax	; declaration complete

  mov ax , 0
  mov cx , 0
  mov dx , readerb
  add ax , cx		; to reset cf
  mov ax , readerc
  mov bx , readerd
  add ax , bx
  jnc readermore
  inc dx            ; the remainder
readermore:
  mov bx , ax
  mov cx , readera
  add dx , cx
  jmp readerloop
readerend:
  ret			; dont forget, number is at dx:bx

divider:
  mov ax , 0
  mov bx , 8		; to divide by bx later
  mov dx , 0
  mov ax , outd4
  div bx		; ax is quotient, dx is remainder
  mov outd4 , ax
  mov ax , outd3
  div bx		;
  mov outd3 , ax
  mov ax , outd2
  div bx
  mov outd2 , ax
  mov ax , outd1
  div bx
  mov outd1 , ax	; remainder is in dx, quotient is in ax
  ret

; variables:

  readera dw ? ; lets say dx:bx is the number we have and the input is input
  readerb dw ? ; as we know the input wont exceed 2^32, dx*8=0000:____ .
  readerc dw ? ; So we record the mid numbers as such:
  readerd dw ? ; dx*8 = readera  bx*8=readerb:readerc input=readerd

  oneh dw ? ; number1 high
  onel dw ? ; number1 low
  twoh dw ? ; number2 high
  twol dw ? ; number2 low

  out1h dw ? ; out1 is onel*twol
  out1l dw ? ;
  out2h dw ? ; out2 is onel*twoh
  out2l dw ? ;
  out3h dw ? ; out3 is oneh*twol
  out3l dw ? ;
  out4h dw ? ; out4 is oneh*twoh
  out4l dw ? ;

  outd1 dw ? ; outd's are output in binary state, from lowest to highest
  outd2 dw ? ;
  outd3 dw ? ;
  outd4 dw ? ;

  temp dw ?  ; just a temp to use in multiplication and at the very begginging of the output


 ;would i use these?

  outq1 dw ? ; outq's are outd/8
  outq2 dw ? ;
  outq3 dw ? ; so they are the quotients of outd's
  outq4 dw ? ;

  outr1 dw ? ; outr's are outd%8
  outr2 dw ? ;
  outr3 dw ? ; so they are the remainders of outd's
  outr4 dw ? ;


  stringone:
db 'Please enter number 1:'
  stringtwo:
db 'Please enter number 2:'
  stringend:
db 'Press anything to close.'
code ends
