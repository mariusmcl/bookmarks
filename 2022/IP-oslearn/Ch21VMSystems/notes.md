1) den bruker 6% står det av CPU-tiden hele tiden.. uansett hvor stort arrayet er 
    - når den allokerer større arrays, så bruker systemet lengre tid på CPUen enn når det er et mindre array. men prosent-tiden brukt summerer opp til 6% uansett
        for (bruker, system): (2, 4 -> 4,2 -> 6, 0) for stort array vs (4, 2 -> 6, 0) for mindre array
    - flere instanser øker bruken lineært
2) 

3) for større arrays, kan starte med å swappe inn minne fra disk, men de sender ikke noe ut igjen og de får plass