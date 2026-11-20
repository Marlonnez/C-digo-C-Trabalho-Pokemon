# Projeto Pokémon — Programação Estruturada em C

Projeto acadêmico com dois programas em linguagem C, baseado nos **151 primeiros Pokémon**.

## Arquivos

- `Grupopokemon_Gerador.c`: gera o arquivo `pokemons.txt` com número da Pokédex, nome, tipagem e estágio evolutivo, em ordem aleatória e sem repetições.
- `Grupopokemon_separador.c`: lê `pokemons.txt`, ordena os números e produz relatórios com a média dos números da Pokédex, contagens por tipo e por estágio evolutivo.

## Como usar

Com um compilador C (GCC), na pasta que contém os arquivos:

```bash
gcc Grupopokemon_Gerador.c -o gerador
gcc Grupopokemon_separador.c -o separador
./gerador
./separador
```

No Windows, o executável geralmente recebe a extensão `.exe`, e pode ser iniciado por `./gerador.exe` e `./separador.exe` em terminais compatíveis.

O gerador cria `pokemons.txt`. Execute-o **antes** do separador. O separador cria automaticamente:

- `numeros_pokedex.txt` — números ordenados e média;
- `tipagens.txt` — contagem e lista de Pokémon por tipo;
- `estagios_evolutivos.txt` — contagem e lista por estágio (Inicial, Intermediário, Final e Único).

Os arquivos `.txt` dentro do RAR original estavam vazios; estes relatórios são preenchidos durante a execução dos programas.

## Origem

Códigos-fonte extraídos do arquivo `Projeto Pokemon(1).rar` enviado para publicação. Os executáveis binários `.exe` do arquivo original não foram incluídos no repositório; compile os códigos-fonte para gerar executáveis em seu sistema.

Dados e referências: [Pokémon Database — Pokédex](https://pokemondb.net/pokedex/all).
