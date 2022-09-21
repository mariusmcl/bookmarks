Operativsystemet tilgjengejliggjør abstraksjoner som vi kaller prosesser for å tillate folk å kjøre programmer på PCen


Det første som skjer når man oppretter en prosess er at OSet tar koden (hva som skal gjøres) og konstanter definert i koden (hva som er 'inputen') og overfører det fra disk til minnet
        -> Her er det jo spennende det Apple har gjort med minne & disk: Mye raskere disk & swapping så det er lett å gå frem og tilbake, gir en god abstraksjon


STACK: Local variables, funksction parameter, retur-adresser. OS initialiserer stack med variabler som er gitt inn til argc & argv

HEAP: dynamisk allokert data (du gjør noe matrisemultiplikasjon inne i programmet) også blir det et nytt objekt med data & plass. malloc() gir programmer en gitt mengde minne. HEAP-STRUCTURE trengs for data-structures som hash-tables, trees, ++...

    malloc() library API

file-descriptors tilgjengeligjøres for å kunne kommunisere: programmet må kunne kommunisere med den eksterne verden, og da oppretter man 'file-descriptors' for å kunne gjøre dette! --> er altså dette som er kommunikasjonsgrunnlaget :))

    file-descriptors for communication inside a program


IO-request til disk: programmet kan bli blokket av at det venter på OS-et. MEN: da skjer 'ingenting' på prosessoren, så det er DISKEN som det ventes på!! ganske utrolig

    IO-request til disk: det er den FYSISKE DISKEN som passer på allokeringen/ventes på!!! 