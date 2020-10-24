# ft_printf

In this project we are introduced to va_args and tasked with the partial recreation of the printf function. 

My implementation was made following IEEE 758 double and extended precision floating point format, and as such, the %f flag is very close to the actual printf's. Flags are managed using a single short, which gives the illusion that I did this in a smart way. It becomes apparent that this is not the case once you look at the code
<br> <img align="right" src="https://github.com/42Curriculum/ft_printf/blob/master/printf.PNG"/> <br>

This supports : 

Conversions :

``` 
d | i| u | o | x | X | c | s | p | % | b <- Does not exist in printf, in mine it prints bits
```

Flags :

```
h | hh | L | ll | - | + | 0 | . | *| [space] | # |
```

## Notes

Unfortunately, I was young and stupid when I made this implementation. It does not use a struct to pass data around and as such is very very messy and does multiple calls to write.

One way to fix this would be to first of all, use a struct and second use a linked list to store all the string data and print everything at the end or, if we wanted to be fast we could use a static array, although that would limit the length of the output, but it can be somewhat compensated by 1) having a big enough array size and / or 2) actually allocating a big enough array once we've determined that the static array would be too small.

I plan to make a better printf sometime in the future
