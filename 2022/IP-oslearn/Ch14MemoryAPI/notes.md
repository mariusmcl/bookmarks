stack-minne er automatisk managed av kompilatoren (input-verdier til fx osv)


1) segfault
2) EXC_BAD_ACCESS, address = 0x0
3) bit hard to interpret, very informative though
attemppttt!!!
4) did not find any issues from gdb w/o any flags. valgrind found 'em
5) No errors are found
6) When printing the value of data[0] i get 5 where it 'should' be 0. I got 5 after freeing the memory! 
    --> Valgrind notices that we are reading (or writing!) free'd memory
    - Tools are okay, but in this case its pretty obvious

7) 