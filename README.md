# image2ascii  
turn the given picture into ascii text by its greyscale

### [C](c_im2ascii)
only accept bmp file  
  
##### usage:  
> ```
> make
> ./image2ascii -p <fileName> -w <width> [-i] [-h]
> ```
> -i: inverse, 1/0 taken to make brighter/darker place more significant  
> -h: print help message  

>ex:
>```
>./image2ascii -p shiki.png -w 40 -i
>```

### [C++](c++_im2ascii)
accept all format support by opencv  
##### usage:
> ```
> make
> ./im2ascii_cpp <fileName> <width> <inverse>
> ```

```
6 5 5 5 ; : - = ; + , , . . . . . . .   _ , : : : : + + + +  
4 5 5 4 _ = = = , - : : : ; ; ; ; ; = , _ : : : : + + + + =  
4 5 5 c     . + : ; ; ; ; ; ; : ; ; ; , = : : : : + + + = =  
4 5 5 - _   , : ; ; ; ; ; c c , c c c = + ; : : : + , + = =  
4 5 5 _ , : + + ; ; c c c c + = c c c , - ; ; : : , = + = =  
4 5 5   a = = c c c c : c : b : b c c + c c ; ; : _ + + + =  
4 5 - b c = ! a b b b , , a 3 + b b c - : c c ; ;   : + + +  
! - + c , ; c c c c : +   3 3 = b b ; = . c c c - . : : + +  
    + = = ; c ; + + ! 2 = ! 3 = a a a , : b c c , - : : : +  
4 , + - = : c + b       +   3 = a a a b b b b - ! = : : : :  
3   - + - ; c     a 3 ? _   + - a a a a b b ; + 1 =   + : +  
; - : , , ; c _ 4 5 5 c = !   - a a a b b c       b = + ; -  
, = + = . ; : a 5 5 _       = + c b b -             = . ; ,  
  . ; : . ; , 2 5 b 0         +   b b   _ c     b 1     + .  
  , : : . ; , 3 5     _ -     : = + . ? 4         a 5 :   .  
  - + : + = , 3 5   _ . ,     0 ; a 3 4 _           5 5 . _  
  , + + : = . 2 3 - - - - = _ 3 3 3 3 2     = -     5 5 c :  
  . + + : + . 0 1 2         1 3 3 3 3 3   - , , . , 5 5 + ;  
  . = + + _   ! 0 1 3 ? ? 3 3 3 3 3 3 3 _ + + +   ? 5 4 , :  
- = _ + +   a a 0 1 2 3 3 3 3 1 2 ? 0 3 2 .     a 4 3 b = :  
0   . = +   : 0 0 1 2 3 3 3 3 + : : 3 3 3 3 3 3 2 2 1 . : :  
4 , = = =     a 0 1 2 3 3 3 ! 1 3 ! 3 3 3 3 2 1 0 0 . : : :  
4 4 . = =   _   : 2 3 3 3 3 3 3 3 3 3 3 3 2 1 0 ! , + : + +  
4 5 2 . ,   . b c . ; 3 3 3 3 3 3 3 3 3 3 2 1 0 ; .   . = =  
4 5 1 = .     . 4 5 2 b ? ! 0 3 3 3 3 3 3 2 1 0 0 0 ? :   +  
4 5 ; 5 ;       . 5 5 0 5 5 ?         _ _   . = + : ; ; _  
4 5 - c 1 . 2 -   0 ; _ 3 5 5 ;         . : ! ? ? ? 0 b c =  
5 5 5 3         _ ; 0 + 5 5 5 5 : = 1 1 1 1 1 2 2 3 ? a ! 0  
7 5 5 0 - _ = = +         , 1 : 4 a : a a a a a ! ! 0 0 a c
```
