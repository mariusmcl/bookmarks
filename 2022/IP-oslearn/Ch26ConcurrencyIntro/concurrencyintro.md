Så hovedpoenger er at forskjellige tråder deler address-space (minne: all data / objekter, kode). Hver tråd har sin egen stack: De kan kalles med forskjellige variabler, men de deler heap.

Altså: Man kan lage to tråder hvor hver initialiseres med hvilke rader de skal prosessere (legge til tallet 2 på fex). 

Da vil de dele minnet for hvor matrisen oppbevarer seg, som er i Heap-en. Når hver tråd returnerer så vil de ha prosessert den delen av matrisen som var assigned til dem.

Naturlige spm. er jo når de to trådene issuer I/O-requests og aksesserer det samme minne-objektet samtidig.. :/ Hva skjer da??? 


Når man lager threads 
    pthread_create(*ptr1, fct, args1)
    pthread_create(*ptr2, fct, args2)
så vet man ikke rekkefølgen de blir executed i! Det er OS-et og schedulern som bestemmer dette