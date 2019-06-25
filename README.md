# malloc2

## API

[x] create_new_link
[x] get_paddded_size
[x] create_new_memory_block
[x] detach_link
[ ] split_block
[ ] create_rest_block
[x] search_best_fit
[ ] search_link_by_address
[ ] insert_link_after
[ ] defrag_before

## Init arena list
mmap une arena pour les headers
On prend un bout de la taille d'un header
On pointe la data vers le reste
La size = size de l'arena - taille du header
La liste header est prete !

## Init list
mmap une arena
On prend un header dans la liste des headers
On fait pointer le debut de la liste dessus

## Recherche
On search best fit
On split block
On prend un nouveau header et on fait pointer la data
On place le morceau voulu dans les used
On actualise les liaisons dans free

## Free
On recherche le pointeur dans les used
On remove le link des used
On le place dans les free
On check si on peut defrag
Si oui on actualise les headers precedents et/ou suivants
Le bout de header retourne dans la liste des free headers. On check si on peut defrag.
