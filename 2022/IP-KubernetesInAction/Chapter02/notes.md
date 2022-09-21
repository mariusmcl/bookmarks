Det beste punktet fra denne artikkelen er når han sier 

"In view of all this, one might ask what is a container at all? A process that runs “in a container” doesn’t run in something that resembles a real enclosure like a VM. It’s only a process to which several namespaces (one for each type) are assigned. Some are shared with other processes, while others are not. This means that the boundaries between the processes do not all fall on the same line."


En prosess som kjører i en container er en prosess som er tilknyttet flere namespaces, en for hver type. Noen namespace-keys kan være delt med andre prosesser, og andre ikke. Skillet mellom hver prosess er altså tilknyttet hvilke namespace-keys den er koblet til


Containere er vanlige linux-prosesser, men er isolert fra hverandre wrt. hvilke namespaces de er assignet, og hvilke privilegier de har når de kjører. Privilegier kan deles opp i 'evner' (capabilities), som kan være om en prosess kan endre systemtiden, om den kan binde til porter under tallet 1K, osv.... 

De kjører som vanlige prosesser og man må derfor ikke ha et OS-lag på toppen, så de er lettere enn VMs

Container RUntime INterface: kubernetes støtter nå flere container runtimes :)

Container image inneholder bruker-applikasjonen og dens avhengigheter. 

Nå skal vi se på å kjøre containere med kubernetes :))